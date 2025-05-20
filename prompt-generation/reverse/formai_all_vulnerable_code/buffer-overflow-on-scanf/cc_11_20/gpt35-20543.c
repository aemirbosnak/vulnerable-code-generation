//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seeding the random number generator
  srand(time(NULL));
  
  // Initializing variables
  char name[20];
  int age, luckyNum, randomNum, fortuneNum;
  
  // Asking for user's input
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  printf("Please enter your lucky number between 1 and 10: ");
  scanf("%d", &luckyNum);
  
  // Generating random number
  randomNum = rand() % 10 + 1;
  
  // Calculating fortune number
  fortuneNum = age * luckyNum * randomNum % 100;
  
  // Displaying fortune message
  printf("\nHello %s, your fortune for today is:\n", name);
  
  switch(fortuneNum) {
    case 0:
      printf("You will have a day full of surprises!\n");
      break;
    case 10:
      printf("A special someone will enter your life today.\n");
      break;
    case 20:
      printf("Your hard work will pay off soon.\n");
      break;
    case 30:
      printf("You will receive unexpected news that will change your life.\n");
      break;
    case 40:
      printf("You will travel to a distant land soon.\n");
      break;
    case 50:
      printf("A new career path is coming your way.\n");
      break;
    case 60:
      printf("Be cautious of someone close to you who might betray you.\n");
      break;
    case 70:
      printf("Great success will come to you in the near future.\n");
      break;
    case 80:
      printf("You will meet someone who will become very important to you.\n");
      break;
    case 90:
      printf("Your financial situation will drastically improve.\n");
      break;
    case 100:
      printf("Today is a lucky day for you!\n");
      break;
    default:
      printf("Something unexpected will happen today.\n");
  }
  
  return 0;
}