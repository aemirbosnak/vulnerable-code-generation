//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <string.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 1000
#define MAX_ITERATIONS 1000

int numVertices;
int numColors;
int numIterations;

int vertexList[MAX_VERTICES];
int colorList[MAX_VERTICES];
int numColorsUsed;

void readInput(void) {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    printf("Enter the number of iterations: ");
    scanf("%d", &numIterations);
    for (int i = 0; i < numVertices; i++) {
        vertexList[i] = i;
    }
}

int isValid(int color) {
    for (int i = 0; i < numVertices; i++) {
        if (colorList[i] == color) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(int color) {
    colorList[vertexList[0]] = color;
    numColorsUsed++;
    for (int i = 1; i < numVertices; i++) {
        int vertex = vertexList[i];
        int j = 0;
        while (!isValid(j)) {
            j++;
        }
        colorList[vertex] = j;
        numColorsUsed++;
    }
}

void printSolution(void) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", vertexList[i], colorList[i]);
    }
}

int main(void) {
    srand(time(NULL));
    readInput();
    int numConflicts = 0;
    while (numColorsUsed < numColors) {
        int color = rand() % numColors;
        while (!isValid(color)) {
            color = rand() % numColors;
        }
        colorGraph(color);
        numColorsUsed++;
        numConflicts = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                if (colorList[i] == colorList[j]) {
                    numConflicts++;
                    break;
                }
            }
        }
        if (numConflicts == 0) {
            break;
        }
    }
    printf("The number of colors used is %d\n", numColorsUsed);
    printf("The number of conflicts is %d\n", numConflicts);
    printSolution();
    return 0;
}