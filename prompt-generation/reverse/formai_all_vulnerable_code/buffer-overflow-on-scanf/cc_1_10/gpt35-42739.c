//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char website[50];
    char username[50];
    char password[50];
};

int num_passwords = 0;

void add_password(struct password passwords[]) {
    struct password new_password;
    printf("Enter website: ");
    scanf("%s", new_password.website);
    printf("Enter username: ");
    scanf("%s", new_password.username);
    printf("Enter password: ");
    scanf("%s", new_password.password);
    passwords[num_passwords++] = new_password;
    printf("Password added successfully!\n");
}

void list_passwords(struct password passwords[]) {
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s - %s - %s\n", i+1, passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void delete_password(struct password passwords[]) {
    int index;
    printf("Enter index of password to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > num_passwords) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index - 1; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i+1];
    }
    num_passwords--;
    printf("Password deleted successfully!\n");
}

int main() {
    struct password passwords[100];
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. List all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password(passwords);
                break;
            case 2:
                list_passwords(passwords);
                break;
            case 3:
                delete_password(passwords);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}