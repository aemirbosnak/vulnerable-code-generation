//Code Llama-13B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random password
char* generate_password() {
    char* password = malloc(10 * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        password[i] = 'a' + rand() % 26;
    }
    return password;
}

// Function to store the password
void store_password(char* password) {
    FILE* file = fopen("password.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s", password);
    fclose(file);
}

// Function to retrieve the password
char* retrieve_password() {
    FILE* file = fopen("password.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char* password = malloc(10 * sizeof(char));
    fgets(password, 10, file);
    fclose(file);
    return password;
}

int main() {
    char* password = generate_password();
    store_password(password);
    char* retrieved_password = retrieve_password();
    if (strcmp(password, retrieved_password) == 0) {
        printf("Password stored and retrieved successfully!\n");
    } else {
        printf("Password not stored correctly!\n");
    }
    free(password);
    free(retrieved_password);
    return 0;
}