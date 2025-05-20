//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure definition for each room
struct Room {
  int room_no;
  char type[10];
  int rate;
  int availability;
};

int main() {
  int num_rooms;
  
  printf("Welcome to C Hotel Management System\n\n");
  printf("Please enter the number of rooms in the hotel: ");

  // Taking the number of rooms input from the user
  scanf("%d", &num_rooms);

  // Creating an array of rooms
  struct Room rooms[num_rooms];

  // Initializing the room details
  for (int i = 0; i < num_rooms; i++) {
    rooms[i].room_no = i+1;
    rooms[i].rate = 0;
    rooms[i].availability = 1;
  }

  // Menu driven program for room management
  while (1) {
    printf("\n\n1. Add room details\n");
    printf("2. Edit room details\n");
    printf("3. Delete room details\n");
    printf("4. Search room details\n");
    printf("5. View room details\n");
    printf("6. Exit\n");

    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      // Adding a new room
      case 1: {
        printf("\nEnter the details of the new room:\n");
        printf("Room no: ");
        int room_no;
        scanf("%d", &room_no);

        // Checking if the room already exists
        for (int i = 0; i < num_rooms; i++) {
          if (rooms[i].room_no == room_no) {
            printf("Room already exists.\n");
            break;
          }
        }

        int rate;
        printf("Rate: ");
        scanf("%d", &rate);
        
        char type[10];
        printf("Type (Single/Double/Triple): ");
        scanf("%s", type);

        for (int i = 0; i < num_rooms; i++) {
          if (rooms[i].room_no == room_no) {
            strcpy(rooms[i].type, type);
            rooms[i].rate = rate;
            rooms[i].availability = 1;
            printf("Room added successfully!\n");
            break;
          }
        }
        break;
      }

      // Editing an existing room
      case 2: {
        printf("\nEnter the room no of the room to be edited: ");
        int room_no;
        scanf("%d", &room_no);

        int flag = 0;
        for (int i = 0; i < num_rooms; i++) {
          if (rooms[i].room_no == room_no) {
            flag = 1;
            char type[10];
            printf("Type (Single/Double/Triple): ");
            scanf("%s", type);
            int rate;
            printf("Rate: ");
            scanf("%d", &rate);

            strcpy(rooms[i].type, type);
            rooms[i].rate = rate;

            printf("Room details updated successfully!\n");
            break;
          }
        }
        if (flag == 0)
          printf("Room not found.\n");
        break;
      }

      // Deleting an existing room
      case 3: {
        printf("\nEnter the room no of the room to be deleted: ");
        int room_no;
        scanf("%d", &room_no);

        int flag = 0;
        for (int i = 0; i < num_rooms; i++) {
          if (rooms[i].room_no == room_no) {
            flag = 1;
            rooms[i].rate = 0;
            rooms[i].availability = 0;
            printf("Room details deleted successfully!\n");
            break;
          }
        }
        if (flag == 0)
          printf("Room not found.\n");
        break;
      }

      // Searching for a room
      case 4: {
        printf("\nEnter the room no to search: ");
        int room_no;
        scanf("%d", &room_no);

        int flag = 0;
        for (int i = 0; i < num_rooms; i++) {
          if (rooms[i].room_no == room_no) {
            flag = 1;
            printf("Details of room no %d:\n", rooms[i].room_no);
            printf("Type : %s\n", rooms[i].type);
            printf("Rate : %d\n", rooms[i].rate);
            printf("Availability : ");
            if (rooms[i].availability == 1)
              printf("Available");
            else
              printf("Not Available");
            printf("\n");
            break;
          }
        }
        if (flag == 0)
          printf("Room not found.\n");
        break;
      }

      // Viewing all rooms and their details
      case 5: {
        printf("\nRoom Details:\n");
        printf("------------------\n");
        printf("Room No  Type      Rate    Availability\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < num_rooms; i++) {
          printf("%-8d%-10s%-8d", rooms[i].room_no, rooms[i].type, rooms[i].rate);
          if (rooms[i].availability == 1)
            printf("%-10s", "Available");
          else
            printf("%-10s", "Not Available");
          printf("\n");
        }
        printf("----------------------------------------\n");
        break;
      }

      // Exiting the program
      case 6: {
        printf("\nThank you for using C Hotel Management System.\n");
        exit(0);
      }

      // Invalid choice input
      default:
        printf("\nInvalid choice. Please try again.\n");
    }
  }

  return 0;
}