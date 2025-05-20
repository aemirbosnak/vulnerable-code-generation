//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 128

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry password_list[MAX_PASSWORDS];
int password_count = 0;

void hide_input(char *buf, size_t len) {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fgets(buf, len, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // Remove newline character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void display_passwords() {
    if (password_count == 0) {
        printf("No passwords saved.\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("Service: %s, Username: %s, Password: %s\n", 
               password_list[i].service, password_list[i].username, password_list[i].password);
    }
}

void save_password() {
    if (password_count >= MAX_PASSWORDS) {
        printf("Password storage is full.\n");
        return;
    }
    
    PasswordEntry entry;
    printf("Enter the service name: ");
    fgets(entry.service, MAX_LENGTH, stdin);
    entry.service[strcspn(entry.service, "\n")] = 0; // Remove newline

    printf("Enter the username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove newline

    printf("Enter the password: ");
    hide_input(entry.password, MAX_LENGTH);

    password_list[password_count++] = entry;
    printf("Password saved successfully!\n");
}

void delete_password() {
    if (password_count == 0) {
        printf("No passwords available to delete.\n");
        return;
    }

    printf("Choose a service to delete:\n");
    for (int i = 0; i < password_count; i++) {
        printf("%d: %s\n", i + 1, password_list[i].service);
    }
    int choice;
    printf("Enter the number of the service you want to delete: ");
    scanf("%d", &choice);
    getchar();  // Clear the newline character from buffer

    if (choice < 1 || choice > password_count) {
        printf("Invalid choice.\n");
        return;
    }

    for (int i = choice - 1; i < password_count - 1; i++) {
        password_list[i] = password_list[i + 1];
    }
    password_count--;
    printf("Password entry deleted successfully!\n");
}

void menu() {
    int choice;
    while (true) {
        printf("\nPassword Management System\n");
        printf("1. Save a Password\n");
        printf("2. Display Stored Passwords\n");
        printf("3. Delete a Password Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline

        switch (choice) {
            case 1:
                save_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Password Management System!\n");
    menu();
    return 0;
}