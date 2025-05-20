//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 20
#define CHAR_COUNT 5
#define NUM_CHARS 10
#define LOWER_CASE 62
#define UPPER_CASE 91
#define DIGITS 48
#define SPECIAL_CHARS 33

int main() {
    char password[LENGTH + 1];
    int i, j, random_index;
    char random_char;

    srand(time(NULL));

    printf("Generating a secure password of length %d:\n", LENGTH);

    for (i = 0; i < LENGTH; i++) {
        int char_type = rand() % CHAR_COUNT;

        switch (char_type) {
            case 0:
                random_index = rand() % NUM_CHARS;
                random_char = (char)(rand() % 10 + '0');
                password[i] = random_char;
                break;
            case 1:
                random_index = rand() % LOWER_CASE;
                random_char = (char)(rand() % 26 + 'a');
                password[i] = random_char;
                break;
            case 2:
                random_index = rand() % UPPER_CASE;
                random_char = (char)(rand() % 26 + 'A');
                password[i] = random_char;
                break;
            case 3:
                random_index = rand() % SPECIAL_CHARS;
                random_char = (char)(rand() % 32 + SPECIAL_CHARS);
                password[i] = random_char;
                break;
            default:
                random_index = rand() % (NUM_CHARS + LOWER_CASE + UPPER_CASE + SPECIAL_CHARS);
                random_char = password[random_index];
                password[i] = random_char;
                memmove(password + random_index, password + i, 1);
                break;
        }
    }

    password[LENGTH] = '\0';

    printf("Generated password: %s\n", password);

    return 0;
}