//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 1000

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void add_entry(struct entry *book, int count) {
    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", book[count].name);

    printf("Enter phone number (max %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", book[count].number);
}

void search_entry(struct entry *book, int count) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", book[i].name, book[i].number);
        }
    }
}

void delete_entry(struct entry *book, int count) {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, delete_name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(book[j].name, book[j + 1].name);
                strcpy(book[j].number, book[j + 1].number);
            }
            count--;
            break;
        }
    }
}

void print_entries(struct entry *book, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nPhone Number: %s\n", book[i].name, book[i].number);
    }
}

int main() {
    struct entry book[MAX_ENTRIES];
    int count = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_ENTRIES; i++) {
        add_entry(book, count);
        count++;
    }

    int choice;
    do {
        printf("\n1. Add Entry\n2. Search Entry\n3. Delete Entry\n4. Print Entries\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(book, count);
                count++;
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);

                search_entry(book, count);
                break;
            case 3:
                printf("Enter name to delete: ");
                char delete_name[MAX_NAME_LENGTH];
                scanf("%s", delete_name);

                delete_entry(book, count);
                break;
            case 4:
                print_entries(book, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}