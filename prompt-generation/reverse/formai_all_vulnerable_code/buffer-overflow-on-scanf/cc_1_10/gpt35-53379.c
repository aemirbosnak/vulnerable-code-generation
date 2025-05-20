//FormAI DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Initialize a struct to store email data
typedef struct {
  char name[50];
  char email[50];
} Email;

// Function to add new emails to mailing list
void addEmail(Email* list, int count) {
  printf("Enter name: ");
  scanf("%s", list[count].name);
  printf("Enter email: ");
  scanf("%s", list[count].email);
  printf("Email added successfully!\n");
}

// Function to display all emails in mailing list
void displayEmails(Email* list, int count) {
  printf("Total emails: %d\n", count);
  printf("Name\t\t\tEmail\n");
  for(int i=0; i<count; i++) {
    printf("%s\t\t\t%s\n", list[i].name, list[i].email);
  }
}

int main() {
  int count = 0; // Initialize count of emails in mailing list
  Email list[100]; // Initialize array of email structs

  // Display options to user and listen for input
  while(1) {
    int choice;
    printf("\n1. Add new email\n");
    printf("2. Display all emails\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch(choice) {
      case 1:
        addEmail(list, count);
        count++;
        break;
      case 2:
        displayEmails(list, count);
        break;
      case 3:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}