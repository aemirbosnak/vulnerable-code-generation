//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 1000
#define MAX_VAL 1000

typedef struct {
    int node1, node2;
    double value;
} component;

int n, m;
component c[MAX_NODES];
double G[MAX_NODES][MAX_NODES], B[MAX_NODES][MAX_NODES], V[MAX_NODES], I[MAX_NODES], x[MAX_NODES];

void input()
{
    printf("Enter the number of nodes and components: ");
    scanf("%d %d", &n, &m);

    printf("Enter the components:\n");
    for (int i = 0; i < m; i++) {
        printf("Component %d: ", i + 1);
        scanf("%d %d %lf", &c[i].node1, &c[i].node2, &c[i].value);
    }

    printf("Enter the voltage at each node:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%lf", &V[i]);
    }
}

void generate_system_of_equations()
{
    for (int i = 0; i < m; i++) {
        int n1 = c[i].node1, n2 = c[i].node2;
        double g = 1.0 / c[i].value;

        if (n1 > 0 && n2 > 0) {
            G[n1][n1] += g;
            G[n2][n2] += g;
            G[n1][n2] -= g;
            G[n2][n1] -= g;
        } else if (n1 < 0 && n2 < 0) {
            B[-n1][-n1] += g;
            B[-n2][-n2] += g;
            B[-n1][-n2] -= g;
            B[-n2][-n1] -= g;
        } else if (n1 > 0 && n2 < 0) {
            G[n1][n1] += g;
            B[-n2][-n2] += g;
            G[n1][-n2] -= g;
            B[-n2][n1] -= g;
        } else if (n1 < 0 && n2 > 0) {
            B[-n1][-n1] += g;
            G[n2][n2] += g;
            B[-n1][n2] -= g;
            G[n2][-n1] -= g;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                B[i][i] += G[i][j];
            }
        }
    }
}

void solve_system_of_equations()
{
    for (int k = 0; k < n; k++) {
        int i_max = -1;
        double max = -1;

        for (int i = k; i < n; i++) {
            if (fabs(B[i][k]) > max) {
                i_max = i;
                max = fabs(B[i][k]);
            }
        }

        if (i_max == -1) {
            printf("Singular matrix\n");
            exit(1);
        }

        if (i_max != k) {
            for (int j = k; j < n; j++) {
                double temp = B[k][j];
                B[k][j] = B[i_max][j];
                B[i_max][j] = temp;
            }

            double temp = V[k];
            V[k] = V[i_max];
            V[i_max] = temp;
        }

        for (int i = k + 1; i < n; i++) {
            double ratio = B[i][k] / B[k][k];

            for (int j = k; j < n; j++) {
                B[i][j] -= ratio * B[k][j];
            }

            V[i] -= ratio * V[k];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;

        for (int j = i + 1; j < n; j++) {
            sum += B[i][j] * x[j];
        }

        x[i] = (V[i] - sum) / B[i][i];
    }
}

void output()
{
    printf("Node voltages:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: %lf\n", i + 1, x[i]);
    }

    printf("Currents:\n");
    for (int i = 0; i < m; i++) {
        double i_c = (x[c[i].node1 - 1] - x[c[i].node2 - 1]) / c[i].value;
        printf("Component %d: %lf\n", i + 1, i_c);
    }
}

int main()
{
    input();
    generate_system_of_equations();
    solve_system_of_equations();
    output();
    return 0;
}