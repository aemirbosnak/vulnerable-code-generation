//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char originalString[50];
    char reversedString[50];

    printf("Welcome to the fantastic C String manipulation program!\n");
    printf("Enter a word or phrase: ");
    scanf("%s", originalString);

    int len = strlen(originalString);
    for (int i = 0; i < len; i++) {
        reversedString[i] = originalString[len-i-1];
    }
    reversedString[len] = '\0';

    printf("Your original string is:\n");
    printf("%s\n", originalString);

    printf("Your reversed string is:\n");
    printf("%s\n", reversedString);

    if (strcmp(originalString, reversedString) == 0) {
        printf("Wow! Your string is a palindrome!\n");
    } else {
        printf("Sorry. Your string is not a palindrome. Try again!\n");
    }

    printf("Now let's make your string ALL CAPS:\n");

    for (int i = 0; i < len; i++) {
        originalString[i] = toupper(originalString[i]);
    }

    printf("%s\n", originalString);

    printf("Finally, let's count the vowels in your original string:\n");

    int vowelCount = 0;
    for (int i = 0; i < len; i++) {
        char currentChar = originalString[i];
        if (currentChar == 'A' || currentChar == 'E' || currentChar == 'I' || currentChar == 'O' || currentChar == 'U') {
            vowelCount++;
        }
    }
    printf("Your string has %d vowels!\n", vowelCount);

    printf("Thanks for using this amazing C String manipulation program! Goodbye!\n");

    return 0;
}