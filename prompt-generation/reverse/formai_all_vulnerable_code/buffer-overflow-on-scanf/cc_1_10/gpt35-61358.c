//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_LENGTH 100

struct contact {
   char name[MAX_NAME_LENGTH];
   char email[MAX_EMAIL_LENGTH];
};

struct mailing_list {
   struct contact contacts[MAX_LIST_LENGTH];
   int count;
};

void add_contact(struct mailing_list *list, char *name, char *email) {
   if (list->count < MAX_LIST_LENGTH) {
      struct contact *contact_ptr = &list->contacts[list->count];
      strncpy(contact_ptr->name, name, MAX_NAME_LENGTH);
      strncpy(contact_ptr->email, email, MAX_EMAIL_LENGTH);
      list->count++;
      printf("\nContact added successfully!");
   } else {
      printf("\nError: Mailing list is full.");
   }
}

void remove_contact(struct mailing_list *list, char *name) {
   int index = -1;
   for (int i = 0; i < list->count; i++) {
      if (strcmp(list->contacts[i].name, name) == 0) {
         index = i;
         break;
      }
   }
   if (index != -1) {
      for (int i = index; i < list->count - 1; i++) {
         list->contacts[i] = list->contacts[i+1];
      }
      list->count--;
      printf("\nContact removed successfully!");
   } else {
      printf("\nError: Contact not found.");
   }
}

void print_list(struct mailing_list *list) {
   printf("\nMailing List:\n");
   for (int i = 0; i < list->count; i++) {
      printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
   }
   printf("\n");
}

int main() {
   struct mailing_list list = {0};

   while (1) {
      char input;
      char name[MAX_NAME_LENGTH];
      char email[MAX_EMAIL_LENGTH];

      printf("\nA) Add contact\nR) Remove contact\nP) Print list\nQ) Quit\n");
      printf("Enter a choice: ");
      scanf(" %c", &input);

      switch(input) {
         case 'A': case 'a':
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(&list, name, email);
            break;

         case 'R': case 'r':
            printf("\nEnter name: ");
            scanf("%s", name);
            remove_contact(&list, name);
            break;

         case 'P': case 'p':
            print_list(&list);
            break;

         case 'Q': case 'q':
            printf("\nGoodbye!\n");
            exit(0);

         default:
            printf("\nInvalid choice.");
            break;
      }
   }
   return 0;
}