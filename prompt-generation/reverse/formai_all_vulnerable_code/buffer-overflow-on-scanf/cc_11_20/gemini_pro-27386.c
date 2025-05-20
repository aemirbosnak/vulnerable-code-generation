//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare an array of characters to store the input text
    char text[1000];

    // Prompt the user to enter some text
    printf("Enter some text: ");

    // Read the text from the user
    scanf("%s", text);

    // Check if the user entered a valid text
    if (strlen(text) == 0) {
        printf("Invalid input. Please enter some text.\n");
        return 1;
    }

    // Print the length of the text
    printf("The length of the text is %lu characters.\n", strlen(text));

    // Print the text in reverse order
    printf("The text in reverse order is: ");
    for (int i = strlen(text) - 1; i >= 0; i--) {
        printf("%c", text[i]);
    }
    printf("\n");

    // Print the number of vowels in the text
    int numVowels = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
            numVowels++;
        }
    }
    printf("The number of vowels in the text is %d.\n", numVowels);

    // Print the number of consonants in the text
    int numConsonants = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            if (text[i] != 'a' && text[i] != 'e' && text[i] != 'i' && text[i] != 'o' && text[i] != 'u') {
                numConsonants++;
            }
        }
    }
    printf("The number of consonants in the text is %d.\n", numConsonants);

    // Print the number of words in the text
    int numWords = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            numWords++;
        }
    }
    printf("The number of words in the text is %d.\n", numWords + 1);

    // Print the average word length in the text
    float avgWordLength = (float)strlen(text) / (numWords + 1);
    printf("The average word length in the text is %.2f characters.\n", avgWordLength);

    return 0;
}