//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int x, y, z, i, choice, map[10][10] = {{0}};
  char name[20];

  printf("Please enter your name:");
  scanf("%s", name);

  map[5][5] = 1; // You are here

  // Generate a map
  for(x = 0; x < 10; x++) {
    for(y = 0; y < 10; y++) {
      map[x][y] = rand() % 3;
    }
  }

  // Display the map
  for(x = 0; x < 10; x++) {
    for(y = 0; y < 10; y++) {
      printf("%d ", map[x][y]);
    }
    printf("\n");
  }

  // Move around the map
  while(1) {
    printf("Enter your move (N, S, E, W): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        if(map[x-1][y] != 0) {
          x--;
        }
        break;
      case 2:
        if(map[x+1][y] != 0) {
          x++;
        }
        break;
      case 3:
        if(map[x][y-1] != 0) {
          y--;
        }
        break;
      case 4:
        if(map[x][y+1] != 0) {
          y++;
        }
        break;
    }

    // Check if you have reached the center
    if(map[x][y] == 1) {
      printf("Congratulations, %s, you have reached the center of the map!", name);
      break;
    }

    // Display the updated map
    for(x = 0; x < 10; x++) {
      for(y = 0; y < 10; y++) {
        printf("%d ", map[x][y]);
      }
      printf("\n");
    }
  }
}