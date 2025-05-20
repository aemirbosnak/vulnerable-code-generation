//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct Component {
    char type;
    int node1, node2;
    double value;
} Component;

Component components[MAX_NODES];
double voltages[MAX_NODES];

int node_counter = 0;

int find_node(int node) {
    int i;
    for(i = 0; i < node_counter; i++) {
        if(node == voltages[i]) {
            return i;
        }
    }
    voltages[node_counter] = node;
    node_counter++;
    return (node_counter - 1);
}

void stamp_component(Component c, double **A, double *B) {
    int n1 = find_node(c.node1);
    int n2 = find_node(c.node2);

    switch(c.type) {
        case 'R':
            if(n1 >= 0 && n2 >= 0) {
                A[n1][n1] += 1 / c.value;
                A[n1][n2] -= 1 / c.value;
                A[n2][n1] -= 1 / c.value;
                A[n2][n2] += 1 / c.value;
            }
            break;

        case 'V':
            if(n1 >= 0) {
                A[node_counter][n1] = 1;
                A[n1][node_counter] = -1;
                B[node_counter] = c.value;
                node_counter++;
            }
            if(n2 >= 0) {
                A[node_counter][n2] = -1;
                A[n2][node_counter] = 1;
                B[node_counter] = -c.value;
                node_counter++;
            }
            break;

        case 'I':
            if(n1 >= 0 && n2 >= 0) {
                A[n1][n2] -= c.value;
                A[n2][n1] += c.value;
            }
            break;

        default:
            printf("Invalid component type!\n");
            exit(1);
    }
}

void solve(double **A, double *B, int size) {
    int i, j, k;
    double factor;

    for(i = 0; i < size; i++) {
        if(A[i][i] == 0) {
            printf("Singular matrix!\n");
            return;
        }

        for(j = i + 1; j < size; j++) {
            factor = A[j][i] / A[i][i];
            for(k = i; k < size; k++) {
                A[j][k] -= A[i][k] * factor;
            }
            B[j] -= B[i] * factor;
        }
    }

    for(i = size - 1; i >= 0; i--) {
        voltages[i] = B[i] / A[i][i];
        for(j = i - 1; j >= 0; j--) {
            B[j] -= A[j][i] * voltages[i];
            A[j][i] = 0;
        }
    }
}

void simulate_circuit(Component *components, int len) {
    int i, j;

    double **A = malloc(sizeof(double*) * node_counter);
    for(i = 0; i < node_counter; i++) {
        A[i] = malloc(sizeof(double) * node_counter);
        for(j = 0; j < node_counter; j++) {
            A[i][j] = 0;
        }
    }

    double *B = malloc(sizeof(double) * node_counter);
    for(i = 0; i < node_counter; i++) {
        B[i] = 0;
    }

    for(i = 0; i < len; i++) {
        stamp_component(components[i], A, B);
    }

    solve(A, B, node_counter);

    for(i = 0; i < node_counter; i++) {
        printf("Voltage at node %g: %g\n", voltages[i]);
    }

    for(i = 0; i < node_counter; i++) {
        free(A[i]);
    }
    free(A);
    free(B);
}

int main() {
    Component components[] = {
        {'R', 1, 2, 220},
        {'V', 2, 0, 5},
        {'R', 2, 3, 100},
        {'I', 3, 0, 0.010},
    };

    simulate_circuit(components, 4);

    return 0;
}