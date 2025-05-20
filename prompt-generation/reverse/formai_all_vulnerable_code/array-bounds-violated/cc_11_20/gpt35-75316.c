//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 100

int main() {
    char inputString[MAX_STRING_LEN], manipulatedString[MAX_STRING_LEN];
    
    printf("Enter a string to manipulate: ");
    fgets(inputString, MAX_STRING_LEN, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // remove newline character
    
    int inputLen = strlen(inputString);
    printf("Length of inputString: %d\n", inputLen);
    
    for (int i=0; i<inputLen; i++) {
        manipulatedString[i] = inputString[inputLen-1-i];
    }
    manipulatedString[inputLen] = '\0';
    
    printf("Manipulated string: %s\n", manipulatedString);
    
    // Ensure manipulatedString is not a palindrome
    int isPalindrome = 1;
    for (int i=0; i<inputLen/2; i++) {
        if (manipulatedString[i] != manipulatedString[inputLen-1-i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        manipulatedString[0] = '!'; // add exclamation point to beginning of string
        printf("Manipulated string is a palindrome - adding exclamation point to beginning:\n%s\n", manipulatedString);
    }
    
    // Ensure manipulatedString contains digit(s)
    int hasDigit = 0;
    for (int i=0; i<inputLen; i++) {
        if (isdigit(manipulatedString[i])) {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        manipulatedString[inputLen-1] = '7'; // replace last character with 7
        printf("Manipulated string does not contain digit - replacing last character with 7:\n%s\n", manipulatedString);
    }
    
    // Ensure manipulatedString starts with a capital letter
    if (manipulatedString[0] >= 'a' && manipulatedString[0] <= 'z') {
        manipulatedString[0] -= 32; // convert to uppercase
        printf("Manipulated string does not start with capital letter - converting first letter to uppercase:\n%s\n", manipulatedString);
    }
    
    // Ensure manipulatedString ends with a period
    if (manipulatedString[inputLen-1] != '.') {
        manipulatedString[inputLen] = '.';
        manipulatedString[inputLen+1] = '\0';
        printf("Manipulated string does not end with period - adding period to end:\n%s\n", manipulatedString);
    }
    
    // Swap characters at positions 4 and 7
    if (inputLen >= 8) {
        char temp = manipulatedString[4];
        manipulatedString[4] = manipulatedString[7];
        manipulatedString[7] = temp;
        printf("Swapping characters at positions 4 and 7:\n%s\n", manipulatedString);
    }
    
    // Convert every other character to uppercase
    for (int i=1; i<inputLen; i+=2) {
        if (manipulatedString[i] >= 'a' && manipulatedString[i] <= 'z') {
            manipulatedString[i] -= 32;
        }
    }
    printf("Converting every other character to uppercase:\n%s\n", manipulatedString);
    
    return 0;
}