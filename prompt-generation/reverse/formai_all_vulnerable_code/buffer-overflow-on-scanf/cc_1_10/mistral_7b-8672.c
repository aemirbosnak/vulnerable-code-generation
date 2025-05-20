//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100
#define NAME_LENGTH 30
#define NUMBER_LENGTH 20

typedef struct {
 char name[NAME_LENGTH];
 char number[NUMBER_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int free_slot = 0;

int find_contact(char *name) {
 for (int i = 0; i < free_slot; i++) {
 if (strcmp(name, contacts[i].name) == 0) {
 return i;
 }
 }
 return -1;
}

void add_contact(Contact new_contact) {
 strcpy(contacts[free_slot].name, new_contact.name);
 strcpy(contacts[free_slot].number, new_contact.number);
 free_slot++;
}

void print_menu() {
 printf("\n****** C Phone Book ******\n");
 printf("1. Add a new contact\n");
 printf("2. Search for a contact\n");
 printf("3. Display all contacts\n");
 printf("4. Exit\n");
}

int main() {
 int choice;
 char name[NAME_LENGTH], number[NUMBER_LENGTH];

 do {
 print_menu();
 scanf("%d", &choice);

 switch (choice) {
 case 1:
 printf("Enter contact name: ");
 scanf("%s", name);
 printf("Enter contact number: ");
 scanf("%s", number);

 Contact new_contact = {name, number};
 add_contact(new_contact);
 printf("Contact added successfully!\n");
 break;

 case 2:
 printf("Enter contact name to search: ");
 scanf("%s", name);
 int index = find_contact(name);
 if (index == -1) {
 printf("Contact not found!\n");
 } else {
 printf("Contact found:\nName: %s\nNumber: %s\n", contacts[index].name, contacts[index].number);
 }
 break;

 case 3:
 printf("Displaying all contacts:\n");
 for (int i = 0; i < free_slot; i++) {
 printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
 }
 break;
 }
} while (choice != 4);

return 0;
}