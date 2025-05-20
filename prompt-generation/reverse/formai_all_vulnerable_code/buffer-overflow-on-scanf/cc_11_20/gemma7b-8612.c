//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void main() {
  system("cls");
  printf("Welcome to the Cozy Coffee Cafe!\n");
  printf("-----------------------\n");
  printf("Please select an item:\n");
  printf("1. Coffee\n");
  printf("2. Tea\n");
  printf("3. Juice\n");
  printf("4. Smoothie\n");
  printf("Please enter your selection:");

  int item_selection;
  scanf("%d", &item_selection);

  switch (item_selection) {
    case 1:
      printf("You selected Coffee.\n");
      printf("Please choose your preferred brewing method:\n");
      printf("1. Pour Over\n");
      printf("2. French Press\n");
      printf("Please enter your choice:");

      int brewing_method;
      scanf("%d", &brewing_method);

      switch (brewing_method) {
        case 1:
          printf("Your Coffee is being brewed using the Pour Over method.\n");
          break;
        case 2:
          printf("Your Coffee is being brewed using the French Press method.\n");
          break;
        default:
          printf("Invalid selection.\n");
          break;
      }
      break;
    case 2:
      printf("You selected Tea.\n");
      printf("Please choose your preferred tea type:\n");
      printf("1. Black Tea\n");
      printf("2. Green Tea\n");
      printf("Please enter your choice:");

      int tea_type;
      scanf("%d", &tea_type);

      switch (tea_type) {
        case 1:
          printf("Your Tea is being brewed using the Black Tea method.\n");
          break;
        case 2:
          printf("Your Tea is being brewed using the Green Tea method.\n");
          break;
        default:
          printf("Invalid selection.\n");
          break;
      }
      break;
    case 3:
      printf("You selected Juice.\n");
      printf("Please choose your preferred juice:\n");
      printf("1. Orange Juice\n");
      printf("2. Grape Juice\n");
      printf("Please enter your choice:");

      int juice_type;
      scanf("%d", &juice_type);

      switch (juice_type) {
        case 1:
          printf("Your Juice is being prepared using the Orange Juice method.\n");
          break;
        case 2:
          printf("Your Juice is being prepared using the Grape Juice method.\n");
          break;
        default:
          printf("Invalid selection.\n");
          break;
      }
      break;
    case 4:
      printf("You selected Smoothie.\n");
      printf("Please choose your preferred fruit:\n");
      printf("1. Banana\n");
      printf("2. Apple\n");
      printf("Please enter your choice:");

      int fruit_type;
      scanf("%d", &fruit_type);

      switch (fruit_type) {
        case 1:
          printf("Your Smoothie is being prepared using the Banana method.\n");
          break;
        case 2:
          printf("Your Smoothie is being prepared using the Apple method.\n");
          break;
        default:
          printf("Invalid selection.\n");
          break;
      }
      break;
    default:
      printf("Invalid selection.\n");
      break;
  }

  printf("Thank you for your order! Please wait for your drink.\n");
  system("pause");
}