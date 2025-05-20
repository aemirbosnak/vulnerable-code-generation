//Gemma-7B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
} Password;

void create_passwords(Password *passwords) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = malloc(20);
        passwords[i].password = malloc(50);
    }
}

void store_passwords(Password *passwords) {
    FILE *fp = fopen("passwords.txt", "w");
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        fprintf(fp, "%s: %s\n", passwords[i].name, passwords[i].password);
    }
    fclose(fp);
}

void retrieve_passwords(Password *passwords) {
    FILE *fp = fopen("passwords.txt", "r");
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        fscanf(fp, "%s: %s\n", passwords[i].name, passwords[i].password);
    }
    fclose(fp);
}

int main() {
    Password passwords[MAX_PASSWORDS];
    create_passwords(passwords);

    // Store passwords
    passwords[0].name = "Alice";
    passwords[0].password = "StrongPassword";
    passwords[1].name = "Bob";
    passwords[1].password = "SecretSecret";

    store_passwords(passwords);

    // Retrieve passwords
    retrieve_passwords(passwords);

    printf("Alice's password: %s\n", passwords[0].password);
    printf("Bob's password: %s\n", passwords[1].password);

    return 0;
}