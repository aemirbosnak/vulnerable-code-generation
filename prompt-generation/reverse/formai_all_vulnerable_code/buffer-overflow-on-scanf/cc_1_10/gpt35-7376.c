//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[50];
  int age;
  int luckyNum;
  char fortune[100];
  
  printf("Welcome to the Automated Fortune Teller!\n");
  
  printf("Please enter your name: ");
  scanf("%s", name);
  
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  printf("Please enter your lucky number: ");
  scanf("%d", &luckyNum);
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Determine the fortune based on lucky number
  switch (luckyNum) {
    case 1:
      sprintf(fortune, "%s, you will have great success in your career!", name);
      break;
    case 2:
      sprintf(fortune, "%s, you will find love in the near future!", name);
      break;
    case 3:
      sprintf(fortune, "%s, you will embark on a great adventure!", name);
      break;
    case 4:
      sprintf(fortune, "%s, you will experience a great loss, but find strength in the aftermath.", name);
      break;
    case 5:
      sprintf(fortune, "%s, you will make a life-changing decision in the coming weeks.", name);
      break;
    case 6:
      sprintf(fortune, "%s, you will receive unexpected good news!", name);
      break;
    case 7:
      sprintf(fortune, "%s, you will be visited by an old friend.", name);
      break;
    case 8:
      sprintf(fortune, "%s, you will receive a sign urging you to take a new path in life.", name);
      break;
    case 9:
      sprintf(fortune, "%s, your perseverance will pay off in a big way.", name);
      break;
    default:
      sprintf(fortune, "%s, your lucky number is not so lucky. Try again with a different one.", name);
      break;
  }
  
  printf("%s\n", fortune);
  
  return 0;

}