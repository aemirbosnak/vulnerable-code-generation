//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

char *generate_password(int length) {
    char *password = malloc(length + 1);  // +1 for the null-terminator
    if (password == NULL) {
        return NULL;
    }

    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < length; i++) {
        int type = rand() % 4;  // 0: lowercase, 1: uppercase, 2: digit, 3: symbol

        switch (type) {
            case 0:  // lowercase
                password[i] = 'a' + (rand() % 26);
                break;
            case 1:  // uppercase
                password[i] = 'A' + (rand() % 26);
                break;
            case 2:  // digit
                password[i] = '0' + (rand() % 10);
                break;
            case 3:  // symbol
                password[i] = "!@#$%^&*()_+}{|"[(rand() % 16)];
                break;
        }
    }

    password[length] = '\0';  // Null-terminate the string

    return password;
}

int main() {
    int length;

    printf("Enter the desired length of the password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Please enter a value between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    char *password = generate_password(length);
    if (password == NULL) {
        printf("Failed to generate password.\n");
        return 2;
    }

    printf("Your password is: %s\n", password);
    free(password);

    return 0;
}