//Code Llama-13B DATASET v1.0 Category: Password management ; Style: immersive
// Password management program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random password
char* generate_password() {
    char password[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        password[i] = rand() % 26 + 'a';
    }
    return password;
}

// Function to check if a password is valid
int is_valid_password(char* password) {
    if (strlen(password) < 8) {
        return 0;
    }
    if (strchr(password, ' ') != NULL) {
        return 0;
    }
    if (strchr(password, '\'') != NULL) {
        return 0;
    }
    return 1;
}

// Function to save a password
void save_password(char* password) {
    FILE* file = fopen("password.txt", "w");
    fprintf(file, "%s", password);
    fclose(file);
}

// Function to load a password
char* load_password() {
    FILE* file = fopen("password.txt", "r");
    char* password = malloc(10);
    fgets(password, 10, file);
    fclose(file);
    return password;
}

// Function to check if a password is the same as the saved one
int is_same_password(char* password) {
    char* saved_password = load_password();
    int same = strcmp(password, saved_password) == 0;
    free(saved_password);
    return same;
}

// Main function
int main() {
    char password[10];
    printf("Enter a password: ");
    scanf("%s", password);
    if (!is_valid_password(password)) {
        printf("Invalid password.\n");
        return 1;
    }
    if (is_same_password(password)) {
        printf("Password already exists.\n");
        return 1;
    }
    save_password(password);
    printf("Password saved.\n");
    return 0;
}