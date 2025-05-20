//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void handle_baggage(int baggage_id)
{
  // Randomly assign a baggage weight
  int weight = rand() % 100 + 1;
  printf("Baggage ID: %d, Weight: %d kg\n", baggage_id, weight);

  // Check if the baggage is overweight
  if (weight > 20)
  {
    printf("Overweight baggage! Fee applicable.\n");
  }

  // Simulate baggage handling tasks
  printf("Baggage is being loaded onto the plane.\n");
  printf("Baggage is being secured in the cargo hold.\n");
  printf("Baggage is being retrieved from the cargo hold.\n");
}

int main()
{
  // Create a baggage handling system for a post-apocalyptic airport
  int baggage_id = 0;
  while (1)
  {
    // Get the baggage ID from the user or generate a new one
    printf("Enter baggage ID (or leave blank for a new one): ");
    char input[20];
    scanf("%s", input);

    // If the user entered a valid baggage ID, handle the baggage
    if (input[0] != '\0')
    {
      handle_baggage(atoi(input));
    }
    else
    {
      // Generate a new baggage ID and handle the baggage
      baggage_id++;
      handle_baggage(baggage_id);
    }

    // Ask the user if they want to continue
    printf("Do you want to continue? (Y/N): ");
    char answer;
    scanf("%c", &answer);

    // If the user does not want to continue, exit the system
    if (answer != 'Y')
    {
      break;
    }
  }

  return 0;
}