//FormAI DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define a structure for a phonebook entry */
typedef struct {
   char name[50];
   char phone[20];
   char email[50];
} PhoneBookEntry;

int main() {
   int num_entries;
   PhoneBookEntry *phonebook;

   /* get the number of entries from the user */
   printf("Enter the number of phone book entries: ");
   scanf("%d", &num_entries);

   /* allocate memory for the phonebook array */
   phonebook = (PhoneBookEntry*)malloc(num_entries * sizeof(PhoneBookEntry));

   /* get the information for each entry */
   for(int i = 0; i < num_entries; i++) {
      printf("\nEntry %d:\n", i+1);

      /* read in the name */
      printf("Name: ");
      scanf("%s", phonebook[i].name);

      /* read in the phone number */
      printf("Phone: ");
      scanf("%s", phonebook[i].phone);

      /* read in the email address */
      printf("Email: ");
      scanf("%s", phonebook[i].email);
   }

   /* display the phonebook entries */
   printf("\nPhonebook Entries:\n");
   for(int i = 0; i < num_entries; i++) {
      printf("\nEntry %d:\n", i+1);
      printf("Name: %s\n", phonebook[i].name);
      printf("Phone: %s\n", phonebook[i].phone);
      printf("Email: %s\n", phonebook[i].email);
   }

   /* free the memory used by the phonebook */
   free(phonebook);

   return 0;
}