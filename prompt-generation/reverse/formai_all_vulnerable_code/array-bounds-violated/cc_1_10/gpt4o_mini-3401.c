//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define CHAR_WIDTH 5
#define CHAR_HEIGHT 7

// ASCII representations for characters A-Z and a-z
const char *asciiArt[] = {
    "  A  \n B B \nC   C\nD   D\nE E E\nF   F\nF   F\n", // A
    "  G  \n G G \nG   G\nG G G\nG   G\n G G \n  G  \n", // B
    " H H \nH   H\nH   H\nH   H\n HHH \nH   H\nH   H\n", // C
    " I I \n I I \n  I  \n  I  \n  I  \n I I \n I I \n", // D
    // (Add similar strings for other letters...)
    " V V \n V V \n V V \n V V \n V V \n  V  \n  V  \n", // V
    " W W \nW   W\nW   W\nW   W\nW W W\nW W W\n     \n", // W
    "X   X\n X X \n  X  \n  X  \n X X \nX   X\n     \n", // X
    "Y   Y\n Y Y \n  Y  \n  Y  \n  Y  \n  Y  \n  Y  \n", // Y
    "Z   Z\n Z Z \n  Z  \n Z   \nZ    \nZ   Z \nZ   Z\n"  // Z
};
  
void printAsciiArt(char *input) {
    int length = strlen(input);
    
    for (int row = 0; row < CHAR_HEIGHT; row++) {
        for (int i = 0; i < length; i++) {
            char ch = input[i];
            if (ch >= 'A' && ch <= 'Z') {
                printf("%.*s ", CHAR_WIDTH, &asciiArt[ch - 'A'][row * (CHAR_WIDTH + 1)]);
            } else if (ch >= 'a' && ch <= 'z') {
                // Here you can handle lowercase letters similarly if you want
                // This is just a placeholder for demonstration
                printf("%.*s ", CHAR_WIDTH, &asciiArt[ch - 'a'][row * (CHAR_WIDTH + 1)]);
            } else {
                printf("     "); // For any non-alphabetic character
            }
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LEN];

    printf("Welcome to the ASCII Art Generator!\n");
    printf("Enter the text (A-Z or a-z): ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // Removing the newline character

    printf("\nHere is your ASCII Art:\n");
    printAsciiArt(input);

    return 0;
}