//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 40
#define MAX_EMAIL_LENGTH 50
#define MAX_MEMBERS 1000

typedef struct {
   char name[MAX_NAME_LENGTH];
   char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
   Member members[MAX_MEMBERS];
   int count;
} MailingList;

void printMenu() {
   printf("\nMENU\n");
   printf("1. Add member\n");
   printf("2. Remove member\n");
   printf("3. List all members\n");
   printf("4. Search for a member\n");
   printf("5. Quit\n");
}

void addMember(MailingList *list) {
   if (list->count == MAX_MEMBERS) {
      printf("Error: the list is full.\n");
      return;
   }

   char name[MAX_NAME_LENGTH];
   printf("Enter the member's name (max %d characters): ", MAX_NAME_LENGTH);
   scanf("%s", name);

   char email[MAX_EMAIL_LENGTH];
   printf("Enter the member's email (max %d characters): ", MAX_EMAIL_LENGTH);
   scanf("%s", email);

   Member member;
   strcpy(member.name, name);
   strcpy(member.email, email);

   list->members[list->count++] = member;

   printf("Member added to the list.\n");
}

void removeMember(MailingList *list) {
   if (list->count == 0) {
      printf("Error: the list is empty.\n");
      return;
   }

   char name[MAX_NAME_LENGTH];
   printf("Enter the name of the member to remove: ");
   scanf("%s", name);

   int indexToRemove = -1;
   for (int i = 0; i < list->count; i++) {
      if (strcmp(list->members[i].name, name) == 0) {
         indexToRemove = i;
         break;
      }
   }

   if (indexToRemove == -1) {
      printf("Error: member not found.\n");
      return;
   }

   for (int i = indexToRemove; i < list->count - 1; i++) {
      list->members[i] = list->members[i + 1];
   }

   list->count--;

   printf("Member removed from the list.\n");
}

void listMembers(MailingList *list) {
   if (list->count == 0) {
      printf("The list is empty.\n");
      return;
   }

   printf("Members of the mailing list:\n");

   for (int i = 0; i < list->count; i++) {
      printf("%s (%s)\n", list->members[i].name, list->members[i].email);
   }
}

void searchMember(MailingList *list) {
   if (list->count == 0) {
      printf("The list is empty.\n");
      return;
   }

   char name[MAX_NAME_LENGTH];
   printf("Enter the name of the member to find: ");
   scanf("%s", name);

   for (int i = 0; i < list->count; i++) {
      if (strcmp(list->members[i].name, name) == 0) {
         printf("%s (%s)\n", list->members[i].name, list->members[i].email);
         return;
      }
   }

   printf("Error: member not found.\n");
}

int main() {
   MailingList list = { {}, 0 };

   int choice = 0;
   do {
      printMenu();
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1: addMember(&list); break;
      case 2: removeMember(&list); break;
      case 3: listMembers(&list); break;
      case 4: searchMember(&list); break;
      case 5: break;
      default: printf("Error: invalid choice.\n");
      }
   } while (choice != 5);

   return 0;
}