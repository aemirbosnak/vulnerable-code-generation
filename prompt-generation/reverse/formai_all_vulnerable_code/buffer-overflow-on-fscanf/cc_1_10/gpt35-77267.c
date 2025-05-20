//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum Password Length
#define MAX_LEN 20

// Password Structure
typedef struct password {
    char name[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
} Password;

// Function Declarations
int menu();
void add_password(Password **passwords, int *num_passwords);
void view_password(Password *password);
void edit_password(Password *passwords, int num_passwords);
void delete_password(Password **passwords, int *num_passwords);
void save_passwords(Password *passwords, int num_passwords);
Password* load_passwords(int *num_passwords);
void display_passwords(Password *passwords, int num_passwords);

// Main Function
int main() {
    Password *passwords = NULL;
    int num_passwords = 0;
    int command;

    printf("Welcome to Password Manager\n\n");
    passwords = load_passwords(&num_passwords);
    while ((command = menu()) != 6) {
        switch (command) {
            case 1:
                add_password(&passwords, &num_passwords);
                break;
            case 2:
                display_passwords(passwords, num_passwords);
                break;
            case 3:
                edit_password(passwords, num_passwords);
                break;
            case 4:
                delete_password(&passwords, &num_passwords);
                break;
            case 5:
                save_passwords(passwords, num_passwords);
                printf("Passwords saved.\n\n");
                break;
            default:
                printf("Invalid command.\n\n");
                break;
        }
    }

    free(passwords);
    return 0;
}

// Function for displaying menu
int menu() {
    int command;
    printf("Menu:\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Edit Password\n");
    printf("4. Delete Password\n");
    printf("5. Save Passwords\n");
    printf("6. Exit\n");
    printf("Enter command: ");
    scanf("%d", &command);
    printf("\n");
    return command;
}

// Function for adding password
void add_password(Password **passwords, int *num_passwords) {
    char name[MAX_LEN], username[MAX_LEN], password[MAX_LEN];
    Password *new_password;

    printf("Add Password:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    new_password = realloc(*passwords, (*num_passwords + 1) * sizeof(Password));
    if (new_password == NULL) {
        printf("Error: Memory allocation failed.\n\n");
        return;
    }

    strcpy(new_password[*num_passwords].name, name);
    strcpy(new_password[*num_passwords].username, username);
    strcpy(new_password[*num_passwords].password, password);

    *passwords = new_password;
    *num_passwords += 1;

    printf("\n");
}

// Function for viewing password
void view_password(Password *password) {
    printf("%s: %s\n", password->username, password->password);
}

// Function for editing password
void edit_password(Password *passwords, int num_passwords) {
    char name[MAX_LEN], new_username[MAX_LEN], new_password[MAX_LEN];
    int i;

    printf("Edit Password:\n");
    printf("Name: ");
    scanf("%s", name);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("New Username: ");
            scanf("%s", new_username);
            printf("New Password: ");
            scanf("%s", new_password);

            strcpy(passwords[i].username, new_username);
            strcpy(passwords[i].password, new_password);

            printf("Password updated.\n\n");
            return;
        }
    }

    printf("Password not found.\n\n");
}

// Function for deleting password
void delete_password(Password **passwords, int *num_passwords) {
    char name[MAX_LEN];
    Password *temp_passwords;
    int i, delete_index = -1;

    printf("Delete Password:\n");
    printf("Name: ");
    scanf("%s", name);

    for (i = 0; i < *num_passwords; i++) {
        if (strcmp((*passwords)[i].name, name) == 0) {
            delete_index = i;
            break;
        }
    }

    if (delete_index == -1) {
        printf("Password not found.\n\n");
        return;
    }

    temp_passwords = malloc((*num_passwords - 1) * sizeof(Password));
    if (temp_passwords == NULL) {
        printf("Error: Memory allocation failed.\n\n");
        return;
    }

    for (i = 0; i < *num_passwords; i++) {
        if (i < delete_index) {
            temp_passwords[i] = (*passwords)[i];
        } else if (i == delete_index) {
            continue;
        } else {
            temp_passwords[i - 1] = (*passwords)[i];
        }
    }

    free(*passwords);
    *passwords = temp_passwords;
    *num_passwords -= 1;

    printf("Password deleted.\n\n");
}

// Function for saving passwords to file
void save_passwords(Password *passwords, int num_passwords) {
    FILE *file;
    int i;

    file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    for (i = 0; i < num_passwords; i++) {
        fprintf(file, "%s %s %s\n", passwords[i].name, passwords[i].username, passwords[i].password);
    }

    fclose(file);
}

// Function for loading passwords from file
Password* load_passwords(int *num_passwords) {
    FILE *file;
    Password *passwords = NULL;
    char name[MAX_LEN], username[MAX_LEN], password[MAX_LEN];

    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("File not found.\n\n");
        return NULL;
    }

    while (fscanf(file, "%s %s %s\n", name, username, password) == 3) {
        passwords = realloc(passwords, (*num_passwords + 1) * sizeof(Password));
        if (passwords == NULL) {
            printf("Error: Memory allocation failed.\n");
            return NULL;
        }
        strcpy(passwords[*num_passwords].name, name);
        strcpy(passwords[*num_passwords].username, username);
        strcpy(passwords[*num_passwords].password, password);
        *num_passwords += 1;
    }

    fclose(file);

    return passwords;
}

// Function for displaying all passwords
void display_passwords(Password *passwords, int num_passwords) {
    int i;
    printf("Passwords:\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%s:\n", passwords[i].name);
        view_password(&passwords[i]);
    }
    printf("\n");
}