//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void createEntry(char name[], char phone[], char email[]) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].phone, phone);
    strcpy(phoneBook[numEntries].email, email);
    numEntries++;
}

int searchByName(char name[]) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void editEntry(int index, char newName[], char newPhone[], char newEmail[]) {
    if (index < 0 || index >= numEntries) {
        printf("Invalid index.\n");
        return;
    }
    strcpy(phoneBook[index].name, newName);
    strcpy(phoneBook[index].phone, newPhone);
    strcpy(phoneBook[index].email, newEmail);
}

void deleteEntry(char name[]) {
    int index = searchByName(name);
    if (index < 0) {
        printf("Entry not found.\n");
        return;
    }
    for (int i = index; i < numEntries - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    numEntries--;
}

void displayAll() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s, %s\n", phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
    }
}

int main() {
    char command[10], name[50], phone[20], email[50];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            scanf("%s %s %s", name, phone, email);
            createEntry(name, phone, email);
        } else if (strcmp(command, "search") == 0) {
            scanf("%s", name);
            int index = searchByName(name);
            if (index >= 0) {
                printf("Found: %s, %s, %s\n", phoneBook[index].name, phoneBook[index].phone, phoneBook[index].email);
            } else {
                printf("Not found.\n");
            }
        } else if (strcmp(command, "edit") == 0) {
            scanf("%s %s %s %s", name, phone, email, name);
            int index = searchByName(name);
            if (index >= 0) {
                editEntry(index, name, phone, email);
            } else {
                printf("Invalid name.\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deleteEntry(name);
        } else if (strcmp(command, "display") == 0) {
            displayAll();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}