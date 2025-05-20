//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct Password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void print_menu() {
    printf("PASSWORD MANAGER\n");
    printf("1. View passwords\n");
    printf("2. Add password\n");
    printf("3. Edit password\n");
    printf("4. Delete password\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void add_password(struct Password passwords[], int *count) {
    if (*count == MAX_PASSWORDS) {
        printf("Password manager is full.\n");
        return;
    }
    struct Password p;
    printf("Enter website: ");
    scanf("%s", p.website);
    printf("Enter username: ");
    scanf("%s", p.username);
    printf("Enter password: ");
    scanf("%s", p.password);
    passwords[*count] = p;
    *count += 1;
    printf("Password added successfully.\n");
}

void view_passwords(struct Password passwords[], int count) {
    printf("PASSWORDS:\n");
    for (int i=0; i<count; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

int get_password_index(struct Password passwords[], int count, char website[]) {
    for (int i=0; i<count; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            return i;
        }
    }
    return -1;
}

void edit_password(struct Password passwords[], int count) {
    if (count == 0) {
        printf("Password manager is empty.\n");
        return;
    }
    char website[MAX_PASSWORD_LENGTH];
    printf("Enter website of password to edit: ");
    scanf("%s", website);
    int index = get_password_index(passwords, count, website);
    if (index == -1) {
        printf("Password for %s not found.\n", website);
        return;
    }
    struct Password p;
    printf("Enter new website (or leave blank to keep current): ");
    scanf("%s", p.website);
    printf("Enter new username (or leave blank to keep current): ");
    scanf("%s", p.username);
    printf("Enter new password (or leave blank to keep current): ");
    scanf("%s", p.password);
    if (strlen(p.website) == 0) {
        strcpy(p.website, passwords[index].website);
    }
    if (strlen(p.username) == 0) {
        strcpy(p.username, passwords[index].username);
    }
    if (strlen(p.password) == 0) {
        strcpy(p.password, passwords[index].password);
    }
    passwords[index] = p;
    printf("Password for %s updated successfully.\n", website);
}

void delete_password(struct Password passwords[], int *count) {
    if (*count == 0) {
        printf("Password manager is empty.\n");
        return;
    }
    char website[MAX_PASSWORD_LENGTH];
    printf("Enter website of password to delete: ");
    scanf("%s", website);
    int index = get_password_index(passwords, *count, website);
    if (index == -1) {
        printf("Password for %s not found.\n", website);
        return;
    }
    for (int i=index; i<*count-1; i++) {
        passwords[i] = passwords[i+1];
    }
    *count -= 1;
    printf("Password for %s deleted successfully.\n", website);
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int count = 0;
    int choice;
    while (true) {
        print_menu();
        choice = get_choice();
        switch (choice) {
        case 1:
            view_passwords(passwords, count);
            break;
        case 2:
            add_password(passwords, &count);
            break;
        case 3:
            edit_password(passwords, count);
            break;
        case 4:
            delete_password(passwords, &count);
            break;
        case 5:
            printf("Password manager exit.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}