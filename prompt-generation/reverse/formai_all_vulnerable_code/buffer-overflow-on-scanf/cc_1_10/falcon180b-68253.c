//Falcon-180B DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(Password* password, int length) {
    const char* characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/";
    int i;
    for (i = 0; i < length; i++) {
        password->password[i] = characters[rand() % strlen(characters)];
    }
    password->length = length;
}

int main() {
    int choice;
    while (1) {
        printf("\n");
        printf("1. Generate password\n");
        printf("2. Save password\n");
        printf("3. Retrieve password\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter password length: ");
            int length;
            scanf("%d", &length);
            generate_password(&passwords[num_passwords], length);
            num_passwords++;
            break;
        case 2:
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);
            strcpy(passwords[num_passwords].password, password);
            passwords[num_passwords].length = strlen(password);
            num_passwords++;
            break;
        case 3:
            printf("Enter password index: ");
            int index;
            scanf("%d", &index);
            if (index >= 0 && index < num_passwords) {
                printf("Password: %s\n", passwords[index].password);
            } else {
                printf("Invalid index\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}