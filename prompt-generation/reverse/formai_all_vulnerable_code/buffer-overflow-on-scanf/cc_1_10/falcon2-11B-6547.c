//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry {
    char name[50];
    char phone[20];
};

void addEntry(struct PhoneBookEntry* entry) {
    printf("Enter name: ");
    fgets(entry->name, sizeof(entry->name), stdin);
    entry->name[strcspn(entry->name, "\n")] = '\0';
    printf("Enter phone: ");
    fgets(entry->phone, sizeof(entry->phone), stdin);
    entry->phone[strcspn(entry->phone, "\n")] = '\0';
    printf("Phone entry added successfully!\n");
}

void deleteEntry(struct PhoneBookEntry* entry) {
    printf("Enter name: ");
    fgets(entry->name, sizeof(entry->name), stdin);
    entry->name[strcspn(entry->name, "\n")] = '\0';
    if (strcmp(entry->name, " ") == 0) {
        printf("No such entry found.\n");
        return;
    }
    printf("Phone entry deleted successfully!\n");
}

void searchEntry(struct PhoneBookEntry* entry) {
    printf("Enter name: ");
    fgets(entry->name, sizeof(entry->name), stdin);
    entry->name[strcspn(entry->name, "\n")] = '\0';
    if (strcmp(entry->name, " ") == 0) {
        printf("No such entry found.\n");
        return;
    }
    printf("Phone entry found successfully!\n");
}

void printEntries() {
    struct PhoneBookEntry entries[100];
    int count = 0;
    printf("Phone Book:\n");
    while (scanf("%s %s", &entries[count].name, &entries[count].phone) == 2) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].phone);
    }
    printf("\n");
}

int main() {
    struct PhoneBookEntry entries[100];
    int count = 0;
    while (1) {
        printf("1. Add Entry\n2. Delete Entry\n3. Search Entry\n4. Print Entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(&entries[count]);
                break;
            case 2:
                deleteEntry(&entries[count]);
                break;
            case 3:
                searchEntry(&entries[count]);
                break;
            case 4:
                printEntries();
                break;
            case 5:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        count++;
    }
    return 0;
}