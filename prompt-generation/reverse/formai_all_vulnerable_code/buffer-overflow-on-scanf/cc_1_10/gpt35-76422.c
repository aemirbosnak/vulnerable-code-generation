//FormAI DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 16
#define MAX_USERNAME_LENGTH 20

typedef struct User {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} User;

typedef struct Node {
  User user;
  struct Node* next;
} Node;

Node* head = NULL;

void display_menu() {
  printf("Welcome to the Password Management System!\n");
  printf("1. Create an account\n");
  printf("2. Login to an existing account\n");
  printf("3. Display all accounts\n");
  printf("4. Delete an account\n");
  printf("5. Exit\n");
  printf("Choose an option: ");
}

Node* create_node(User user) {
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->user = user;
  new_node->next = NULL;
  return new_node;
}

void insert_node(User user) {
  Node* new_node = create_node(user);
  if (head == NULL) {
    head = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
}

void create_account() {
  User user;
  printf("Enter a username (max 20 characters): ");
  scanf("%s", user.username);
  printf("Enter a password (must be at least 10 characters long): ");
  scanf("%s", user.password);
  while (strlen(user.password) < 10) {
    printf("Password not long enough. Enter a password (must be at least 10 characters long): ");
    scanf("%s", user.password);
  }
  insert_node(user);
  printf("Account created successfully.\n\n");
}

void display_all_accounts() {
  if (head == NULL) {
    printf("No accounts to display.\n\n");
    return;
  }
  printf("All accounts:\n");
  Node* current_node = head;
  while (current_node != NULL) {
    printf("Username: %s, Password: %s\n", current_node->user.username, current_node->user.password);
    current_node = current_node->next;
  }
  printf("\n");
}

void delete_account() {
  if (head == NULL) {
    printf("No accounts to delete.\n\n");
    return;
  }
  char username[MAX_USERNAME_LENGTH];
  printf("Enter the username for the account you want to delete: ");
  scanf("%s", username);
  Node* current_node = head;
  Node* previous_node = NULL;
  while (current_node != NULL) {
    if (strcmp(current_node->user.username, username) == 0) {
      if (previous_node == NULL) {
        head = current_node->next;
      } else {
        previous_node->next = current_node->next;
      }
      free(current_node);
      printf("Account deleted successfully.\n\n");
      return;
    }
    previous_node = current_node;
    current_node = current_node->next;
  }
  printf("Account not found.\n\n");
}

void login_attempt() {
  if (head == NULL) {
    printf("No accounts to log in to.\n\n");
    return;
  }
  char username[MAX_USERNAME_LENGTH];
  printf("Enter your username: ");
  scanf("%s", username);
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);
  Node* current_node = head;
  while (current_node != NULL) {
    if (strcmp(current_node->user.username, username) == 0 && strcmp(current_node->user.password, password) == 0) {
      printf("Login successful.\n\n");
      return;
    }
    current_node = current_node->next;
  }
  printf("Login failed.\n\n");
}

int main() {
  int option;
  do {
    display_menu();
    scanf("%d", &option);
    switch (option) {
      case 1:
        create_account();
        break;
      case 2:
        login_attempt();
        break;
      case 3:
        display_all_accounts();
        break;
      case 4:
        delete_account();
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid option. Please choose an option from the menu.\n\n");
        break;
    }
  } while (option != 5);
  return 0;
}