//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char room_type[20];
  int check_in;
  int check_out;
} Guest;

typedef struct {
  int room_number;
  int capacity;
  char room_type[20];
  float price;
} Room;

Guest guests[100];
Room rooms[100];
int num_guests = 0;
int num_rooms = 0;

void add_guest() {
  Guest guest;

  printf("Enter guest name: ");
  scanf("%s", guest.name);

  printf("Enter room type: ");
  scanf("%s", guest.room_type);

  printf("Enter check-in date (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &guest.check_in, &guest.check_in, &guest.check_in);

  printf("Enter check-out date (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &guest.check_out, &guest.check_out, &guest.check_out);

  guests[num_guests++] = guest;
}

void add_room() {
  Room room;

  printf("Enter room number: ");
  scanf("%d", &room.room_number);

  printf("Enter room capacity: ");
  scanf("%d", &room.capacity);

  printf("Enter room type: ");
  scanf("%s", room.room_type);

  printf("Enter room price: ");
  scanf("%f", &room.price);

  rooms[num_rooms++] = room;
}

void print_guests() {
  int i;

  printf("Guests:\n");
  for (i = 0; i < num_guests; i++) {
    printf("%s, %s, %d/%d/%d, %d/%d/%d\n", guests[i].name, guests[i].room_type, guests[i].check_in, guests[i].check_in, guests[i].check_in, guests[i].check_out, guests[i].check_out, guests[i].check_out);
  }
}

void print_rooms() {
  int i;

  printf("Rooms:\n");
  for (i = 0; i < num_rooms; i++) {
    printf("%d, %d, %s, %f\n", rooms[i].room_number, rooms[i].capacity, rooms[i].room_type, rooms[i].price);
  }
}

int main() {
  int choice;

  do {
    printf("1. Add guest\n");
    printf("2. Add room\n");
    printf("3. Print guests\n");
    printf("4. Print rooms\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: add_guest(); break;
      case 2: add_room(); break;
      case 3: print_guests(); break;
      case 4: print_rooms(); break;
      case 5: exit(0); break;
      default: printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}