//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
  char name[50];
  char phone[15];
  char email[50];
};

int main() {

  int choice, option, index, count = 0; 
  
  struct Contact contacts[100]; 
  
  while (1) {
    printf("Welcome to Your Phone Book!\n");
    printf("1. Add new contact\n");
    printf("2. Edit a contact\n");
    printf("3. Delete a contact\n");
    printf("4. Search for a contact\n");
    printf("5. Display all contacts\n");
    printf("6. Exit the program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: 
        printf("\nAdding new contact\n");
        printf("Enter name: ");
        scanf("%s", contacts[count].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[count].phone);
        printf("Enter email: ");
        scanf("%s", contacts[count].email);
        printf("\nNew contact added successfully!\n\n");
        count++;
        break;

      case 2: 
        if (count == 0) {
          printf("\nNo contacts available\n\n");
          break;
        }
        printf("\nEditing a contact\n");
        printf("Enter index of contact to edit: ");
        scanf("%d", &index);
        if (index >= count) {
          printf("\nInvalid index, please try again.\n\n");
          break;
        }
        printf("1. Edit name\n");
        printf("2. Edit phone number\n");
        printf("3. Edit email\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
          case 1:
            printf("Enter new name: ");
            scanf("%s", contacts[index].name);
            printf("\nContact updated successfully!\n\n");
            break;
          case 2:
            printf("Enter new phone number: ");
            scanf("%s", contacts[index].phone);
            printf("\nContact updated successfully!\n\n");
            break;
          case 3:
            printf("Enter new email: ");
            scanf("%s", contacts[index].email);
            printf("\nContact updated successfully!\n\n");
            break;
          default:
            printf("\nInvalid option, please try again.\n\n");
            break;
        }
        break;

      case 3: 
        if (count == 0) {
          printf("\nNo contacts available\n\n");
          break;
        }
        printf("\nDeleting a contact\n");
        printf("Enter index of contact to delete: ");
        scanf("%d", &index);
        if (index >= count) {
          printf("\nInvalid index, please try again.\n\n");
          break;
        }
        for (int i = index; i < count - 1; i++) {
          strcpy(contacts[i].name, contacts[i+1].name);
          strcpy(contacts[i].phone, contacts[i+1].phone);
          strcpy(contacts[i].email, contacts[i+1].email);
        }
        printf("\nContact deleted successfully!\n\n");
        count--;
        break;

      case 4: 
        if (count == 0) {
          printf("\nNo contacts available\n\n");
          break;
        }
        printf("\nSearching for a contact\n");
        printf("Enter name or phone number to search: ");
        char search[50];
        scanf("%s", search);
        int found = 0;
        for (int i = 0; i < count; i++) {
          if (strcmp(search, contacts[i].name) == 0 || strcmp(search, contacts[i].phone) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone);
            printf("Email: %s\n\n", contacts[i].email);
            found = 1;
          }
        }
        if (!found) {
          printf("\nNo matching contacts found\n\n");
        }
        break;

      case 5: 
        if (count == 0) {
          printf("\nNo contacts available\n\n");
          break;
        }
        printf("\nDisplaying all contacts\n");
        for (int i = 0; i < count; i++) {
          printf("Name: %s\n", contacts[i].name);
          printf("Phone Number: %s\n", contacts[i].phone);
          printf("Email: %s\n\n", contacts[i].email);
        }
        break;

      case 6: 
        printf("\nThank you for using our Phone Book!\n");
        exit(0);

      default:
        printf("\nInvalid choice, please try again.\n\n");
        break;
    }
  }

  return 0;
}