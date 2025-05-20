//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 30

struct Password {
   char website[MAX_LENGTH];
   char username[MAX_LENGTH];
   char password[MAX_LENGTH];
};

void savePasswords(struct Password passwords[]) {
   FILE *fp;

   fp = fopen("passwords.txt", "w");

   if (fp == NULL) {
      printf("Error opening file\n");
      return;
   }

   for (int i = 0; i < MAX_PASSWORDS; i++) {
      fprintf(fp, "%s:%s:%s\n", 
         passwords[i].website, 
         passwords[i].username, 
         passwords[i].password);
   }

   fclose(fp);
}

void readPasswords(struct Password passwords[]) {
   FILE *fp;

   fp = fopen("passwords.txt", "r");

   if (fp == NULL) {
      printf("No passwords found\n");
      return;
   }

   char line[MAX_LENGTH*3];
   int i = 0;

   while (fgets(line, MAX_LENGTH*3, fp) != NULL) {
      char *website = strtok(line, ":");
      char *username = strtok(NULL, ":");
      char *password = strtok(NULL, "\n");

      strcpy(passwords[i].website, website);
      strcpy(passwords[i].username, username);
      strcpy(passwords[i].password, password);
      i++;
   }

   fclose(fp);
}

void addPassword(struct Password passwords[]) {
   for (int i = 0; i < MAX_PASSWORDS; i++) {
      if (passwords[i].website[0] == '\0') {
         printf("Website: ");
         scanf("%s", passwords[i].website);

         printf("Username: ");
         scanf("%s", passwords[i].username);

         printf("Password: ");
         scanf("%s", passwords[i].password);

         printf("Password added successfully!\n");
         return;
      }
   }
   printf("Maximum number of passwords reached!\n");
}

void searchPasswords(struct Password passwords[]) {
   char website[MAX_LENGTH];
   printf("Website to search: ");
   scanf("%s", website);

   for (int i = 0; i < MAX_PASSWORDS; i++) {
      if (strcmp(passwords[i].website, website) == 0) {
         printf("Website: %s\n", passwords[i].website);
         printf("Username: %s\n", passwords[i].username);
         printf("Password: %s\n", passwords[i].password);
         return;
      }
   }
   printf("Password not found!\n");
}

int main() {
   char option;

   struct Password passwords[MAX_PASSWORDS];

   readPasswords(passwords);

   do {
      printf("\n1 - Add password\n");
      printf("2 - Search password\n");
      printf("3 - Exit\n");

      printf("\nEnter option: ");
      scanf("%c", &option);
      getchar(); // Clears buffer

      switch(option) {
         case '1':
            addPassword(passwords);
            break;
         case '2':
            searchPasswords(passwords);
            break;
         case '3':
            savePasswords(passwords);
            printf("Exiting...\n");
            break;
         default:
            printf("Invalid option, try again.\n");
            break;
      }
   } while (option != '3');

   return 0;
}