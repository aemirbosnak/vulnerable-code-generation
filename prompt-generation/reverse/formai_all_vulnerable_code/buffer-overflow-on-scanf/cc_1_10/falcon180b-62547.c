//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[20];
    char phone[15];
} entry;

void addEntry(entry entries[], int count, char name[], char phone[]) {
    if (count >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);
    count++;
}

void searchEntry(entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
        }
    }
}

void deleteEntry(entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(&entries[i], 0, sizeof(entry));
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    entry entries[MAX_ENTRIES];
    int count = 0;
    char choice;
    do {
        printf("Phone book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter name: ");
                char name[20];
                scanf("%s", name);
                printf("Enter phone: ");
                char phone[15];
                scanf("%s", phone);
                addEntry(entries, count, name, phone);
                break;
            case '2':
                printf("Enter name to search: ");
                char searchName[20];
                scanf("%s", searchName);
                searchEntry(entries, count, searchName);
                break;
            case '3':
                printf("Enter name to delete: ");
                char delName[20];
                scanf("%s", delName);
                deleteEntry(entries, count, delName);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}