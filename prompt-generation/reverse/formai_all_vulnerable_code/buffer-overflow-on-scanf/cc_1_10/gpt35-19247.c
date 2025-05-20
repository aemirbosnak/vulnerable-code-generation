//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
/* A modular C program of Phone Book */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  char phone_number[10];
} Contact;

void add_contact(Contact[], int);
void search_contact(Contact[], int);
void delete_contact(Contact[], int);
void display_contacts(Contact[], int);

int main() {
  int choice, num_of_contacts = 0;
  char input;

  Contact phone_book[50];

  do {
    printf("\n\n\t\tPHONE BOOK\n");
    printf("\t1. Add contact\n");
    printf("\t2. Search contact\n");
    printf("\t3. Delete contact\n");
    printf("\t4. Display contacts\n");
    printf("\t5. Exit\n");
    printf("\n\tEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_contact(phone_book, num_of_contacts);
        num_of_contacts++;
        break;
      case 2:
        search_contact(phone_book, num_of_contacts);
        break;
      case 3:
        delete_contact(phone_book, num_of_contacts);
        num_of_contacts--;
        break;
      case 4:
        display_contacts(phone_book, num_of_contacts);
        break;
      case 5:
        printf("\nThank you for using Phone Book!\n");
        exit(0);
      default:
        printf("\nInvalid choice. Please enter again.\n");
    }

    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &input);

  } while(input == 'y' || input == 'Y');

  return 0;
}

void add_contact(Contact phone_book[], int num_of_contacts) {
  printf("\nEnter the name: ");
  scanf("%s", phone_book[num_of_contacts].name);

  printf("Enter the phone number: ");
  scanf("%s", phone_book[num_of_contacts].phone_number);

  printf("\nContact added successfully!\n");
}

void search_contact(Contact phone_book[], int num_of_contacts) {
  char input[20];
  int i, found = 0;

  printf("\nEnter the name to search: ");
  scanf("%s", input);

  for(i=0; i<num_of_contacts; i++) {
    if(strcmp(phone_book[i].name, input) == 0) {
      printf("\nContact found!\n");
      printf("\tName: %s\n", phone_book[i].name);
      printf("\tPhone number: %s\n", phone_book[i].phone_number);
      found = 1;
      break;
    }
  }

  if(!found)
    printf("\nContact not found!\n");
}

void delete_contact(Contact phone_book[], int num_of_contacts) {
  char input[20];
  int i, found = 0;

  printf("\nEnter the name to delete: ");
  scanf("%s", input);

  for(i=0; i<num_of_contacts; i++) {
    if(strcmp(phone_book[i].name, input) == 0) {
      found = 1;
      break;
    }
  }

  if(found) {
    for(; i<num_of_contacts-1; i++) {
      strcpy(phone_book[i].name, phone_book[i+1].name);
      strcpy(phone_book[i].phone_number, phone_book[i+1].phone_number);
    }

    printf("\nContact deleted successfully!\n");
  }
  else
    printf("\nContact not found!\n");
}

void display_contacts(Contact phone_book[], int num_of_contacts) {
  int i;

  if(num_of_contacts == 0)
    printf("\nNo contacts available!\n");
  else {
    printf("\n\tCONTACTS\n");
    printf("\t---------------------------------------------\n");
    printf("\t|         NAME         |    PHONE NUMBER     |\n");
    printf("\t---------------------------------------------\n");

    for(i=0; i<num_of_contacts; i++) {
      printf("\t| %-20s | %-19s |\n", phone_book[i].name, phone_book[i].phone_number);
    }

    printf("\t---------------------------------------------\n");
  }
}