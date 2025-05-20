//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

// Function declarations
void generatePassword(char* password, int length);
void shuffle(char* array, size_t n);

int main() {
    // Variables initialization
    char password[MAX_LENGTH + 1]; // Allow for null-terminator
    int length = -1; // Default value, will be updated later
    time_t t;

    // Generate seed for random number generator
    srand((unsigned)time(&t));

    // Ask for password length
    while (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("How many characters do you want your password to have? (%d-%d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid length. Please try again.\n");
        }
    }

    // Generate password
    generatePassword(password, length);

    // Display password
    printf("Your new password is: %s\n", password);

    return 0;
}

void generatePassword(char* password, int length) {
    char* lower = "abcdefghijklmnopqrstuvwxyz";
    char* upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* digits = "0123456789";
    char* special = "!@#$%^&*()_-+={}[]\\|:;\"'<>,.?/~`";
    char charset[MAX_LENGTH + 1];
    int index = 0;

    // Add at least one character from each character set
    charset[index++] = lower[rand() % strlen(lower)];
    charset[index++] = upper[rand() % strlen(upper)];
    charset[index++] = digits[rand() % strlen(digits)];
    charset[index++] = special[rand() % strlen(special)];

    // Add remaining characters
    for (int i = index; i < length; i++) {
        char* set = (char*)&charset;
        int setIndex = rand() % 4;
        if (setIndex == 0) {
            charset[i] = lower[rand() % strlen(lower)];
        } else if (setIndex == 1) {
            charset[i] = upper[rand() % strlen(upper)];
        } else if (setIndex == 2) {
            charset[i] = digits[rand() % strlen(digits)];
        } else {
            charset[i] = special[rand() % strlen(special)];
        }
    }

    // Shuffle character set
    shuffle(charset, length);

    // Copy character set into password
    strncpy(password, charset, length);
    password[length] = '\0'; // Null-terminate password string
}

void shuffle(char* array, size_t n) {
    // Use Fisher-Yates shuffle algorithm
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}