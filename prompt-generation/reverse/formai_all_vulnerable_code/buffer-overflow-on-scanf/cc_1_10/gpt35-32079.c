//FormAI DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
  char name[30];
  char phone[20];
};

int main() {
  struct Contact phonebook[MAX_CONTACTS];
  int num_contacts = 0;

  printf("Welcome to your C Phone Book!\n");

  while(1) {
    printf("\nEnter a command (add, search, or quit): ");
    char command[10];
    scanf("%s", command);

    if(strcmp(command, "add") == 0) {
      if(num_contacts == MAX_CONTACTS) {
        printf("Your phone book is full. Cannot add any more contacts.\n");
        continue;
      }

      struct Contact new_contact;

      printf("Enter the name: ");
      scanf("%s", new_contact.name);
      printf("Enter the phone number: ");
      scanf("%s", new_contact.phone);

      phonebook[num_contacts] = new_contact;
      num_contacts++;

      printf("Contact added successfully.\n");

    } else if(strcmp(command, "search") == 0) {
      if(num_contacts == 0) {
        printf("Your phone book is empty. Cannot search for contacts.\n");
        continue;
      }

      char search_term[30];
      printf("Enter a name to search for: ");
      scanf("%s", search_term);

      int num_matches = 0;

      for(int i = 0; i < num_contacts; i++) {
        if(strcmp(search_term, phonebook[i].name) == 0) {
          printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
          num_matches++;
        }
      }

      if(num_matches == 0) {
        printf("No contacts found.\n");
      }

    } else if(strcmp(command, "quit") == 0) {
      printf("Thank you for using your C Phone Book!\n");
      break;
    } else {
      printf("Invalid command. Please enter add, search, or quit.\n");
    }
  }

  return 0;
}