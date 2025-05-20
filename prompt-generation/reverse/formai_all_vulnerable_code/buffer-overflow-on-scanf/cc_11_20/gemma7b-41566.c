//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char name[20];
  char sign[20];
  int num1;
  int num2;

  printf("Welcome to the Crystal Ball, Mr. Holmes!\n");
  printf("Please provide your name: ");
  scanf("%s", name);

  printf("Excellent, %s. Now tell me your sign: ", name);
  scanf("%s", sign);

  printf("Very well, %s. Now give me two numbers: ", name);
  scanf("%d %d", &num1, &num2);

  int fortune = 0;

  if (strcmp(sign, "Aries") == 0) {
    fortune = num1 + num2 - 13;
  } else if (strcmp(sign, "Taurus") == 0) {
    fortune = num1 + num2 * 2;
  } else if (strcmp(sign, "Gemini") == 0) {
    fortune = num1 - num2 / 2;
  } else if (strcmp(sign, "Cancer") == 0) {
    fortune = num1 * num2 + 11;
  } else if (strcmp(sign, "Leo") == 0) {
    fortune = num1 - num2 * 2;
  } else if (strcmp(sign, "Virgo") == 0) {
    fortune = num1 + num2 / 2;
  } else if (strcmp(sign, "Libra") == 0) {
    fortune = num1 * num2 - 13;
  } else if (strcmp(sign, "Scorpio") == 0) {
    fortune = num1 + num2 * 2;
  } else if (strcmp(sign, "Sagittarius") == 0) {
    fortune = num1 - num2 / 2;
  } else if (strcmp(sign, "Capricorn") == 0) {
    fortune = num1 * num2 + 11;
  } else if (strcmp(sign, "Aquarius") == 0) {
    fortune = num1 + num2 / 2;
  } else if (strcmp(sign, "Pisces") == 0) {
    fortune = num1 - num2 * 2;
  }

  printf("Your fortune, %s, is: ", name);
  printf("%d\n", fortune);

  return 0;
}