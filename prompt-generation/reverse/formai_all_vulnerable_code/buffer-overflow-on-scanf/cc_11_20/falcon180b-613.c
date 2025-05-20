//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

int main() {
    char *password = malloc(MAX_SIZE);
    int password_length = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;
    int num_digits = 0;
    int num_special = 0;

    printf("Enter the desired password length: ");
    scanf("%d", &password_length);

    if (password_length < 4 || password_length > MAX_SIZE) {
        printf("Invalid password length.\n");
        exit(1);
    }

    printf("Enter the number of uppercase letters: ");
    scanf("%d", &num_uppercase);

    printf("Enter the number of lowercase letters: ");
    scanf("%d", &num_lowercase);

    printf("Enter the number of digits: ");
    scanf("%d", &num_digits);

    printf("Enter the number of special characters: ");
    scanf("%d", &num_special);

    for (int i = 0; i < num_uppercase; i++) {
        char rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        while (!isupper(rand_char)) {
            rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        }
        password[i] = rand_char;
    }

    for (int i = num_uppercase; i < num_uppercase + num_lowercase; i++) {
        char rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        while (!islower(rand_char)) {
            rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        }
        password[i] = rand_char;
    }

    for (int i = num_uppercase + num_lowercase; i < num_uppercase + num_lowercase + num_digits; i++) {
        char rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        while (!isdigit(rand_char)) {
            rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        }
        password[i] = rand_char;
    }

    for (int i = num_uppercase + num_lowercase + num_digits; i < num_uppercase + num_lowercase + num_digits + num_special; i++) {
        char rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        while (!isdigit(rand_char) &&!isupper(rand_char) &&!islower(rand_char)) {
            rand_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        }
        password[i] = rand_char;
    }

    for (int i = 0; i < password_length; i++) {
        printf("%c", password[i]);
    }

    printf("\n");
    return 0;
}