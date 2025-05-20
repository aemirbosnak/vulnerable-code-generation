//FormAI DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100  // Maximum number of passwords that can be stored

struct Password {
   char site[20];
   char username[20];
   char password[20];
};

typedef struct Password Password;

void displayMenu() {
   printf("\nPassword Management System");
   printf("\n1. Add password entry");
   printf("\n2. View password entries");
   printf("\n3. Search for password");
   printf("\n4. Delete password entry");
   printf("\n5. Exit");
}

void addPasswordEntry(int *numPasswords, Password passwords[]){
   if (*numPasswords == MAX_PASSWORDS) {
      printf("\nMaximum number of passwords reached\n");
      return;
   }

   printf("\nEnter site: ");
   scanf("%s", passwords[*numPasswords].site);
   printf("\nEnter username: ");
   scanf("%s", passwords[*numPasswords].username);
   printf("\nEnter password: ");
   scanf("%s", passwords[*numPasswords].password);

   *numPasswords += 1;

   printf("\nPassword entry added successfully!\n");
}

void viewPasswordEntries(int numPasswords, Password passwords[]) {
   if (numPasswords == 0) {
      printf("\nNo passwords added yet\n");
      return;
   }

   printf("\nSite\t\tUsername\t\tPassword");
   printf("\n--------------------------------------------------\n");

   for (int i = 0; i < numPasswords; i++) {
      printf("%s\t\t%s\t\t\t%s\n", passwords[i].site, passwords[i].username, passwords[i].password);
   }
}

void searchPassword(int numPasswords, Password passwords[]) {
   if (numPasswords == 0) {
      printf("\nNo passwords added yet\n");
      return;
   }

   char site[20];
   printf("\nEnter site to search for: ");
   scanf("%s", site);

   for (int i = 0; i < numPasswords; i++) {
      if (strcmp(site, passwords[i].site) == 0) {
         printf("\nSite: %s\nUsername: %s\nPassword: %s\n", passwords[i].site,
                passwords[i].username, passwords[i].password);
         return;
      }
   }

   printf("\nPassword entry not found\n");   
}

void deletePasswordEntry(int *numPasswords, Password passwords[]) {
   if (*numPasswords == 0) {
      printf("\nNo passwords added yet\n");
      return;
   }

   char site[20];
   printf("\nEnter site to delete entry for: ");
   scanf("%s", site);

   for (int i = 0; i < *numPasswords; i++) {
      if (strcmp(site, passwords[i].site) == 0) {
         for (int j = i; j < *numPasswords - 1; j++) {
            strcpy(passwords[j].site, passwords[j+1].site);
            strcpy(passwords[j].username, passwords[j+1].username);
            strcpy(passwords[j].password, passwords[j+1].password);
         }

         *numPasswords -= 1;

         printf("\nPassword entry deleted successfully\n");
         return;
      }
   }

   printf("\nPassword entry not found\n");   
}

int main() {
   Password passwords[MAX_PASSWORDS];
   int numPasswords = 0;
   int choice;

   while (1) {
      displayMenu();
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            addPasswordEntry(&numPasswords, passwords);
            break;

         case 2:
            viewPasswordEntries(numPasswords, passwords);
            break;

         case 3:
            searchPassword(numPasswords, passwords);
            break;

         case 4:
            deletePasswordEntry(&numPasswords, passwords);
            break;

         case 5:
            exit(0);

         default:
            printf("\nInvalid choice\n");
            break;
      }   
   }

   return 0;
}