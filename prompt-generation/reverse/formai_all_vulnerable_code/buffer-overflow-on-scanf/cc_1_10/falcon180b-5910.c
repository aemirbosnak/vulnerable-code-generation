//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

int compare_strings(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] == s2[i]) {
        i++;
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 1;
        }
    }
    return 0;
}

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void delete_password() {
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username to delete: ");
    scanf("%s", username);
    for (int i = 0; i < num_passwords; i++) {
        if (compare_strings(passwords[i].username, username)) {
            free(passwords[i].username);
            free(passwords[i].password);
            passwords[i] = passwords[num_passwords - 1];
            num_passwords--;
            break;
        }
    }
}

void list_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                list_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}