//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structure for each room
struct room {
   int room_number;
   char room_type[20];
   float room_price;
   int room_occupancy;
};

// Define structure for each guest
struct guest {
   char guest_name[50];
   int guest_age;
   char guest_address[100];
};

// Define structure for each reservation
struct reservation {
   struct guest guest_info;
   struct room room_info;
};

// Define some constant values
#define NUM_ROOMS 10
#define NUM_GUESTS 10

// Define function to print a room
void print_room(struct room r) {
   printf("----- ROOM INFO -----\n");
   printf("Room number: %d\n", r.room_number);
   printf("Room type: %s\n", r.room_type);
   printf("Room price: %.2f\n", r.room_price);
   printf("Room occupancy: %d\n", r.room_occupancy);
}

// Define function to print a guest
void print_guest(struct guest g) {
   printf("----- GUEST INFO -----\n");
   printf("Guest name: %s\n", g.guest_name);
   printf("Guest age: %d\n", g.guest_age);
   printf("Guest address: %s\n", g.guest_address);
}

// Define function to print a reservation
void print_reservation(struct reservation r) {
   printf("**** RESERVATION ****\n");
   print_guest(r.guest_info);
   print_room(r.room_info);
}

// Define function to find a guest by name
struct guest find_guest(char guest_name[], struct guest guest_list[]) {
   for (int i = 0; i < NUM_GUESTS; i++) {
      if (strcmp(guest_name, guest_list[i].guest_name) == 0) {
         return guest_list[i];
      }
   }
   // If the guest is not found, return an empty guest
   struct guest empty_guest = {"", 0, ""};
   return empty_guest;
}

// Main function
int main() {
   // Initialize a list of rooms
   struct room room_list[NUM_ROOMS] = {
      {101, "Single", 50.00, 1},
      {102, "Single", 50.00, 1},
      {103, "Double", 75.00, 2},
      {104, "Double", 75.00, 2},
      {105, "Double", 75.00, 2},
      {106, "Triple", 100.00, 3},
      {107, "Triple", 100.00, 3},
      {108, "Suite", 150.00, 4},
      {109, "Suite", 150.00, 4},
      {110, "Presidential Suite", 300.00, 5}
   };

   // Initialize a list of guests
   struct guest guest_list[NUM_GUESTS] = {
      {"John Smith", 30, "123 Main St"},
      {"Jane Doe", 25, "456 Elm St"},
      {"Bob Johnson", 45, "789 Maple St"},
      {"Mary Wilson", 50, "321 Oak St"},
      {"Tom Brown", 35, "654 Pine St"},
      {"Tim Lee", 40, "987 Cedar St"},
      {"Sue Davis", 55, "246 Birch St"},
      {"Pat Thompson", 60, "369 Mulberry St"},
      {"Mike Perez", 20, "802 Walnut St"},
      {"Lisa Garcia", 28, "976 Chestnut St"}
   };

   // Initialize an empty list of reservations
   struct reservation reservation_list[NUM_GUESTS];

   // Print all the rooms
   for (int i = 0; i < NUM_ROOMS; i++) {
      print_room(room_list[i]);
   }

   // Print all the guests
   for (int i = 0; i < NUM_GUESTS; i++) {
      print_guest(guest_list[i]);
   }

   // Make a reservation
   struct reservation new_reservation;
   printf("Enter guest name: ");
   scanf("%s", new_reservation.guest_info.guest_name);
   new_reservation.guest_info = find_guest(new_reservation.guest_info.guest_name, guest_list);
   printf("Enter room number: ");
   scanf("%d", &new_reservation.room_info.room_number);
   new_reservation.room_info = room_list[new_reservation.room_info.room_number - 101];
   print_reservation(new_reservation);

   // Add the reservation to the list of reservations
   reservation_list[0] = new_reservation;

   // Print all the reservations
   for (int i = 0; i < NUM_GUESTS; i++) {
      if (strlen(reservation_list[i].guest_info.guest_name) > 0)
         print_reservation(reservation_list[i]);
   }

   return 0;
}