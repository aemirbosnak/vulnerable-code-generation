//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, choice;
  char name[20];

  printf("Welcome to the Whispering Oracle, %s.\n", name);
  printf("Please choose a number between 1 and 10:** ");
  scanf("%d", &num);

  switch (num) {
    case 1:
      printf("Your future is bright, my dear %s.\n", name);
      printf("You will find love and prosperity.\n");
      break;
    case 2:
      printf("Your path is filled with possibilities, %s.\n", name);
      printf("You have the power to change the world.\n");
      break;
    case 3:
      printf("Beware, %s, there is danger ahead.\n", name);
      printf("You may face challenges and obstacles.\n");
      break;
    case 4:
      printf("You have a guardian angel watching over you, %s.\n", name);
      printf("Expect miracles and blessings.\n");
      break;
    case 5:
      printf("Your creativity will soar, %s.\n", name);
      printf("You will find success in your chosen field.\n");
      break;
    case 6:
      printf("You have a strong connection to the spiritual realm, %s.\n", name);
      printf("You will find answers to your questions.\n");
      break;
    case 7:
      printf("Your intuition is strong, %s.\n", name);
      printf("You will be guided by your dreams.\n");
      break;
    case 8:
      printf("You have a gift for healing, %s.\n", name);
      printf("You will bring joy to others.\n");
      break;
    case 9:
      printf("You are a leader, %s.\n", name);
      printf("You will inspire others.\n");
      break;
    case 10:
      printf("May the stars shine upon you, %s.\n", name);
      printf("You have a bright future ahead.\n");
      break;
    default:
      printf("Invalid number, %s. Please try again.\n", name);
  }

  return 0;
}