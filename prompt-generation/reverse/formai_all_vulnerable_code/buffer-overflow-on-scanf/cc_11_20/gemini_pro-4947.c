//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int choice;
  printf("Welcome to the Surrealist Fortune Teller!\n");
  printf("Would you like to hear your fortune?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  scanf("%d", &choice);
  if (choice == 1) {
    int fortune = rand() % 10;
    switch (fortune) {
      case 0:
        printf("You will find a lost key that will unlock a hidden treasure.\n");
        break;
      case 1:
        printf("You will meet a stranger who will become a lifelong friend.\n");
        break;
      case 2:
        printf("You will have a dream that will come true.\n");
        break;
      case 3:
        printf("You will find a new love that will make you feel complete.\n");
        break;
      case 4:
        printf("You will have a great success in your career.\n");
        break;
      case 5:
        printf("You will travel to a faraway land that will change your life.\n");
        break;
      case 6:
        printf("You will discover a new talent that will make you famous.\n");
        break;
      case 7:
        printf("You will win a lottery that will make you rich.\n");
        break;
      case 8:
        printf("You will find a cure for a disease that has plagued humanity for centuries.\n");
        break;
      case 9:
        printf("You will become the leader of a great nation.\n");
        break;
    }
  } else if (choice == 2) {
    printf("Thank you for visiting the Surrealist Fortune Teller!\n");
  } else {
    printf("Invalid choice.\n");
  }
  return 0;
}