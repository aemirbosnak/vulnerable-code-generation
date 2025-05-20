//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 25 // maximum password length
#define MIN_LENGTH 8 // minimum password length

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int length; // variable to store the desired password length
    char password[MAX_LENGTH + 1]; // variable to store the generated password
    
    // get desired password length from user input
    printf("How long would you like your password to be? (must be between %d and %d characters)\n", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);
    
    // check that desired password length is within allowed range
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Password must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }
    
    // generate a random password using a combination of uppercase letters, lowercase letters, digits, and symbols
    const char symbols[] = "!@#$%^&*()_+=-[]{}\\|;:'\",.<>/?";
    const int num_symbols = sizeof(symbols) / sizeof(symbols[0]) - 1; // subtract 1 to exclude null terminator
    
    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 4; // pick a random character type (0 = uppercase letter, 1 = lowercase letter, 2 = digit, 3 = symbol)
        
        switch (type) {
            case 0:
                password[i] = 'A' + (rand() % 26); // uppercase letter
                break;
            case 1:
                password[i] = 'a' + (rand() % 26); // lowercase letter
                break;
            case 2:
                password[i] = '0' + (rand() % 10); // digit
                break;
            default:
                password[i] = symbols[rand() % num_symbols]; // symbol
        }
    }
    
    password[length] = '\0'; // add null terminator to end of string
    
    // output generated password to user
    printf("Your new password is: %s\n", password);
    
    return 0;
}