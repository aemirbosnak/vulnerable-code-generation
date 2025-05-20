//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <string.h>

// function to convert text to ascii art
void textToAscii(char string[]) {

    char asciiArt[10][100]; // 10 lines and 100 columns for the art
   
    // initialize each line of ascii art to empty string
    for (int i = 0; i < 10; i++) {
        strcpy(asciiArt[i], "");
    }

    // add ascii art characters to each line
    for (int i = 0; i < strlen(string); i++) {
        switch (string[i]) {
            case 'A':
                strcat(asciiArt[0], "  /\\  ");
                strcat(asciiArt[1], " /  \\ ");
                strcat(asciiArt[2], "/    \\");
                strcat(asciiArt[3], "------");
                strcat(asciiArt[4], "/    \\");
                strcat(asciiArt[5], "/      \\");
                strcat(asciiArt[6], "/        \\");
                break;
            case 'B':
                strcat(asciiArt[0], "------");
                strcat(asciiArt[1], "|     \\");
                strcat(asciiArt[2], "|      |");
                strcat(asciiArt[3], "------");
                strcat(asciiArt[4], "|      |");
                strcat(asciiArt[5], "|      /");
                strcat(asciiArt[6], "------");
                break;
            // add more cases for other characters
            default:
                strcat(asciiArt[0], " ");
                strcat(asciiArt[1], " ");
                strcat(asciiArt[2], " ");
                strcat(asciiArt[3], " ");
                strcat(asciiArt[4], " ");
                strcat(asciiArt[5], " ");
                strcat(asciiArt[6], " ");
        }
    }

    // print the ascii art
    for (int i = 0; i < 10; i++) {
        printf("%s\n", asciiArt[i]);
    }
}

int main() {
    char string[100];

    // get input from user
    printf("Enter text to convert to ASCII art: ");
    scanf("%s", string);

    textToAscii(string);

    return 0;
}