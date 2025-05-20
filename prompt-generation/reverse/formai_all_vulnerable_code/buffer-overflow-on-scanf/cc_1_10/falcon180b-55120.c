//Falcon-180B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* name, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].length = strlen(password);
    num_passwords++;
}

void generate_password(int length) {
    char password[MAX_PASSWORD_LENGTH];
    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[length] = '\0';
    printf("Generated password: %s\n", password);
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Name: %s\nPassword: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter password length (between 8 and 50): ");
        scanf("%d", &length);

        if (length < 8 || length > 50) {
            printf("Error: Password length must be between 8 and 50.\n");
            continue;
        }

        printf("Enter password: ");
        scanf("%s", password);

        add_password(name, password);
    }

    return 0;
}