//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  printf("Welcome to the Crystal Ball!\n");
  printf("Please provide me with your name: ");
  char name[20];
  scanf("%s", name);
  printf("Please tell me your question: ");
  char question[100];
  scanf("%s", question);
  srand(time(NULL));
  int number = rand() % 10;
  switch (number) {
    case 0:
      printf("The stars align in your favor, %s. You will have a lucky day.", name);
      break;
    case 1:
      printf("A journey awaits you, %s. Prepare for a new adventure.", name);
      break;
    case 2:
      printf("Beware of hidden dangers, %s. Be cautious.", name);
      break;
    case 3:
      printf("Love is in the air, %s. Prepare for a romantic encounter.", name);
      break;
    case 4:
      printf("Your intuition is strong, %s. Trust your instincts.", name);
      break;
    case 5:
      printf("A new opportunity presents itself, %s. Seize the day.", name);
      break;
    case 6:
      printf("Good luck, %s. May fortune favor you.", name);
      break;
    case 7:
      printf("A guardian angel is watching over you, %s. You are safe.", name);
      break;
    case 8:
      printf("A hidden treasure awaits you, %s. Seek it out.", name);
      break;
    case 9:
      printf("A new chapter begins, %s. Embrace the future.", name);
      break;
  }
  printf("\nThank you for visiting the Crystal Ball, %s. May your future be bright.", name);
  system("pause");
  return 0;
}