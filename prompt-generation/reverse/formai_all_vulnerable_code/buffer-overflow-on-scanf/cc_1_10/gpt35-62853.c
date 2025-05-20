//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook_entry {
   char name[20];
   char phone[20];
} PhonebookEntry;

int main() {
   // Initialize phonebook with 10 entries
   PhonebookEntry *phonebook = malloc(10 * sizeof(PhonebookEntry));
   int num_entries = 0;

   // User menu
   int choice = 0;
   while (choice != 4) {
      printf("\n1 - Add entry\n2 - Search for entry\n3 - Print all entries\n4 - Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      if (choice == 1) {
         // Get new entry details from user
         printf("\nEnter name: ");
         scanf("%s", phonebook[num_entries].name);
         printf("Enter phone: ");
         scanf("%s", phonebook[num_entries].phone);

         printf("\nEntry added successfully.");
         num_entries++;
      }
      else if (choice == 2) {
         // Get search query from user
         printf("\nEnter a name to search for: ");
         char search_name[20];
         scanf("%s", search_name);

         // Search for entry
         int found = 0;
         for (int i = 0; i < num_entries; i++) {
            if (strcmp(search_name, phonebook[i].name) == 0) {
               printf("\n%s - %s", phonebook[i].name, phonebook[i].phone);
               found = 1;
               break;
            }
         }

         if (!found) {
            printf("\nEntry not found.");
         }
      }
      else if (choice == 3) {
         // Print all entries
         printf("\nPhonebook Entries:\n");
         for (int i = 0; i < num_entries; i++) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
         }
      }
      else if (choice != 4) {
         printf("\nInvalid choice. Please try again.");
      }
   }

   free(phonebook);

   return 0;
}