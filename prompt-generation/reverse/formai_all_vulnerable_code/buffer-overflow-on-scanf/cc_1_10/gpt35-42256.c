//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // set up variables
  int a, b, c;
  srand(time(NULL));
  
  // generate two random numbers between 0 and 10
  a = rand() % 11;
  b = rand() % 11;
  
  // prompt user to multiply the two numbers
  printf("What is %d times %d? ", a, b);
  scanf("%d", &c);
  
  // check if the user's answer is correct
  if (c == a * b) {
    printf("Congratulations, you got it right!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", a*b);
  }
  
  // generate two more random numbers and ask user to subtract them
  a = rand() % 11;
  b = rand() % 11;
  
  printf("What is %d minus %d? ", a, b);
  scanf("%d", &c);
  
  if (c == a - b) {
    printf("Congratulations, you got it right!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", a-b);
  }
  
  // generate two more random numbers and ask user to add them
  a = rand() % 11;
  b = rand() % 11;
  
  printf("What is %d plus %d? ", a, b);
  scanf("%d", &c);
  
  if (c == a + b) {
    printf("Congratulations, you got it right!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", a+b);
  }
  
  // generate two more random numbers and ask user to divide them
  a = rand() % 11;
  b = rand() % 10 + 1; // make sure b is not 0
  
  printf("What is %d divided by %d (rounded down)? ", a, b);
  scanf("%d", &c);
  
  if (c == a / b) {
    printf("Congratulations, you got it right!\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", a/b);
  }
  
  return 0;
}