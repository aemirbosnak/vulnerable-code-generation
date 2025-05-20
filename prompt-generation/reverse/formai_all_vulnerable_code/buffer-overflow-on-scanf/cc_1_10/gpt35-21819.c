//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
   char name[20];
   int room_no;
   int stay_duration;
}guests[10];

void add_guest() {
   int i=0;
   char name[20];
   int room_no;
   int stay_duration;
   printf("Enter the guest name: ");
   scanf("%s", name);
   printf("Enter the room number: ");
   scanf("%d", &room_no);
   printf("Enter the stay duration in days: ");
   scanf("%d", &stay_duration);
   while(i<10) {
      if(strcmp(guests[i].name, "") == 0) {
         strcpy(guests[i].name, name);
         guests[i].room_no = room_no;
         guests[i].stay_duration = stay_duration;
         break;
      }
      else
         i++;   
   }

}

void display_guests() {
   int i = 0;
   printf("Guests List:\n");
   while (i<10) {
      if(strcmp(guests[i].name, "") != 0) {
         printf("%s\tRoom No:%d\tStay Duration:%d days\n", guests[i].name, guests[i].room_no, guests[i].stay_duration);
      }
      i++;
   }
}

void checkout_guest() {
   int i, room_no;
   printf("Enter the room number of the guest to checkout: ");
   scanf("%d",&room_no);
   for(i=0; i<10; i++) {
      if(guests[i].room_no == room_no) {
         printf("%s has checked out from room number %d after staying for %d days.\n", guests[i].name, guests[i].room_no, guests[i].stay_duration);
         guests[i].name[0] = '\0'; 
         guests[i].room_no = 0;
         guests[i].stay_duration = 0;
         break;
      }   
   }
}

int main() {
   int option;
  
   while(1) {
      printf("Welcome to C Hotel Management System\n");
      printf("1. Add Guest\n");
      printf("2. Display Guests list\n");
      printf("3. Checkout Guest\n");
      printf("4. Exit\n");
      printf("\nEnter an option: ");
      scanf("%d", &option);
      switch(option) {
         case 1:
            add_guest();
            break;
         case 2:
            display_guests();
            break;
         case 3:
            checkout_guest();
            break;
         case 4:
            printf("Thank you.\n");
            exit(0);
         default:
            printf("Invalid Option.");   
      }
   }
   return 0;
}