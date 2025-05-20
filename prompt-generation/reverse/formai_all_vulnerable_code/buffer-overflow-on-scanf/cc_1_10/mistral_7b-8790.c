//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: automated
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define CHAR_SET_SIZE 62

void generate_password(char* password, int length) {
    int base;
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={}[]|\\:;\"<>,.?/~`";

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        base = rand() % CHAR_SET_SIZE;
        password[i] = char_set[base];
    }
    password[length] = '\0';
}

int main() {
    int length, confirmed = 0;
    char password[MAX_LENGTH + 1];

    printf("Enter desired password length (min. %d, max. %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    while (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Try again: ");
        scanf("%d", &length);
    }

    generate_password(password, length);

    do {
        printf("\nGenerated password: %s\nConfirm password: ", password);
        scanf("%s", password);

        if (strcmp(password, password) == 0) {
            confirmed = 1;
        } else {
            printf("Passwords do not match. Try again: ");
        }
    } while (confirmed != 1);

    printf("\nPassword accepted.\n");

    return 0;
}