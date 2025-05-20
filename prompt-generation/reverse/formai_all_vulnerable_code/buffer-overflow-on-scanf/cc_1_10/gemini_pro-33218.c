//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 20

typedef struct _entry {
    char username[20];
    char password[20];
} entry;

void add_entry(entry *entries, int *num_entries, char *username, char *password) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Error: Password database is full.\n");
        return;
    }

    strcpy(entries[*num_entries].username, username);
    strcpy(entries[*num_entries].password, password);
    (*num_entries)++;
}

void find_entry(entry *entries, int num_entries, char *username) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].username, username) == 0) {
            printf("Found entry for username %s:\n", username);
            printf("Password: %s\n", entries[i].password);
            return;
        }
    }

    printf("No entry found for username %s.\n", username);
}

void print_entries(entry *entries, int num_entries) {
    printf("Current password database:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n", entries[i].password);
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char command[20];
    char username[20];
    char password[20];

    while (1) {
        printf("Enter command (add, find, print, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            add_entry(entries, &num_entries, username, password);
        } else if (strcmp(command, "find") == 0) {
            printf("Enter username: ");
            scanf("%s", username);

            find_entry(entries, num_entries, username);
        } else if (strcmp(command, "print") == 0) {
            print_entries(entries, num_entries);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}