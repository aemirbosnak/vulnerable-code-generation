//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random integer within a specified range */
int generateRandom(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

/* Function to generate a secure password */
void generatePassword(int length) {
    int i, randomNum, countLower = 0, countUpper = 0, countSpecial = 0, countNums = 0;
    char password[length];
    char lowerCaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char upperCaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char specialChars[] = "!@#$%^&*()_-+={}[]:;<>,.?/~`";
    char nums[] = "0123456789";
    
    /* Initialize random seed */
    srand(time(0));
    
    /* Generate random characters */
    for(i = 0; i < length; i++) {
        randomNum = generateRandom(1,4);
        if(randomNum == 1) {
            /* Choose a random lowercase character */
            password[i] = lowerCaseLetters[generateRandom(0, 25)];
            countLower++;
        } else if(randomNum == 2) {
            /* Choose a random uppercase character */
            password[i] = upperCaseLetters[generateRandom(0, 25)];
            countUpper++;
        } else if(randomNum == 3) {
            /* Choose a random special character */
            password[i] = specialChars[generateRandom(0, 31)];
            countSpecial++;
        } else {
            /* Choose a random number */
            password[i] = nums[generateRandom(0, 9)];
            countNums++;
        }
    }
    
    /* If not enough of each type of character, generate a new password */
    if(countLower < 2 || countUpper < 2 || countSpecial < 2 || countNums < 2) {
        generatePassword(length);
    } else {
        /* Print out generated password */
        printf("Your secure password is: ");
        for(i = 0; i < length; i++) {
            printf("%c", password[i]);
        }
        printf("\n");
    }
}

int main () {
    int length;
    printf("How long would you like your password to be? (Minimum 8 Characters): ");
    scanf("%d", &length);
    if(length < 8) {
        printf("Invalid length. Please choose a length of at least 8 characters.\n");
    } else {
        generatePassword(length);
    }
    return 0;
}