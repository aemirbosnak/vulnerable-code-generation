//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_GUESTS 2

typedef struct Room {
  int number;
  char status;
  struct Guest {
    char name[MAX_GUESTS];
    int room_number;
  } guests[MAX_GUESTS];
} Room;

Room rooms[MAX_ROOMS];

int main() {
  int i, j, room_number, guests_number;
  char command;

  for (i = 0; i < MAX_ROOMS; i++) {
    rooms[i].number = i + 1;
    rooms[i].status = 'O';
  }

  while (1) {
    printf("Enter command (H/A/R/Q): ");
    scanf("%c", &command);

    switch (command) {
      case 'H':
        printf("List of rooms:\n");
        for (i = 0; i < MAX_ROOMS; i++) {
          printf("Room %d: ", rooms[i].number);
          if (rooms[i].status == 'O') {
            printf("Occupied\n");
          } else {
            printf("Available\n");
          }
        }
        break;

      case 'A':
        printf("Enter room number: ");
        scanf("%d", &room_number);

        for (i = 0; i < MAX_ROOMS; i++) {
          if (rooms[i].number == room_number) {
            if (rooms[i].status == 'O') {
              printf("Room is occupied.\n");
            } else {
              printf("Enter guest name: ");
              scanf("%s", rooms[i].guests[0].name);
              rooms[i].guests[0].room_number = room_number;
              rooms[i].status = 'O';
              printf("Room is occupied.\n");
            }
          }
        }
        break;

      case 'R':
        printf("Enter room number: ");
        scanf("%d", &room_number);

        for (i = 0; i < MAX_ROOMS; i++) {
          if (rooms[i].number == room_number) {
            if (rooms[i].status == 'O') {
              printf("Room is occupied.\n");
            } else {
              rooms[i].status = 'A';
              printf("Room is available.\n");
            }
          }
        }
        break;

      case 'Q':
        exit(0);
    }
  }
}