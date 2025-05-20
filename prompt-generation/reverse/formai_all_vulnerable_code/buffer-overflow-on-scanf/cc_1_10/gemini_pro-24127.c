//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character
char rand_char() {
    return (char)rand_range('a', 'z');
}

// Function to generate a random number
int rand_int() {
    return rand();
}

// Function to generate a random string of length n
char *rand_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = rand_char();
    }
    str[n] = '\0';
    return str;
}

// Function to generate a random password of length n
char *rand_password(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        int r = rand_range(0, 2);
        switch (r) {
            case 0:
                str[i] = rand_char();
                break;
            case 1:
                str[i] = rand_int();
                break;
            case 2:
                str[i] = rand_string(1);
                break;
        }
    }
    str[n] = '\0';
    return str;
}

// Main function
int main() {
    srand(time(NULL));

    // Get the length of the password
    int n;
    printf("Enter the length of the password: ");
    scanf("%d", &n);

    // Generate a random password
    char *password = rand_password(n);

    // Print the password
    printf("Password: %s\n", password);

    return 0;
}