//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20

typedef struct CharacterSet {
    char name[20];
    int length;
    unsigned char start, end;
} CharacterSet;

CharacterSet characterSets[] = {
    {"Lowercase", 26, 'a', 'z'},
    {"Uppercase", 26, 'A', 'Z'},
    {"Digits", 10, '0', '9'},
    {"Special", 32, '!', '~'}
};

void generatePassword(char *password, int length) {
    int setCount = sizeof(characterSets) / sizeof(CharacterSet);
    int i, j;
    for (i = 0; i < length; i++) {
        int setIndex = rand() % setCount;
        CharacterSet *set = characterSets + setIndex;
        int charIndex = rand() % set->length;
        password[i] = set->start + charIndex;
    }
    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    int length;
    char password[MAX_LENGTH + 1];

    printf("Enter the length of the password: ");
    scanf("%d", &length);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    generatePassword(password, length);
    printf("Your secure password is: %s\n", password);

    return 0;
}