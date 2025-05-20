//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

void fibonacciSequence(int num) {
  int first = 0, second = 1, count = 0;

  printf("%d %d ", first, second);

  count += 2;

  while(count < num) {
    int next = first + second;
    first = second;
    second = next;

    printf("%d ", next);
    count++;
  }
}

void drawLine(int length) {
  for(int i = 0; i < length; i++) {
    printf("-");
  }
  printf("\n");
}

void drawFibonacciVisualizer(int num) {
  int first = 0, second = 1, count = 0;

  drawLine(20);

  printf("| %6d |\n", first);

  count++;

  if(num > 1) {
    drawLine(20);

    printf("| %6d |\n", second);

    count++;
  }

  while(count < num) {
    int next = first + second;
    first = second;
    second = next;

    drawLine(20);

    printf("| %6d |\n", next);
    count++;
  }

  drawLine(20);
}

int main() {
  int num;

  printf("Enter the number of Fibonacci numbers to display: ");
  scanf("%d", &num);

  if(num == 0) {
    printf("Cannot display 0 Fibonacci numbers.\n");
    return 0;
  }

  printf("The first %d Fibonacci numbers are:\n", num);
  fibonacciSequence(num);

  printf("\n\n");

  drawFibonacciVisualizer(num);

  return 0;
}