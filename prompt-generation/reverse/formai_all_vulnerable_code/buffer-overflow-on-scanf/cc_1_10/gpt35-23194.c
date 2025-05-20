//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password_list password_list;
struct password_list {
    char *website;
    char *username;
    char *password;
    password_list *next;
};

void add_password(password_list **passwords, char *website, char *username, char *password) {
    password_list *new_password = malloc(sizeof(password_list));
    int website_len = strlen(website);
    int username_len = strlen(username);
    int password_len = strlen(password);
    new_password->website = malloc(sizeof(char) * (website_len + 1));
    new_password->username = malloc(sizeof(char) * (username_len + 1));
    new_password->password = malloc(sizeof(char) * (password_len + 1));
    strcpy(new_password->website, website);
    strcpy(new_password->username, username);
    strcpy(new_password->password, password);
    new_password->next = NULL;
    if (*passwords == NULL) {
        *passwords = new_password;
    } else {
        password_list *curr = *passwords;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_password;
    }
    printf("Password added successfully!\n");
}

void find_password(password_list *passwords, char *website) {
    while (passwords != NULL) {
        if (strcmp(passwords->website, website) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords->website, passwords->username, passwords->password);
            return;
        }
        passwords = passwords->next;
    }
    printf("Password not found for %s\n", website);
}

void remove_password(password_list **passwords, char *website) {
    password_list *prev = NULL;
    password_list *curr = *passwords;
    while (curr != NULL) {
        if (strcmp(curr->website, website) == 0) {
            if (prev == NULL) {
                *passwords = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->website);
            free(curr->username);
            free(curr->password);
            free(curr);
            printf("Password removed successfully!\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Password not found for %s\n", website);
}

void print_passwords(password_list *passwords) {
    if (passwords == NULL) {
        printf("No passwords saved.\n");
        return;
    }
    while (passwords != NULL) {
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n", passwords->website, passwords->username, passwords->password);
        passwords = passwords->next;
    }
}

void save_passwords(password_list *passwords) {
    FILE *f = fopen("passwords.txt", "w");
    if (f == NULL) {
        printf("Unable to save passwords.\n");
        return;
    }
    while (passwords != NULL) {
        fprintf(f, "%s,%s,%s\n", passwords->website, passwords->username, passwords->password);
        passwords = passwords->next;
    }
    fclose(f);
    printf("Passwords saved successfully!\n");
}

void load_passwords(password_list **passwords) {
    FILE *f = fopen("passwords.txt", "r");
    if (f == NULL) {
        printf("No saved passwords found.\n");
        return;
    }
    char line[256];
    while (fgets(line, 256, f) != NULL) {
        char *website = strtok(line, ",");
        char *username = strtok(NULL, ",");
        char *password = strtok(NULL, ",");
        add_password(passwords, website, username, password);
    }
    fclose(f);
    printf("Passwords loaded successfully!\n");
}

int main() {
    password_list *passwords = NULL;
    int choice;
    char website[256], username[256], password[256];

    printf("Welcome to Password Manager v1.0\n");

    load_passwords(&passwords);

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a password\n");
        printf("2. Find a password\n");
        printf("3. Remove a password\n");
        printf("4. Print all passwords\n");
        printf("5. Save passwords\n");
        printf("6. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                printf("\nPlease enter the website: ");
                fgets(website, 256, stdin);
                website[strcspn(website, "\n")] = '\0'; // remove trailing newline
                printf("Please enter the username: ");
                fgets(username, 256, stdin);
                username[strcspn(username, "\n")] = '\0'; // remove trailing newline
                printf("Please enter the password: ");
                fgets(password, 256, stdin);
                password[strcspn(password, "\n")] = '\0'; // remove trailing newline
                add_password(&passwords, website, username, password);
                break;
            case 2:
                printf("\nPlease enter the website: ");
                fgets(website, 256, stdin);
                website[strcspn(website, "\n")] = '\0'; // remove trailing newline
                find_password(passwords, website);
                break;
            case 3:
                printf("\nPlease enter the website: ");
                fgets(website, 256, stdin);
                website[strcspn(website, "\n")] = '\0'; // remove trailing newline
                remove_password(&passwords, website);
                break;
            case 4:
                printf("\n");
                print_passwords(passwords);
                break;
            case 5:
                save_passwords(passwords);
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}