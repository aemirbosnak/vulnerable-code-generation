//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000 // Maximum number of contacts that can be stored

struct Contacts {
  char name[50];
  char phone[15];
};

struct Contacts phoneBook[SIZE];
int count = 0; // Total number of contacts in the phone book

void addContact();
void removeContact();
void searchContact();
void displayContacts();
void saveToFile();
void loadFromFile();

int main() {
  int choice;

  loadFromFile(); // Load contacts from file upon starting the program
  
  printf("Welcome to My Phone Book!\n");
  
  while(1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add a contact\n");
    printf("2. Remove a contact\n");
    printf("3. Search for a contact\n");
    printf("4. Display all contacts\n");
    printf("5. Save contacts to file\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addContact();
        break;
      case 2:
        removeContact();
        break;
      case 3:
        searchContact();
        break;
      case 4:
        displayContacts();
        break;
      case 5:
        saveToFile();
        break;
      case 6:
        saveToFile();
        printf("Thank you for using My Phone Book!\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

void addContact() {
  if(count == SIZE) {
    printf("Sorry, the phone book is full.\n");
    return;
  }

  printf("\nEnter the name of the contact: ");
  scanf("%s", phoneBook[count].name);
  printf("Enter the phone number of the contact: ");
  scanf("%s", phoneBook[count].phone);
  count++;

  printf("\nContact added successfully!\n");
}

void removeContact() {
  char name[50];
  int index = -1;

  if(count == 0) {
    printf("\nThere are no contacts to remove.\n");
    return;
  }

  printf("\nEnter the name of the contact to remove: ");
  scanf("%s", name);

  for(int i=0; i<count; i++) {
    if(strcmp(phoneBook[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  if(index == -1) {
    printf("\nThe contact was not found in the phone book.\n");
    return;
  }

  for(int i=index; i<count-1; i++) {
    strcpy(phoneBook[i].name, phoneBook[i+1].name);
    strcpy(phoneBook[i].phone, phoneBook[i+1].phone);
  }

  count--;

  printf("\nContact removed successfully!\n");
}

void searchContact() {
  char name[50];
  int index = -1;

  if(count == 0) {
    printf("\nThere are no contacts to search.\n");
    return;
  }

  printf("\nEnter the name of the contact to search: ");
  scanf("%s", name);

  for(int i=0; i<count; i++) {
    if(strcmp(phoneBook[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  if(index == -1) {
    printf("\nThe contact was not found in the phone book.\n");
    return;
  }

  printf("\nContact details:\n");
  printf("Name: %s\n", phoneBook[index].name);
  printf("Phone: %s\n", phoneBook[index].phone);
}

void displayContacts() {
  if(count == 0) {
    printf("\nThere are no contacts to display.\n");
    return;
  }

  printf("\nAll contacts in the phone book:\n\n");

  for(int i=0; i<count; i++) {
    printf("Name: %s\n", phoneBook[i].name);
    printf("Phone: %s\n\n", phoneBook[i].phone);
  }
}

void saveToFile() {
  FILE *file_pointer = fopen("phonebook.dat", "wb");

  if(file_pointer == NULL) {
    printf("\nError: Could not open file to save contacts.\n");
    return;
  }

  fwrite(&count, sizeof(int), 1, file_pointer);
  fwrite(phoneBook, sizeof(struct Contacts), count, file_pointer);

  fclose(file_pointer);

  printf("\nContacts saved to file successfully!\n");
}

void loadFromFile() {
  FILE *file_pointer = fopen("phonebook.dat", "rb");

  if(file_pointer == NULL) {
    printf("\nNo contacts to load from file.\n");
    return;
  }

  fread(&count, sizeof(int), 1, file_pointer);
  fread(phoneBook, sizeof(struct Contacts), count, file_pointer);

  fclose(file_pointer);
}