//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

#define CHARACTER_SET_SIZE 94
#define CHARACTER_SET \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
    "abcdefghijklmnopqrstuvwxyz" \
    "0123456789" \
    "!@#$%^&*()_+-=[]{}|;:,.<>?/~`"

void generate_password(int length, char *password) {
    static int initialized = 0;
    static char character_set[CHARACTER_SET_SIZE];

    if (!initialized) {
        memset(character_set, 0, CHARACTER_SET_SIZE);
        strcpy(character_set, CHARACTER_SET);
        srand(time(NULL));
        initialized = 1;
    }

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password length must be between %d and %d\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        exit(1);
    }

    int i;
    for (i = 0; i < length; i++) {
        int index = rand() % CHARACTER_SET_SIZE;
        password[i] = character_set[index];
    }

    password[length] = '\0';
}

int main() {
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    char password[MAX_PASSWORD_LENGTH];
    generate_password(length, password);

    printf("Generated password: %s\n", password);

    return 0;
}