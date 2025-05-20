//FormAI DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

typedef struct {
  char name[50];
  char phone[20];
} Contact;

int numContacts = 0;
Contact contacts[MAX_CONTACTS];

void addContact(char *name, char *phone) {
  if (numContacts == MAX_CONTACTS) {
    printf("Error: can't add contact, phone book is full\n");
    return;
  }
  
  Contact newContact;
  strcpy(newContact.name, name);
  strcpy(newContact.phone, phone);
  
  contacts[numContacts++] = newContact;
  printf("Added contact %s: %s\n", name, phone);
}

void removeContact(char *name) {
  int indexToRemove = -1;
  
  for (int i = 0; i < numContacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      indexToRemove = i;
      break;
    }
  }
  
  if (indexToRemove == -1) {
    printf("Error: contact %s not found\n", name);
    return;
  }
  
  for (int i = indexToRemove; i < numContacts-1; i++) {
    contacts[i] = contacts[i+1];
  }
  
  numContacts--;
  printf("Removed contact %s\n", name);
}

void printContacts() {
  printf("Phone Book:\n");
  for (int i = 0; i < numContacts; i++) {
    printf("%s: %s\n", contacts[i].name, contacts[i].phone);
  }
}

int main() {
  while (1) {
    printf("\nCommands:\n");
    printf("  add <name> <phone>\n");
    printf("  remove <name>\n");
    printf("  print\n");
    printf("  quit\n");
    
    char command[10];
    scanf("%s", command);
    
    if (strcmp(command, "add") == 0) {
      char name[50];
      char phone[20];
      scanf("%s %s", name, phone);
      addContact(name, phone);
    }
    
    else if (strcmp(command, "remove") == 0) {
      char name[50];
      scanf("%s", name);
      removeContact(name);
    }
    
    else if (strcmp(command, "print") == 0) {
      printContacts();
    }
    
    else if (strcmp(command, "quit") == 0) {
      break;
    }
    
    else {
      printf("Error: invalid command\n");
    }
  }
  
  return 0;
}