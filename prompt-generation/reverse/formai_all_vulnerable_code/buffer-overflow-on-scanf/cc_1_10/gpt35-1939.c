//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_NUM_ENTRIES 10
#define PIN_CODE_LENGTH 4
#define MAX_ATTEMPTS 3

struct password_entry {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int authenticate();
int read_entry(struct password_entry *entry);
int write_entry(struct password_entry *entry);
int get_choice();
int find_entry(char *username, struct password_entry *entry_list, int num_entries);
int add_entry(struct password_entry *entry_list, int *num_entries);
int remove_entry(struct password_entry *entry_list, int *num_entries);
char *encrypt(char *password);
char *decrypt(char *password);

int main() {

    int choice;
    struct password_entry entry_list[MAX_NUM_ENTRIES];
    int num_entries = 0;

    while (1) {

        if (!authenticate()) {
            printf("Authentication failed, the program will exit.\n");
            exit(EXIT_FAILURE);
        }

        printf("\nPassword Management System\n\n");
        printf("1. Add Password Entry\n");
        printf("2. Remove Password Entry\n");
        printf("3. View Password Entry\n");
        printf("4. Quit\n\n");

        choice = get_choice();

        switch (choice) {

            case 1:
                if (add_entry(entry_list, &num_entries)) {
                    printf("Password entry added.\n");
                } else {
                    printf("Failed to add password entry.\n");
                }
                break;

            case 2:
                if (remove_entry(entry_list, &num_entries)) {
                    printf("Password entry removed.\n");
                } else {
                    printf("Failed to remove password entry.\n");
                }
                break;

            case 3:
                printf("Enter Username: ");
                char username[MAX_USERNAME_LENGTH];
                scanf("%s", username);
                struct password_entry *entry = malloc(sizeof(struct password_entry));
                int index = find_entry(username, entry_list, num_entries);
                if (index == -1) {
                    printf("Password entry not found.\n");
                } else {
                    memcpy(entry, &entry_list[index], sizeof(struct password_entry));
                    printf("Username: %s\n", entry->username);
                    printf("Password: %s\n", decrypt(entry->password));
                }
                free(entry);
                break;

            case 4:
                printf("Goodbye.\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

    }

    return 0;
}

int authenticate() {

    char pin_code[PIN_CODE_LENGTH + 1];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {

        printf("Enter pin code: ");
        scanf("%s", pin_code);

        if (strcmp(pin_code, "1234") == 0) {
            return 1;
        } else {
            attempts++;
            printf("Incorrect pin code, %d attempts left.\n", MAX_ATTEMPTS - attempts);
        }

    }

    return 0;
}

int read_entry(struct password_entry *entry) {

    printf("Enter Username: ");
    scanf("%s", entry->username);

    printf("Enter Password: ");
    scanf("%s", entry->password);

    return 1;
}

int write_entry(struct password_entry *entry) {

    FILE *fp;
    fp = fopen("passwords.txt", "a");

    if (fp == NULL) {
        return 0;
    }

    fprintf(fp, "%s %s\n", entry->username, encrypt(entry->password));

    fclose(fp);

    return 1;
}

int get_choice() {

    int choice;

    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

int find_entry(char *username, struct password_entry *entry_list, int num_entries) {

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entry_list[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

int add_entry(struct password_entry *entry_list, int *num_entries) {

    if (*num_entries == MAX_NUM_ENTRIES) {
        return 0;
    }

    struct password_entry *entry = malloc(sizeof(struct password_entry));

    if (!read_entry(entry)) {
        return 0;
    }

    if (!write_entry(entry)) {
        free(entry);
        return 0;
    }

    memcpy(&entry_list[*num_entries], entry, sizeof(struct password_entry));
    (*num_entries)++;

    free(entry);

    return 1;
}

int remove_entry(struct password_entry *entry_list, int *num_entries) {

    char username[MAX_USERNAME_LENGTH];
    printf("Enter Username to remove: ");
    scanf("%s", username);

    int index = find_entry(username, entry_list, *num_entries);

    if (index == -1) {
        return 0;
    }

    for (int i = index + 1; i < *num_entries; i++) {
        memcpy(&entry_list[i - 1], &entry_list[i], sizeof(struct password_entry));
    }

    (*num_entries)--;

    return 1;
}

char *encrypt(char *password) {

    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        password[i] = toupper(password[i]);
    }

    return password;
}

char *decrypt(char *password) {

    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        password[i] = tolower(password[i]);
    }

    return password;
}