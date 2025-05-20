//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct Room {
  char room_no[MAX];
  char room_type[MAX];
  int available;
  int price;
} Room;

Room rooms[MAX];

void display_rooms() {
  for (int i = 0; i < MAX; i++) {
    printf("Room No: %s, Room Type: %s, Available: %d, Price: %d\n", rooms[i].room_no, rooms[i].room_type, rooms[i].available, rooms[i].price);
  }
}

void book_room() {
  char room_no[MAX];
  printf("Enter room number: ");
  scanf("%s", room_no);

  for (int i = 0; i < MAX; i++) {
    if (strcmp(rooms[i].room_no, room_no) == 0) {
      if (rooms[i].available) {
        rooms[i].available = 0;
        printf("Room booked successfully!\n");
      } else {
        printf("Room is not available.\n");
      }
    }
  }
}

void check_availability() {
  char room_no[MAX];
  printf("Enter room number: ");
  scanf("%s", room_no);

  for (int i = 0; i < MAX; i++) {
    if (strcmp(rooms[i].room_no, room_no) == 0) {
      if (rooms[i].available) {
        printf("Room is available.\n");
      } else {
        printf("Room is not available.\n");
      }
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Hotel Management System!\n");

  while (1) {
    printf("Please select an option:\n");
    printf("1. Display Rooms\n");
    printf("2. Book a Room\n");
    printf("3. Check Room Availability\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        display_rooms();
        break;
      case 2:
        book_room();
        break;
      case 3:
        check_availability();
        break;
      case 4:
        exit(0);
    }
  }

  return 0;
}