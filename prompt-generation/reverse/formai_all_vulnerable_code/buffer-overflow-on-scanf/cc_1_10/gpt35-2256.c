//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome to the Surreal Medical Store Management System!
  printf("██████╗ ██╗   ██╗███████╗████████╗ ██████╗ ██╗   ██╗\n");
  printf("██╔══██╗╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔═══██╗╚██╗ ██╔╝\n");
  printf("██████╔╝ ╚████╔╝ ███████╗   ██║   ██║   ██║ ╚████╔╝ \n");
  printf("██╔═══╝   ╚██╔╝  ╚════██║   ██║   ██║   ██║  ╚██╔╝  \n");
  printf("██║        ██║   ███████║   ██║   ╚██████╔╝   ██║   \n");
  printf("╚═╝        ╚═╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝   \n\n");

  // Let's start by declaring some variables
  char med_name[100];
  int med_quantity, choice;
  float med_price;

  // Seed the random number generator with the current time
  srand(time(0));

  // Display the menu
  printf("Select an option:\n");
  printf("1. Add medicine\n");
  printf("2. Remove medicine\n");
  printf("3. Check available medicines\n");
  scanf("%d", &choice);

  // Perform the selected action
  switch (choice) {
    case 1:
      // Ask the user for the medicine details
      printf("Enter medicine name: ");
      scanf("%s", med_name);
      printf("Enter medicine quantity: ");
      scanf("%d", &med_quantity);
      printf("Enter medicine price: ");
      scanf("%f", &med_price);

      // Add the medicine to the inventory
      printf("\nAdding %d units of %s to the inventory at $%.2f each...\n", med_quantity, med_name, med_price);
      printf("Done!\n");
      break;
    case 2:
      // Ask the user for the medicine details
      printf("Enter medicine name: ");
      scanf("%s", med_name);
      printf("Enter medicine quantity to remove: ");
      scanf("%d", &med_quantity);

      // Simulate the removal of the medicine from the inventory
      printf("\nRemoving %d units of %s from the inventory...\n", med_quantity, med_name);
      if (rand() % 2 == 0) {
        printf("Done!\n");
      } else {
        printf("Oops, something went wrong! Better luck next time.\n");
      }
      break;
    case 3:
      // Display the available medicines
      printf("\nHere is the list of available medicines:\n");
      printf("1. Paracetamol - $5.00 per unit\n");
      printf("2. Ibuprofen - $7.50 per unit\n");
      printf("3. Vitamin C - $10.00 per unit\n");
      printf("4. Aspirin - $8.50 per unit\n");
      printf("5. Diazepam - $15.00 per unit\n");
      break;
    default:
      // Inform the user of the invalid choice
      printf("\nInvalid choice, please try again.\n");
  }

  return 0;
}