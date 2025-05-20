//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 25
#define MIN_LENGTH 8

void generatePassword(char password[], int length);
void addRandomSymbol(char password[]);
void shuffleArray(char arr[], int size);

int main() {
    int length;
    char password[MAX_LENGTH];
    
    printf("Welcome to C Secure Password Generator!\n");
    printf("Enter desired password length (minimum %d characters): ", MIN_LENGTH);
    scanf("%d", &length);

    // validate length
    if (length < MIN_LENGTH) {
        printf("Sorry, password length must be at least %d characters.\n", MIN_LENGTH);
        return 1;
    } else if (length > MAX_LENGTH) {
        printf("Sorry, password length cannot be more than %d characters.\n", MAX_LENGTH);
        return 1;
    }
    
    // generate password
    generatePassword(password, length);
    
    // output password
    printf("\nYour secure password is:\n%s\n", password);
    
    return 0;
}

void generatePassword(char password[], int length) {
    // initialize password with lowercase letters
    for (int i = 0; i < length; i++) {
        password[i] = 'a' + rand() % 26;
    }
    
    // add uppercase letters
    int numUppercase = rand() % (length / 4) + 1; // at least one uppercase letter
    for (int i = 0; i < numUppercase; i++) {
        int index = rand() % length;
        password[index] = toupper(password[index]);
    }
    
    // add numbers
    int numNumbers = rand() % (length / 4) + 1; // at least one number
    for (int i = 0; i < numNumbers; i++) {
        int index = rand() % length;
        password[index] = '0' + rand() % 10;
    }
    
    // add symbols
    addRandomSymbol(password);
    
    // shuffle the password
    shuffleArray(password, length);
}

void addRandomSymbol(char password[]) {
    char symbols[] = "!@#$%^&*()_+-={}|[]\\:\";'<>,.?/~`";
    int numSymbols = sizeof(symbols) - 1;
    int index = rand() % numSymbols;
    password[rand() % strlen(password)] = symbols[index];
}

void shuffleArray(char arr[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}