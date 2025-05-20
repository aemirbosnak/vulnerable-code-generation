//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char password[50];
    int length = 0;
    char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}|;:,.<>/?";
    char all_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";

    printf("Enter desired password length (minimum 8): ");
    scanf("%d", &length);

    if (length < 8) {
        printf("Password length too short. Please enter a length of 8 or more.\n");
        return 1;
    }

    srand(time(NULL));

    int random_chars[length];
    int random_chars_count = 0;

    while (random_chars_count < length) {
        int random_index = rand() % 4;

        if (random_index == 0 && strlen(lowercase_chars) > 0) {
            password[random_chars_count] = lowercase_chars[rand() % strlen(lowercase_chars)];
            random_chars[random_chars_count] = 0;
            random_chars_count++;
        } else if (random_index == 1 && strlen(uppercase_chars) > 0) {
            password[random_chars_count] = uppercase_chars[rand() % strlen(uppercase_chars)];
            random_chars[random_chars_count] = 1;
            random_chars_count++;
        } else if (random_index == 2 && strlen(numbers) > 0) {
            password[random_chars_count] = numbers[rand() % strlen(numbers)];
            random_chars[random_chars_count] = 2;
            random_chars_count++;
        } else if (random_index == 3 && strlen(symbols) > 0) {
            password[random_chars_count] = symbols[rand() % strlen(symbols)];
            random_chars[random_chars_count] = 3;
            random_chars_count++;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%c", password[i]);
    }

    printf("\n");

    return 0;
}