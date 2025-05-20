//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

void generatePassword(char* password, int length);
int isValid(char* password);
char randomCharacter();
int randomNumber(int min, int max);

int main() {
    char password[MAX_LENGTH + 1];
    int length;
    
    srand(time(NULL));
    
    printf("Welcome to the Secure Password Generator!\n\n");

    do {
        printf("Enter the length of the password(%d-%d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
    } while(length < MIN_LENGTH || length > MAX_LENGTH);

    generatePassword(password, length);
    
    printf("\nYour password is: %s\n\n", password);
    
    return 0;
}

void generatePassword(char* password, int length) {
    int i;
    
    for(i = 0; i < length; i++) {
        password[i] = randomCharacter();
    }
    
    password[length] = '\0';
    
    if(!isValid(password)) {
        generatePassword(password, length);
    }
}

int isValid(char* password) {
    int i, uppercase = 0, lowercase = 0, digit = 0, symbol = 0;
    
    for(i = 0; password[i] != '\0'; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            uppercase++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lowercase++;
        } else if(password[i] >= '0' && password[i] <= '9') {
            digit++;
        } else {
            symbol++;
        }
    }
    
    if(uppercase < 1 || lowercase < 1 || digit < 1 || symbol < 1) {
        return 0;
    }
    
    return 1;
}

char randomCharacter() {
    int category = randomNumber(1, 4);
    
    if(category == 1) {
        // Uppercase letter
        return (char)randomNumber(65, 90);
    } else if(category == 2) {
        // Lowercase letter
        return (char)randomNumber(97, 122);
    } else if(category == 3) {
        // Digit
        return (char)randomNumber(48, 57);
    } else {
        // Symbol
        return (char)randomNumber(33, 47);
    }
}

int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}