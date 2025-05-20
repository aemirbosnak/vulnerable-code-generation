//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

int generate_password(char* password, int length);

int main() {
    int length;
    char password[100];

    printf("Enter the desired password length (between 8 and 100): ");
    scanf("%d", &length);

    if (length < 8 || length > 100) {
        printf("Invalid password length.\n");
        return 1;
    }

    generate_password(password, length);

    printf("Your password is: %s\n", password);
    return 0;
}

int generate_password(char* password, int length) {
    const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers_chars[] = "0123456789";
    const char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?\\/";

    char* chars = (char*) malloc(length * sizeof(char));

    int i = 0;
    while (i < length) {
        int char_set = rand() % 4;

        switch (char_set) {
            case 0:
                chars[i] = lowercase_chars[rand() % strlen(lowercase_chars)];
                break;
            case 1:
                chars[i] = uppercase_chars[rand() % strlen(uppercase_chars)];
                break;
            case 2:
                chars[i] = numbers_chars[rand() % strlen(numbers_chars)];
                break;
            case 3:
                chars[i] = special_chars[rand() % strlen(special_chars)];
                break;
        }

        i++;
    }

    strcpy(password, chars);
    free(chars);

    return 0;
}