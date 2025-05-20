//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 1000
#define MAX_CONVEYOR 50

// define variables
int baggageCount = 0;
int conveyorCount = 0;
int baggage[MAX_BAGGAGE];
int conveyor[MAX_CONVEYOR];

// surreal program starts here
int main() {
  printf("Welcome to the Surrealist Baggage Handling Simulation!\n");

  // create a loop to handle baggage
  while(1) {
    printf("\nDo you have a suitcase to add? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y') {
      if(conveyorCount >= MAX_CONVEYOR) {
        printf("Sorry, our conveyer belt is full.\n"); 
      } else {
        printf("Please add your suitcase to the conveyer.\n");
        int suitcase;
        scanf("%d", &suitcase);
        conveyor[conveyorCount++] = suitcase;
      }
    } else if(answer == 'n' || answer == 'N') {
      printf("Great, let's process our suitcases.\n");
      break;
    } else {
      printf("I'm sorry, I don't understand.\n");
    }
  }

  // process baggage on conveyer belt
  while(conveyorCount > 0) {
    int suitcase = conveyor[--conveyorCount];
    printf("Processing suitcase %d...\n", suitcase);
    int destination = (suitcase % 6) + 1; // generate random destination
    printf("Sending suitcase %d to Terminal %d.\n", suitcase, destination);
    baggage[baggageCount++] = suitcase;
  }

  // print processed baggages
  printf("\nHere are the processed baggages:\n");
  for(int i=0; i<baggageCount; i++) {
    printf("Suitcase %d\n", baggage[i]);
  }

  // end program
  printf("\nThank you for using the Surrealist Baggage Handling Simulation!\n");
  return 0;
}