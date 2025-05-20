//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

int main(void) {
    char password[MAX_PASSWORD_LENGTH+1];
    int password_length;
    srand(time(NULL)); // initialize random number generator
    
    // Loop until password length is valid
    do {
        printf("Enter desired password length (%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    } while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH);
    
    int upper_count = password_length/3; // At least one uppercase letter
    int lower_count = password_length - upper_count; // Remaining characters can be lowercase
    int digits_count = password_length/4 + (password_length%4 != 0); // At least one digit per 4 characters
    int special_count = password_length - upper_count - lower_count - digits_count; // Remaining characters can be special
    
    // Generate uppercase letters
    for (int i = 0; i < upper_count; i++) {
        char c = rand() % 26 + 'A'; // Generate random uppercase letter
        password[i] = c;
    }
    // Generate lowercase letters
    for (int i = upper_count; i < upper_count+lower_count; i++) {
        char c = rand() % 26 + 'a'; // Generate random lowercase letter
        password[i] = c;
    }
    // Generate digits
    for (int i = upper_count+lower_count; i < upper_count+lower_count+digits_count; i++) {
        char c = rand() % 10 + '0'; // Generate random digit
        password[i] = c;
    }
    // Generate special characters
    for (int i = upper_count+lower_count+digits_count; i < password_length; i++) {
        char c = rand() % 15 + '!';
        if (c >= ':' && c <= '@') {
            c += 'A' - ':';
        } else if (c >= '[' && c <= '`') {
            c += 'a' - '[';
        } else if (c >= '{' && c <= '~') {
            c += '0' - '{';
        } // Generate random special character
        password[i] = c;
    }
    
    printf("Your generated password is: %s\n", password);
    return 0;
}