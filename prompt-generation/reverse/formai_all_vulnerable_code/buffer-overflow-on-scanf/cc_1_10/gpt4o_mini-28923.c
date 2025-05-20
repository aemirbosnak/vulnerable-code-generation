//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 16
#define NUM_SPECIAL_CHARS 10
#define NUM_DIGITS 10
#define NUM_UPPERCASE 26
#define NUM_LOWERCASE 26

const char specialChars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
const char digits[NUM_DIGITS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const char upperCase[NUM_UPPERCASE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                                        'U', 'V', 'W', 'X', 'Y', 'Z'};
const char lowerCase[NUM_LOWERCASE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
                                        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
                                        'u', 'v', 'w', 'x', 'y', 'z'};

void generatePassword(char *password, int length) {
    int i = 0;

    // Ensure at least one character of each type
    password[i++] = specialChars[rand() % NUM_SPECIAL_CHARS];
    password[i++] = digits[rand() % NUM_DIGITS];
    password[i++] = upperCase[rand() % NUM_UPPERCASE];
    password[i++] = lowerCase[rand() % NUM_LOWERCASE];

    // Fill the rest of the password with random characters from all categories
    const char *allChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    int allCharsSize = strlen(allChars);

    for (; i < length; i++) {
        password[i] = allChars[rand() % allCharsSize];
    }
    
    // Shuffle the password array
    for (i = 0; i < length; i++) {
        int r = rand() % length;
        char temp = password[i];
        password[i] = password[r];
        password[r] = temp;
    }
    password[length] = '\0'; // Null terminate the string
}

int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator
    
    int passwordLength;
    
    // Get password length from user
    printf("Enter desired password length (%d - %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &passwordLength);
    
    // Validate the password length
    if (passwordLength < MIN_LENGTH || passwordLength > MAX_LENGTH) {
        printf("Invalid length! Please enter a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }
    
    char *password = (char *)malloc((passwordLength + 1) * sizeof(char)); // +1 for null-terminator
    if (password == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generatePassword(password, passwordLength);
    
    printf("Generated Password: %s\n", password);
    
    free(password); // Clean up allocated memory
    return 0;
}