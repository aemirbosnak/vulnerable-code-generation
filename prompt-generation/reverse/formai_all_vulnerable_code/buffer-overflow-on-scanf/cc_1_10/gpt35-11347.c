//FormAI DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password_entry {
    char *website;
    char *username;
    char *password;
};

int main() {
    printf("Welcome to your password manager!\n");

    int max_entries = 5;
    int num_entries = 0;

    struct password_entry *entries = (struct password_entry*)malloc(max_entries * sizeof(struct password_entry));

    while (1) {
        printf("\nEnter a command: ADD/VIEW/EXIT\n");

        char command[10];
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            if (num_entries == max_entries) {
                max_entries *= 2;
                entries = (struct password_entry*)realloc(entries, max_entries * sizeof(struct password_entry));
            }

            struct password_entry new_entry;

            printf("\nEnter website:\n");
            char website_buffer[100];
            scanf("%s", website_buffer);
            new_entry.website = (char*)malloc(strlen(website_buffer)+1);
            strcpy(new_entry.website, website_buffer);

            printf("Enter username:\n");
            char username_buffer[100];
            scanf("%s", username_buffer);
            new_entry.username = (char*)malloc(strlen(username_buffer)+1);
            strcpy(new_entry.username, username_buffer);

            printf("Enter password:\n");
            char password_buffer[100];
            scanf("%s", password_buffer);
            new_entry.password = (char*)malloc(strlen(password_buffer)+1);
            strcpy(new_entry.password, password_buffer);

            entries[num_entries] = new_entry;
            num_entries++;

            printf("Password added successfully!\n");
        }
        else if (strcmp(command, "VIEW") == 0) {
            printf("\nYour saved passwords:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s %s %s\n", entries[i].website, entries[i].username, entries[i].password);
            }
        }
        else if (strcmp(command, "EXIT") == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid command.\n");
        }
    }

    for (int i = 0; i < num_entries; i++) {
        free(entries[i].website);
        free(entries[i].username);
        free(entries[i].password);
    }
    free(entries);

    return 0;
}