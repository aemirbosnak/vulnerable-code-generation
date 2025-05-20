//FormAI DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
   char name[50];
   char address[100];
   int roomNo;
   int days;
   float bill;
};

void addGuest(struct guest g[]) {
   int i;
   for(i = 0; i < 3; i++) {
      printf("\nEnter guest %d name: ", i+1);
      scanf("%s", g[i].name);
      printf("Enter address: ");
      scanf("%s", g[i].address);
      printf("Enter room number: ");
      scanf("%d", &g[i].roomNo);
      printf("Enter number of days to stay: ");
      scanf("%d", &g[i].days);
      g[i].bill = g[i].days * 100.0;
      printf("Bill for guest %d is: %.2f\n", i+1, g[i].bill);
   }
}

void searchGuest(struct guest g[], char search_name[]) {
   int i, found = 0;
   for(i = 0; i < 3; i++) {
      if(strcmp(g[i].name, search_name) == 0) {
         printf("\nGuest %d\nName: %s\nAddress: %s\nRoom Number: %d\nDays to stay: %d\nBill: %.2f\n", i+1, g[i].name, g[i].address, g[i].roomNo, g[i].days, g[i].bill);
         found = 1;
      }
   }
   if(found == 0)
      printf("\nGuest not found.");
}

int main() {
   printf("======= Welcome to C Hotel Management System ======\n");

   struct guest guests[3];
   char search_name[50];

   addGuest(guests);

   printf("\nEnter name to search: ");
   scanf("%s", search_name);
   searchGuest(guests, search_name);

   printf("\n======= Thank you for using C Hotel Management System ======\n");
   return 0;
}