//FormAI DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EmailList {
   char name[50];
   char email[100];
};

void addEmailToList(struct EmailList *list, int *size);
void removeEmailFromList(struct EmailList *list, int *size);
void showEmailList(struct EmailList *list, int size);

int main() {
   struct EmailList *list;
   int size = 0, choice;

   printf("Welcome to the Email List Manager!\n\n");

   do {
      printf("Please choose an option:\n");
      printf("[1] Add email to list\n");
      printf("[2] Remove email from list\n");
      printf("[3] Show email list\n");
      printf("[4] Exit\n");
      printf("Choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            addEmailToList(list, &size);
            break;
         case 2:
            removeEmailFromList(list, &size);
            break;
         case 3:
            showEmailList(list, size);
            break;
         case 4:
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid choice, please try again.\n");
      }
   } while(choice != 4);

   return 0;
}

void addEmailToList(struct EmailList *list, int *size) {
   char name[50], email[100];
   printf("Enter name: ");
   scanf(" %[^\n]s", name);
   printf("Enter email: ");
   scanf(" %s", email);

   if(*size == 0) {
      list = malloc(sizeof(struct EmailList));
   } else {
      list = realloc(list, (*size+1)*sizeof(struct EmailList));
   }

   strcpy(list[*size].name, name);
   strcpy(list[*size].email, email);

   printf("Email added to list!\n\n");

   (*size)++;
}

void removeEmailFromList(struct EmailList *list, int *size) {
   char email[100];
   int i, found = 0;

   if(*size == 0) {
      printf("No emails in list.\n\n");
      return;
   }

   printf("Enter email to remove: ");
   scanf(" %s", email);

   for(i = 0; i < *size; i++) {
      if(strcmp(list[i].email, email) == 0) {
         found = 1;
         break;
      }
   }

   if(found) {
      for(; i < *size-1; i++) {
         strcpy(list[i].name, list[i+1].name);
         strcpy(list[i].email, list[i+1].email);
      }

      (*size)--;
      list = realloc(list, *size*sizeof(struct EmailList));
      printf("Email removed from list!\n\n");
   } else {
      printf("Email not found.\n\n");
   }
}

void showEmailList(struct EmailList *list, int size) {
   int i;

   if(size == 0) {
      printf("No emails in list.\n\n");
      return;
   }

   printf("Email List:\n");
   for(i = 0; i < size; i++) {
      printf("%d. %s (%s)\n", i+1, list[i].name, list[i].email);
   }
   printf("\n");
}