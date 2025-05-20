//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the number of floors in the house: ");
  scanf("%d", &n);

  int rooms[n];

  printf("Enter the number of rooms on each floor: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &rooms[i]);
  }

  printf("Rooms on each floor: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", rooms[i]);
  }

  printf("\n");

  for (int i = 0; i < n; i++) {
    int doors[rooms[i]];

    printf("Enter the number of doors in each room: ");
    for (int j = 0; j < rooms[i]; j++) {
      scanf("%d", &doors[j]);
    }

    printf("Doors in each room: ");
    for (int j = 0; j < rooms[i]; j++) {
      printf("%d ", doors[j]);
    }

    printf("\n");
  }

  printf("Enter the number of doors on each floor: ");
  int doorsTotal[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &doorsTotal[i]);
  }

  printf("Doors on each floor: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", doorsTotal[i]);
  }

  printf("\n");

  printf("The total number of doors in the house is: %d", doorsTotal[0] * rooms[0]);
  return 0;
}