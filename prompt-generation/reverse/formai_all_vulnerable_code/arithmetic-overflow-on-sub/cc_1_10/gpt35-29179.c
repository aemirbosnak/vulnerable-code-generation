//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50     // maximum number of nodes in the circuit
#define MAX_EDGES 100    // maximum number of edges in the circuit

int R[MAX_EDGES], L[MAX_EDGES], C[MAX_EDGES];   // resistance, inductance and capacitance of each edge
int u[MAX_EDGES], v[MAX_EDGES];                // the nodes of each edge
int N, M;                                      // number of nodes and edges
double dt;                                      // simulation time step
double V[MAX_NODES], I[MAX_NODES];              // voltage and current of each node
double A[MAX_EDGES][MAX_NODES];                 // adjacent matrix of the circuit
double B[MAX_EDGES], X[MAX_EDGES];              // data for solving matrix equation Ax=B, X is the solution

// solve the matrix equation Ax = B for X
void solve() {
    int i, j, k;
    double m;

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            A[i][j] = 0.0;
        }
        A[i][u[i]] = 1.0 / R[i];
        A[i][v[i]] = -1.0 / R[i];
        if (L[i] != 0) {
            A[i][v[i]] -= dt / L[i];
            A[i][u[i]] += dt / L[i];
        }
        if (C[i] != 0) {
            B[i] = C[i] * (V[u[i]] - V[v[i]]) / dt;
        }
        else {
            B[i] = 0.0;
        }
    }
    B[1] -= I[1];
    X[1] = B[1] / A[1][1];
    for (i = 2; i <= M; i++) {
        m = A[i][i-1] / A[i-1][i-1];
        A[i][i] -= m * A[i-1][i];
        B[i] -= m * B[i-1];
    }
    X[M] = B[M] / A[M][M];
    for (i = M-1; i >= 1; i--) {
        X[i] = (B[i] - A[i][i+1] * X[i+1]) / A[i][i];
    }
}

int main() {
    int i, j, k, l;
    char line[100];

    // read input
    scanf("%d %d %lf", &N, &M, &dt);
    for (i = 1; i <= M; i++) {
        scanf("%d %d %d %d %d", &u[i], &v[i], &R[i], &L[i], &C[i]);
    }

    // simulate circuit
    for (i = 0; i < 1000; i++) {
        // compute voltage and current of each node
        for (j = 1; j <= N; j++) {
            I[j] = 0.0;
            for (k = 1; k <= M; k++) {
                if (u[k] == j) {
                    I[j] -= X[k];
                }
                else if (v[k] == j) {
                    I[j] += X[k];
                }
            }
            V[j] += dt * I[j];
        }
        // solve matrix equation for new edge currents
        solve();
        // print output
        for (j = 1; j <= N; j++) {
            printf("V[%d] = %lf\n", j, V[j]);
        }
        for (j = 1; j <= M; j++) {
            printf("I[%d] = %lf\n", j, X[j]);
        }
    }
    return 0;
}