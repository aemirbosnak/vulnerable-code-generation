//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[16];
} entry_t;

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    int index;

    while(1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_entries == MAX_ENTRIES) {
                    printf("Sorry, phone book is full!\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", entries[num_entries].name);
                    printf("Enter phone number: ");
                    scanf("%s", entries[num_entries].phone);
                    num_entries++;
                    printf("Entry added successfully!\n");
                }
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", entries[0].name);
                index = 0;
                while(index < num_entries) {
                    if(strcmp(entries[index].name, entries[0].name) == 0) {
                        printf("Phone number: %s\n", entries[index].phone);
                        break;
                    }
                    index++;
                }
                if(index == num_entries) {
                    printf("Entry not found!\n");
                }
                break;
            case '3':
                printf("Phone Book Entries:\n");
                for(index = 0; index < num_entries; index++) {
                    printf("Name: %s, Phone number: %s\n", entries[index].name, entries[index].phone);
                }
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}