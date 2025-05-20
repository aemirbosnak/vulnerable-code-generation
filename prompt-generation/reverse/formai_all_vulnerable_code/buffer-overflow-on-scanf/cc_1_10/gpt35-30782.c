//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void printAsciiArt(char message[]) {
    int i, j, k;

    // An array of possible ASCII characters
    char asciiChars[] = "$@B%8&WM#*oahkbdpwmZO0QCJYXzcvnxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    // Determine the length of the ASCII character array
    int asciiCharsLength = strlen(asciiChars);

    // Determine the length of the message
    int messageLength = strlen(message);

    // Create a 2D character array to hold the ASCII art
    char asciiArt[MAX_SIZE][MAX_SIZE];

    // Initialize the ASCII art array with spaces
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            asciiArt[i][j] = ' ';
        }
    }

    // Iterate over the message and add the relevant characters
    for (i = 0; i < messageLength; i++) {
        char currentChar = message[i];

        // Find the location of the currentChar in asciiChars
        int index = -1;
        for (j = 0; j < asciiCharsLength; j++) {
            if (asciiChars[j] == currentChar) {
                index = j;
                break;
            }
        }

        // Determine the character to use for the ASCII art based on the index
        char asciiChar = ' ';
        if (index != -1) {
            int asciiCharIndex = ((index * 10) / asciiCharsLength);
            asciiChar = asciiChars[asciiCharIndex];
        }

        // Add the ASCII character to the array
        asciiArt[i / 10][i % 10] = asciiChar;
    }

    // Print out the ASCII art array
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char message[MAX_SIZE];
    printf("Enter a message to turn into ASCII art: ");
    scanf("%[^\n]", message);
    printAsciiArt(message);
    return 0;
}