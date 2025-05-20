//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Structure to represent a guest in the hotel
  struct guest {
    char name[30];
    int room_number;
    int stay_duration;
  };

  // Function to display the menu
  void display_menu() {
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Room availability\n");
    printf("4. Room status\n");
    printf("5. Exit\n");
  }

  // Function to check-in a guest
  void check_in(struct guest* guest) {
    printf("Enter the guest's name: ");
    scanf("%s", guest->name);
    printf("Enter the room number: ");
    scanf("%d", &guest->room_number);
    printf("Enter the stay duration: ");
    scanf("%d", &guest->stay_duration);
  }

  // Function to check-out a guest
  void check_out(struct guest* guest) {
    printf("Enter the guest's name: ");
    scanf("%s", guest->name);
    printf("Enter the room number: ");
    scanf("%d", &guest->room_number);
  }

  // Function to check the availability of a room
  void room_availability() {
    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);
    if (room_number == 1) {
      printf("Room 1 is available\n");
    } else if (room_number == 2) {
      printf("Room 2 is available\n");
    } else if (room_number == 3) {
      printf("Room 3 is available\n");
    } else {
      printf("Invalid room number\n");
    }
  }

  // Function to display the status of a room
  void room_status() {
    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);
    if (room_number == 1) {
      printf("Room 1 is occupied\n");
    } else if (room_number == 2) {
      printf("Room 2 is occupied\n");
    } else if (room_number == 3) {
      printf("Room 3 is occupied\n");
    } else {
      printf("Invalid room number\n");
    }
  }

  int main() {
    struct guest guest;
    int choice;

    // Display the menu
    display_menu();

    // Take input from the user
    scanf("%d", &choice);

    // Perform the action based on the user's choice
    switch (choice) {
      case 1:
        check_in(&guest);
        break;
      case 2:
        check_out(&guest);
        break;
      case 3:
        room_availability();
        break;
      case 4:
        room_status();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }

    return 0;
  }