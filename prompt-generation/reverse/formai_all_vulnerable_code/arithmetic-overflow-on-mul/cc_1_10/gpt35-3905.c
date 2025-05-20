//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  int num, den, gcf, lcm;
  char op;

  printf("Welcome to the Most Insane Math Quiz!\n");
  printf("-------------------------------\n");
  printf("Aim high and don't forget your math formulas, the first question is:\n");

  //generate random numbers between 1 and 100
  srand(time(0));
  num = rand() % 100 + 1;
  den = rand() % 100 + 1;

  //reduce numerator and denominator by their greatest common factor
  gcf = gcd(num, den);
  num /= gcf;
  den /= gcf;

  //ask user to input operation: add or subtract
  printf("%d / %d ", num, den);
  printf("[+ or -]: ");
  scanf(" %c", &op);

  if(op == '+') {
    printf("Good choice! Here's the next question:\n");
    //generate new random numbers and add them to previous result
    num = rand() % 100 + 1;
    den = rand() % 100 + 1;
    gcf = gcd(num, den);
    num /= gcf;
    den /= gcf;
    printf("%d / %d + %d / %d ", num, den, num, den);
    printf("[=]: ");
    scanf("%d / %d", &num, &den);
    //reduce numerator and denominator by their greatest common factor
    gcf = gcd(num, den);
    num /= gcf;
    den /= gcf;
    //calculate lowest common multiple and print result
    lcm = (den * (den / gcf)) / (den / gcf);
    printf("Amazing! Your result is: %d / %d\n", (num * (lcm / den)) + (num * (lcm / den)), lcm);
  }
  else if(op == '-') {
    printf("Interesting! Here's the next question:\n");
    //generate new random numbers and subtract them from previous result
    num = rand() % 100 + 1;
    den = rand() % 100 + 1;
    gcf = gcd(num, den);
    num /= gcf;
    den /= gcf;
    printf("%d / %d - %d / %d ", num, den, num, den);
    printf("[=]: ");
    scanf("%d / %d", &num, &den);
    //reduce numerator and denominator by their greatest common factor
    gcf = gcd(num, den);
    num /= gcf;
    den /= gcf;
    //calculate lowest common multiple and print result
    lcm = (den * (den / gcf)) / (den / gcf);
    printf("Mind-blowing! Your result is: %d / %d\n", (num * (lcm / den)) - (num * (lcm / den)), lcm);
  }
  else {
    printf("What?! Invalid input?! You didn't follow instructions!\n");
  }

  printf("-------------------------------\n");
  printf("Thanks for playing!\n");

  return 0;
}

int gcd(int a, int b) {
  if(a == 0) {
    return b;
  }
  else {
    return gcd(b % a, a);
  }
}