#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 10
#define MAX_PASSWORD_LEN 20

typedef struct User {
    char name[MAX_NAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

User user[] = {
    {"admin", "secret"},
    {"guest", "pass123"}
};

void login() {
    char inputName[MAX_NAME_LEN];
    char inputPassword[MAX_PASSWORD_LEN];
    int i;

    printf("Enter username: ");
    gets(inputName);

    printf("Enter password: ");
    gets(inputPassword);

    for (i = 0; i < 2; i++) {
        if (strcmp(user[i].name, inputName) == 0 && strcmp(user[i].password, inputPassword) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid credentials. Please try again.\n");
}

int main() {
    login();
    return 0;
}
