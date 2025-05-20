//FormAI DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int a, b, c, result, answer, response;
  srand(time(NULL));

  printf("Welcome to the Math Game!\n");
  printf("You will be given a C Math equation to solve.\n");
  printf("Enter your answer and earn points!\n");
  printf("Press 0 to quit the game.\n");

  while(1){
    a = rand() % 11;
    b = rand() % 11;
    c = rand() % 11;

    switch(rand() % 3){
      case 0:
        result = a + b + c;
        printf("%d + %d + %d = ", a, b, c);
        break;
      case 1:
        result = a - b - c;
        printf("%d - %d - %d = ", a, b, c);
        break;
      case 2:
        result = a * b * c;
        printf("%d * %d * %d = ", a, b, c);
        break;
      default:
        break;
    }

    scanf("%d", &answer);

    if(answer == 0){
      printf("Thanks for playing!\n");
      break;
    }else if(answer == result){
      printf("Great job! You earned 10 points.\n");
    }else{
      printf("Incorrect! The correct answer is %d.\n", result);
    }

    printf("Do you want to continue? Press 1 to continue or any key to quit.\n");
    scanf("%d", &response);

    if(response != 1){
      printf("Thanks for playing!\n");
      break;
    }
  }

  return 0;
}