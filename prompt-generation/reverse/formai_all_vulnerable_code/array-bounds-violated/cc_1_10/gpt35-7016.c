//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

void securePasswordGenerator(char*);

int main() {
    char password[PASSWORD_LENGTH];

    securePasswordGenerator(password);

    printf("Your secure password: %s\n", password);

    return 0;
}

void securePasswordGenerator(char* password) {
    char symbols[] = "!@#$%^&*()_+{}|:<>?-=[]\\;',./";
    char numbers[] = "0123456789";
    char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
    char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char allCharacters[100];

    int i, j;
    srand(time(NULL)); // Initialize random seed

    // Concatenate all possible characters into one array
    for(i = 0; i < 94; i++) {
        if(i < 10)
            allCharacters[i] = numbers[i % 10];
        else if(i < 36)
            allCharacters[i] = lowerCase[i % 26];
        else if(i < 62)
            allCharacters[i] = upperCase[i % 26];
        else
            allCharacters[i] = symbols[i % 32];
    }

    // Generate random password using all characters
    for(i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = allCharacters[rand() % 94];
    }

    // Make sure password contains at least one of each type of character
    password[0] = upperCase[rand() % 26];
    password[1] = lowerCase[rand() % 26];
    password[2] = numbers[rand() % 10];
    password[3] = symbols[rand() % 32];

    // Shuffle the password using Fisher-Yates algorithm
    for(i = PASSWORD_LENGTH - 1; i > 0; i--) {
        j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}