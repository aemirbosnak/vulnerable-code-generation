//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 15           // Maximum length of password
#define NUM_UPPERCASE 3         // Number of uppercase characters in password
#define NUM_LOWERCASE 3         // Number of lowercase characters in password
#define NUM_DIGITS 3            // Number of digits in password
#define NUM_SPECIAL 3           // Number of special characters in password
#define SPECIAL_CHARS "!@#$%^&*()-_+="      // List of special characters that can be used in password

int main() {
    char password[MAX_LENGTH + 1];
    int i, j, k, l;
    int random_num, num_uppercase = 0, num_lowercase = 0, num_digits = 0, num_special = 0;
    srand((unsigned int) time(NULL));      // Set seed for random number generator
    
    // Generate password with required number of characters
    for (i = 0; i < MAX_LENGTH; i++) {
        // Generate random number between 1 and 4
        random_num = rand() % 4 + 1;
        
        // Choose character type based on random number
        switch(random_num) {
            case 1:
                if (num_uppercase < NUM_UPPERCASE) {
                    password[i] = rand() % 26 + 65;      // Generate random uppercase letter
                    num_uppercase++;
                }
                else {
                    i--;        // Decrement counter if already reached required number of uppercase letters
                }
                break;
            case 2:
                if (num_lowercase < NUM_LOWERCASE) {
                    password[i] = rand() % 26 + 97;      // Generate random lowercase letter
                    num_lowercase++;
                }
                else {
                    i--;        // Decrement counter if already reached required number of lowercase letters
                }
                break;
            case 3:
                if (num_digits < NUM_DIGITS) {
                    password[i] = rand() % 10 + 48;      // Generate random digit
                    num_digits++;
                }
                else {
                    i--;        // Decrement counter if already reached required number of digits
                }
                break;
            case 4:
                if (num_special < NUM_SPECIAL) {
                    password[i] = SPECIAL_CHARS[rand() % 16];      // Generate random special character
                    num_special++;
                }
                else {
                    i--;        // Decrement counter if already reached required number of special characters
                }
                break;
        }
    }
    
    // Add remaining characters (if any) as random uppercase letters
    for (j = i; j < MAX_LENGTH; j++) {
        password[j] = rand() % 26 + 65;
    }
    
    // Shuffle password using Fisher-Yates algorithm
    for (k = MAX_LENGTH; k >= 2; k--) {
        l = rand() % k;
        char temp = password[l];
        password[l] = password[k - 1];
        password[k - 1] = temp;
    }
    
    // Print password
    printf("Generated password: %s\n", password);
    
    return 0;
}