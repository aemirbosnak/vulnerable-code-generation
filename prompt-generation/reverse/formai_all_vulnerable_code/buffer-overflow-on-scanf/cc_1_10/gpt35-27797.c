//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random number between 0 and 9
int getRandomNumber(){
  srand(time(NULL));
  int r = rand() % 10;
  return r;
}

int main(){
  
  printf("***********WELCOME TO AUTOMATED FORTUNE TELLER***********\n");

  //Prompt user to ask a question
  char question[100];
  printf("\nAsk me a question, and I will provide you with an answer: ");
  scanf("%[^\n]", question);

  //Generate random number to determine fortune
  int fortune = getRandomNumber();

  //Print fortune based on random number
  switch(fortune){
    case 0:
      printf("\nAnswer is uncertain. Please ask again later.");
      break;
    case 1:
      printf("\nAll signs point to yes.");
      break;
    case 2:
      printf("\nDon't count on it.");
      break;
    case 3:
      printf("\nCannot predict now.");
      break;
    case 4:
      printf("\nMy sources say no.");
      break;
    case 5:
      printf("\nOutlook not so good.");
      break;
    case 6:
      printf("\nSigns point to a bright future.");
      break;
    case 7:
      printf("\nAsk again later.");
      break;
    case 8:
      printf("\nYes definitely.");
      break;
    case 9:
      printf("\nBetter not tell you now.");
      break;
    default:
      printf("\nSomething went wrong. Please try again.");
      break;
  }

  printf("\nThank you for using Automated Fortune Teller.\n");
  
  return 0;
}