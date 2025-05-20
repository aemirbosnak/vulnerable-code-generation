//FormAI DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PW_LENGTH 20
#define MAX_PW_COUNT 100

typedef struct {
    int id;
    char password[MAX_PW_LENGTH + 1];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_PW_COUNT];
    int count;
} PasswordDatabase;

void add_password(PasswordDatabase* db, char* password) {
    if (db->count >= MAX_PW_COUNT) {
        printf("Password database is full. Cannot add password.\n");
        return;
    }

    PasswordEntry new_entry;
    new_entry.id = db->count + 1;
    strncpy(new_entry.password, password, MAX_PW_LENGTH);
    new_entry.password[MAX_PW_LENGTH] = '\0';

    db->entries[db->count] = new_entry;
    db->count++;

    printf("Password added successfully.\n");
}

void list_passwords(PasswordDatabase* db) {
    if (db->count == 0) {
        printf("No passwords in database.\n");
        return;
    }

    printf("%-5s  %-20s\n", "ID", "Password");
    for (int i = 0; i < db->count; i++) {
        PasswordEntry entry = db->entries[i];
        printf("%-5d  %-20s\n", entry.id, entry.password);
    }
}

int get_password_count(PasswordDatabase* db) {
    return db->count;
}

int main() {
    PasswordDatabase db;
    db.count = 0;

    int option = 0;
    while (option != 3) {
        printf("\n1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                char password[MAX_PW_LENGTH + 1];
                printf("\nEnter new password (maximum length %d): ", MAX_PW_LENGTH);
                scanf("%s", password);
                add_password(&db, password);
                break;
            }
            case 2:
                list_passwords(&db);
                break;
            case 3:
                printf("\nExiting...\n\n");
                break;
            default:
                printf("\nInvalid option. Please enter a number from 1-3.\n");
                break;
        }
    }

    return 0;
}