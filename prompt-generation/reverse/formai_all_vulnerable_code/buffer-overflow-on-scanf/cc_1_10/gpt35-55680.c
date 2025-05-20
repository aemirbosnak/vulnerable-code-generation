//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20

void generatePassword(int length, char* password) {
    srand(time(NULL));

    // Define character sets
    const char* lowerAlphabets = "abcdefghijklmnopqrstuvwxyz";
    const char* upperAlphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* numbers = "0123456789";
    const char* symbols = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";

    // Get the length of each character set
    int lowerAlphabetsLength = strlen(lowerAlphabets);
    int upperAlphabetsLength = strlen(upperAlphabets);
    int numbersLength = strlen(numbers);
    int symbolsLength = strlen(symbols);

    // Initialize counters
    int numLowerAlphabets = 0;
    int numUpperAlphabets = 0;
    int numNumbers = 0;
    int numSymbols = 0;

    // Pick at least one character from each character set
    password[0] = lowerAlphabets[rand() % lowerAlphabetsLength];
    numLowerAlphabets++;
    password[1] = upperAlphabets[rand() % upperAlphabetsLength];
    numUpperAlphabets++;
    password[2] = numbers[rand() % numbersLength];
    numNumbers++;
    password[3] = symbols[rand() % symbolsLength];
    numSymbols++;

    // Fill the rest of the password with random characters
    for (int i = 4; i < length; i++) {
        int category = rand() % 4;

        if (category == 0 && numLowerAlphabets < length / 4) {
            password[i] = lowerAlphabets[rand() % lowerAlphabetsLength];
            numLowerAlphabets++;
        } else if (category == 1 && numUpperAlphabets < length / 4) {
            password[i] = upperAlphabets[rand() % upperAlphabetsLength];
            numUpperAlphabets++;
        } else if (category == 2 && numNumbers < length / 4) {
            password[i] = numbers[rand() % numbersLength];
            numNumbers++;
        } else if (numSymbols < length / 4) {
            password[i] = symbols[rand() % symbolsLength];
            numSymbols++;
        } else {
            i--;
        }
    }

    // Shuffle the password
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    char password[MAX_LENGTH];
    int length;

    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Validate input
    if (length <= 0 || length > MAX_LENGTH) {
        printf("Invalid length!\n");
        return 1;
    }

    // Generate password
    generatePassword(length, password);

    printf("Generated password: %s\n", password);

    return 0;
}