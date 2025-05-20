//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    int index;

    while(1) {
        printf("Phone Book Menu:\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display all entries\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
        case '1':
            if(num_entries >= MAX_ENTRIES) {
                printf("Phone book is full.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", entries[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", entries[num_entries].phone);
                num_entries++;
            }
            break;

        case '2':
            printf("Enter name to search: ");
            scanf("%s", entries[num_entries].name);
            for(index = 0; index < num_entries; index++) {
                if(strcmp(entries[index].name, entries[num_entries].name) == 0) {
                    printf("Phone number: %s\n", entries[index].phone);
                }
            }
            break;

        case '3':
            printf("Phone Book:\n");
            for(index = 0; index < num_entries; index++) {
                printf("%s: %s\n", entries[index].name, entries[index].phone);
            }
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}