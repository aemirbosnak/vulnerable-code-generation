//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel_room {
  int room_number;
  char room_type[10];
  char status[10];
  char guest_name[20];
  int no_of_guests;
  char check_in_date[10];
  char check_out_date[10];
};

struct hotel_room rooms[10];

int main() {
  int i, choice;
  char room_type[10], status[10], guest_name[20], check_in_date[10], check_out_date[10];
  int no_of_guests;

  for (i = 0; i < 10; i++) {
    printf("Enter room number: ");
    scanf("%d", &rooms[i].room_number);
    printf("Enter room type: ");
    scanf("%s", &rooms[i].room_type);
    printf("Enter status: ");
    scanf("%s", &rooms[i].status);
    printf("Enter guest name: ");
    scanf("%s", &rooms[i].guest_name);
    printf("Enter number of guests: ");
    scanf("%d", &rooms[i].no_of_guests);
    printf("Enter check-in date: ");
    scanf("%s", &rooms[i].check_in_date);
    printf("Enter check-out date: ");
    scanf("%s", &rooms[i].check_out_date);
  }

  while (1) {
    printf("1. View all rooms\n");
    printf("2. View available rooms\n");
    printf("3. Book a room\n");
    printf("4. Check-in\n");
    printf("5. Check-out\n");
    printf("6. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("View all rooms:\n");
        for (i = 0; i < 10; i++) {
          printf("%d. Room number: %d, Room type: %s, Status: %s, Guest name: %s, Number of guests: %d, Check-in date: %s, Check-out date: %s\n", i + 1, rooms[i].room_number, rooms[i].room_type, rooms[i].status, rooms[i].guest_name, rooms[i].no_of_guests, rooms[i].check_in_date, rooms[i].check_out_date);
        }
        break;
      case 2:
        printf("View available rooms:\n");
        for (i = 0; i < 10; i++) {
          if (strcmp(rooms[i].status, "Available") == 0) {
            printf("%d. Room number: %d, Room type: %s, Status: %s, Guest name: %s, Number of guests: %d, Check-in date: %s, Check-out date: %s\n", i + 1, rooms[i].room_number, rooms[i].room_type, rooms[i].status, rooms[i].guest_name, rooms[i].no_of_guests, rooms[i].check_in_date, rooms[i].check_out_date);
          }
        }
        break;
      case 3:
        printf("Book a room:\n");
        printf("Enter room number: ");
        scanf("%d", &rooms[i].room_number);
        printf("Enter room type: ");
        scanf("%s", &rooms[i].room_type);
        printf("Enter status: ");
        scanf("%s", &rooms[i].status);
        printf("Enter guest name: ");
        scanf("%s", &rooms[i].guest_name);
        printf("Enter number of guests: ");
        scanf("%d", &rooms[i].no_of_guests);
        printf("Enter check-in date: ");
        scanf("%s", &rooms[i].check_in_date);
        printf("Enter check-out date: ");
        scanf("%s", &rooms[i].check_out_date);
        break;
      case 4:
        printf("Check-in:\n");
        printf("Enter room number: ");
        scanf("%d", &rooms[i].room_number);
        printf("Enter guest name: ");
        scanf("%s", &rooms[i].guest_name);
        printf("Enter number of guests: ");
        scanf("%d", &rooms[i].no_of_guests);
        printf("Enter check-in date: ");
        scanf("%s", &rooms[i].check_in_date);
        break;
      case 5:
        printf("Check-out:\n");
        printf("Enter room number: ");
        scanf("%d", &rooms[i].room_number);
        printf("Enter guest name: ");
        scanf("%s", &rooms[i].guest_name);
        printf("Enter check-out date: ");
        scanf("%s", &rooms[i].check_out_date);
        break;
      case 6:
        printf("Exiting...\n");
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }

  return 0;
}