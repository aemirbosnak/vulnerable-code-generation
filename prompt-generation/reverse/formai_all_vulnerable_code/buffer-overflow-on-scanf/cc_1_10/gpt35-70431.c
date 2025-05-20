//FormAI DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Define structure for storing hotel guest information
struct guest {
   char name[50];
   int room_number;
   int num_of_nights;
   float room_rate;
   float total_room_charge;
   float tax;
   float total_charge;
};

// Function to display hotel guest information
void display_guest_info(struct guest g) {
   printf("Name: %s\n", g.name);
   printf("Room Number: %d\n", g.room_number);
   printf("Number of Nights: %d\n", g.num_of_nights);
   printf("Room Rate: $%.2f\n", g.room_rate);
   printf("Total Room Charge: $%.2f\n", g.total_room_charge);
   printf("Tax: $%.2f\n", g.tax);
   printf("Total Charge: $%.2f\n", g.total_charge);
}

int main() {
   // Declare variables to store user input
   char name[50];
   int room_number;
   int num_of_nights;
   
   // Declare constant variables
   const float TAX_RATE = 0.15;
   const float ROOM_RATE = 80.0;

   // Get input from user
   printf("Enter guest name: ");
   fgets(name, 50, stdin);
   printf("Enter room number: ");
   scanf("%d", &room_number);
   printf("Enter number of nights: ");
   scanf("%d", &num_of_nights);

   // Calculate charges
   float total_room_charge = num_of_nights * ROOM_RATE;
   float tax = total_room_charge * TAX_RATE;
   float total_charge = total_room_charge + tax;

   // Create guest struct and populate with user input and calculated values
   struct guest new_guest;
   strncpy(new_guest.name, name, sizeof(new_guest.name));
   new_guest.room_number = room_number;
   new_guest.num_of_nights = num_of_nights;
   new_guest.room_rate = ROOM_RATE;
   new_guest.total_room_charge = total_room_charge;
   new_guest.tax = tax;
   new_guest.total_charge = total_charge;

   // Display guest information
   display_guest_info(new_guest);
   
   return 0;
}