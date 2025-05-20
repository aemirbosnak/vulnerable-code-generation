//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include<stdio.h>
#include<math.h>

#define MAX_NODES 100
#define MAX_GAINS 1000

int n, e, g_cnt;
int edges[MAX_NODES][MAX_NODES];
double edges_gains[MAX_NODES][MAX_NODES];
double voltages[MAX_NODES];
double gains[MAX_GAINS];

void dfs(int node, double current_gain){
    // if the node is the last one, store the total gain
    if(node == n-1){
        gains[g_cnt++] = current_gain;
        return;
    }

    // go through all the edges
    for(int i=0; i<n; i++){
        if(edges[node][i]){
            // update the voltage and calculate the new gain
            voltages[i] = voltages[node] * edges_gains[node][i];
            double new_gain = current_gain * edges_gains[node][i];

            // continue the search to the next node
            dfs(i, new_gain);
        }
    }
}

int main(){
    // read inputs
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for(int i=0; i<e; i++){
        int from, to;
        double gain;

        printf("Enter the edge (from, to, gain): ");
        scanf("%d %d %lf", &from, &to, &gain);

        edges[from][to] = 1;
        edges_gains[from][to] = gain;
    }

    // do the circuit analysis
    dfs(0, 1.0);
    double total_gain = 0.0;

    for(int i=0; i<g_cnt; i++){
        total_gain += gains[i];
    }

    // print the total gain
    printf("The total gain of the circuit is: %lf\n", total_gain);

    return 0;
}