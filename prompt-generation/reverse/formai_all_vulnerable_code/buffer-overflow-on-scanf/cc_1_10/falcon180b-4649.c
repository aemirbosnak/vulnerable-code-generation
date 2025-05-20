//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void add_entry(struct entry* entries, int count, char* name, char* number) {
    if (count >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].number, number);

    count++;
}

void search_entry(struct entry* entries, int count, char* name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(struct entry* entries, int* count, char* name) {
    int i;

    for (i = 0; i < *count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (*count - i - 1) * sizeof(struct entry));
            (*count)--;
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                char number[MAX_NUMBER_LENGTH];

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter number: ");
                scanf("%s", number);

                add_entry(entries, count, name, number);
                break;
            }

            case 2: {
                char name[MAX_NAME_LENGTH];

                printf("Enter name to search: ");
                scanf("%s", name);

                search_entry(entries, count, name);
                break;
            }

            case 3: {
                char name[MAX_NAME_LENGTH];

                printf("Enter name to delete: ");
                scanf("%s", name);

                delete_entry(entries, &count, name);
                break;
            }

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}