//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

void drawLine(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void drawText(char* str) {
    // ASCII art characters, where each index corresponds to a line of the text art
    char characters[26][10] = {
        {"XXXXX   "},
        {"X    X  "},
        {"X    X  "},
        {"X    X  "},
        {"XXXXX   "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "},
        {"        "}
    };
    
    int length = strlen(str);
    drawLine('*', length + 4);
    
    for (int i = 0; i < 7; i++) {
        printf("*");
        for (int j = 0; j < length; j++) {
            int charIndex = str[j] - 'A';
            printf("%s", characters[charIndex][i] );
        }
        printf("*\n");
    }
    
    drawLine('*', length + 4);
}

int main() {
    char text[100];
    
    printf("Enter a word or phrase in all caps: ");
    scanf("%s", text);
    
    drawText(text);
    
    return 0;
}