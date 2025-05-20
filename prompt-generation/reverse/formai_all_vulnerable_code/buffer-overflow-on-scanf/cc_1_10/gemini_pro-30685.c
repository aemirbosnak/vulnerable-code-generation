//GEMINI-pro DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

typedef struct {
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

int add_password(char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        return -1;
    }
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
    return 0;
}

int get_password(char *name, char *password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(password, passwords[i].password);
            return 0;
        }
    }
    return -1;
}

int delete_password(char *name) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            for (int j = i + 1; j < num_passwords; j++) {
                passwords[j - 1] = passwords[j];
            }
            num_passwords--;
            return 0;
        }
    }
    return -1;
}

int main() {
    int choice;
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];

    while (1) {
        printf("1. Add password\n2. Get password\n3. Delete password\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                if (add_password(name, password) == 0) {
                    printf("Password added successfully.\n");
                } else {
                    printf("Error adding password.\n");
                }
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                if (get_password(name, password) == 0) {
                    printf("Password: %s\n", password);
                } else {
                    printf("Error getting password.\n");
                }
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                if (delete_password(name) == 0) {
                    printf("Password deleted successfully.\n");
                } else {
                    printf("Error deleting password.\n");
                }
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}