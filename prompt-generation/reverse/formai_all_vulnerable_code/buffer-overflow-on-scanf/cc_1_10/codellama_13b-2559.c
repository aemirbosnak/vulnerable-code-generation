//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
// Airport Baggage Handling Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store baggage information
typedef struct baggage {
  char id[10];
  char owner[50];
  char destination[50];
  int weight;
} bag;

// Function to generate a unique ID
void generate_id(bag *b) {
  srand(time(NULL));
  int i;
  for (i = 0; i < 10; i++) {
    b->id[i] = (char)rand() % 26 + 'A';
  }
}

// Function to check if the baggage is lost
int is_lost(bag *b) {
  int chance = rand() % 100;
  return chance < 5;
}

// Function to check if the baggage is delayed
int is_delayed(bag *b) {
  int chance = rand() % 100;
  return chance < 10;
}

// Function to print baggage information
void print_bag(bag *b) {
  printf("Baggage ID: %s\n", b->id);
  printf("Owner: %s\n", b->owner);
  printf("Destination: %s\n", b->destination);
  printf("Weight: %d\n", b->weight);
}

// Main function
int main() {
  // Initialize variables
  bag b;
  int i, num_bags;
  printf("Enter the number of bags: ");
  scanf("%d", &num_bags);

  // Generate baggage information
  for (i = 0; i < num_bags; i++) {
    generate_id(&b);
    printf("Enter the owner's name: ");
    scanf("%s", b.owner);
    printf("Enter the destination: ");
    scanf("%s", b.destination);
    printf("Enter the weight: ");
    scanf("%d", &b.weight);
    print_bag(&b);
    if (is_lost(&b)) {
      printf("Baggage %s has been lost\n", b.id);
    } else if (is_delayed(&b)) {
      printf("Baggage %s has been delayed\n", b.id);
    } else {
      printf("Baggage %s has been delivered\n", b.id);
    }
  }

  return 0;
}