//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  int a, b, c, d;
  char op1, op2;
  float ans, user_ans;
  
  // generate 4 random integers between 0-9
  a = rand() % 10;
  b = rand() % 10;
  c = rand() % 10;
  d = rand() % 10;
  
  // generate 2 random operators from +,-,x,/
  int op1_index = rand() % 4;
  int op2_index = rand() % 4;
  
  if (op1_index == 0) {
    op1 = '+';
    ans = a + b;
  } else if (op1_index == 1) {
    op1 = '-';
    ans = a - b;
  } else if (op1_index == 2) {
    op1 = 'x';
    ans = a * b;
  } else {
    op1 = '/';
    ans = (float)a / (float)b;
  }
  
  if (op2_index == 0) {
    op2 = '+';
    ans += c;
  } else if (op2_index == 1) {
    op2 = '-';
    ans -= c;
  } else if (op2_index == 2) {
    op2 = 'x';
    ans *= c;
  } else {
    op2 = '/';
    ans /= (float)c;
  }
  
  printf("What is %d %c %d %c %d?\n", a, op1, b, op2, c);
  scanf("%f", &user_ans);
  
  if (abs(user_ans - ans) < 0.001) {
    printf("Correct, the answer is %.3f\n", ans);
  } else {
    printf("Incorrect, the answer is %.3f\n", ans);
  }
  
  return 0;
}