//FormAI DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

struct User {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};
typedef struct User user;

user database[MAX_USERS];
int userCount = 0;

void saveUser(user newUser) { // Adds user to database
  if(userCount >= MAX_USERS) {
    printf("Error: cannot add more users to database\n");
    return;
  }

  database[userCount] = newUser;
  userCount++;
}

void displayDatabase() { // Displays all users in database
  if(userCount == 0) {
    printf("Database is empty\n");
    return;
  }

  printf("Database:\n");
  for(int i=0; i<userCount; i++) {
    printf("  Username: %s   Password: %s\n",
      database[i].username, database[i].password);
  }
}

int main() {
  // Uncomment these lines to test database display function
  //displayDatabase();
  //return 0;

  printf("Welcome to Password Management Program!\n");
  printf("Here, you can add new users with their respective passwords.\n");

  while(1) {
    printf("\nEnter the username (max length %d): ", MAX_PASSWORD_LENGTH-1);
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    printf("Enter the password (max length %d): ", MAX_PASSWORD_LENGTH-1);
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    user newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);

    saveUser(newUser);
    printf("User added to database successfully!\n");

    printf("\nWould you like to add another user? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'n') {
      displayDatabase(); // Displays all users in database
      return 0;
    }
  }
}