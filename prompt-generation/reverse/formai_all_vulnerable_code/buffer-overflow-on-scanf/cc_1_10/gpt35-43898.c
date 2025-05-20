//FormAI DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>

int main() {

  int i;
  char name[20];
  
  printf("Welcome to Funny C Programming!\n");
  printf("What is your name? ");
  scanf("%s", name);
  
  printf("Hello, %s! Let's have some fun with C programming!\n", name);
  
  printf("=============================\n");
  printf("Let's count to 10 together!\n");
  
  for (i = 1; i <= 10; i++) {
    printf("%d\n", i);
  }
  
  printf("=============================\n");
  printf("Now let's print out your name backwards!\n");
  
  for (i = 19; i >= 0; i--) {
    if (name[i] != '\0') {
      printf("%c", name[i]);
    }
  }
  
  printf("\n");
  printf("=============================\n");
  printf("Okay, now it's time for some math!\n");
  
  int num1, num2;
  printf("Enter a number: ");
  scanf("%d", &num1);
  printf("Enter another number: ");
  scanf("%d", &num2);
  
  printf("%d + %d = %d\n", num1, num2, num1+num2);
  printf("%d - %d = %d\n", num1, num2, num1-num2);
  printf("%d * %d = %d\n", num1, num2, num1*num2);
  
  if (num2 == 0) {
    printf("Cannot divide by zero!\n");
  } else {
    printf("%d / %d = %.2f\n", num1, num2, (float)num1/num2);
  }
  
  printf("=============================\n");
  printf("Now, let's have some fun with arrays!\n");
  
  int my_arr[5] = {10, 20, 30, 40, 50};
  
  printf("The elements of the array are:\n");
  
  for (i = 0; i < 5; i++) {
    printf("%d\n", my_arr[i]);
  }
  
  printf("=============================\n");
  printf("Okay, that's enough fun for now. Bye %s, see you next time!\n", name);
  
  return 0;
}