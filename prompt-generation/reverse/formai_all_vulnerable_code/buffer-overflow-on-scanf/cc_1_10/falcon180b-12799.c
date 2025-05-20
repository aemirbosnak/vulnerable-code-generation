//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} Entry;

int main() {
    Entry phonebook[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    char searchName[50];

    do {
        printf("C Phone Book\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", phonebook[numEntries].name);
                printf("Enter phone number: ");
                scanf("%s", phonebook[numEntries].phone);
                numEntries++;
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", searchName);
                for(int i=0; i<numEntries; i++) {
                    if(strcmp(phonebook[i].name, searchName) == 0) {
                        printf("Name: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}