//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

/* This is the most exciting circuit simulator program ever!
 * With this incredible program, you can simulate all kinds
 * of circuits and watch the magic happen before your very eyes!
 * It's like being a magician, but with electricity instead of rabbits!
 * Here's how it works:
 */

#define MAX_NODES 100
#define MAX_ELEMENTS 200

/* First, we set up the variables that we will need. */

typedef struct {
    int node1;
    int node2;
    double value;
} element;

int num_nodes, num_elements;

double G[MAX_NODES][MAX_NODES];
double b[MAX_NODES];
double x[MAX_NODES];
element e_list[MAX_ELEMENTS];

/* Then we define the main function, which will do all the work. */

int main() {
    /* First we read in all the values from the user. */
    printf("How many nodes does your circuit have? ");
    scanf("%d", &num_nodes);
    printf("How many elements does your circuit have? ");
    scanf("%d", &num_elements);
    printf("Now enter the values for each element.\n");
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %lf", &e_list[i].node1, &e_list[i].node2, &e_list[i].value);
    }
    /* Then we set up the matrices that we will need. */
    for (int i = 0; i < num_elements; i++) {
        G[e_list[i].node1][e_list[i].node2] += 1 / e_list[i].value;
        G[e_list[i].node2][e_list[i].node1] += 1 / e_list[i].value;
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i == j) {
                G[i][i] = -1;
            }
        }
    }
    b[num_nodes - 1] = -1;
    /* Then we solve the matrix equation using Gauss-Jordan elimination. */
    for (int i = 0; i < num_nodes - 1; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            double ratio = G[j][i] / G[i][i];
            for (int k = i; k < num_nodes; k++) {
                G[j][k] -= ratio * G[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }
    for (int i = num_nodes - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < num_nodes; j++) {
            sum += G[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / G[i][i];
    }
    /* Finally we print out the results. */
    printf("The voltage at each node in the circuit is:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %lf\n", i + 1, x[i]);
    }
    printf("Thank you for using the most exciting circuit simulator program ever!\n");
    return 0;
}