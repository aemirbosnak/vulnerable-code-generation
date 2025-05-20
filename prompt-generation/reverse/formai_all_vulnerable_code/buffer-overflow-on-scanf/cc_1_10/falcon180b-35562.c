//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

void add_entry(entry_t entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);
    count++;
}

void display_entry(entry_t entry) {
    printf("%s: %s\n", entry.name, entry.phone);
}

void search_entry(entry_t entries[], int count, char* name) {
    int i;
    for(i=0; i<count; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            display_entry(entries[i]);
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Display entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry(entries, count);
                break;
            case 2:
                printf("Displaying all entries:\n");
                int i;
                for(i=0; i<count; i++) {
                    display_entry(entries[i]);
                }
                break;
            case 3:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}