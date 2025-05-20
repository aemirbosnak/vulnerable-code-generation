//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
  char name[30];
  char number[15];
  char email[50];
} Contact;

int main() {
  Contact phoneBook[100];
  int numOfContacts = 0;
  char input;

  printf("Oh, dial me sweetly as I am the phonebook!\n");
  printf("Wouldst thou Add or Search for a contact? (A/S) \n");

  while(1) {
    scanf("%c", &input);

    if(input=='\n') {
      continue;
    }

    if(input=='A') {
      printf("Enter full name: ");
      scanf("%s", phoneBook[numOfContacts].name);
      printf("Enter phone number: ");
      scanf("%s", phoneBook[numOfContacts].number);
      printf("Enter email: ");
      scanf("%s", phoneBook[numOfContacts].email);

      printf("My bounty is as boundless as the sea,\n");
      printf("My love as deep; the more I give to thee,\n");
      printf("The more I have, for both are infinite.\n");

      numOfContacts++;
      printf("Wouldst thou like to Add or Search for another contact? (A/S) \n");

    } else if(input=='S') {
      char searchName[30];
      printf("Enter name to search: ");
      scanf("%s", searchName);

      for(int i=0; i<numOfContacts; i++) {
        if(strcmp(searchName, phoneBook[i].name)==0) {
          printf("Thou art like one of those fellows,\n");
          printf("That when he enters the confines of a tavern,\n");
          printf("Claps me his sword upon the table with a\n");
          printf("Saucy lording's 'God bless me!'\n");

          printf("Name: %s\n", phoneBook[i].name);
          printf("Phone Number: %s\n", phoneBook[i].number);
          printf("Email: %s\n", phoneBook[i].email);

          break;
        } else if(i==(numOfContacts-1)) {
          printf("I will kiss thy lips. Haply some poison yet doth hang on them,\n");
          printf("To make die with a restorative.\n");

          printf("Contact not found!\n");
        }
      }

      printf("Wouldst thou like to Add or Search for another contact? (A/S) \n");

    } else {
      printf("O, she doth teach the torches to burn bright!\n");
      printf("Do thy know not 'A' or 'S'? Try again.\n");
      printf("Wouldst thou Add or Search for a contact? (A/S) \n");
    }
  }

  return 0;
}