//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256
#define FILENAME "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_PASSWORDS];
    int count;
} PasswordManager;

void initialize_password_manager(PasswordManager* manager) {
    manager->count = 0;
}

void load_passwords(PasswordManager* manager) {
    FILE* file = fopen(FILENAME, "r");
    if (file) {
        while (fscanf(file, "%s %s", manager->entries[manager->count].service, manager->entries[manager->count].password) == 2) {
            manager->count++;
        }
        fclose(file);
    }
}

void save_passwords(PasswordManager* manager) {
    FILE* file = fopen(FILENAME, "w");
    if (file) {
        for (int i = 0; i < manager->count; i++) {
            fprintf(file, "%s %s\n", manager->entries[i].service, manager->entries[i].password);
        }
        fclose(file);
    }
}

void add_password(PasswordManager* manager) {
    if (manager->count >= MAX_PASSWORDS) {
        printf("Password manager is full!\n");
        return;
    }
    printf("Enter service name: ");
    scanf("%s", manager->entries[manager->count].service);
    printf("Enter password: ");
    scanf("%s", manager->entries[manager->count].password);
    manager->count++;
    save_passwords(manager);
}

void retrieve_password(PasswordManager* manager) {
    char service[MAX_LENGTH];
    printf("Enter service name to retrieve password: ");
    scanf("%s", service);
    
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->entries[i].service, service) == 0) {
            printf("Password for %s is: %s\n", service, manager->entries[i].password);
            return;
        }
    }
    printf("Service not found!\n");
}

void delete_password(PasswordManager* manager) {
    char service[MAX_LENGTH];
    printf("Enter service name to delete password: ");
    scanf("%s", service);
    
    int found = 0;
    for (int i = 0; i < manager->count; i++) {
        if (found) {
            manager->entries[i-1] = manager->entries[i]; // shift up
        } else if (strcmp(manager->entries[i].service, service) == 0) {
            found = 1; // mark the found one
        }
    }
    if (found) {
        manager->count--;
        save_passwords(manager);
        printf("Password for %s deleted!\n", service);
    } else {
        printf("Service not found!\n");
    }
}

void display_menu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PasswordManager manager;
    initialize_password_manager(&manager);
    load_passwords(&manager);

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password(&manager);
                break;
            case 2:
                retrieve_password(&manager);
                break;
            case 3:
                delete_password(&manager);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}