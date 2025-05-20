//FormAI DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Entry;

int numEntries = 0;
Entry entries[MAX_ENTRIES];

void saveEntries()
{
    FILE *file = fopen("entries.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numEntries; i++) {
            fprintf(file, "%s;%s;%s\n", entries[i].name, entries[i].email, entries[i].phone);
        }
        fclose(file);
    }
}

void addEntry()
{
    if (numEntries < MAX_ENTRIES) {
        Entry entry;
        printf("Enter name: ");
        fgets(entry.name, MAX_NAME_LENGTH, stdin);
        entry.name[strcspn(entry.name, "\n")] = 0;
        printf("Enter email: ");
        fgets(entry.email, MAX_EMAIL_LENGTH, stdin);
        entry.email[strcspn(entry.email, "\n")] = 0;
        printf("Enter phone: ");
        fgets(entry.phone, MAX_PHONE_LENGTH, stdin);
        entry.phone[strcspn(entry.phone, "\n")] = 0;

        entries[numEntries++] = entry;
        saveEntries();
    } else {
        printf("Error: maximum number of entries reached\n");
    }
}

void deleteEntry()
{
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: entry not found\n");
    } else {
        for (int i = index; i < numEntries-1; i++) {
            entries[i] = entries[i+1];
        }
        numEntries--;
        saveEntries();
        printf("Entry deleted\n");
    }
}

void searchEntry()
{
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].name, name) != NULL) {
            printf("Name: %s\nEmail: %s\nPhone: %s\n\n", entries[i].name, entries[i].email, entries[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Error: entry not found\n");
    }
}

void printEntries()
{
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nEmail: %s\nPhone: %s\n\n", entries[i].name, entries[i].email, entries[i].phone);
    }
}

int main()
{
    FILE *file = fopen("entries.txt", "r");
    if (file != NULL) {
        char buffer[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2];
        while (fgets(buffer, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2, file) != NULL) {
            Entry entry;
            sscanf(buffer, "%[^;];%[^;];%s", entry.name, entry.email, entry.phone);
            entries[numEntries++] = entry;
        }
        fclose(file);
        printf("%d entries loaded from file\n", numEntries);
    }

    char choice;
    do {
        printf("Choose an option:\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Print entries\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case '1':
                addEntry();
                break;
            case '2':
                deleteEntry();
                break;
            case '3':
                searchEntry();
                break;
            case '4':
                printEntries();
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: invalid choice\n");
                break;
        }
    } while (choice != '5');

    return 0;
}