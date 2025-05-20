//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, answer;
  srand(time(0)); // seed for random number generator
  
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Think of a number from 1-10 and I will guess what it is.\n");
  
  // loop until correct answer is guessed
  while (1) {
    num = rand() % 10 + 1; // generate random guess
    printf("Is your number %d? (0 for no, 1 for yes): ", num);
    scanf("%d", &answer);
    if (answer == 1) {
      printf("I have correctly guessed your number!\n");
      break;
    }
    else {
      printf("Hmm, okay. Let me guess again...\n");
    }
  }
  
  // generate fortune based on number guessed
  switch(num) {
    case 1:
      printf("Your future looks bright.\n");
      break;
    case 2:
      printf("You will have a surprise visit from an old friend.\n");
      break;
    case 3:
      printf("Your hard work will pay off.\n");
      break;
    case 4:
      printf("Be prepared for a challenge, but you will come out stronger.\n");
      break;
    case 5:
      printf("A new opportunity is on the horizon.\n");
      break;
    case 6:
      printf("Your health is important, make sure to prioritize it.\n");
      break;
    case 7:
      printf("Your creativity will be valued and recognized.\n");
      break;
    case 8:
      printf("Taking a risk will lead to success.\n");
      break;
    case 9:
      printf("You will meet someone who will have a significant impact on your life.\n");
      break;
    case 10:
      printf("You will receive unexpected news, but it will ultimately benefit you.\n");
      break;
    default:
      printf("I'm sorry, I couldn't generate a fortune for you.\n");
      break;
  }
  
  return 0;
}