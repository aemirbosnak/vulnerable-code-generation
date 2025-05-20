//FormAI DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

char password_storage[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
int num_passwords = 0;

void store_password(char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: password storage is full\n");
        return;
    }
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Error: password length exceeds maximum of %d\n", MAX_PASSWORD_LENGTH);
        return;
    }
    strncpy(password_storage[num_passwords++], password, MAX_PASSWORD_LENGTH);
    printf("Password successfully stored!\n");
}

void retrieve_password(char *password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(password_storage[i], password) == 0) {
            printf("Password found in storage!\n");
            return;
        }
    }
    printf("Password not found in storage.\n");
}

int main() {
    printf("Welcome to the Password Management Program\n");
    printf("Enter 'store' to store a password or 'retrieve' to retrieve a password: ");
    
    char user_input[10];
    scanf("%s", user_input);
    
    if (strcmp(user_input, "store") == 0) {
        printf("Enter the password to store: ");
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);
        store_password(password);
    } else if (strcmp(user_input, "retrieve") == 0) {
        printf("Enter the password to retrieve: ");
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);
        retrieve_password(password);
    } else {
        printf("Invalid command entered. Please try again.\n");
    }
    
    return 0;
}