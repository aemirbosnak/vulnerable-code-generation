//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 25

char* generate_password(int length);
void shuffle(char* array, size_t n);

int main(void) {
    srand(time(NULL)); // set seed for random number generator

    int password_length;
    do {
        printf("Enter password length between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    } while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH);

    char* password = generate_password(password_length);
    printf("Your secure password is: %s\n", password);
    free(password); // free memory

    return 0;
}

char* generate_password(int length) {
    char* lowercase = "abcdefghijklmnopqrstuvwxyz";
    char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numbers = "0123456789";
    char* special_chars = "!#$&*+-=?@^_~";

    int num_lowercase = 2;
    int num_uppercase = 2;
    int num_numbers = 2;
    int num_special_chars = 2;

    char* password = malloc((length + 1) * sizeof(char));
    if (!password) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    // randomly fill password with required characters
    int i;
    for (i = 0; i < num_lowercase; i++) {
        password[i] = lowercase[rand() % strlen(lowercase)];
    }
    for (i = num_lowercase; i < num_lowercase + num_uppercase; i++) {
        password[i] = uppercase[rand() % strlen(uppercase)];
    }
    for (i = num_lowercase + num_uppercase; i < num_lowercase + num_uppercase + num_numbers; i++) {
        password[i] = numbers[rand() % strlen(numbers)];
    }
    for (i = num_lowercase + num_uppercase + num_numbers; i < num_lowercase + num_uppercase + num_numbers + num_special_chars; i++) {
        password[i] = special_chars[rand() % strlen(special_chars)];
    }

    // randomly fill remaining password positions with any character
    for (i = num_lowercase + num_uppercase + num_numbers + num_special_chars; i < length; i++) {
        char c = rand() % 95 + 32; // ASCII printable characters only
        password[i] = c;
    }

    shuffle(password, length); // shuffle password so characters are not in order

    password[length] = '\0'; // add null terminator
    return password;
}

void shuffle(char* array, size_t n) {
    // Fisher-Yates shuffle algorithm
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            char temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}