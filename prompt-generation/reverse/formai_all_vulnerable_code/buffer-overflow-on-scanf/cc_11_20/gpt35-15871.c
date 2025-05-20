//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int room_number;
  char guest_name[50];
  int num_guests;
  float rate;
} room;

int main() {
  room rooms[10];
  int option, num_rooms = 0, i;
  do {
    printf("Welcome to the C Hotel Management System!\n");
    printf("1. Book a Room\n2. View All Rooms\n3. Check Out\n4. Exit\n");
    printf("Enter an option: ");
    scanf("%d", &option);
    switch(option) {
      case 1:
        if(num_rooms >= 10) {
          printf("No rooms available, please try again later.\n");
        } else {
          printf("Enter the room number: ");
          scanf("%d", &rooms[num_rooms].room_number);
          printf("Enter the guest name: ");
          scanf("%s", &rooms[num_rooms].guest_name);
          printf("Enter the number of guests: ");
          scanf("%d", &rooms[num_rooms].num_guests);
          printf("Enter the daily rate: ");
          scanf("%f", &rooms[num_rooms].rate);
          printf("Room booked successfully!\n");
          num_rooms++;
        }
        break;
      case 2:
        if(num_rooms == 0) {
          printf("No rooms booked yet.\n");
        } else {
          printf("Rooms Booked:\n");
          printf("Room No.\tGuest Name\tNum. Guests\tDaily Rate\n");
          for(i = 0; i < num_rooms; i++) {
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", rooms[i].room_number, rooms[i].guest_name, rooms[i].num_guests, rooms[i].rate);
          }
        }
        break;
      case 3:
        if(num_rooms == 0) {
          printf("No rooms booked yet.\n");
        } else {
          int found = 0;
          int check_room;
          printf("Enter the room number to check out: ");
          scanf("%d", &check_room);
          for(i = 0; i < num_rooms; i++) {
            if(rooms[i].room_number == check_room) {
              printf("Total Bill for Room No. %d (%s):\n", rooms[i].room_number, rooms[i].guest_name);
              printf("Daily Rate\tNum. of Days\tTotal Amount\n");
              printf("%.2f\t\t", rooms[i].rate);
              int num_days;
              printf("Enter the number of days: ");
              scanf("%d", &num_days);
              printf("%d\t\t", num_days);
              printf("%.2f\n", rooms[i].rate * num_days);
              found = 1;
              num_rooms--;
              for(int j = i; j < num_rooms; j++) {
                rooms[j] = rooms[j+1];
              }
              printf("Check out successful!\n");
              break;
            }
          }
          if(!found) {
            printf("Room not found.\n");
          }
        }
        break;
      case 4:
        printf("Exiting C Hotel Management System...\n");
        break;
      default:
        printf("Invalid option.\n");
        break;
    }
  } while(option != 4);
  return 0;
}