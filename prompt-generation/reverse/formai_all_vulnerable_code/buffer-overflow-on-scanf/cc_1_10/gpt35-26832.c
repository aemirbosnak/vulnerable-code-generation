//FormAI DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct mailing_list {
  char name[50];
  char email[50];
  struct mailing_list* next;
};

struct mailing_list* head = NULL;

void add_to_list(char* name, char* email) {
  struct mailing_list* current = head;
  struct mailing_list* new_node = malloc(sizeof(struct mailing_list));
  if (new_node == NULL) {
    printf("Error: Memory allocation failure\n");
    return;
  }
  strcpy(new_node->name, name);
  strcpy(new_node->email, email);
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
    printf("Added %s to the mailing list with email %s.\n", name, email);
    return;
  }
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  printf("Added %s to the mailing list with email %s.\n", name, email);
}

void print_list() {
  struct mailing_list* current = head;
  if (head == NULL) {
    printf("No one is currently on the mailing list.\n");
    return;
  }
  printf("Current Mailing List:\n");
  while (current != NULL) {
    printf("Name: %s\nEmail: %s\n", current->name, current->email);
    current = current->next;
  }
}

void delete_from_list(char* email) {
  struct mailing_list* current = head;
  struct mailing_list* temp = NULL;
  if (head == NULL) {
    printf("No one is currently on the mailing list.\n");
    return;
  }
  if (strcmp(head->email, email) == 0) {
    temp = head;
    head = head->next;
    free(temp);
    printf("%s has been removed from the mailing list.\n", email);
    return;
  }
  while (current->next != NULL) {
    if (strcmp(current->next->email, email) == 0) {
      temp = current->next;
      current->next = temp->next;
      free(temp);
      printf("%s has been removed from the mailing list.\n", email);
      return;
    }
    current = current->next;
  }
  printf("%s is not on the mailing list.\n", email);
}

int main() {
  printf("Welcome to Ye Olde Mailing List Manager!\n");
  while(1) {
    printf("\nPlease choose an option:\n");
    printf("1. Add someone to the mailing list.\n");
    printf("2. Remove someone from the mailing list.\n");
    printf("3. View the current mailing list.\n");
    printf("4. Quit the program and send the ravens.\n");
    char name[50];
    char email[50];
    int choice;
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("What is the name of the person to be added to the mailing list?\n");
        scanf("%s", name);
        printf("What is the email of the person to be added to the mailing list?\n");
        scanf("%s", email);
        add_to_list(name, email);
        break;
      case 2:
        printf("Please enter the email of the person to remove from the mailing list:\n");
        scanf("%s", email);
        delete_from_list(email);
        break;
      case 3:
        print_list();
        break;
      case 4:
        printf("Farewell, and trust in the old gods and the new.\n");
        return 0;
      default:
        printf("Invalid option. Please try again.\n");
    }
  }
}