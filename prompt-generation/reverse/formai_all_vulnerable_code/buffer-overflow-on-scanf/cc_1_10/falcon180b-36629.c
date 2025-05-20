//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[51];
    char phone[16];
} entry;

void add_entry(entry entries[], int count, char* name, char* phone) {
    if(count >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);
    count++;
}

void view_entry(entry entries[], int count) {
    int i;

    printf("Phone Book Entries:\n");
    for(i=0; i<count; i++) {
        printf("%d. %s - %s\n", i+1, entries[i].name, entries[i].phone);
    }
}

void search_entry(entry entries[], int count, char* name) {
    int i;

    for(i=0; i<count; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            printf("Found entry for %s:\n", name);
            printf("%s - %s\n", entries[i].name, entries[i].phone);
        }
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int count = 0;

    printf("Welcome to the Phone Book!\n");

    while(1) {
        printf("\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[51], phone[16];

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter phone number: ");
                scanf("%s", phone);

                add_entry(entries, count, name, phone);

                break;
            }

            case 2: {
                view_entry(entries, count);

                break;
            }

            case 3: {
                char name[51];

                printf("Enter name to search: ");
                scanf("%s", name);

                search_entry(entries, count, name);

                break;
            }

            case 4: {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}