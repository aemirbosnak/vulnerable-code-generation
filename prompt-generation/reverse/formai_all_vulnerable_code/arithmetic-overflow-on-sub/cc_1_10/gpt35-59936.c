//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 20

void delay(int milliseconds) {
  usleep(milliseconds * 1000);
}

int main() {
  int current = 1;
  int last = 1;
  int temp;
  int x = 0;
  int y = 0;
  time_t start_time = time(NULL);

  /* Initialize the console to display the sequence */
  printf("\033[2J");
  printf("\033[%d;%dH", 1, 1);
  printf("Fibonacci Sequence Visualizer\n");
  printf("-----------------------------\n");

  while (1) {
    /* Print the current number */
    printf("%d\n", current);

    /* Calculate the next number in the sequence */
    temp = current;
    current += last;
    last = temp;

    /* Update the display */
    printf("\033[%d;%dH", y + 3, x + 1);
    printf("%d", current);
    fflush(stdout);

    /* Wait for a moment before calculating the next number */
    delay(100);

    /* Shift the display to the right */
    x += 1;

    /* Check if the display has moved out of bounds */
    if (x >= WIDTH) {
      /* Move to the next row */
      x = 0;
      y += 1;

      /* Check if the display has moved off of the screen */
      if (y >= HEIGHT) {
        /* Clear the console and reset the display */
        printf("\033[2J");
        printf("\033[%d;%dH", 1, 1);
        printf("Fibonacci Sequence Visualizer\n");
        printf("-----------------------------\n");

        /* Reset the cursor position */
        x = 0;
        y = 0;
      }
    }

    /* Check if the program has been running for over 5 minutes */
    if (time(NULL) - start_time >= 300) {
      /* Clear the console and exit the program */
      printf("\033[2J");
      printf("\033[%d;%dH", 1, 1);
      printf("Exiting Fibonacci Sequence Visualizer...\n");
      exit(0);
    }
  }

  return 0;
}