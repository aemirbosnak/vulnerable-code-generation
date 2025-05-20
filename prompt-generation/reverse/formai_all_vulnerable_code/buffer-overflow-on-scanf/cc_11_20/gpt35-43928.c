//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct PhoneBookEntry {
  char name[20];
  char phone[15];
};

int main() {
  struct PhoneBookEntry phoneBook[MAX_ENTRIES];
  int num_entries = 0;
  char choice;

  printf("*** C Phone Book App ***\n");

  do {
    printf("\nMenu\n");
    printf("====\n");
    printf("1. Add an entry\n");
    printf("2. Search for an entry\n");
    printf("3. Show all entries\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(choice) {

      case '1':
        if(num_entries < MAX_ENTRIES) {
          printf("\nEnter name: ");
          scanf("%s", phoneBook[num_entries].name);
          printf("Enter phone number: ");
          scanf("%s", phoneBook[num_entries].phone);
          printf("Entry added!\n");
          num_entries++;
        }
        else {
          printf("\nPhone book is full!\n");
        }
        break;

      case '2':
        if(num_entries > 0) {
          char search[20];
          printf("\nEnter name to search: ");
          scanf("%s", search);
          int found = 0;
          for(int i = 0; i < num_entries; i++) {
            if(strcmp(search, phoneBook[i].name) == 0) {
              printf("\n%s's phone number is %s\n", phoneBook[i].name, phoneBook[i].phone);
              found = 1;
            }
          }
          if(!found) {
            printf("\n%s not found in phone book\n", search);
          }
        }
        else {
          printf("\nPhone book is empty!\n");
        }
        break;

      case '3':
        if(num_entries > 0) {
          printf("\nPhone Book\n");
          printf("==========\n");
          for(int i = 0; i < num_entries; i++) {
            printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
          }
        }
        else {
          printf("\nPhone book is empty!\n");
        }
        break;

      case '4':
        printf("\nGoodbye!\n");
        break;

      default:
        printf("\nInvalid choice!\n");
    }

  } while(choice != '4');

  return 0;
}