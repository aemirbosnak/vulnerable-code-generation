//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char number[15];
};

void add_entry(struct entry entries[], int *count) {
    printf("Enter name: ");
    scanf("%s", entries[*count].name);

    printf("Enter number: ");
    scanf("%s", entries[*count].number);

    (*count)++;
}

void search_entry(struct entry entries[], int count, char *name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
        }
    }
}

void delete_entry(struct entry entries[], int *count) {
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i + 1], (*count - i - 1) * sizeof(struct entry));
            (*count)--;
            break;
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_ENTRIES) {
                    printf("Phone book is full.\n");
                } else {
                    add_entry(entries, &count);
                }
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            case 3:
                delete_entry(entries, &count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}