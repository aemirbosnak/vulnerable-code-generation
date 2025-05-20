//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
   char name[MAX_NAME_LEN];
   char email[MAX_EMAIL_LEN];
} Contact;

int main() {
   int numContacts = 0;
   Contact* mailingList = NULL; // will be dynamically allocated
   char choice = ' ';

   printf("Mailing List Manager\n");
   printf("====================\n");

   while (choice != 'q') {
      printf("\nMenu:\n");
      printf("a) Add contact\n");
      printf("d) Delete contact\n");
      printf("l) List contacts\n");
      printf("q) Quit\n");
      printf("Enter choice: ");
      scanf(" %c", &choice);

      switch (choice) {
         case 'a':
            // Add a new contact
            mailingList = (Contact*)realloc(mailingList, (numContacts+1)*sizeof(Contact));
            printf("\nEnter name: ");
            scanf(" %s", mailingList[numContacts].name);
            printf("\nEnter email: ");
            scanf(" %s", mailingList[numContacts].email);
            numContacts++;
            printf("\nContact added!\n");
            break;

         case 'd':
            // Delete a contact
            if (numContacts == 0) {
               printf("\nNo contacts to delete\n");
            } else {
               char name[MAX_NAME_LEN];
               int found = 0;

               printf("\nEnter name to delete: ");
               scanf(" %s", name);

               for (int i=0; i<numContacts; i++) {
                  if (strcmp(name, mailingList[i].name) == 0) {
                     found = 1;
                     for (int j=i; j<numContacts-1; j++) {
                        mailingList[j] = mailingList[j+1];
                     }
                     numContacts--;
                     mailingList = (Contact*)realloc(mailingList, numContacts*sizeof(Contact));
                     printf("\nContact deleted!\n");
                     break;
                  }
               }

               if (!found) {
                  printf("\nContact not found\n");
               }
            }
            break;

         case 'l':
            // List all contacts
            if (numContacts == 0) {
               printf("\nNo contacts to list\n");
            } else {
               printf("\nContacts:\n");
               for (int i=0; i<numContacts; i++) {
                  printf("%s (%s)\n", mailingList[i].name, mailingList[i].email);
               }
            }
            break;

         case 'q':
            // Quit the program
            printf("\nGoodbye!\n");
            free(mailingList); // remember to free dynamically allocated memory!
            break;

         default:
            printf("\nInvalid choice. Try again.\n");
            break;
      }
   }

   return 0;
}