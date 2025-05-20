//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define ALPHABET_SIZE 26

char *generatePassword(int length) {
    static char password[MAX_LENGTH + 1];
    static int index = 0;
    static int count = 0;

    char *characters[ALPHABET_SIZE + 1];

    int i;

    for (i = 0; i < ALPHABET_SIZE; i++) {
        characters[i] = (char) i + 'a';
    }

    characters[ALPHABET_SIZE] = 0;

    srand(time(NULL));

    int j;
    int upper_count = 0;
    int lower_count = 0;

    for (j = 0; j < length; j++) {
        int random_index = rand() % ALPHABET_SIZE;
        int random_char = characters[random_index];

        if (isupper(random_char)) {
            upper_count++;
        } else if (islower(random_char)) {
            lower_count++;
        }

        if (upper_count > 0 && lower_count > 0) {
            password[index] = random_char;
            index++;
            upper_count--;
            lower_count--;
        } else if (upper_count > 0) {
            password[index] = (char) toupper(random_char);
            index++;
            upper_count--;
        } else if (lower_count > 0) {
            password[index] = (char) tolower(random_char);
            index++;
            lower_count--;
        } else {
            password[index] = random_char;
            index++;
        }

        if (index == MAX_LENGTH) {
            break;
        }
    }

    password[index] = 0;

    return password;
}

int main() {
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Please enter a number between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    char *password = generatePassword(length);
    printf("Your secure password is: %s\n", password);

    return 0;
}