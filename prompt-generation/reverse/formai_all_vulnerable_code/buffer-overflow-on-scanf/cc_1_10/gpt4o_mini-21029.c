//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50
#define FILENAME "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

void add_password();
void display_passwords();
void delete_password();
void clear_buffer();

int main() {
    int choice;
    
    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_password() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }

    Password new_password;

    printf("Enter service name: ");
    fgets(new_password.service, MAX_LENGTH, stdin);
    strtok(new_password.service, "\n"); // Remove newline character

    printf("Enter username: ");
    fgets(new_password.username, MAX_LENGTH, stdin);
    strtok(new_password.username, "\n"); // Remove newline character

    printf("Enter password: ");
    fgets(new_password.password, MAX_LENGTH, stdin);
    strtok(new_password.password, "\n"); // Remove newline character

    fprintf(file, "%s,%s,%s\n", new_password.service, new_password.username, new_password.password);
    fclose(file);

    printf("Password added successfully!\n");
}

void display_passwords() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    char line[MAX_LENGTH * 3];
    printf("\n--- Stored Passwords ---\n");
    while (fgets(line, sizeof(line), file)) {
        char service[MAX_LENGTH], username[MAX_LENGTH], password[MAX_LENGTH];
        sscanf(line, "%[^,],%[^,],%[^,\n]", service, username, password);
        printf("Service: %s | Username: %s | Password: %s\n", service, username, password);
    }
    fclose(file);
}

void delete_password() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    Password passwords[MAX_PASSWORDS];
    int count = 0;
    char line[MAX_LENGTH * 3];

    while (fgets(line, sizeof(line), file) && count < MAX_PASSWORDS) {
        sscanf(line, "%[^,],%[^,],%[^,\n]", passwords[count].service, passwords[count].username, passwords[count].password);
        count++;
    }
    fclose(file);

    printf("Select the index of the password to delete (0 to %d): \n", count - 1);
    for (int i = 0; i < count; i++) {
        printf("%d. Service: %s, Username: %s\n", i, passwords[i].service, passwords[i].username);
    }

    int index;
    scanf("%d", &index);
    if (index < 0 || index >= count) {
        printf("Invalid index. No password deleted.\n");
        return;
    }

    file = fopen(FILENAME, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != index) {
            fprintf(file, "%s,%s,%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
        }
    }

    fclose(file);
    printf("Password deleted successfully!\n");
}

void clear_buffer() {
    while (getchar() != '\n');
}