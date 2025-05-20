//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define MAX_ENTRIES 10

typedef struct {
    char username[MAX_USERNAME_LEN+1];
    char password[MAX_PASSWORD_LEN+1];
} LoginEntry;

int main() {
    LoginEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    int choice = 0;
    while (1) {
        printf("1. Add login entry\n");
        printf("2. View login entry\n");
        printf("3. Quit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (numEntries >= MAX_ENTRIES) {
                printf("Max number of entries reached.\n");
                continue;
            }

            char username[MAX_USERNAME_LEN+1];
            char password[MAX_PASSWORD_LEN+1];

            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            if (strlen(username) > MAX_USERNAME_LEN || strlen(password) > MAX_PASSWORD_LEN) {
                printf("Username or password too long.\n");
                continue;
            }

            LoginEntry entry;
            strncpy(entry.username, username, MAX_USERNAME_LEN+1);
            strncpy(entry.password, password, MAX_PASSWORD_LEN+1);

            entries[numEntries++] = entry;

            printf("Login entry added.\n");
        }
        else if (choice == 2) {
            if (numEntries == 0) {
                printf("No login entries.\n");
                continue;
            }

            for (int i = 0; i < numEntries; i++) {
                printf("Entry %d:\n", i+1);
                printf("  Username: %s\n", entries[i].username);
                printf("  Password: %s\n", entries[i].password);
            }
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}