//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LEN 20
#define MAX_USERNAME_LEN 20
#define MAX_ENTRIES 100

struct password_entry {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASS_LEN];
};

struct password_manager {
    struct password_entry entries[MAX_ENTRIES];
    int num_entries;
};

void add_user(struct password_manager* manager) {
    if(manager->num_entries == MAX_ENTRIES) {
        printf("Password manager is full\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", manager->entries[manager->num_entries].username);
    printf("Enter password: ");
    scanf("%s", manager->entries[manager->num_entries].password);
    manager->num_entries++;
}

void list_users(struct password_manager* manager) {
    if(manager->num_entries == 0) {
        printf("Password manager is empty\n");
        return;
    }

    printf("All Users in Password Manager:\n");
    for(int i=0; i<manager->num_entries; i++) {
        printf("Username: %s | Password: %s\n", manager->entries[i].username, manager->entries[i].password);
    }
}

void delete_user(struct password_manager* manager) {
    if(manager->num_entries == 0) {
        printf("Password manager is empty\n");
        return;
    }

    char username[MAX_USERNAME_LEN];
    printf("Enter username to be deleted: ");
    scanf("%s", username);

    for(int i=0; i<manager->num_entries; i++) {
        if(strcmp(username, manager->entries[i].username) == 0) {
            printf("User '%s' has been deleted\n", manager->entries[i].username);
            for(int j=i; j<manager->num_entries-1; j++) {
                strcpy(manager->entries[j].username, manager->entries[j+1].username);
                strcpy(manager->entries[j].password, manager->entries[j+1].password);
            }
            manager->num_entries--;
            return;
        }
    }

    printf("User '%s' not found in password manager\n", username);
}

void modify_user(struct password_manager* manager) {
    if(manager->num_entries == 0) {
        printf("Password manager is empty\n");
        return;
    }

    char username[MAX_USERNAME_LEN];
    printf("Enter username to be modified: ");
    scanf("%s", username);

    for(int i=0; i<manager->num_entries; i++) {
        if(strcmp(username, manager->entries[i].username) == 0) {
            printf("Enter the new password: ");
            scanf("%s", manager->entries[i].password);
            printf("Password for user '%s' has been modified\n", manager->entries[i].username);
            return;
        }
    }

    printf("User '%s' not found in password manager\n", username);
}

int main() {
    struct password_manager manager;

    manager.num_entries = 0;

    while(1) {
        int choice;

        printf("\nPlease choose an option:\n");
        printf("1 - Add User\n");
        printf("2 - List Users\n");
        printf("3 - Delete User\n");
        printf("4 - Modify User\n");
        printf("5 - Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user(&manager);
                break;
            case 2:
                list_users(&manager);
                break;
            case 3:
                delete_user(&manager);
                break;
            case 4:
                modify_user(&manager);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}