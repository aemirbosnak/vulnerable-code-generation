//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <string.h>

int main(void) {
    char text[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline character
    
    printf("\nHere's your ASCII art:\n");
    
    int length = strlen(text);
    
    char *asciiArt[length][7];
    
    // Create ASCII art for each letter
    asciiArt[0][0] = "  _______ ";
    asciiArt[0][1] = " /       \\";
    asciiArt[0][2] = "/         \\";
    asciiArt[0][3] = "\\         /";
    asciiArt[0][4] = " \\_______/";
    asciiArt[0][5] = "-----------";
    asciiArt[0][6] = "           ";
    
    asciiArt[1][0] = "     __  ";
    asciiArt[1][1] = "   /    \\";
    asciiArt[1][2] = "  |      |";
    asciiArt[1][3] = "   \\___/";
    asciiArt[1][4] = "         ";
    asciiArt[1][5] = "-----------";
    asciiArt[1][6] = "         ";
    
    // Add more letters here
    
    // Loop through each line of ASCII art
    for (int i = 0; i < 7; i++) {
        // Loop through each letter in text
        for (int j = 0; j < length; j++) {
            int asciiValue = (int) text[j];
            if (asciiValue > 90) {
                asciiValue -= 32; // Convert lowercase to uppercase
            }
            int index = asciiValue - 65; // A is ASCII code 65
            printf("%s", asciiArt[index][i]);
        }
        printf("\n");
    }
    
    return 0;
}