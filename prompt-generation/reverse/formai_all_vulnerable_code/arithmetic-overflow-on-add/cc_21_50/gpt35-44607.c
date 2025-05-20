//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[20];
  int age, lucky_num, years_to_live;

  printf("Hello! What is your name?\n");
  scanf("%s", name);

  printf("Nice to meet you, %s! What is your age?\n", name);
  scanf("%d", &age);

  printf("Great! What is your lucky number?\n");
  scanf("%d", &lucky_num);

  srand(time(0));
  int random_num = rand() % 100 + 1;
  printf("The random number is %d.\n", random_num);

  int sum = age + lucky_num + random_num;
  printf("The sum is %d.\n", sum);

  years_to_live = sum % 20;
  printf("You will live for %d years.\n", years_to_live);

  switch (years_to_live) {
    case 0:
      printf("Sorry, you will not live long.\n");
      break;
    case 1:
    case 2:
    case 3:
    case 4:
      printf("You will live a short life.\n");
      break;
    case 5:
    case 6:
    case 7:
      printf("You will live a normal life.\n");
      break;
    case 8:
    case 9:
      printf("You will live a long life.\n");
      break;
    case 10:
    case 11:
    case 12:
      printf("You will live a very long life.\n");
      break;
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
      printf("You will live an incredibly long life!\n");
      break;
  }

  return 0;
}