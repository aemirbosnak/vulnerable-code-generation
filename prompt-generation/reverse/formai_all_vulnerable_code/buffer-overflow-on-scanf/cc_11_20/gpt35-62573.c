//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  int answer;
  srand(time(0)); //Seed random number generator
  
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("----------------------------------------\n");
  printf("Think of a question and I will give you an answer.\n");
  printf("Enter any positive integer between 1-10 to proceed or 0 to exit: ");
  scanf("%d", &answer);
  
  while(answer != 0) {
    switch(rand() % 10 + 1) {
      case 1:
        printf("Yes.\n");
        break;
      case 2:
        printf("No.\n");
        break;
      case 3:
        printf("It is certain.\n");
        break;
      case 4:
        printf("Cannot predict now.\n");
        break;
      case 5:
        printf("Outlook not so good.\n");
        break;
      case 6:
        printf("Very doubtful.\n");
        break;
      case 7:
        printf("You may rely on it.\n");
        break;
      case 8:
        printf("Better not tell you now.\n");
        break;
      case 9:
        printf("My sources say no.\n");
        break;
      case 10:
        printf("Signs point to yes.\n");
        break;
    }
    
    printf("Enter another positive integer between 1-10 to ask another question or 0 to exit: ");
    scanf("%d", &answer);
    
  }
  
  printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
  
  return 0;
}