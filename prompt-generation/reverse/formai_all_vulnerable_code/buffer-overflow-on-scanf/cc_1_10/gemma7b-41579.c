//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Dance of the Caffeinated Molecules
  system("clear");
  printf("Welcome to the Surrealist C Cafe!\n");
  printf("Please select an item from the menu:\n");
  printf("1. Liquid Dreamscape\n");
  printf("2. Caffeinated Cronies\n");
  printf("3. Bean-tastic Brew\n");
  printf("4. Sensory Sorbet\n");
  printf("Enter your choice: ");

  int choice = 0;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You have selected the Liquid Dreamscape, a concoction of swirling coffee and ethereal vapors.\n");
      break;
    case 2:
      printf("You have selected the Caffeinated Cronies, a brew steeped in strong coffee and adorned with mischievous gremlins.\n");
      break;
    case 3:
      printf("You have selected the Bean-tastic Brew, a potent elixir crafted from roasted beans and steeped in boiling water.\n");
      break;
    case 4:
      printf("You have selected the Sensory Sorbet, a refreshing beverage crafted with fresh fruit and bubbly bubbles.\n");
      break;
    default:
      printf("Invalid selection. Please try again.\n");
  }

  // The Caffeinated Muse
  printf("Would you like to add a side of muse with your drink? (Y/N): ");
  char answer = ' ';
  scanf(" %c ", &answer);

  if (answer == 'Y') {
    printf("You have chosen the Caffeinated Muse, a companion of exquisite beauty and profound wisdom.\n");
  }

  // The Caffeinated Oracle
  printf("Would you like to consult the Caffeinated Oracle? (Y/N): ");
  answer = ' ';
  scanf(" %c ", &answer);

  if (answer == 'Y') {
    printf("Please enter your question: ");
    char question[100] = "";
    scanf("%s", question);

    printf("The Caffeinated Oracle has spoken: %s\n", question);
  }

  // The Surrealist Receipt
  printf("Thank you for your visit to the Surrealist C Cafe. Please enjoy your beverage and muse.\n");
  printf("Your Total: $%f\n", 5.0);
  printf("We hope you have a surrealist good time.\n");

  return 0;
}