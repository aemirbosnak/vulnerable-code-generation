//FormAI DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct system_admin {
    char name[50];
    char username[50];
    char password[50];
    int permissions;
};

struct system_admin sys_admins[10];

int num_sys_admins = 0;

void add_sys_admin() {
    if(num_sys_admins >= 10) {
        printf("Maximum number of system admins reached.\n");
        return;
    }
    struct system_admin new_admin;
    printf("Enter the new system admin's name: ");
    fgets(new_admin.name, 50, stdin);
    printf("Enter the new system admin's username: ");
    fgets(new_admin.username, 50, stdin);
    printf("Enter the new system admin's password: ");
    fgets(new_admin.password, 50, stdin);
    printf("Enter the new system admin's permissions (1 = read only, 2 = read/write, 3 = admin): ");
    scanf("%d", &new_admin.permissions);
    while(getchar() != '\n'); // flush the input buffer
    sys_admins[num_sys_admins++] = new_admin;
    printf("System admin added.\n");
}

void view_sys_admins() {
    if(num_sys_admins == 0) {
        printf("No system admins.\n");
        return;
    }
    for(int i = 0; i < num_sys_admins; i++) {
        printf("Name: %s", sys_admins[i].name);
        printf("Username: %s", sys_admins[i].username);
        printf("Permissions: %d\n", sys_admins[i].permissions);
    }
}

void change_password() {
    char username[50];
    char password[50];
    printf("Enter your username: ");
    fgets(username, 50, stdin);
    printf("Enter your current password: ");
    fgets(password, 50, stdin);
    for(int i = 0; i < num_sys_admins; i++) {
        if(strcmp(sys_admins[i].username, username) == 0 && strcmp(sys_admins[i].password, password) == 0) {
            // found the user
            printf("Enter your new password: ");
            fgets(sys_admins[i].password, 50, stdin);
            printf("Password changed.\n");
            return;
        }
    }
    printf("Invalid username or password.\n");
}

int main() {
    int choice;
    do {
        printf("1. Add system admin\n");
        printf("2. View system admins\n");
        printf("3. Change password\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // flush the input buffer
        switch(choice) {
            case 1:
                add_sys_admin();
                break;
            case 2:
                view_sys_admins();
                break;
            case 3:
                change_password();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}