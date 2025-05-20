//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include <stdio.h>

#define MAX_NODES 1000
#define MAX_IN_NODES 10

int n, in_nodes[MAX_IN_NODES], out_node;

/* function to simulate circuit */
void simulate()
{
    int nodes[MAX_NODES];
    
    /* initialize all nodes to 0 */
    for (int i=0; i<MAX_NODES; i++) {
        nodes[i] = 0;
    }
    
    /* set input node values */
    for (int i=0; i<MAX_IN_NODES; i++) {
        nodes[in_nodes[i]] = 1;
    }
    
    /* evaluate circuit */
    for (;;) {
        /* calculate output node value */
        int output = nodes[out_node];
        
        /* print output */
        printf("Output: %d\n", output);
        
        /* prompt for input */
        printf("Enter input values: ");
        for (int i=0; i<MAX_IN_NODES; i++) {
            int val;
            scanf("%d", &val);
            nodes[in_nodes[i]] = val;
        }
    }
}

int main()
{
    /* prompt for input */
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    /* prompt for input nodes */
    for (int i=0; i<MAX_IN_NODES; i++) {
        printf("Enter input node %d: ", i);
        scanf("%d", &in_nodes[i]);
    }
    
    /* prompt for output node */
    printf("Enter output node: ");
    scanf("%d", &out_node);
    
    /* simulate circuit */
    simulate();
    
    return 0;
}