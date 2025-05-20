//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char romeo_genome[100], juliet_genome[100];
  srand(time(NULL));
  
  // Romeo's genome sequence
  printf("Enter Romeo's genome sequence: ");
  scanf("%s", romeo_genome);
  
  // Juliet's genome sequence
  printf("Enter Juliet's genome sequence: ");
  scanf("%s", juliet_genome);
  
  // Convert to uppercase for proper comparison
  for(int i=0; romeo_genome[i]!='\0'; i++) {
    if(romeo_genome[i] >= 'a' && romeo_genome[i] <= 'z') {
      romeo_genome[i] -= 32;
    }
  }
  
  for(int i=0; juliet_genome[i]!='\0'; i++) {
    if(juliet_genome[i] >= 'a' && juliet_genome[i] <= 'z') {
      juliet_genome[i] -= 32;
    }
  }
  
  // Compare genome sequences
  int common_genes = 0;
  
  for(int i=0; romeo_genome[i]!='\0'; i++) {
    if(romeo_genome[i] == juliet_genome[i]) {
      common_genes++;
    } else {
      int pick = rand() % 2;
      if(pick == 0) {
        romeo_genome[i] = juliet_genome[i];
      } else {
        juliet_genome[i] = romeo_genome[i];
      }
    }
  }
  
  // Display result
  printf("\nAfter genome sequencing:\n");
  printf("Romeo's genome sequence: %s\n", romeo_genome);
  printf("Juliet's genome sequence: %s\n", juliet_genome);
  printf("Number of common genes: %d\n", common_genes);

  return 0;
}