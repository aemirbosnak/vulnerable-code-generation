//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 20

struct Password {
    int id;
    char password[MAX_PASSWORD_LENGTH+1];
};

void display_menu() {
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit\n");
}

void add_password(struct Password passwords[], int *password_count) {
    if (*password_count == MAX_PASSWORDS) {
        printf("You've reached the maximum number of passwords\n");
        return;
    }
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    struct Password new_password;
    new_password.id = *password_count + 1;
    strcpy(new_password.password, password);
    passwords[*password_count] = new_password;
    *password_count += 1;
    printf("Password added successfully!\n");
}

void view_passwords(struct Password passwords[], int password_count) {
    if (password_count == 0) {
        printf("There are no passwords currently saved.\n");
        return;
    }
    printf("ID\tPassword\n");
    for (int i = 0; i < password_count; i++) {
        printf("%d\t%s\n", passwords[i].id, passwords[i].password);
    }
}

void delete_password(struct Password passwords[], int *password_count) {
    if (password_count == 0) {
        printf("There are no passwords currently saved.\n");
        return;
    }
    int id_to_delete;
    printf("Enter ID of password to delete: ");
    scanf("%d", &id_to_delete);
    int index_to_delete = -1;
    for (int i = 0; i < *password_count; i++) {
        if (passwords[i].id == id_to_delete) {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete == -1) {
        printf("ID not found\n");
        return;
    }
    for (int i = index_to_delete; i < *password_count - 1; i++) {
        passwords[i] = passwords[i+1];
    }
    *password_count -= 1;
    printf("Password deleted successfully!\n");
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int password_count = 0;

    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password(passwords, &password_count);
                break;
            case 2:
                view_passwords(passwords, password_count);
                break;
            case 3:
                delete_password(passwords, &password_count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}