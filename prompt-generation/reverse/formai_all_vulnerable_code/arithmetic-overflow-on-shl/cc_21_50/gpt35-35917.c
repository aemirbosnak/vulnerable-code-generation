//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>

#define MAX_NODES 1000
#define MAX_VOLTS 10
#define MAX_ELEMS 2000

int A[MAX_ELEMS][MAX_NODES+1];
int z[MAX_NODES+1];

int main() {
    int n, m, i, j, k;
    int v[MAX_ELEMS], e[MAX_ELEMS][2];
    int w[MAX_NODES+1];
    int count;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &e[i][0], &e[i][1], &v[i]);
        e[i][0]--;
        e[i][1]--;
    }

    /* generate all possible combinations of voltages */
    for (i = 0; i < (1 << n); i++) {
        count = 0;

        /* for every voltage combination, generate the nodal equations */
        for (j = 0; j < n; j++) {
            z[j] = (i & (1 << j)) ? MAX_VOLTS : -MAX_VOLTS;
        }

        for (j = 0; j < n; j++) {
            for (k = 0; k <= n; k++) {
                A[count][k] = 0;
            }

            A[count][j] = 1;

            for (k = 0; k < m; k++) {
                if (e[k][0] == j) {
                    A[count][e[k][1]] = -1;
                    A[count][n] -= v[k];
                } else if (e[k][1] == j) {
                    A[count][e[k][0]] = -1;
                    A[count][n] += v[k];
                }
            }

            count++;
        }

        /* solve the nodal equations */
        for (j = 0; j < n; j++) {
            w[j] = 0;
        }

        for (j = 0; j < count; j++) {
            int p;

            for (k = 0; k < n; k++) {
                if (A[j][k] != 0) {
                    p = k;
                    break;
                }
            }

            if (w[p] == 0) {
                double f = 1.0 / A[j][p];
                for (k = 0; k <= n; k++) {
                    A[j][k] *= f;
                }

                w[p] = 1;
            } else {
                continue;
            }

            for (k = 0; k < count; k++) {
                if (k == j || A[k][p] == 0) {
                    continue;
                }

                double f = A[k][p];
                for (i = 0; i <= n; i++) {
                    A[k][i] -= f * A[j][i];
                }
            }
        }

        for (j = 0; j < n; j++) {
            printf("%d ", z[j]);
        }

        printf("%.2f\n", A[0][n]);
    }

    return 0;
}