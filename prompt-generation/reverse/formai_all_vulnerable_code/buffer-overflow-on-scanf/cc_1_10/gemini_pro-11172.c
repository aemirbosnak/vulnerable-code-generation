//GEMINI-pro DATASET v1.0 Category: Password management ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *label;
    char *username;
    char *password;
} password_entry;

int main() {
    int num_entries = 0;
    password_entry *entries = NULL;

    // Read the number of entries from the user.
    printf("How many password entries do you want to store? ");
    scanf("%d", &num_entries);

    // Allocate memory for the entries.
    entries = malloc(sizeof(password_entry) * num_entries);
    if (entries == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for password entries.\n");
        return 1;
    }

    // Read the entries from the user.
    for (int i = 0; i < num_entries; i++) {
        printf("Enter the label for entry %d: ", i + 1);
        entries[i].label = malloc(50);
        scanf("%s", entries[i].label);

        printf("Enter the username for entry %d: ", i + 1);
        entries[i].username = malloc(50);
        scanf("%s", entries[i].username);

        printf("Enter the password for entry %d: ", i + 1);
        entries[i].password = malloc(50);
        scanf("%s", entries[i].password);
    }

    // Print the entries to the console.
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("  Label: %s\n", entries[i].label);
        printf("  Username: %s\n", entries[i].username);
        printf("  Password: %s\n", entries[i].password);
    }

    // Free the memory allocated for the entries.
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].label);
        free(entries[i].username);
        free(entries[i].password);
    }
    free(entries);

    return 0;
}