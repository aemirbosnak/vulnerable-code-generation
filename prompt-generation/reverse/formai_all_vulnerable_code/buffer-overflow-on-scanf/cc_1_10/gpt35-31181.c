//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_STORED_PASSWORDS 10

typedef struct password_entry {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

typedef struct password_manager {
    password_entry passwords[MAX_STORED_PASSWORDS];
    int num_passwords;
} password_manager;

void add_password_entry(password_manager* manager, char* username, char* password) {
    if (manager->num_passwords == MAX_STORED_PASSWORDS) {
        printf("Error: Password manager is full\n");
        return;
    }

    password_entry* entry = &(manager->passwords[manager->num_passwords]);
    strncpy(entry->username, username, MAX_USERNAME_LENGTH - 1);
    strncpy(entry->password, password, MAX_PASSWORD_LENGTH - 1);

    printf("Added password entry for %s\n", username);
    manager->num_passwords++;
}

int find_password_entry_index(password_manager* manager, char* username) {
    for (int i = 0; i < manager->num_passwords; i++) {
        password_entry* entry = &(manager->passwords[i]);
        if (strcmp(entry->username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void remove_password_entry(password_manager* manager, char* username) {
    int index = find_password_entry_index(manager, username);

    if (index == -1) {
        printf("Error: Could not find password entry for %s\n", username);
        return;
    }

    for (int i = index; i < manager->num_passwords - 1; i++) {
        password_entry* current = &(manager->passwords[i]);
        password_entry* next = &(manager->passwords[i + 1]);
        memcpy(current, next, sizeof(password_entry));
    }

    manager->num_passwords--;
    printf("Removed password entry for %s\n", username);
}

void list_password_entries(password_manager* manager) {
    printf("Password entries:\n");
    for (int i = 0; i < manager->num_passwords; i++) {
        password_entry* entry = &(manager->passwords[i]);
        printf("%s\t%s\n", entry->username, entry->password);
    }
}

typedef struct user_request {
    char command[10];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_request;

user_request get_user_request() {
    user_request request = {"", "", ""};
    scanf("%s", request.command);
    scanf("%s", request.username);
    scanf("%s", request.password);
    return request;
}

void perform_command(password_manager* manager, user_request request) {
    if (strcmp(request.command, "add") == 0) {
        add_password_entry(manager, request.username, request.password);
    } else if (strcmp(request.command, "remove") == 0) {
        remove_password_entry(manager, request.username);
    } else if (strcmp(request.command, "list") == 0) {
        list_password_entries(manager);
    } else {
        printf("Error: Invalid command\n");
    }
}

void print_menu() {
    printf("Password Manager\n");
    printf("Commands:\n");
    printf("add <username> <password>\n");
    printf("remove <username>\n");
    printf("list\n");
    printf("Type 'exit' to quit\n");
}

int main() {
    password_manager manager = {{}, 0};
    print_menu();

    while (1) {
        user_request request = get_user_request();
        if (strcmp(request.command, "exit") == 0) {
            break;
        }
        perform_command(&manager, request);
    }

    return 0;
}