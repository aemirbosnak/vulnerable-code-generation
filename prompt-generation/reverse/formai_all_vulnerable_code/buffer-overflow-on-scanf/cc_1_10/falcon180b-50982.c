//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[i] = '\0';
}

void add_password(char* password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            printf("Password already exists.\n");
            return;
        }
    }
    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].length = strlen(password);
    num_passwords++;
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%d. %s\n", i+1, passwords[i].password);
    }
}

int main() {
    int choice;
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("1. Generate password\n");
        printf("2. Add password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the length of the password: ");
                scanf("%d", &passwords[num_passwords].length);
                generate_password(passwords[num_passwords].password, passwords[num_passwords].length);
                num_passwords++;
                break;
            case 2:
                printf("Enter the password: ");
                scanf("%s", password);
                add_password(password);
                break;
            case 3:
                print_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}