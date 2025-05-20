//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12
#define CHARACTER_SET_LENGTH 62
#define NUMBER_OF_SPECIAL_CHARS 4
#define NUMBER_OF_UPPERCASE_CHARS 4
#define NUMBER_OF_LOWERCASE_CHARS 4
#define NUMBER_OF_DIGITS 4

void generate_password(char* password, char* character_set);
void generate_special_chars(char* special_chars);
void generate_uppercase_chars(char* uppercase_chars);
void generate_lowercase_chars(char* lowercase_chars);
void generate_digits(char* digits);

int main() {
    char password[PASSWORD_LENGTH];
    char special_chars[NUMBER_OF_SPECIAL_CHARS];
    char uppercase_chars[NUMBER_OF_UPPERCASE_CHARS];
    char lowercase_chars[NUMBER_OF_LOWERCASE_CHARS];
    char digits[NUMBER_OF_DIGITS];

    generate_special_chars(special_chars);
    generate_uppercase_chars(uppercase_chars);
    generate_lowercase_chars(lowercase_chars);
    generate_digits(digits);

    generate_password(password, special_chars);
    printf("Password: %s\n", password);

    return 0;
}

void generate_password(char* password, char* character_set) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = character_set[rand() % strlen(character_set)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

void generate_special_chars(char* special_chars) {
    strcpy(special_chars, "!@#$%^&*()_+");
}

void generate_uppercase_chars(char* uppercase_chars) {
    strcpy(uppercase_chars, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void generate_lowercase_chars(char* lowercase_chars) {
    strcpy(lowercase_chars, "abcdefghijklmnopqrstuvwxyz");
}

void generate_digits(char* digits) {
    strcpy(digits, "0123456789");
}