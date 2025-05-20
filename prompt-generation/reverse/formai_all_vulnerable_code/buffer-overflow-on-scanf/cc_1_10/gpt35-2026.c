//FormAI DATASET v1.0 Category: Educational ; Style: artistic
// The Artistic Fibonacci Series Program
// By Chatbot

#include <stdio.h>

int main() {
  int a = 0, b = 1, c, i, num;
  printf("Enter the number of terms: ");
  scanf("%d", &num);

  printf("The Fibonacci series of %d terms is:\n", num);

  // The Artistic part of the program
  printf("*");
  for(i=1; i<=num; i++){
    printf("    *");
  }
  printf("\n");

  // The Fibonacci series
  for(i=1; i<=num; i++) {
      printf("*  ");
      printf("%d", a);
      c = a + b;
      a = b;
      b = c;

      if(i==1) {
          printf(" ");
      } else if(i%3 == 0) {
          printf(" *  ");
      } else if(i%2 == 0){
          printf(" $ ");
      } else {
          printf(" _ ");
      }

      printf("  *");
      printf("\n");
  }

  // The Artistic part again
  printf("*");
  for(i=1; i<=num; i++){
    printf("    *");
  }
  printf("\n");

  return 0;
}