//Code Llama-13B DATASET v1.0 Category: Password management ; Style: Donald Knuth
// Don Knuth's Password Management Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random password
char* generate_password() {
    char* password = malloc(16);
    const char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+;:,<.>/?";
    int password_length = 16;
    int i;

    srand(time(NULL));

    for (i = 0; i < password_length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    return password;
}

// Function to store passwords in a file
void store_password(char* password) {
    FILE* fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(fp, "%s\n", password);
    fclose(fp);
}

// Function to retrieve passwords from a file
char* retrieve_password() {
    FILE* fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char* password = malloc(16);
    fscanf(fp, "%s", password);
    fclose(fp);

    return password;
}

int main() {
    char* password = generate_password();
    store_password(password);
    printf("Password: %s\n", password);

    char* retrieved_password = retrieve_password();
    printf("Retrieved password: %s\n", retrieved_password);

    return 0;
}