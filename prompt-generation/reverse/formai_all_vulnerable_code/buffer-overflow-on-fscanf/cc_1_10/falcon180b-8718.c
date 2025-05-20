//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char name[2];
  char symbol;
  int atomic_number;
  int atomic_weight;
} element;

void load_elements(element *table, int size) {
  int i = 0;
  FILE *fp = fopen("elements.txt", "r");
  
  if (fp == NULL) {
    printf("Error loading elements.\n");
    exit(1);
  }
  
  while (fscanf(fp, "%s%c%d%d", table[i].name, &table[i].symbol, &table[i].atomic_number, &table[i].atomic_weight) == 4 && i < size) {
    i++;
  }
  
  fclose(fp);
}

int main() {
  int score = 0;
  int size = 118;
  element table[size];
  char input[10];
  
  load_elements(table, size);
  
  printf("Welcome to the Periodic Table Quiz!\n");
  printf("There are %d elements in the table.\n", size);
  
  while (1) {
    printf("Enter an element or type 'quit' to exit: ");
    scanf("%s", input);
    
    if (strcmp(input, "quit") == 0) {
      break;
    }
    
    int found = 0;
    for (int i = 0; i < size; i++) {
      if (strcmp(table[i].name, input) == 0 || strcmp(table[i].symbol, input) == 0) {
        printf("Element found: %s (%c)\n", table[i].name, table[i].symbol);
        printf("Atomic number: %d\n", table[i].atomic_number);
        printf("Atomic weight: %d\n", table[i].atomic_weight);
        score++;
        found = 1;
        break;
      }
    }
    
    if (!found) {
      printf("Element not found.\n");
    }
  }
  
  printf("You scored %d out of %d.\n", score, size);
  
  return 0;
}