//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_LINES 500

struct Line {
    int from, to;
    float resistance;
};

float parallel(float a, float b) {
    return (a * b) / (a + b);
}

float series(float a, float b) {
    return a + b;
}

int main() {
    int numNodes, numLines;
    float resistance[MAX_NODES] = {0};
    struct Line lines[MAX_LINES];

    //Get input from user
    printf("Enter number of nodes (up to %d): ", MAX_NODES);
    scanf("%d", &numNodes);

    printf("Enter number of lines (up to %d): ", MAX_LINES);
    scanf("%d", &numLines);

    //Fill lines array with data from user
    for (int i = 0; i < numLines; i++) {
        printf("Enter line %d information: \n", i+1);
        printf("  From node (1-%d): ", numNodes);
        scanf("%d", &lines[i].from);

        printf("  To node (1-%d): ", numNodes);
        scanf("%d", &lines[i].to);

        printf("  Resistance of line: ");
        scanf("%f", &lines[i].resistance);
    }

    //Calculate total resistance of circuit
    for (int i = 0; i < numLines; i++) {
        int from = lines[i].from, to = lines[i].to;
        float r = lines[i].resistance;

        resistance[from-1] = series(resistance[from-1], r);
        resistance[to-1] = series(resistance[to-1], r);
        resistance[from-1] = parallel(resistance[from-1], resistance[to-1]);
        resistance[to-1] = resistance[from-1];
    }

    //Output total resistance
    printf("Total resistance of circuit is: %f\n", resistance[0]);

    return 0;
}