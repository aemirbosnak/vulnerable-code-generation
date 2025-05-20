//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILENAME_PREFIX "diary_"

void add_entry(const char *username);
void view_entries(const char *username);
int login(char *username);

int main() {
    char username[MAX_LENGTH];

    printf("Welcome to the Multiplayer Digital Diary!\n");
    
    while (1) {
        if (login(username)) {
            int choice;
            do {
                printf("\n1. Add Diary Entry\n2. View Your Entries\n3. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();  // consume newline left by scanf

                switch (choice) {
                    case 1:
                        add_entry(username);
                        break;
                    case 2:
                        view_entries(username);
                        break;
                    case 3:
                        printf("Logging out, Goodbye %s!\n", username);
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            } while (choice != 3);
        }
    }

    return 0;
}

int login(char *username) {
    printf("Enter your username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline character
    printf("Successfully logged in as %s.\n", username);
    return 1;
}

void add_entry(const char *username) {
    char entry[MAX_LENGTH];
    char filename[MAX_LENGTH];

    snprintf(filename, sizeof(filename), "%s%s.txt", FILENAME_PREFIX, username);
    FILE *file = fopen(filename, "a");

    if (!file) {
        perror("Could not open diary file");
        return;
    }

    printf("Enter your diary entry (type 'exit' to finish):\n");
    while (1) {
        fgets(entry, sizeof(entry), stdin);
        entry[strcspn(entry, "\n")] = 0;  // Remove newline character

        if (strcmp(entry, "exit") == 0) {
            break;
        }

        fprintf(file, "%s\n", entry);
    }

    fclose(file);
    printf("Your entry has been saved!\n");
}

void view_entries(const char *username) {
    char filename[MAX_LENGTH];
    char entry[MAX_LENGTH];

    snprintf(filename, sizeof(filename), "%s%s.txt", FILENAME_PREFIX, username);
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("No entries found for %s.\n", username);
        return;
    }

    printf("\nYour Diary Entries:\n");
    while (fgets(entry, sizeof(entry), file)) {
        printf("%s", entry);
    }

    fclose(file);
}