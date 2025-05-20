//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define NUM_CHARS 10
#define LOWER_CASE 26
#define UPPER_CASE 26
#define SPECIAL_CHARS 11

const char *numbers = "0123456789";
const char *lower_case = "abcdefghijklmnopqrstuvwxyz";
const char *upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>/?`~";

int main() {
    char password[MAX_LENGTH + 1];
    int length, i, random_index;

    srand(time(NULL));

    printf("Enter password length between %d and %d: ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Exiting...\n");
        return 1;
    }

    memset(password, 0, sizeof(password));

    for (i = 0; i < length; i++) {
        int char_type = rand() % 4;

        switch (char_type) {
            case 0:
                random_index = rand() % NUM_CHARS;
                password[i] = numbers[random_index];
                break;
            case 1:
                random_index = rand() % LOWER_CASE;
                password[i] = lower_case[random_index];
                break;
            case 2:
                random_index = rand() % UPPER_CASE;
                password[i] = upper_case[random_index];
                break;
            case 3:
                random_index = rand() % SPECIAL_CHARS;
                password[i] = special_chars[random_index];
                break;
        }
    }

    printf("Generated password: %s\n", password);

    return 0;
}