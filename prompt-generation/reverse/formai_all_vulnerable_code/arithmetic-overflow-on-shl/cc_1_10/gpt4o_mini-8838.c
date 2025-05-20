//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32

// A function to convert decimal to binary
void decimalToBinary(int n, char *binaryString) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binaryString[i] = (n & (1 << i)) ? '1' : '0';
    }
    binaryString[MAX_BITS] = '\0'; // Null-terminate the string
}

// A function to ask the user for a number and check if it's positive
int getPositiveNumber() {
    int number;
    while (1) {
        printf("Enter a positive integer (or a cookie recipe, I’m always hungry!): ");
        scanf("%d", &number);
        if (number >= 0) {
            return number;
        }
        printf("Please, I beg you, just a positive number! Not a negative cake! 😭\n");
    }
}

// A quirky function to fetch a random binary pun
void tellBinaryPun() {
    const char *puns[] = {
        "Why did the computer go to the doctor? It had a bad case of binary!",
        "Why do programmers prefer dark mode? Because light attracts bugs!",
        "There are 10 types of people in the world: those who understand binary and those who don’t.",
        "I would tell a joke about UDP, but you might not get it.",
        "Parallel lines have so much in common. It’s a shame they’ll never meet.",
        "Why do Java developers wear glasses? Because they can’t C#!",
    };

    int punCount = sizeof(puns) / sizeof(puns[0]);
    int randomIndex = rand() % punCount;
    printf("Fun Fact of the Day: %s\n", puns[randomIndex]);
}

int main() {
    // Seed the random number generator for puns
    srand(time(NULL));

    // Step right up, folks! Enter your number for a marvelous binary conversion!
    printf("🎩✨ Welcome to the Great Binary Converter! ✨🎩\n");
    tellBinaryPun(); // Let's start with a pun to lighten the mood!

    // Get a positive number
    int decimalNumber = getPositiveNumber();

    // Create an array to hold the binary string
    char binaryString[MAX_BITS + 1];
    
    // Convert the number to binary
    decimalToBinary(decimalNumber, binaryString);

    // Show off our hard work
    printf("Your fabulous binary conversion of %d is: %s\n", decimalNumber, binaryString);
    
    // A little fun message before we go 
    printf("🎊 Congratulations! You've just entered the binary world! 🎊\n");
    printf("Next time you’re at a party, just switch to binary and confuse all your friends! 🤖😂\n");
    
    return 0;
}