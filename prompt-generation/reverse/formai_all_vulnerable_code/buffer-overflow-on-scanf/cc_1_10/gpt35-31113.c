//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

/* Function prototypes */
void menu();
void add_password();
void view_password();
void update_password();
void delete_password();
void save_passwords();
void get_passwords();
void encrypt(char[]);
void decrypt(char[], char[]);
void clear_input_buffer();

/* Global variables */
struct Password {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} password_list[100];

int total_passwords = 0;
char master_password[MAX_LENGTH] = "";

int main() {
    printf("Welcome to Brave Password Manager!\n");

    // Ask user to set master password
    printf("Please set a master password: ");
    fgets(master_password, MAX_LENGTH, stdin);
    master_password[strcspn(master_password, "\n")] = 0;
    encrypt(master_password);

    // Load passwords from file
    get_passwords();

    // Display menu and wait for user input
    menu();

    return 0;
}

void menu() {
    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Update a password\n");
        printf("4. Delete a password\n");
        printf("5. Save passwords\n");
        printf("6. Exit\n");

        printf("Enter choice (1-6): ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: add_password(); break;
            case 2: view_password(); break;
            case 3: update_password(); break;
            case 4: delete_password(); break;
            case 5: save_passwords(); break;
            case 6: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
}

void add_password() {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    // Get service name
    printf("Enter service name: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0;

    // Get username
    printf("Enter username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;

    // Get password
    printf("Enter password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;

    // Add password to list
    strcpy(password_list[total_passwords].service, service);
    strcpy(password_list[total_passwords].username, username);
    encrypt(password);
    strcpy(password_list[total_passwords].password, password);

    printf("Password added for %s.\n", service);
    total_passwords++;
}

void view_password() {
    int i;

    if (total_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Service\t\tUsername\tPassword\n");
    printf("---------------------------------------------------------\n");

    for (i = 0; i < total_passwords; i++) {
        printf("%-15s\t%-15s\t%s\n", password_list[i].service, password_list[i].username, password_list[i].password);
    }
}

void update_password() {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int i;

    if (total_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    // Get service name
    printf("Enter service name: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0;

    // Find the password for the service
    for (i = 0; i < total_passwords; i++) {
        if (strcmp(password_list[i].service, service) == 0) {
            // Get username
            printf("Enter new username (leave blank to keep existing username): ");
            fgets(username, MAX_LENGTH, stdin);
            username[strcspn(username, "\n")] = 0;

            if (strlen(username) > 0) {
                strcpy(password_list[i].username, username);
            }

            // Get password
            printf("Enter new password (leave blank to keep existing password): ");
            fgets(password, MAX_LENGTH, stdin);
            password[strcspn(password, "\n")] = 0;

            if (strlen(password) > 0) {
                encrypt(password);
                strcpy(password_list[i].password, password);
            }

            printf("Password updated for %s.\n", service);
            return;
        }
    }

    printf("No password found for %s.\n", service);
}

void delete_password() {
    char service[MAX_LENGTH];
    int i, j;

    if (total_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    // Get service name
    printf("Enter service name: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0;

    // Find the password for the service and delete it
    for (i = 0; i < total_passwords; i++) {
        if (strcmp(password_list[i].service, service) == 0) {
            printf("Password deleted for %s.\n", service);

            // Shift all passwords after the deleted one down one index
            for (j = i; j < total_passwords - 1; j++) {
                strcpy(password_list[j].service, password_list[j+1].service);
                strcpy(password_list[j].username, password_list[j+1].username);
                strcpy(password_list[j].password, password_list[j+1].password);
            }

            total_passwords--;
            return;
        }
    }

    printf("No password found for %s.\n", service);
}

void save_passwords() {
    FILE *fp;
    char filename[MAX_LENGTH];
    int i;

    if (total_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Enter filename to save to: ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write master password to file
    fprintf(fp, "%s\n", master_password);

    // Write each password to file
    for (i = 0; i < total_passwords; i++) {
        fprintf(fp, "%s\n", password_list[i].service);
        fprintf(fp, "%s\n", password_list[i].username);
        fprintf(fp, "%s\n", password_list[i].password);
    }

    fclose(fp);
    printf("Passwords saved to %s.\n", filename);
}

void get_passwords() {
    FILE *fp;
    char filename[MAX_LENGTH], line[MAX_LENGTH];
    int i = 0;

    printf("Enter filename to load from: ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read master password from file and try to decrypt it
    fgets(line, MAX_LENGTH, fp);
    line[strcspn(line, "\n")] = 0;
    decrypt(line, master_password);

    // Read each password from file and add it to the list
    while (fgets(line, MAX_LENGTH, fp)) {
        line[strcspn(line, "\n")] = 0;

        if (i % 3 == 0) {
            strcpy(password_list[total_passwords].service, line);
        } else if (i % 3 == 1) {
            strcpy(password_list[total_passwords].username, line);
        } else {
            decrypt(line, password_list[total_passwords].password);
            total_passwords++;
        }

        i++;
    }

    fclose(fp);
    printf("Passwords loaded from %s.\n", filename);
}

void encrypt(char str[]) {
    int i;

    // Change each character to its corresponding alphabetical position
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]) - 'a';
    }

    // Add 1 to each character
    for (i = 0; i < strlen(str); i++) {
        str[i]++;
    }
}

void decrypt(char str[], char key[]) {
    int i;

    // Subtract 1 from each character
    for (i = 0; i < strlen(str); i++) {
        str[i]--;
    }

    // Change each character to its corresponding alphabetical character
    for (i = 0; i < strlen(str); i++) {
        str[i] = key[(int)str[i]];
    }
}

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}