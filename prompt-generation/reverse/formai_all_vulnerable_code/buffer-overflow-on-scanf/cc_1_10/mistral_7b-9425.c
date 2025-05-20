//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 12
#define MAX_LEN 20

// Function to generate a random number
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character
char rand_char() {
    int random = rand();
    if (random % 2 == 0) {
        return 'a' + (rand() % 26);
    } else {
        return 'A' + (rand() % 26);
    }
}

// Function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is an alphabet
int is_alphabet(char c) {
    return (isalpha(c));
}

// Function to check if a character is a special character
int is_special(char c) {
    switch(c) {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
        case '(':
        case ')':
        case '-':
        case '+':
        case '=':
        case '_':
        case '>':
        case '<':
        case '{':
        case '}':
        case '|':
        case '[':
        case ']':
        case ';':
        case ':':
        case '\"':
        case '\'':
        case '`':
        case ',':
        case '.':
        case '/':
            return 1;
        default:
            return 0;
    }
}

// Function to generate a random password
void generate_password(char* password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (i % 3 == 0) { // Add an alphabet character
            password[i] = is_digit(rand_char()) ? rand_char() : 'A' + (rand() % 26);
        } else if (i % 3 == 1) { // Add a digit character
            password[i] = is_digit(rand_char()) ? rand_char() : '0' + (rand() % 10);
        } else { // Add a special character
            password[i] = is_special(rand_char());
        }
    }
    password[length] = '\0'; // Add null terminator
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int length;
    char password[MAX_LEN + 1];

    printf("How long do you want your password to be? (Between %d and %d)\n", MIN_LEN, MAX_LEN);
    scanf("%d", &length);

    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Invalid length! Exiting...\n");
        return 1;
    }

    generate_password(password, length);

    printf("Your new funny password is: %s\n", password);

    return 0;
}