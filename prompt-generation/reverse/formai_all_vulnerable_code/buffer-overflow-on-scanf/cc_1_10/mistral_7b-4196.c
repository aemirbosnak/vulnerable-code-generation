//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 10
#define MAX_LENGTH 20
#define LOWER 97
#define UPPER 91
#define NUM 48
#define SPECIAL 33

char *love_strings = "love, passion, heart, romance, kiss, sweet, tender, care, dream, desire";
char *romantic_symbols = "♥ ♥♥ ♥♥♥ ♥♥♥♥ ♥♥♥♥♥ ♥♥♥♥♥♥";

void generate_password(char *password, int length) {
    int i, j, random_index;
    char random_char;

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        if (i % 3 == 0) { // Add a love string
            random_index = rand() % (strlen(love_strings) - 1);
            random_char = love_strings[random_index];
            password[i] = random_char;
        } else if (i % 5 == 0) { // Add a romantic symbol
            random_index = rand() % (strlen(romantic_symbols) - 1);
            random_char = romantic_symbols[random_index];
            password[i] = random_char;
        } else { // Add a random character from the alphabet, numbers, or special characters
            int random_type = rand() % 3;

            if (random_type == 0) { // Lowercase
                random_index = rand() % 26;
                random_char = (char)(LOWER + random_index);
            } else if (random_type == 1) { // Uppercase
                random_index = rand() % 26;
                random_char = (char)(UPPER + random_index);
            } else { // Numbers or special characters
                int random_num_or_special = rand() % 2;

                if (random_num_or_special == 0) { // Numbers
                    random_index = rand() % 10;
                    random_char = (char)(NUM + random_index);
                } else { // Special characters
                    random_index = rand() % (SPECIAL + 10);
                    random_char = (char)(SPECIAL + random_index - 10);
                }
            }

            password[i] = random_char;
        }
    }

    password[length] = '\0'; // Null terminate the password
}

int main() {
    int length;
    char password[MAX_LENGTH + 1];

    printf("Enter the desired length of your romantic password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length! Please enter a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    generate_password(password, length);

    printf("Your romantic password is: %s\n", password);

    return 0;
}