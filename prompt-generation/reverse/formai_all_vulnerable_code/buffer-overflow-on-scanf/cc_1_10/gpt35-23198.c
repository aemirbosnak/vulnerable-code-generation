//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry { 
  char name[50];
  char phoneNumber[15];
  char address[100];
};

void addEntry(struct PhoneBookEntry* entries, int* count) {
  printf("Enter the name: ");
  scanf("%s", entries[*count].name);

  printf("Enter the phone number (XXX-XXX-XXXX): ");
  scanf("%s", entries[*count].phoneNumber);

  printf("Enter the address: ");
  scanf("%s", entries[*count].address);

  (*count)++;
}

void printAllEntries(struct PhoneBookEntry* entries, int count) {
  printf("Name\t\tPhone Number\t\tAddress\n");
  for(int i=0; i<count; i++){
      printf("%s\t\t%s\t\t%s\n", entries[i].name, entries[i].phoneNumber, entries[i].address);
  }
}

void searchEntry(struct PhoneBookEntry* entries, int count){
    char query[50];
    int found = 0;
    printf("Enter the name to search: ");
    scanf("%s", query);
    
    for(int i=0; i<count; i++){
        if(strcmp(entries[i].name, query) == 0){
            printf("Name: %s\tPhone Number: %s\tAddress:%s\n", entries[i].name, entries[i].phoneNumber, entries[i].address);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("No results found for \"%s\".\n", query);
    }
}

int main() {
  struct PhoneBookEntry entries[100];
  int count = 0;
  int choice;
  
  while(1){
    printf("\n\n");
    printf("Welcome to My Phone book Application!\n");
    printf("1. Add a new entry\n");
    printf("2. Print all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit the program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            addEntry(entries, &count);
            break;
        case 2:
            printAllEntries(entries, count);
            break;
        case 3:
            searchEntry(entries, count);
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid choice!\n");
            break;
    }
  }
  
  return 0;
}