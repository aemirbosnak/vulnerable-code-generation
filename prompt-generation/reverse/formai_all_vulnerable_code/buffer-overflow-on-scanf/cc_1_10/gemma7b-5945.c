//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void baggage_handling(void)
{
  // Declare variables
  int baggage_count = 0;
  char baggage_type[20];
  int baggage_weight = 0;
  char passenger_name[50];

  // Get passenger name and baggage information
  printf("Enter your name: ");
  scanf("%s", passenger_name);

  printf("Enter the number of bags you have: ");
  scanf("%d", &baggage_count);

  printf("Enter the type of baggage (e.g. checked, hand, carry-on): ");
  scanf("%s", baggage_type);

  printf("Enter the weight of each bag (in kilograms): ");
  scanf("%d", &baggage_weight);

  // Calculate total baggage weight
  int total_baggage_weight = baggage_count * baggage_weight;

  // Display baggage information
  printf("\n**Passenger Name:** %s\n", passenger_name);
  printf("**Number of Bags:** %d\n", baggage_count);
  printf("**Baggage Type:** %s\n", baggage_type);
  printf("**Total Baggage Weight:** %d kilograms\n", total_baggage_weight);

  // Check if baggage weight exceeds limit
  if (total_baggage_weight > 20)
  {
    printf("Sorry, your baggage weight exceeds the limit of 20 kilograms. Please reduce the number of bags you are bringing or repackage your items.\n");
  }
  else
  {
    printf("Your baggage is within the limit. Please proceed to the baggage claim area.\n");
  }
}

int main()
{
  baggage_handling();

  return 0;
}