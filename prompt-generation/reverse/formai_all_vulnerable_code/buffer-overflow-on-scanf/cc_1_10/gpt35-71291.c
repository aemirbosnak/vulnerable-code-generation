//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20 // Maximum password length
#define MAX_USERNAME_LEN 20 // Maximum username length

struct Account {
    char username[MAX_USERNAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
};

int main() {
    int n; // Number of accounts
    printf("Enter the number of accounts: ");
    scanf("%d", &n);
    printf("\n");

    struct Account *accounts = malloc(n * sizeof(struct Account));
    if (!accounts) {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(1);
    }

    // Reading account data from user
    for (int i = 0; i < n; i++) {
        printf("Account %d:\n", i + 1);
        printf("Enter username (max %d characters): ", MAX_USERNAME_LEN);
        scanf("%s", accounts[i].username);
        printf("Enter password (max %d characters): ", MAX_PASSWORD_LEN);
        scanf("%s", accounts[i].password);
        printf("\n");
    }

    // Writing account data to file
    FILE *fp = fopen("passwords.txt", "w");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %s\n", accounts[i].username, accounts[i].password);
    }
    fclose(fp);

    // Reading account data from file
    fp = fopen("passwords.txt", "r");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file\n");
        exit(1);
    }
    char buffer[MAX_USERNAME_LEN + MAX_PASSWORD_LEN + 3];
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *username = strtok(buffer, " ");
        char *password = strtok(NULL, " ");
        printf("Username: %s\n", username);
        printf("Password: %s\n", password);
    }
    fclose(fp);

    free(accounts);
    return 0;
}