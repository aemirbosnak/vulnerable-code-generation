//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

#define NUM_LOWERCASE_CHARS 26
#define NUM_UPPERCASE_CHARS 26
#define NUM_DIGITS 10
#define NUM_SPECIAL_CHARS 12

char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|\\:;\"'<>,.?/~`";

void generate_password(char *password, int length) {
    int index;
    for (int i = 0; i < length; i++) {
        int char_type = rand() % 4;
        switch (char_type) {
            case 0:
                index = rand() % NUM_LOWERCASE_CHARS;
                password[i] = char_set[index + 'a'];
                break;
            case 1:
                index = rand() % NUM_UPPERCASE_CHARS;
                password[i] = char_set[index + 'A'];
                break;
            case 2:
                index = rand() % NUM_DIGITS;
                password[i] = char_set['0' + index];
                break;
            case 3:
                index = rand() % NUM_SPECIAL_CHARS;
                password[i] = char_set[NUM_LOWERCASE_CHARS + NUM_UPPERCASE_CHARS + NUM_DIGITS + index];
                break;
        }
    }
    password[length] = '\0';
}

int main() {
    int password_length;
    char password[MAX_PASSWORD_LENGTH + 1];

    srand(time(NULL));

    password_length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;

    generate_password(password, password_length);

    printf("Generated Password: %s\n", password);

    return 0;
}