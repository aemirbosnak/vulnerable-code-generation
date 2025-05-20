//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }
    printf("Enter name for password: ");
    scanf("%s", passwords[num_passwords].name);
    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);
    num_passwords++;
}

void view_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\n%s\n", passwords[i].name, passwords[i].password);
    }
}

void search_password() {
    printf("Enter name to search for password: ");
    char search_name[50];
    scanf("%s", search_name);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, search_name) == 0) {
            printf("%s\n%s\n", passwords[i].name, passwords[i].password);
        }
    }
}

void delete_password() {
    printf("Enter name of password to delete: ");
    char delete_name[50];
    scanf("%s", delete_name);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, delete_name) == 0) {
            memset(passwords[i].password, 0, PASSWORD_LENGTH);
            strcpy(passwords[i].name, "");
            num_passwords--;
        }
    }
}

int main() {
    system("clear");
    printf("Password Manager\n");
    int choice;
    while (1) {
        printf("\n1. Add password\n2. View passwords\n3. Search password\n4. Delete password\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}