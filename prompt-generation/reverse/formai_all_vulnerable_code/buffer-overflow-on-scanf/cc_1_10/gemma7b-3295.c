//Gemma-7B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int valid;
} Password;

void generate_passwords(Password *passwords, int num) {
    for (int i = 0; i < num; i++) {
        passwords[i].name = malloc(20);
        passwords[i].password = malloc(20);
        passwords[i].valid = 0;
    }
}

void save_passwords(Password *passwords, int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter the name for password %d: ", i + 1);
        scanf("%s", passwords[i].name);

        printf("Enter the password for password %d: ", i + 1);
        scanf("%s", passwords[i].password);

        passwords[i].valid = 1;
    }
}

void show_passwords(Password *passwords, int num) {
    for (int i = 0; i < num; i++) {
        if (passwords[i].valid) {
            printf("Name: %s\n", passwords[i].name);
            printf("Password: %s\n", passwords[i].password);
            printf("\n");
        }
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    generate_passwords(passwords, MAX_PASSWORDS);
    save_passwords(passwords, MAX_PASSWORDS);
    show_passwords(passwords, MAX_PASSWORDS);

    return 0;
}