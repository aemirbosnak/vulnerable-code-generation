//FormAI DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
  int room_no;
  char type[20];
  int price;
  int status; //0 = vacant, 1 = occupied, 2 = reserved
};

struct booking {
  int booking_id;
  int room_no;
  char name[50];
  char phone[15];
  char email[50];
  char check_in[15];
  char check_out[15];
};

void display_menu() {
  printf("\n\n");
  printf("**** Hotel Management System ****\n");
  printf("\n");
  printf("1. Add Room\n");
  printf("2. Remove Room\n");
  printf("3. Display Rooms\n");
  printf("4. Book Room\n");
  printf("5. Cancel Booking\n");
  printf("6. Display Bookings\n");
  printf("7. Exit\n");
  printf("\n");
}

void add_room(struct room *rooms, int *num_rooms) {
  int room_no, price;
  char type[20];

  printf("\nEnter Room No: ");
  scanf("%d", &room_no);

  // Check if room already exists
  for (int i = 0; i < *num_rooms; i++) {
    if (rooms[i].room_no == room_no) {
      printf("\nError: Room already exists!\n");
      return;
    }
  }

  printf("Enter Room Type: ");
  scanf("%s", type);

  printf("Enter Room Price: ");
  scanf("%d", &price);

  // Add new room to array
  rooms[*num_rooms].room_no = room_no;
  strcpy(rooms[*num_rooms].type, type);
  rooms[*num_rooms].price = price;
  rooms[*num_rooms].status = 0;
  (*num_rooms)++;

  printf("\nRoom added successfully!\n");
}

void remove_room(struct room *rooms, int *num_rooms, int room_no) {
  // Find room index
  int room_index = -1;
  for (int i = 0; i < *num_rooms; i++) {
    if (rooms[i].room_no == room_no) {
      room_index = i;
      break;
    }
  }

  // Check if room found
  if (room_index == -1) {
    printf("\nError: Room not found!\n");
    return;
  }

  // Check if room is vacant
  if (rooms[room_index].status != 0) {
    printf("\nError: Room is not vacant!\n");
    return;
  }

  // Remove room
  for (int i = room_index; i < (*num_rooms) - 1; i++) {
    rooms[i] = rooms[i+1];
  }
  (*num_rooms)--;

  printf("\nRoom removed successfully!\n");
}

void display_rooms(struct room *rooms, int num_rooms) {
  printf("\n---- Rooms ----\n");
  printf("Room No\tType\tPrice\tStatus\n");

  for (int i = 0; i < num_rooms; i++) {
    printf("%d\t%s\t%d\t", rooms[i].room_no, rooms[i].type, rooms[i].price);

    switch (rooms[i].status) {
      case 0:
        printf("Vacant\n");
        break;
      case 1:
        printf("Occupied\n");
        break;
      case 2:
        printf("Reserved\n");
        break;
    }
  }
}

void book_room(struct room *rooms, int num_rooms, struct booking *bookings, int *num_bookings, int room_no) {
  // Check if room exists
  int room_index = -1;
  for (int i = 0; i < num_rooms; i++) {
    if (rooms[i].room_no == room_no) {
      room_index = i;
      break;
    }
  }

  if (room_index == -1) {
    printf("\nError: Room not found!\n");
    return;
  }

  // Check if room is vacant or reserved
  if (rooms[room_index].status != 0 && rooms[room_index].status != 2) {
    printf("\nError: Room is not available!\n");
    return;
  }

  // Get booking details
  int booking_id = *num_bookings + 1;
  char name[50], phone[15], email[50], check_in[15], check_out[15];

  printf("\nEnter Name: ");
  scanf(" %[^\n]s", name);

  printf("Enter Phone: ");
  scanf("%s", phone);

  printf("Enter Email: ");
  scanf("%s", email);

  printf("Enter Check-in Date (dd/mm/yyyy): ");
  scanf("%s", check_in);

  printf("Enter Check-out Date (dd/mm/yyyy): ");
  scanf("%s", check_out);

  // Add booking
  bookings[*num_bookings].booking_id = booking_id;
  bookings[*num_bookings].room_no = room_no;
  strcpy(bookings[*num_bookings].name, name);
  strcpy(bookings[*num_bookings].phone, phone);
  strcpy(bookings[*num_bookings].email, email);
  strcpy(bookings[*num_bookings].check_in, check_in);
  strcpy(bookings[*num_bookings].check_out, check_out);
  (*num_bookings)++;

  // Update room status to occupied
  rooms[room_index].status = 1;

  printf("\nRoom booked successfully!\n");
}

void cancel_booking(struct room *rooms, int num_rooms, struct booking *bookings, int *num_bookings, int booking_id) {
  // Find booking index
  int booking_index = -1;
  for (int i = 0; i < *num_bookings; i++) {
    if (bookings[i].booking_id == booking_id) {
      booking_index = i;
      break;
    }
  }

  // Check if booking found
  if (booking_index == -1) {
    printf("\nError: Booking not found!\n");
    return;
  }

  // Update room status to vacant
  int room_no = bookings[booking_index].room_no;
  for (int i = 0; i < num_rooms; i++) {
    if (rooms[i].room_no == room_no) {
      rooms[i].status = 0;
      break;
    }
  }

  // Remove booking
  for (int i = booking_index; i < (*num_bookings) - 1; i++) {
    bookings[i] = bookings[i+1];
  }
  (*num_bookings)--;

  printf("\nBooking cancelled successfully!\n");
}

void display_bookings(struct booking *bookings, int num_bookings) {
  printf("\n---- Bookings ----\n");
  printf("Booking ID\tRoom No\tName\tPhone\tEmail\tCheck-in\tCheck-out\n");

  for (int i = 0; i < num_bookings; i++) {
    printf("%d\t\t%d\t%s\t%s\t%s\t%s\t%s\n", bookings[i].booking_id, bookings[i].room_no, bookings[i].name, bookings[i].phone, bookings[i].email, bookings[i].check_in, bookings[i].check_out);
  }
}

int main() {
  struct room rooms[50];
  int num_rooms = 0;

  struct booking bookings[50];
  int num_bookings = 0;

  int choice;
  while (1) {
    display_menu();
    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_room(rooms, &num_rooms);
        break;
      case 2:
        if (num_rooms == 0) {
          printf("\nError: No rooms available!\n");
          break;
        }
        int room_no;
        printf("\nEnter Room No to remove: ");
        scanf("%d", &room_no);
        remove_room(rooms, &num_rooms, room_no);
        break;
      case 3:
        if (num_rooms == 0) {
          printf("\nNo rooms available!\n");
          break;
        }
        display_rooms(rooms, num_rooms);
        break;
      case 4:
        if (num_rooms == 0) {
          printf("\nError: No rooms available!\n");
          break;
        }
        int room_num;
        printf("\nEnter Room No to book: ");
        scanf("%d", &room_num);
        book_room(rooms, num_rooms, bookings, &num_bookings, room_num);
        break;
      case 5:
        if (num_bookings == 0) {
          printf("\nError: No bookings available!\n");
          break;
        }
        int booking_num;
        printf("\nEnter Booking ID to cancel: ");
        scanf("%d", &booking_num);
        cancel_booking(rooms, num_rooms, bookings, &num_bookings, booking_num);
        break;
      case 6:
        if (num_bookings == 0) {
          printf("\nNo bookings available!\n");
          break;
        }
        display_bookings(bookings, num_bookings);
        break;
      case 7:
        printf("Thank you for using Hotel Management System!\n");
        exit(0);
      default:
        printf("\nInvalid choice! Please try again.\n");
        break;
    }
  }

  return 0;
}