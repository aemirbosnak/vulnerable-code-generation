//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to generate a random string of given length
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    if (string == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        string[i] = rand() % 94 + 33; // 33 is the ASCII code for '!'
    }
    string[length] = '\0';

    return string;
}

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric(char *string) {
    for (int i = 0; string[i]!= '\0'; i++) {
        if (!isalnum(string[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a secure password of given length
char *generate_secure_password(int length) {
    char *password = NULL;
    int is_secure = 0;

    while (!is_secure) {
        password = generate_random_string(length);
        is_secure = is_alphanumeric(password);
    }

    return password;
}

int main() {
    int length;

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    if (length <= 0 || length > MAX_LENGTH) {
        printf("Error: Invalid password length.\n");
        exit(1);
    }

    char *password = generate_secure_password(length);
    printf("Secure password: %s\n", password);

    free(password);
    return 0;
}