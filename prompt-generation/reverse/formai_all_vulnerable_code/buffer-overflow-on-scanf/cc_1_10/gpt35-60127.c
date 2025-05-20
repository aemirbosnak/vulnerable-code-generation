//FormAI DATASET v1.0 Category: System administration ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define MAX_USERS 10

typedef struct {
  char username[MAX_LEN];
  char password[MAX_LEN];
  int isAdmin;
} User;

User users[MAX_USERS];
int numUsers = 0;

void login()
{
  char newUser[MAX_LEN];
  char newPassword[MAX_LEN];

  printf("Enter username: ");
  scanf("%s", newUser);
  printf("Enter password: ");
  scanf("%s", newPassword);

  int foundUser = 0;
  for(int i = 0; i < numUsers; i++) {
    if(strcmp(users[i].username, newUser) == 0) {
      foundUser = 1;
      if(strcmp(users[i].password, newPassword) == 0) {
        printf("Welcome %s!\n", users[i].username);
        if(users[i].isAdmin) {
          printf("You are an admin.\n");
        }
      } else {
        printf("Wrong password.\n");
      }
      break;
    }
  }

  if(!foundUser) {
    printf("User %s not found.\n", newUser);
  }
}

void createUser()
{
  if(numUsers >= MAX_USERS) {
    printf("Maximum number of users reached.\n");
    return;
  }

  char newUser[MAX_LEN];
  char newPassword[MAX_LEN];
  char isAdminInput[MAX_LEN];

  printf("Enter new username: ");
  scanf("%s", newUser);
  printf("Enter new password: ");
  scanf("%s", newPassword);
  printf("Is the new user an admin? (y/n): ");
  scanf("%s", isAdminInput);

  int isAdmin = 0;
  if(strcmp(isAdminInput, "y") == 0 || strcmp(isAdminInput, "yes") == 0) {
    isAdmin = 1;
  }

  User newUserObj;
  strcpy(newUserObj.username, newUser);
  strcpy(newUserObj.password, newPassword);
  newUserObj.isAdmin = isAdmin;

  users[numUsers] = newUserObj;
  numUsers++;

  printf("User %s created successfully.\n", newUser);
}

int main()
{
  while(1) {
    int option;
    printf("Choose an option:\n");
    printf("1. Login\n");
    printf("2. Create new user\n");
    printf("3. Exit\n");
    scanf("%d", &option);

    switch(option) {
      case 1:
        login();
        break;
      case 2:
        createUser();
        break;
      case 3:
        printf("Exiting...\n");
        exit(0);
        break;
      default:
        printf("Invalid option. Try again.\n");
        break;
    }
  }
  
  return 0;
}