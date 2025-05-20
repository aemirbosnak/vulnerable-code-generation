//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Declare variables
  char name[100];
  int age;
  int luckyNumber;
  int randomNum;
  int fortuneNum;

  srand(time(NULL));

  // Get user input
  printf("Welcome to the Automated Fortune Teller. Please enter your name: ");
  scanf("%s", name);

  printf("Thank you, %s. Please enter your age: ", name);
  scanf("%d", &age);

  printf("Thank you, %s. Please enter your lucky number: ", name);
  scanf("%d", &luckyNumber);

  // Generate random number
  randomNum = rand() % 10 + 1;
  printf("\nRandom number generated: %d\n", randomNum);

  // Calculate fortune number
  fortuneNum = (age + luckyNumber) / randomNum;

  // Generate fortune
  switch (fortuneNum) {
    case 0:
      printf("\n%s, you are destined for greatness. Keep pushing towards your goals.\n", name);
      break;
    case 1:
      printf("\n%s, your future is bright. Keep a positive outlook and good things will come.\n", name);
      break;
    case 2:
      printf("\n%s, be cautious in the coming days. Look out for unexpected obstacles.\n", name);
      break;
    case 3:
      printf("\n%s, change is coming your way. Embrace it and be open to new opportunities.\n", name);
      break;
    case 4:
      printf("\n%s, be prepared for challenges ahead. Keep a level head and stay focused on your goals.\n", name);
      break;
    case 5:
      printf("\n%s, you have a strong support system. Lean on those around you for guidance and support.\n", name);
      break;
    case 6:
      printf("\n%s, you will face some difficulties in the near future. Stay strong and keep moving forward.\n", name);
      break;
    case 7:
      printf("\n%s, luck is on your side. Take advantage of opportunities that come your way.\n", name);
      break;
    case 8:
      printf("\n%s, expect the unexpected. Be prepared for anything that comes your way.\n", name);
      break;
    case 9:
      printf("\n%s, your hard work will pay off in the end. Keep pushing towards your goals.\n", name);
      break;
    default:
      printf("\n%s, something went wrong. Please try again later.\n", name);
  }

  return 0;
}