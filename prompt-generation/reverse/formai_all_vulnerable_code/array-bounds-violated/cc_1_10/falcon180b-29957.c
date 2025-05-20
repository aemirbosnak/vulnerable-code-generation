//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 64
#define MIN_LENGTH 8
#define NUM_SYMBOLS 6
#define NUM_LOWER 26
#define NUM_UPPER 26
#define NUM_NUMBERS 10

void generate_password(char* password, int length, int symbols, int lowercase, int uppercase, int numbers);

int main() {
    int length = 12;
    int symbols = 2;
    int lowercase = 1;
    int uppercase = 1;
    int numbers = 1;

    char password[MAX_LENGTH];

    generate_password(password, length, symbols, lowercase, uppercase, numbers);

    printf("Generated password: %s\n", password);

    return 0;
}

void generate_password(char* password, int length, int symbols, int lowercase, int uppercase, int numbers) {
    int i;
    char charset[NUM_SYMBOLS];
    int num_charsets = 0;

    // Initialize charset
    charset[num_charsets++] = '!';
    charset[num_charsets++] = '@';
    charset[num_charsets++] = '#';
    charset[num_charsets++] = '$';
    charset[num_charsets++] = '%';
    charset[num_charsets++] = '&';

    if (lowercase) {
        for (i = 0; i < NUM_LOWER; i++) {
            charset[num_charsets++] = 'a' + i;
        }
    }

    if (uppercase) {
        for (i = 0; i < NUM_UPPER; i++) {
            charset[num_charsets++] = 'A' + i;
        }
    }

    if (numbers) {
        for (i = 0; i < NUM_NUMBERS; i++) {
            charset[num_charsets++] = '0' + i;
        }
    }

    // Shuffle charset
    for (i = 0; i < num_charsets; i++) {
        int j = rand() % num_charsets;

        char temp = charset[i];
        charset[i] = charset[j];
        charset[j] = temp;
    }

    // Generate password
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % num_charsets];
    }

    password[length] = '\0';
}