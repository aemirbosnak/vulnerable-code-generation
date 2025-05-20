//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  // Declare variables
  char baggage_tag[20];
  int baggage_weight;
  char baggage_owner_name[50];
  char baggage_destination[50];

  // Get baggage information
  printf("Enter baggage tag: ");
  scanf("%s", baggage_tag);

  printf("Enter baggage weight (in kg): ");
  scanf("%d", &baggage_weight);

  printf("Enter baggage owner's name: ");
  scanf("%s", baggage_owner_name);

  printf("Enter baggage destination: ");
  scanf("%s", baggage_destination);

  // Print baggage information
  printf("\nBaggage Tag: %s\n", baggage_tag);

  printf("Baggage Weight: %d kg\n", baggage_weight);

  printf("Baggage Owner's Name: %s\n", baggage_owner_name);

  printf("Baggage Destination: %s\n", baggage_destination);

  // Calculate baggage fees
  int fees = baggage_weight * 2;

  // Print baggage fees
  printf("\nTotal baggage fees: %d\n", fees);

  // Print baggage handling status
  printf("Baggage handling status: Checked in\n");

  // Generate baggage tag sticker
  printf("Baggage tag sticker generated!\n");

  // Print goodbye message
  printf("Thank you for using our baggage handling system. Have a safe flight!\n");

  return;
}