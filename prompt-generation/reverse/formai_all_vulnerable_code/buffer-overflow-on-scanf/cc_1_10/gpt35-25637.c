//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[20];
  int age;
  srand(time(NULL));
  int luck_num = rand() % 100 + 1;
  int health_num = rand() % 100 + 1;
  int wealth_num = rand() % 100 + 1;

  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Please enter your name: ");
  scanf("%s", &name);
  printf("Hello %s, please enter your age: ", name);
  scanf("%d", &age);

  if (age < 18) {
    printf("I'm sorry, you must be 18 or older to use the Automated Fortune Teller.\n");
    return 0;
  }

  printf("\nCalculating your fortune...\n");

  printf("\n-----Lucky Number-----\n");
  if (luck_num < 50) {
    printf("Your lucky number is %d. It looks like luck may not be on your side today.\n", luck_num);
  } else {
    printf("Your lucky number is %d. Looks like today might be your lucky day!\n", luck_num);
  }

  printf("\n-----Health-----\n");
  if (health_num < 25) {
    printf("Your health rating is %d. You might want to take extra precautions today.\n", health_num);
  } else if (health_num < 75) {
    printf("Your health rating is %d. Looks like you're doing alright today!\n", health_num);
  } else {
    printf("Your health rating is %d. Keep up the good work!\n", health_num);
  }

  printf("\n-----Wealth-----\n");
  if (wealth_num < 25) {
    printf("Your wealth rating is %d. You might want to watch your spending today.\n", wealth_num);
  } else if (wealth_num < 75) {
    printf("Your wealth rating is %d. It looks like you're in a good financial state today!\n", wealth_num);
  } else {
    printf("Your wealth rating is %d. Looks like you're on your way to financial success!\n", wealth_num);
  }

  printf("\nThank you for using the Automated Fortune Teller. Good luck!\n");

  return 0;
}