//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    char phone[15];
} entry;

void add_entry(entry *book[], int *count) {
    printf("Enter name: ");
    scanf("%s", book[*count]->name);
    printf("Enter phone number: ");
    scanf("%s", book[*count]->phone);
    (*count)++;
}

void delete_entry(entry *book[], int *count) {
    printf("Enter name to delete: ");
    char name[30];
    scanf("%s", name);
    int i = 0;
    while (i < *count) {
        if (strcmp(name, book[i]->name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(book[j]->name, book[j + 1]->name);
                strcpy(book[j]->phone, book[j + 1]->phone);
            }
            (*count)--;
            return;
        }
        i++;
    }
    printf("Entry not found.\n");
}

void search_entry(entry *book[], int count) {
    printf("Enter name to search: ");
    char name[30];
    scanf("%s", name);
    int i = 0;
    while (i < count) {
        if (strcmp(name, book[i]->name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i]->name, book[i]->phone);
            return;
        }
        i++;
    }
    printf("Entry not found.\n");
}

void print_entries(entry *book[], int count) {
    int i = 0;
    while (i < count) {
        printf("Name: %s\nPhone: %s\n", book[i]->name, book[i]->phone);
        i++;
    }
}

int main() {
    entry *book[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(book, &count);
                break;
            case 2:
                delete_entry(book, &count);
                break;
            case 3:
                search_entry(book, count);
                break;
            case 4:
                print_entries(book, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}