//FormAI DATASET v1.0 Category: Computer Biology ; Style: satisfied
#include <stdio.h>

int main() {
  // Declare variables
  int numGenes, numSamples;
  float geneExp[100][100];
  char geneNames[100][100], sampleNames[100][100];

  // Ask user for input
  printf("Enter the number of genes: ");
  scanf("%d", &numGenes);
  printf("Enter the number of samples: ");
  scanf("%d", &numSamples);

  // Get gene names
  printf("Enter gene names:\n");
  for (int i = 0; i < numGenes; i++) {
    scanf("%s", geneNames[i]);
  }

  // Get sample names
  printf("Enter sample names:\n");
  for (int i = 0; i < numSamples; i++) {
    scanf("%s", sampleNames[i]);
  }

  // Get gene expression values
  printf("Enter gene expression values:\n");
  for (int i = 0; i < numGenes; i++) {
    for (int j = 0; j < numSamples; j++) {
      scanf("%f", &geneExp[i][j]);
    }
  }

  // Print gene expression table
  printf("\nGene Expression Table:\n\n");
  printf("%-15s", "");
  for (int i = 0; i < numSamples; i++) {
    printf("%-15s", sampleNames[i]);
  }
  printf("\n");
  for (int i = 0; i < numGenes; i++) {
    printf("%-15s", geneNames[i]);
    for (int j = 0; j < numSamples; j++) {
      printf("%-15.2f", geneExp[i][j]);
    }
    printf("\n");
  }

  return 0;
}