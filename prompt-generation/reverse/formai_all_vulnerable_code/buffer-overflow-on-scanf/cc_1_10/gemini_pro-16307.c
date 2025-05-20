//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
  char name[50];
  char phone_number[20];
} contact;

// Define the phone book
contact phone_book[MAX_CONTACTS];

// Get the number of contacts in the phone book
int get_num_contacts() {
  int num_contacts = 0;
  FILE *fp = fopen("phone_book.txt", "r");
  if (fp != NULL) {
    while (fgets(phone_book[num_contacts].name, 50, fp) != NULL) {
      fgets(phone_book[num_contacts].phone_number, 20, fp);
      num_contacts++;
    }
    fclose(fp);
  }
  return num_contacts;
}

// Print the phone book
void print_phone_book(int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    printf("%s %s\n", phone_book[i].name, phone_book[i].phone_number);
  }
}

// Add a contact to the phone book
void add_contact(char *name, char *phone_number) {
  int num_contacts = get_num_contacts();
  FILE *fp = fopen("phone_book.txt", "a");
  if (fp != NULL) {
    fprintf(fp, "%s\n%s\n", name, phone_number);
    fclose(fp);
  }
}

// Delete a contact from the phone book
void delete_contact(char *name) {
  int num_contacts = get_num_contacts();
  FILE *fp = fopen("phone_book.txt", "r");
  if (fp != NULL) {
    FILE *fp_new = fopen("phone_book_new.txt", "w");
    if (fp_new != NULL) {
      for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) != 0) {
          fprintf(fp_new, "%s\n%s\n", phone_book[i].name, phone_book[i].phone_number);
        }
      }
      fclose(fp_new);
    }
    fclose(fp);
    remove("phone_book.txt");
    rename("phone_book_new.txt", "phone_book.txt");
  }
}

// Search for a contact in the phone book
void search_contact(char *name) {
  int num_contacts = get_num_contacts();
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Found contact: %s %s\n", phone_book[i].name, phone_book[i].phone_number);
      return;
    }
  }
  printf("Contact not found.\n");
}

// Main function
int main() {
  int choice;
  char name[50];
  char phone_number[20];

  // Get the number of contacts in the phone book
  int num_contacts = get_num_contacts();

  do {
    // Display the menu
    printf("\nPhone Book Management System\n");
    printf("1. Print Phone Book\n");
    printf("2. Add Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        print_phone_book(num_contacts);
        break;
      case 2:
        printf("Enter the contact name: ");
        scanf(" %[^\n]", name);
        printf("Enter the contact phone number: ");
        scanf(" %[^\n]", phone_number);
        add_contact(name, phone_number);
        num_contacts = get_num_contacts();
        break;
      case 3:
        printf("Enter the contact name: ");
        scanf(" %[^\n]", name);
        delete_contact(name);
        num_contacts = get_num_contacts();
        break;
      case 4:
        printf("Enter the contact name: ");
        scanf(" %[^\n]", name);
        search_contact(name);
        break;
      case 5:
        printf("Thank you for using the Phone Book Management System.\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}