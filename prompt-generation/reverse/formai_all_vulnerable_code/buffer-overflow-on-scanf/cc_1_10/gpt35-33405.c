//FormAI DATASET v1.0 Category: Funny ; Style: imaginative
// Welcome to the world of imagination where code gets fun!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 20

// Simply prints a line with some style
void printLine() {
    printf("===============================\n");
}

// Generates a random message with the given prefix and suffix
void generateMessage(char prefix[], char suffix[], int numChars) {
    char message[MAX_CHARS];
    srand(time(NULL));
    for(int i = 0; i < numChars; i++) {
        message[i] = rand() % 26 + 'a';
    }
    message[numChars] = '\0';
    printf("%s%s%s\n", prefix, message, suffix);
}

int main() {
    char name[MAX_CHARS];
    printf("Welcome to the Funny Program!\n");
    printLine();

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello %s! Let's have some fun. :)\n", name);
    printLine();

    // Let's generate a funny message by combining some random words
    printf("Here is a random message for you! ");
    generateMessage("Wow, ", " is such a funny word!", 8);
    printLine();

    // Let's do a countdown
    printf("Countdown to 0: ");
    for(int i = 5; i >= 0; i--) {
        printf("%d... ", i);
        sleep(1);
    }
    printf("Blastoff!\n");
    printLine();

    // Let's reverse a string
    char str[MAX_CHARS];
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    printf("Reversed string: ");
    for(int i = strlen(str)-1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    printLine();

    // Let's generate a random number and do some calculations
    int num = rand() % 100;
    printf("Random number: %d\n", num);
    printf("Square of the number: %d\n", num*num);
    printf("Cube of the number: %d\n", num*num*num);
    printf("Factorial of the number: ");
    int fact = 1;
    for(int i = 1; i <= num; i++) {
        fact = fact * i;
    }
    printf("%d\n", fact);
    printLine();

    // Let's say goodbye
    generateMessage("Goodbye ", ", see you later!", 6);
    return 0;
}