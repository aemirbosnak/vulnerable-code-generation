//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

/* defining constants */
#define ROWS 10
#define COLS 10
#define MAX_COORDINATES 20

/* function prototypes */
void initMap(char map[][COLS]);
void printMap(char map[][COLS]);
void navigate(char map[][COLS], int coordinates[][2], int count);

int main(void) {
  char map[ROWS][COLS];
  int coordinates[MAX_COORDINATES][2];
  int count = 0;
  
  printf("GPS Navigation Simulation\n\n");
  printf("Enter coordinates in the format x,y (-1 to stop): ");
  scanf("%d,%d", &coordinates[count][0], &coordinates[count][1]);
  
  /* looping through user input coordinates */
  while (coordinates[count][0] != -1 && count < MAX_COORDINATES) {
    count++;
    printf("Enter coordinates in the format x,y (-1 to stop): ");
    scanf("%d,%d", &coordinates[count][0], &coordinates[count][1]);
  }
  
  /* initializing and printing map */
  initMap(map);
  printf("\nInitial Map:\n");
  printMap(map);
  
  /* navigating through coordinates */
  navigate(map, coordinates, count);
  
  printf("\nFinal Map:\n");
  printMap(map);
  
  return 0;
}

/* function to initialize map */
void initMap(char map[][COLS]) {
  int i, j;
  
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      map[i][j] = '.';
    }
  }
}

/* function to print map */
void printMap(char map[][COLS]) {
  int i, j;
  
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c ", map[i][j]);
    }
    printf("\n");
  }
}

/* function to navigate through coordinates */
void navigate(char map[][COLS], int coordinates[][2], int count) {
  int i, x, y;
  char symbol = 'A';
  
  for (i = 0; i < count; i++) {
    x = coordinates[i][0];
    y = coordinates[i][1];
    
    if (x < 0 || x > ROWS-1 || y < 0 || y > COLS-1) {
      printf("Invalid coordinate: (%d,%d)\n", x, y);
      continue;
    }
    if (map[x][y] != '.') {
      printf("Obstacle found at: (%d,%d)\n", x, y);
      continue;
    }
    
    map[x][y] = symbol;
    symbol++;
  }
}