//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Baggage {
  char owner[20];
  int flight_num;
  bool is_checked;
};

int main() {
  printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

  // Initializing random seed for random flight number generation
  srand(time(0));

  int num_bags;
  printf("Enter the number of bags to process: ");
  scanf("%d", &num_bags);
  
  struct Baggage *bags = malloc(num_bags * sizeof(struct Baggage));

  // Input
  for (int i = 0; i < num_bags; i++) {
    printf("\nEnter details for Bag #%d:\n", i+1);
    printf("Owner Name: ");
    scanf("%s", bags[i].owner);
    bags[i].is_checked = false;
    bags[i].flight_num = rand() % 1000 + 1; // Random flight number between 1 and 1000
  }

  printf("\nAll bags have been registered for check-in.\n\n");
  printf("Starting the baggage handling process...\n\n");

  // Baggage Handling
  for (int i = 0; i < num_bags; i++) {
    printf("Processing Bag #%d...\n", i+1);
    printf("Owner Name: %s\n", bags[i].owner);
    printf("Flight Number: %d\n", bags[i].flight_num);

    if (bags[i].is_checked) {
      printf("Baggage is already checked in.\n");
    }
    else {
      printf("Checking in baggage for flight %d...\n", bags[i].flight_num);
      bags[i].is_checked = true;
    }

    printf("\n");
  }

  printf("All bags have been successfully checked in!\n");

  free(bags);

  return 0;
}