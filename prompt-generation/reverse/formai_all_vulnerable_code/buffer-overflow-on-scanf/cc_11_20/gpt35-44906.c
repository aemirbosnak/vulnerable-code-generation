//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXROOMS 100

struct room {
  int number;
  char type[10];
  int occupancy;
  float rate;
};

int main() {

  struct room hotel[MAXROOMS];
  int i, num_rooms, choice, room_num;
  char temp[10];
  float total_income = 0.0;

  printf("Welcome to Hotel Management System\n");
  printf("Enter number of rooms in the hotel: ");
  scanf("%d", &num_rooms);

  for (i = 0; i < num_rooms; i++) {
      printf("Enter details for room %d\n", i+1);
      printf("Room number: ");
      scanf("%d", &hotel[i].number);
      printf("Room type (Single/Double): ");
      scanf("%s", hotel[i].type);
      printf("Occupancy (1/2): ");
      scanf("%d", &hotel[i].occupancy);
      printf("Rate ($/night): ");
      scanf("%f", &hotel[i].rate);
      printf("\n");
  }

  do {
      printf("Enter 1 to display all rooms\n");
      printf("Enter 2 to display available rooms\n");
      printf("Enter 3 to book a room\n");
      printf("Enter 4 to check out of a room\n");
      printf("Enter 5 to exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch(choice) {
          case 1: 
              printf("All Rooms\n");
              printf("Room No.\tType\tOccupancy\tRate\n");
              for (i = 0; i < num_rooms; i++) {
                  printf("%d\t\t%s\t%d\t\t%.2f\n", hotel[i].number, hotel[i].type, hotel[i].occupancy, hotel[i].rate);
              }
              printf("\n");
              break;

          case 2:
              printf("Available Rooms\n");
              printf("Room No.\tType\tOccupancy\tRate\n");
              for (i = 0; i < num_rooms; i++) {
                  if (hotel[i].occupancy == 0) {
                      printf("%d\t\t%s\t%d\t\t%.2f\n", hotel[i].number, hotel[i].type, hotel[i].occupancy, hotel[i].rate);
                  }
              }
              printf("\n");
              break;

          case 3:
              printf("Enter room number: ");
              scanf("%d", &room_num);
              for (i = 0; i < num_rooms; i++) {
                  if (hotel[i].number == room_num) {
                      if (hotel[i].occupancy == 0) {
                          printf("Enter guest name: ");
                          scanf("%s", temp);
                          printf("Enter number of nights: ");
                          scanf("%d", &hotel[i].occupancy);
                          total_income += hotel[i].rate * hotel[i].occupancy;
                          printf("Room booked successfully!\n\n");
                      } else {
                          printf("Room is already occupied.\n\n");
                      }
                  }
              }
              break;

          case 4:
              printf("Enter room number: ");
              scanf("%d", &room_num);
              for (i = 0; i < num_rooms; i++) {
                  if (hotel[i].number == room_num) {
                      if (hotel[i].occupancy != 0) {
                          printf("Guest %s checked out of room %d\n", temp, hotel[i].number);
                          hotel[i].occupancy = 0;
                      } else {
                          printf("Room is already vacant.\n");
                      }
                  }
              }
              printf("\n");
              break;

          case 5:
              printf("Total Income: $%.2f\n", total_income);
              printf("Exiting...\n");
              break;

          default:
              printf("Invalid choice. Please try again.\n\n");
              break;
      }

  } while (choice != 5);

  return 0;
}