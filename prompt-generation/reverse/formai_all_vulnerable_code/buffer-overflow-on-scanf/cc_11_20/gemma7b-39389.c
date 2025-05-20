//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
  char letter, guess_letter;
  int i, j, k;
  time_t t;

  t = time(NULL);
  srand(t);

  num1 = rand() % 11;
  num2 = rand() % 11;
  num3 = rand() % 11;
  num4 = rand() % 11;
  num5 = rand() % 11;
  num6 = rand() % 11;
  num7 = rand() % 11;
  num8 = rand() % 11;
  num9 = rand() % 11;
  num10 = rand() % 11;

  printf("Welcome to the Crystal Ball!\n");
  printf("Please guess a letter:");
  scanf("%c", &guess_letter);

  for (i = 0; i < 10; i++) {
    if (guess_letter == num1) {
      printf("Your destiny is intertwined with the number %d.\n", num1);
    } else if (guess_letter == num2) {
      printf("The number %d holds secrets that you must uncover.\n", num2);
    } else if (guess_letter == num3) {
      printf("The number %d is guiding you towards a path of wealth.\n", num3);
    } else if (guess_letter == num4) {
      printf("Beware of the number %d, it may bring you misfortune.\n", num4);
    } else if (guess_letter == num5) {
      printf("The number %d is a symbol of love and friendship.\n", num5);
    } else if (guess_letter == num6) {
      printf("The number %d is your guardian angel.\n", num6);
    } else if (guess_letter == num7) {
      printf("The number %d is a harbinger of change.\n", num7);
    } else if (guess_letter == num8) {
      printf("The number %d is a catalyst for growth.\n", num8);
    } else if (guess_letter == num9) {
      printf("The number %d is a reminder to stay positive.\n", num9);
    } else if (guess_letter == num10) {
      printf("The number %d is your lucky number.\n", num10);
    }
  }

  return 0;
}