//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Phone Book structure
typedef struct phone_book {
  char name[50];
  char number[20];
} PhoneBook;

// Declare the Phone Book array
PhoneBook phone_book[100];

// Function to add a contact to the Phone Book
void add_contact(int index) {
  printf("Enter the name of the contact: ");
  scanf("%s", phone_book[index].name);
  printf("Enter the number of the contact: ");
  scanf("%s", phone_book[index].number);
}

// Function to search for a contact in the Phone Book
void search_contact(char *name) {
  int i;
  for (i = 0; i < 100; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Contact found!\n");
      printf("Name: %s\n", phone_book[i].name);
      printf("Number: %s\n", phone_book[i].number);
      return;
    }
  }
  printf("Contact not found!\n");
}

// Function to delete a contact from the Phone Book
void delete_contact(char *name) {
  int i;
  for (i = 0; i < 100; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Contact deleted!\n");
      phone_book[i].name[0] = '\0';
      phone_book[i].number[0] = '\0';
      return;
    }
  }
  printf("Contact not found!\n");
}

// Function to print the Phone Book
void print_phone_book() {
  int i;
  for (i = 0; i < 100; i++) {
    if (strlen(phone_book[i].name) > 0) {
      printf("%s\n", phone_book[i].name);
      printf("%s\n", phone_book[i].number);
    }
  }
}

// Main function
int main() {
  int choice;
  char name[50];

  // Welcome message
  printf("Welcome to the Phone Book!\n");

  // Loop until the user chooses to quit
  while (1) {
    // Display the menu
    printf("\n1. Add a contact\n");
    printf("2. Search for a contact\n");
    printf("3. Delete a contact\n");
    printf("4. Print the Phone Book\n");
    printf("5. Quit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        add_contact(0);
        break;
      case 2:
        printf("Enter the name of the contact you want to search for: ");
        scanf("%s", name);
        search_contact(name);
        break;
      case 3:
        printf("Enter the name of the contact you want to delete: ");
        scanf("%s", name);
        delete_contact(name);
        break;
      case 4:
        print_phone_book();
        break;
      case 5:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}