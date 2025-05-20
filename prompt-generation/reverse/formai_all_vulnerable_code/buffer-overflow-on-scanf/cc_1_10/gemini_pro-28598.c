//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *site;
    char *username;
    char *password;
} password_t;

int main() {
    int num_passwords = 0;
    password_t *passwords = NULL;

    // Get the number of passwords from the user
    printf("Enter the number of passwords you want to store: ");
    scanf("%d", &num_passwords);

    // Allocate memory for the passwords
    passwords = malloc(sizeof(password_t) * num_passwords);

    // Get the details of each password from the user
    for (int i = 0; i < num_passwords; i++) {
        printf("Enter the site name: ");
        passwords[i].site = malloc(100);
        scanf("%s", passwords[i].site);

        printf("Enter the username: ");
        passwords[i].username = malloc(100);
        scanf("%s", passwords[i].username);

        printf("Enter the password: ");
        passwords[i].password = malloc(100);
        scanf("%s", passwords[i].password);
    }

    // Print the details of each password
    printf("\nHere are the passwords you entered:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Site: %s\n", passwords[i].site);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }

    // Free the memory allocated for the passwords
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i].site);
        free(passwords[i].username);
        free(passwords[i].password);
    }
    free(passwords);

    return 0;
}