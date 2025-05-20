//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Maximum number of passwords

struct password {
  char website[50];
  char username[20];
  char password[20];
}; // Defining a new struct called password

void encrypt(char *str) {
  for(int i = 0; i < strlen(str); i++) {
    str[i] += 3;
  }
} // Encrypt function to encrypt the passwords

void decrypt(char *str) {
  for(int i = 0; i < strlen(str); i++) {
    str[i] -= 3;
  }
} // Decrypt function to decrypt the passwords

int main() {
  struct password passwords[MAX];
  int num_passwords = 0;
  int choice;

  while(1) {
    printf("\nPassword Management System\n");
    printf("==========================\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter details for password %d:\n", num_passwords + 1);
        printf("Website: ");
        scanf("%s", passwords[num_passwords].website);
        printf("Username: ");
        scanf("%s", passwords[num_passwords].username);
        printf("Password: ");
        scanf("%s", passwords[num_passwords].password);
        encrypt(passwords[num_passwords].password);
        num_passwords++;
        printf("\nPassword added successfully!\n");
        break;
      case 2:
        if(num_passwords == 0) {
          printf("\nNo passwords to display.\n");
        } else {
          printf("\nAll Passwords:\n");
          for(int i = 0; i < num_passwords; i++) {
            printf("====================\n");
            printf("Website: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            decrypt(passwords[i].password);
            printf("Password: %s\n", passwords[i].password);
            encrypt(passwords[i].password);
            printf("====================\n");
          }
        }
        break;
      case 3:
        if(num_passwords == 0) {
          printf("\nNo passwords to search for.\n");
        } else {
          char search_website[50];
          printf("\nEnter website to search for: ");
          scanf("%s", search_website);
          int found = 0;
          for(int i = 0; i < num_passwords; i++) {
            if(strcmp(search_website, passwords[i].website) == 0) {
              printf("====================\n");
              printf("Website: %s\n", passwords[i].website);
              printf("Username: %s\n", passwords[i].username);
              decrypt(passwords[i].password);
              printf("Password: %s\n", passwords[i].password);
              encrypt(passwords[i].password);
              printf("====================\n");
              found = 1;
              break;
            }
          }
          if(found == 0) {
            printf("\nPassword not found for website %s.\n", search_website);
          }
        }
        break;
      case 4:
        if(num_passwords == 0) {
          printf("\nNo passwords to delete.\n");
        } else {
          char delete_website[50];
          printf("\nEnter website to delete: ");
          scanf("%s", delete_website);
          int found = 0;
          for(int i = 0; i < num_passwords; i++) {
            if(strcmp(delete_website, passwords[i].website) == 0) {
              for(int j = i; j < num_passwords - 1; j++) {
                strcpy(passwords[j].website, passwords[j+1].website);
                strcpy(passwords[j].username, passwords[j+1].username);
                strcpy(passwords[j].password, passwords[j+1].password);
              }
              num_passwords--;
              found = 1;
              printf("\nPassword for website %s deleted successfully.\n", delete_website);
              break;
            }
          }
          if(found == 0) {
            printf("\nPassword not found for website %s.\n", delete_website);
          }
        }
        break;
      case 5:
        printf("\nExiting program...\n");
        exit(0);
      default:
        printf("\nInvalid choice. Please choose a valid option.\n");
        break;
    }
  }

  return 0;
}