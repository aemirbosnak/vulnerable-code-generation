//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>
#include <string.h>

void generateArt(char* text) {
    char* lines[8][200];
    int lineLength[8], maxLength = 0;
    int i, j, k, l;
    
    // Initializing the lines and line lengths
    for(i = 0; i < 8; i++) {
        lineLength[i] = 0;
        for(j = 0; j < 200; j++) {
            lines[i][j] = " ";
        }
    }
    
    // Looping through every character of the input text
    for(i = 0; i < strlen(text); i++) {
        char c = text[i];
        int ascii = (int) c;
        
        // Finding the ASCII art for the current character
        char* art[8];
        int artLength = 0;
        if(ascii >= 32 && ascii <= 126) {
            art[0] = "  ..######..  \n";
            art[1] = "  .########.  \n";
            art[2] = "  .########.  \n";
            art[3] = "  ..######..  \n";
            art[4] = "     ##       \n";
            art[5] = "     ##       \n";
            art[6] = "     ##       \n";
            art[7] = "     ##       \n";
            artLength = 8;
            
            // Generating ASCII art for the character
            for(j = 0; j < artLength; j++) {
                for(k = 0; k < strlen(art[j]); k++) {
                    if(art[j][k] != '\n') {
                        lines[j][lineLength[j]] = &art[j][k];
                        lineLength[j]++;
                    }
                }
                if(lineLength[j] > maxLength) {
                    maxLength = lineLength[j];
                }
            }
        }
    }
    
    // Printing the final ASCII art for the input text
    printf("\n");
    for(i = 0; i < 8; i++) {
        for(j = 0; j < maxLength; j++) {
            if(lines[i][j] != NULL) {
                printf("%c", *lines[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text to generate ASCII art: ");
    scanf("%[^\n]", text);
    generateArt(text);
    return 0;
}