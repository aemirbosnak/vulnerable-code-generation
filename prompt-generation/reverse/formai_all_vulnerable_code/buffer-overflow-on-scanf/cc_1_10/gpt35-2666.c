//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_ENTRIES 10

struct login_info {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool get_input(char *prompt, char *buffer, size_t buffer_size) {
    printf("%s", prompt);
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        return false;
    }
    size_t len = strlen(buffer);
    if (len == buffer_size - 1 && buffer[len - 1] != '\n') {
        printf("Input too long!\n");
        clear_input_buffer();
        return false;
    }
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    return true;
}

void add_entry(struct login_info *entries, int *num_entries) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Database full!\n");
        return;
    }
    if (!get_input("Enter username: ", entries[*num_entries].username, MAX_USERNAME_LENGTH)) {
        return;
    }
    if (!get_input("Enter password: ", entries[*num_entries].password, MAX_PASSWORD_LENGTH)) {
        return;
    }
    (*num_entries)++;
    printf("Entry added successfully!\n");
}

void remove_entry(struct login_info *entries, int *num_entries) {
    if (*num_entries == 0) {
        printf("Database empty!\n");
        return;
    }
    char username[MAX_USERNAME_LENGTH];
    if (!get_input("Enter username to remove: ", username, MAX_USERNAME_LENGTH)) {
        return;
    }
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(entries[i].username, username) == 0) {
            for (int j = i; j < *num_entries - 1; j++) {
                strcpy(entries[j].username, entries[j + 1].username);
                strcpy(entries[j].password, entries[j + 1].password);
            }
            (*num_entries)--;
            printf("Entry removed successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

void list_entries(struct login_info *entries, int num_entries) {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].username, entries[i].password);
    }
}

int main(void) {
    struct login_info entries[MAX_ENTRIES];
    int num_entries = 0;
    while (true) {
        printf("\nMenu:\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. List entries\n");
        printf("4. Quit\n");
        int choice;
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input!\n");
            clear_input_buffer();
            continue;
        }
        switch (choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                remove_entry(entries, &num_entries);
                break;
            case 3:
                list_entries(entries, num_entries);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        clear_input_buffer();
    }
}