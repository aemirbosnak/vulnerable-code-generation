//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 10

int canvas[HEIGHT][WIDTH];

void initCanvas() {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      canvas[i][j] = 0;
    }
  }
}

void userInput() {
  int i, j;
  char input;
  
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("Enter color for pixel (%d,%d): ", i, j);
      scanf(" %c", &input);
      
      if (input == 'r') {
        canvas[i][j] = 1;
      } else if (input == 'g') {
        canvas[i][j] = 2;
      } else if (input == 'b') {
        canvas[i][j] = 3;
      }
    }
  }
}

void displayCanvas() {
  int i, j;
  
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (canvas[i][j] == 0) {
        printf(" ");
      } else if (canvas[i][j] == 1) {
        printf("X");
      } else if (canvas[i][j] == 2) {
        printf("O");
      } else if (canvas[i][j] == 3) {
        printf("#");
      }
    }
    printf("\n");
  }
}

void saveCanvas() {
  int i, j;
  FILE *file;
  
  file = fopen("canvas.txt", "w");
  
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (canvas[i][j] == 0) {
        fprintf(file, " ");
      } else if (canvas[i][j] == 1) {
        fprintf(file, "X");
      } else if (canvas[i][j] == 2) {
        fprintf(file, "O");
      } else if (canvas[i][j] == 3) {
        fprintf(file, "#");
      }
    }
    fprintf(file, "\n");
  }
  
  fclose(file);
}

int main() {
  initCanvas();
  userInput();
  displayCanvas();
  saveCanvas();
  
  return 0;
}