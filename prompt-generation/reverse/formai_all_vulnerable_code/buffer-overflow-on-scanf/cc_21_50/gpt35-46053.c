//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 40

int main(void) {
    /* Define character sets for password generation */
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char symbols[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    /* Initialize variables */
    int length, i, rand_index;
    char password[MAX_LENGTH] = {0};

    /* Get desired password length from user */
    printf("Enter password length (up to %d): ", MAX_LENGTH);
    scanf("%d", &length);
    if (length < 1 || length > MAX_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    /* Get desired complexity from user */
    int complex_upper, complex_lower, complex_digits, complex_symbols;
    printf("Enter complexity (1-4):\n");
    printf("1 = lowercase letters\n2 = lowercase and uppercase letters\n");
    printf("3 = lowercase and uppercase letters plus digits\n4 = all characters\n");
    scanf("%d", &complex_symbols);
    switch (complex_symbols) {
        case 1:
            complex_upper = 0;
            complex_lower = 1;
            complex_digits = 0;
            complex_symbols = 0;
            break;
        case 2:
            complex_upper = 1;
            complex_lower = 1;
            complex_digits = 0;
            complex_symbols = 0;
            break;
        case 3:
            complex_upper = 1;
            complex_lower = 1;
            complex_digits = 1;
            complex_symbols = 0;
            break;
        case 4:
            complex_upper = 1;
            complex_lower = 1;
            complex_digits = 1;
            complex_symbols = 1;
            break;
        default:
            printf("Invalid complexity level.\n");
            return 1;
    }

    /* Seed random number generator */
    srand(time(NULL));

    /* Generate password */
    for (i = 0; i < length; i++) {
        /* Select character set */
        char *char_set;
        int char_set_size;
        if (i == 0 && complex_upper) {
            char_set = uppercase;
            char_set_size = sizeof(uppercase)/sizeof(uppercase[0]);
        }
        else if (i == 0 && complex_lower) {
            char_set = lowercase;
            char_set_size = sizeof(lowercase)/sizeof(lowercase[0]);
        }
        else if (i == 0 && complex_digits) {
            char_set = digits;
            char_set_size = sizeof(digits)/sizeof(digits[0]);
        }
        else if (i == 0 && complex_symbols) {
            char_set = symbols;
            char_set_size = sizeof(symbols)/sizeof(symbols[0]);
        }
        else {
            /* Ensure password contains at least one character from each chosen set */
            do {
                rand_index = rand() % 4;
            } while ((rand_index == 0 && !complex_upper) || 
                     (rand_index == 1 && !complex_lower) || 
                     (rand_index == 2 && !complex_digits) || 
                     (rand_index == 3 && !complex_symbols));
            switch (rand_index) {
                case 0:
                    char_set = uppercase;
                    char_set_size = sizeof(uppercase)/sizeof(uppercase[0]);
                    break;
                case 1:
                    char_set = lowercase;
                    char_set_size = sizeof(lowercase)/sizeof(lowercase[0]);
                    break;
                case 2:
                    char_set = digits;
                    char_set_size = sizeof(digits)/sizeof(digits[0]);
                    break;
                case 3:
                    char_set = symbols;
                    char_set_size = sizeof(symbols)/sizeof(symbols[0]);
                    break;
            }
        }
        /* Randomly select character from character set */
        rand_index = rand() % char_set_size;
        password[i] = char_set[rand_index];
    }
    /* Add newline character for readability */
    password[length] = '\n';

    /* Output password */
    printf("Your secure password is:\n");
    printf("%s", password);

    return 0;
}