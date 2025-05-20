//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define PASSWORD_DB_FILE "passwords.txt"

typedef struct password {
    char site[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct password *next;
} password_t;

password_t *head = NULL;

void save_passwords_to_file() {
    FILE *file = fopen(PASSWORD_DB_FILE, "w");
    
    password_t *current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %s\n", current->site, current->username, current->password);
        current = current->next;
    }
    
    fclose(file);
}

void load_passwords_from_file() {
    head = NULL;
    
    FILE *file = fopen(PASSWORD_DB_FILE, "r");
    if (file == NULL) {
        return;
    }
    
    while (!feof(file)) {
        password_t *new_password = (password_t*) malloc(sizeof(password_t));
        if (fscanf(file, "%s %s %s\n", new_password->site, new_password->username, new_password->password) != 3) {
            free(new_password);
            break;
        }
        
        new_password->next = head;
        head = new_password;
    }
    
    fclose(file);
}

void add_password() {
    password_t *new_password = (password_t*) malloc(sizeof(password_t));
    
    printf("Enter site: ");
    scanf("%s", new_password->site);
    
    printf("Enter username: ");
    scanf("%s", new_password->username);
    
    printf("Enter password: ");
    scanf("%s", new_password->password);
    
    new_password->next = head;
    head = new_password;
    
    save_passwords_to_file();
    
    printf("Password added.\n");
}

void delete_password() {
    printf("Enter site: ");
    char site_to_delete[MAX_PASSWORD_LENGTH];
    scanf("%s", site_to_delete);
    
    if (head == NULL) {
        printf("Password database is empty.\n");
        return;
    }
    
    password_t *current = head;
    password_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->site, site_to_delete) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            save_passwords_to_file();
            printf("Password deleted.\n");
            return;
        }
        
        previous = current;
        current = current->next;
    }
    
    printf("Site not found.\n");
}

void list_passwords() {
    if (head == NULL) {
        printf("Password database is empty.\n");
        return;
    }
    
    password_t *current = head;
    while (current != NULL) {
        printf("Site: %s\n", current->site);
        printf("Username: %s\n", current->username);
        printf("Password: %s\n", current->password);
        printf("\n");
        
        current = current->next;
    }
}

int main() {
    load_passwords_from_file();
    
    while (1) {
        printf("Select an option:\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                list_passwords();
                break;
            case 4:
                save_passwords_to_file();
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}