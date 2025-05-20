//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILE_NAME "passwords.txt"

void add_password();
void view_passwords();
void delete_password();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Password Management System ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
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
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_password() {
    FILE *file;
    char service[MAX_LENGTH], username[MAX_LENGTH], password[MAX_LENGTH];

    printf("Enter service name: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0; // Remove newline
    printf("Enter username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline
    printf("Enter password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s,%s,%s\n", service, username, password);
    fclose(file);
    printf("Password added successfully!\n");
}

void view_passwords() {
    FILE *file;
    char line[MAX_LENGTH];

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    printf("%-20s %-20s %-20s\n", "Service", "Username", "Password");
    printf("-------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        char *service = token ? token : "";
        token = strtok(NULL, ",");
        char *username = token ? token : "";
        token = strtok(NULL, ",");
        char *password = token ? token : "";
        
        printf("%-20s %-20s %-20s\n", service, username, password);
    }
    
    fclose(file);
}

void delete_password() {
    FILE *file, *temp;
    char line[MAX_LENGTH];
    char service[MAX_LENGTH];

    printf("Enter the service name to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0; // Remove newline

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Error opening temp file");
        fclose(file);
        return;
    }

    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, service) == NULL) {
            fputs(line, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);
    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Password entry for '%s' deleted successfully!\n", service);
    } else {
        printf("No entry found for '%s'.\n", service);
    }
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}