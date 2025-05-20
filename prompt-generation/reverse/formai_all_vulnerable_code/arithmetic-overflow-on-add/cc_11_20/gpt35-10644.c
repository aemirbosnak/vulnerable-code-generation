//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int passwordLength;
    int numLetters, numNumbers, numSpecialChars;
    int i;

    srand(time(NULL));

    printf("Enter the desired length of your password: ");
    scanf("%d", &passwordLength);

    printf("Enter the number of letters you want in your password: ");
    scanf("%d", &numLetters);

    printf("Enter the number of numbers you want in your password: ");
    scanf("%d", &numNumbers);

    printf("Enter the number of special characters you want in your password: ");
    scanf("%d", &numSpecialChars);

    int numTotalChars = numLetters + numNumbers + numSpecialChars;

    if(numTotalChars > passwordLength) {
        printf("Error: The sum of letters, numbers, and special characters is greater than the length of the password.\n");
        return 0;
    }

    char password[passwordLength + 1];

    for(i = 0; i < numLetters; i++) {
        password[i] = rand() % 26 + 97; // random lowercase letter
    }

    for(i = 0; i < numNumbers; i++) {
        password[numLetters + i] = rand() % 10 + 48; // random digit 0-9
    }

    for(i = 0; i < numSpecialChars; i++) {
        int randNum = rand() % 6;

        switch(randNum) {
            case 0:
                password[numLetters + numNumbers + i] = 33; // !
                break;
            case 1:
                password[numLetters + numNumbers + i] = 35; // #
                break;
            case 2:
                password[numLetters + numNumbers + i] = 36; // $
                break;
            case 3:
                password[numLetters + numNumbers + i] = 37; // %
                break;
            case 4:
                password[numLetters + numNumbers + i] = 38; // &
                break;
            case 5:
                password[numLetters + numNumbers + i] = 42; // *
                break;
        }
    }

    for(i = numTotalChars; i < passwordLength; i++) {
        int randNum = rand() % 4;

        switch(randNum) {
            case 0:
                password[i] = rand() % 26 + 65; // random uppercase letter
                break;
            case 1:
                password[i] = rand() % 26 + 97; // random lowercase letter
                break;
            case 2:
                password[i] = rand() % 10 + 48; // random digit 0-9
                break;
            case 3:
                password[i] = rand() % 15 + 33; // random special character
                break;
        }
    }

    password[passwordLength] = '\0'; // add null terminator to end of string

    printf("Your generated password is: %s\n", password);

    return 0;
}