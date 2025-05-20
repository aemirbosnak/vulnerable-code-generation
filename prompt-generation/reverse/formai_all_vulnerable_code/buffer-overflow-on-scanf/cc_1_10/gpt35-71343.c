//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_bags;
  int flights_handled;
  int total_bags_handled = 0;
  int bags_accepted = 0;
  int bags_rejected = 0;
  int bags_waiting = 0;
  int time_to_handle_bag = 2;

  printf("Welcome to the Airport Baggage Handling Simulation!\n");
  printf("Please enter the number of bags: ");
  scanf("%d", &num_bags);
  printf("Please enter the number of flights to handle: ");
  scanf("%d", &flights_handled);

  srand(time(NULL)); // seed for rand()

  for(int i = 0; i < flights_handled; i++) {
    printf("\nHandling Flight %d...\n", i+1);

    for(int j = 0; j < num_bags; j++) {
      int rand_num = rand() % 100 + 1; // random number from 1 to 100

      if(rand_num <= 75) { // accept bag
        printf("Bag %d accepted!\n", j+1);
        bags_accepted++;
        bags_waiting++;
        total_bags_handled++;
      } else { // reject bag
        printf("Bag %d rejected\n", j+1);
        bags_rejected++;
        total_bags_handled++;
      }
    }

    // handle bags
    printf("Handling Bags...\n");
    while(bags_waiting > 0) {
      printf("%d bag(s) remaining...\n", bags_waiting);
      for(int k = 0; k < time_to_handle_bag; k++) {
        printf(". ");
        // simulate delay
        for(int l = 0; l < 1000000000; l++);
      }
      printf("\n%d bag(s) handled!\n", bags_waiting);
      bags_waiting--;
    }

    printf("Flight %d handled!\n", i+1);
  }

  // print final statistics
  printf("\nSimulation Complete!\n");
  printf("Total Bags Accepted: %d\n", bags_accepted);
  printf("Total Bags Rejected: %d\n", bags_rejected);
  printf("Total Bags Handled: %d\n", total_bags_handled);

  return 0;
}