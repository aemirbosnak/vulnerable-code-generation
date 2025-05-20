//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>

// define the structure for a guest 
struct Guest {
   char name[50];
   int age;
   char email[50];
   int room_number;
};

// initialize arrays to store guest data
struct Guest guest_list[100];
int num_guests = 0;

void display_menu() {
   // display the options for the user to select from
   printf("HOTEL MANAGEMENT SYSTEM\n");
   printf("1. Add Guest\n");
   printf("2. Delete Guest\n");
   printf("3. View Guests\n");
   printf("4. Exit\n");
}

void add_guest() {
   // add a new guest to the guest list
   struct Guest new_guest;

   printf("Enter guest name: ");
   scanf("%s", new_guest.name);
   
   printf("Enter guest age: ");
   scanf("%d", new_guest.age);
   
   printf("Enter guest email: ");
   scanf("%s", new_guest.email);
   
   printf("Enter guest room number: ");
   scanf("%d", new_guest.room_number);
   
   guest_list[num_guests++] = new_guest;
   
   printf("Guest added successfully.\n");
}

void delete_guest() {
   // provide functionality to delete a guest from the guest list
   int room_number;
   printf("Enter room number of guest to delete: ");
   scanf("%d", &room_number);
   
   for (int i = 0; i < num_guests; i++) {
      if (guest_list[i].room_number == room_number) {
         // shift the elements after the deleted guest one index to the left
         for (int j = i; j < num_guests - 1; j++) {
            guest_list[j] = guest_list[j+1];
         }
         num_guests--;
         printf("Guest deleted successfully.\n");
         return;
      }
   }
   
   printf("Guest not found.\n");
}

void view_guests() {
   // display all guests currently checked in
   for (int i = 0; i < num_guests; i++) {
      printf("Guest %d:\n", i+1);
      printf("Name: %s\n", guest_list[i].name);
      printf("Age: %d\n", guest_list[i].age);
      printf("Email: %s\n", guest_list[i].email);
      printf("Room Number: %d\n", guest_list[i].room_number);
      printf("-----------------\n");
   }
}

int main() {
   int option;
   do {
      display_menu();
      scanf("%d", &option);
      
      switch (option) {
         case 1:
            add_guest();
            break;
         case 2:
            delete_guest();
            break;
         case 3:
            view_guests();
            break;
         case 4:
            printf("Exiting program...\n");
            break;
         default:
            printf("Invalid option selected. Please try again.\n");
            break;
      }
   } while (option != 4);
   
   return 0;
}