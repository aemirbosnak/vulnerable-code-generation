//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define PASSWORD_LENGTH 50
#define FILENAME "passwords.txt"

typedef struct {
    char site[100];
    char username[50];
    char password[PASSWORD_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entry_count = 0;

// Function prototypes
void load_passwords();
void save_passwords();
void add_entry(const char *site, const char *username, const char *password);
void view_entries();
void delete_entry(const char *site);
void clear_buffer();

int main() {
    load_passwords();

    int choice;
    char site[100], username[50], password[PASSWORD_LENGTH];

    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                printf("Enter site: ");
                fgets(site, sizeof(site), stdin);
                strtok(site, "\n"); // Remove newline character

                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                strtok(username, "\n");

                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                strtok(password, "\n");

                add_entry(site, username, password);
                break;

            case 2:
                view_entries();
                break;

            case 3:
                printf("Enter site to delete: ");
                fgets(site, sizeof(site), stdin);
                strtok(site, "\n");

                delete_entry(site);
                break;

            case 4:
                save_passwords();
                printf("Exiting. Passwords saved to '%s'.\n", FILENAME);
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void load_passwords() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No existing passwords found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%99s %49s %49s", entries[entry_count].site, entries[entry_count].username, entries[entry_count].password) == 3) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) {
            printf("Maximum entries reached, not loading more\n");
            break;
        }
    }
    fclose(file);
}

void save_passwords() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error saving passwords.\n");
        return;
    }
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s %s %s\n", entries[i].site, entries[i].username, entries[i].password);
    }
    fclose(file);
}

void add_entry(const char *site, const char *username, const char *password) {
    if (entry_count < MAX_ENTRIES) {
        strcpy(entries[entry_count].site, site);
        strcpy(entries[entry_count].username, username);
        strcpy(entries[entry_count].password, password);
        entry_count++;
        printf("Password added successfully.\n");
    } else {
        printf("Unable to add entry, maximum limit reached.\n");
    }
}

void view_entries() {
    if (entry_count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Stored Passwords:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Site: %s, User: %s, Password: %s\n", 
                entries[i].site, entries[i].username, entries[i].password);
    }
}

void delete_entry(const char *site) {
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].site, site) == 0) {
            // Shift down all entries after the deleted one
            for (int j = i; j < entry_count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            entry_count--;
            printf("Entry for site '%s' deleted successfully.\n", site);
            return;
        }
    }
    printf("No entry found for site '%s'\n", site);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}