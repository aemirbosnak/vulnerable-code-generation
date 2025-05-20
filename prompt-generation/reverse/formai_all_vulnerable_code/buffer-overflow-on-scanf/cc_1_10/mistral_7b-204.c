//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_COUNT 52
#define SPECIAL_CHAR_COUNT 12

char password[256];
char characters[CHAR_COUNT];
char special_characters[SPECIAL_CHAR_COUNT];

void initialize_arrays() {
    int i;

    for (i = 0; i < CHAR_COUNT; i++) {
        if (i < 10) {
            characters[i] = '0' + i;
        } else if (i < CHAR_COUNT - 10) {
            characters[i] = 'a' + (i - 10);
        } else {
            characters[i] = 'A' + (i - 10 - 26);
        }
    }

    for (i = 0; i < SPECIAL_CHAR_COUNT; i++) {
        special_characters[i] = "!@#$%^&*()_+-={[}]]|\\:\"<>,.?/~`"[i];
    }
}

void generate_password(int length) {
    int i, j, random_index;

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        random_index = rand() % CHAR_COUNT;
        password[i] = (i % 3) == 0 ? special_characters[rand() % SPECIAL_CHAR_COUNT] : characters[random_index];
    }

    password[length] = '\0';
}

int main() {
    int length;

    initialize_arrays();

    printf("Enter the length of the password: ");
    scanf("%d", &length);

    generate_password(length);

    printf("Generated password: %s\n", password);

    return 0;
}