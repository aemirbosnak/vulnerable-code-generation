//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length = 0;

    srand(time(NULL));

    // Add lowercase letters
    for (int i = 'a'; i <= 'z'; i++) {
        password[length++] = i;
    }

    // Add uppercase letters
    for (int i = 'A'; i <= 'Z'; i++) {
        password[length++] = i;
    }

    // Add numbers
    for (int i = '0'; i <= '9'; i++) {
        password[length++] = i;
    }

    // Add special characters
    password[length++] = '!';
    password[length++] = '@';
    password[length++] = '#';
    password[length++] = '$';
    password[length++] = '%';
    password[length++] = '^';
    password[length++] = '&';
    password[length++] = '*';

    // Shuffle the password
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Print the password
    printf("Your secure password is: %s\n", password);

    return 0;
}