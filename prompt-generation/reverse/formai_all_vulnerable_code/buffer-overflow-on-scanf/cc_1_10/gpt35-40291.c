//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LEN 20
#define MIN_LEN 8

char* generate_password(int len, char* password);

int main() {
    int len = MIN_LEN;
    char* password = malloc(sizeof(char) * (MAX_LEN + 1));

    // set seed for random
    srand(time(NULL));

    printf("Welcome to the password generator!\n");
    while (true) {
        printf("Please enter the length of password you want to generate (8 - 20): ");
        scanf("%d", &len);
        if (len < MIN_LEN || len > MAX_LEN) {
            printf("Invalid length! Please enter a number between %d and %d.\n", MIN_LEN, MAX_LEN);
        } else {
            break;
        }
    }

    printf("Your password is: %s\n", generate_password(len, password));
    free(password);
    return 0;
}

char* generate_password(int len, char* password) {
    if (len <= 0) {
        password[0] = '\0';
        return password;
    }

    int ascii_code = rand() % 94 + 33;
    char random_char = (char) ascii_code;

    // make sure the password doesn't start with whitespace
    if (len == MAX_LEN && random_char == ' ') {
        return generate_password(len, password);
    }

    password[0] = random_char;
    password = generate_password(len - 1, password + 1);
    return password - 1;
}