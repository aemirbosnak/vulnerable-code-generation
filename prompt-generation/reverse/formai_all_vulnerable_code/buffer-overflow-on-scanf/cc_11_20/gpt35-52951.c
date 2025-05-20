//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact {
   char name[30];
   char email[50];
   char phone[15];
};

int main() {
   int choice=0, contacts=0;
   struct contact *contact_list = NULL;
   
   printf("Welcome to C Phone Book!\n");
   printf("------------------------\n");

   while(choice!=4) {
      printf("What would you like to do?\n");
      printf("1. Add a contact\n");
      printf("2. Display all contacts\n");
      printf("3. Search for a contact\n");
      printf("4. Exit the program\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            //Adding a new contact
            contact_list = (struct contact*)realloc(contact_list, (contacts+1)*sizeof(struct contact));
            printf("Enter name: ");
            scanf("%s", contact_list[contacts].name);
            printf("Enter email: ");
            scanf("%s", contact_list[contacts].email);
            printf("Enter phone: ");
            scanf("%s", contact_list[contacts].phone);
            contacts++;
            break;

         case 2:
            //Displaying all contacts
            if (contacts==0)
               printf("Your phone book is empty!\n");
            else {
               printf("Name\tEmail\tPhone\n");
               printf("------------------------\n");
               for (int i=0; i<contacts; i++) {
                  printf("%s\t%s\t%s\n", contact_list[i].name, contact_list[i].email, contact_list[i].phone);
               }
               printf("------------------------\n");
            }
            break;

         case 3:
            //Searching for a particular contact
            if (contacts==0)
               printf("Your phone book is empty!\n");
            else {
               char search_name[30];
               printf("Enter the name to search for: ");
               scanf("%s", search_name);
               int found=0;
               for (int i=0; i<contacts; i++) {
                  if (strcmp(search_name, contact_list[i].name)==0) {
                     printf("Name\tEmail\tPhone\n");
                     printf("------------------------\n");
                     printf("%s\t%s\t%s\n", contact_list[i].name, contact_list[i].email, contact_list[i].phone);
                     printf("------------------------\n");
                     found=1;
                     break;
                  }
               }
               if (!found)
                  printf("Contact not found!\n");
            }
            break;

         case 4:
            //Exiting the program
            printf("Thank you for using C Phone Book! Goodbye.\n");
            break;

         default:
            printf("Invalid choice. Please try again!\n");
            break;
      }
   }

   free(contact_list);
   return 0;
}