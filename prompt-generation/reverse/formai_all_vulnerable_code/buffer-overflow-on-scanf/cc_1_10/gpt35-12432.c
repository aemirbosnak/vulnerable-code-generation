//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct User {
  char name[20];
  char password[MAX_PASSWORD_LENGTH + 1];
} User;

typedef struct Database {
  User users[MAX_USERS];
  int num_users;
} Database;

void menu() {
  printf("\nWelcome to Password Management System\n");
  printf("------------------------------------\n");
  printf("1. Add user\n");
  printf("2. View users\n");
  printf("3. Update user password\n");
  printf("4. Delete user\n");
  printf("5. Exit\n");
}

int get_password_strength(char *password) {
  int length = strlen(password);
  int strength = 0;

  if (length < 8) {
    strength = 1;
  } else if (length < 12) {
    strength = 2;
  } else {
    strength = 3;
  }

  int num_digits = 0;
  int num_lower = 0;
  int num_upper = 0;

  for (int i = 0; i < length; i++) {
    char c = password[i];
    if (c >= '0' && c <= '9') {
      num_digits++;
    } else if (c >= 'a' && c <= 'z') {
      num_lower++;
    } else if (c >= 'A' && c <= 'Z') {
      num_upper++;
    }
  }

  if (num_digits >= 2) {
    strength++;
  } 
  
  if (num_lower >= 2) {
    strength++;
  }

  if (num_upper >= 2) {
    strength++;
  }

  return strength;
}

void add_user(Database *db) {
  if (db->num_users >= MAX_USERS) {
    printf("Error: database is full\n");
    return;
  }

  User user;
  
  printf("\nEnter user name: ");
  scanf("%s", user.name);
  
  printf("Enter password: ");
  scanf("%s", user.password);

  int strength = get_password_strength(user.password);

  if (strength < 2) {
    printf("Error: password is too weak\n");
    return;
  }

  strcpy(db->users[db->num_users].name, user.name);
  strcpy(db->users[db->num_users].password, user.password);

  db->num_users++;

  printf("User added successfully!\n");
}

void view_users(Database *db) {
  printf("\nUsers in database:\n");
  printf("---------------------------\n");
  for (int i = 0; i < db->num_users; i++) {
    printf("%d. %s\n", i+1, db->users[i].name);
  }
}

void update_password(Database *db) {
  printf("\nEnter user name to update password: ");
  char name[20];
  scanf("%s", name);

  int idx = -1;
  for (int i = 0; i < db->num_users; i++) {
    if (strcmp(db->users[i].name, name) == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    printf("Error: user not found\n");
    return;
  }

  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter new password: ");
  scanf("%s", password);

  int strength = get_password_strength(password);

  if (strength < 2) {
    printf("Error: password is too weak\n");
    return;
  }

  strcpy(db->users[idx].password, password);

  printf("Password updated successfully for user: %s\n", name);
}

void delete_user(Database *db) {
  printf("\nEnter user name to delete: ");
  char name[20];
  scanf("%s", name);

  int idx = -1;
  for (int i = 0; i < db->num_users; i++) {
    if (strcmp(db->users[i].name, name) == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    printf("Error: user not found\n");
    return;
  }

  for (int i = idx; i < db->num_users-1; i++) {
    strcpy(db->users[i].name, db->users[i+1].name);
    strcpy(db->users[i].password, db->users[i+1].password);
  }

  db->num_users--;

  printf("User deleted successfully: %s\n", name);
}

void clean_stdin() {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

int main() {
  Database db = {0};

  while (1) {
    menu();

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_user(&db);
        break;
      case 2:
        view_users(&db);
        break;
      case 3:
        update_password(&db);
        break;
      case 4:
        delete_user(&db);
        break;
      case 5:
        printf("\nThank you for using the Password Management System.\n");
        return 0;
      default:
        printf("\nInvalid choice. Please select a valid option.\n");
        break;
    }

    clean_stdin();
  }
  return 0;
}