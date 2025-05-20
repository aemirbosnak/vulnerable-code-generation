//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

int graphColor[MAX];
int numberOfVertices, numberOfEdges;

int graph[MAX][MAX];
bool isSafe(int currentVertex, int currentColor) {
  for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {
    if (graph[currentVertex][vertexIndex] == 1 && currentColor == graphColor[vertexIndex])
      return false;
  }
  return true;
}

bool graphColoringAlgorithmHelper(int currentVertex, int numberOfColors) {
  if (currentVertex == numberOfVertices)
    return true;
  for (int colorIndex = 1; colorIndex <= numberOfColors; colorIndex++) {
    if (isSafe(currentVertex, colorIndex)) {
      graphColor[currentVertex] = colorIndex;
      if (graphColoringAlgorithmHelper(currentVertex + 1, numberOfColors) == true)
        return true;
      graphColor[currentVertex] = 0;
    }
  }
  return false;
}

bool graphColoringAlgorithm(int numberOfColors) {
  if (graphColoringAlgorithmHelper(0, numberOfColors) == false)
    return false;
  return true;
}

void printSolution() {
  printf("The color assigned to each vertex are:\n");
  for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++)
    printf("Vertex %d -> Color %d\n", vertexIndex, graphColor[vertexIndex]);
}

int main() {
  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &numberOfVertices);

  printf("Enter the number of edges in the graph: ");
  scanf("%d", &numberOfEdges);

  printf("Enter the edges in the graph: \n");
  for (int edgeIndex = 0; edgeIndex < numberOfEdges; edgeIndex++) {
    int firstVertex, secondVertex;
    scanf("%d%d", &firstVertex, &secondVertex);
    graph[firstVertex][secondVertex] = 1;
    graph[secondVertex][firstVertex] = 1;
  }

  printf("Enter the number of colors: ");
  int numberOfColors;
  scanf("%d", &numberOfColors);

  if (graphColoringAlgorithm(numberOfColors) == false)
    printf("Coloring not possible with %d colors\n", numberOfColors);
  else
    printSolution();

  return 0;
}