//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCII_ART_HEIGHT 7
#define ASCII_ART_WIDTH 6

// Define ASCII Art representation for each character
const char* asciiArt[][ASCII_ART_HEIGHT] = {
    // Space
    {"      ", "      ", "      ", "      ", "      ", "      ", "      "},
    // A
    {"  A   ", " A A  ", "AAAAA ", "A   A ", "A   A ", "A   A ", "      "},
    // B
    {"BBBB  ", "B   B ", "B   B ", "BBBB  ", "B   B ", "BBBB  ", "      "},
    // C
    {" CCCC ", "C     ", "C     ", "C     ", " CCCC ", "      ", "      "},
    // D
    {"DDDD  ", "D   D ", "D   D ", "D   D ", "DDDD  ", "      ", "      "},
    // E
    {"EEEEE ", "E     ", "E     ", "EEEEE ", "E     ", "EEEEE ", "      "},
    // F
    {"FFFFF ", "F     ", "F     ", "FFFFF ", "F     ", "F     ", "      "},
    // G
    {" GGGG ", "G     ", "G  GG ", "G   G ", " GGGG ", "      ", "      "},
    // H
    {"H   H ", "H   H ", "HHHHH ", "H   H ", "H   H ", "      ", "      "},
    // I
    {"IIIII ", "  I   ", "  I   ", "  I   ", "IIIII ", "      ", "      "},
    // J
    {"  JJJ ", "    J ", "    J ", "    J ", " JJJJ ", "      ", "      "},
    // K
    {"K   K ", "K  K  ", "KK    ", "K  K  ", "K   K ", "      ", "      "},
    // L
    {"L     ", "L     ", "L     ", "L     ", "LLLLL ", "      ", "      "},
    // M
    {"M   M ", "MM MM ", "M M M ", "M   M ", "M   M ", "      ", "      "},
    // N
    {"N   N ", "N N N ", "N  NN ", "N   N ", "N   N ", "      ", "      "},
    // O
    {" OOO  ", "O   O ", "O   O ", "O   O ", " OOO  ", "      ", "      "},
    // P
    {"PPPP  ", "P   P ", "P   P ", "PPPP  ", "P     ", "P     ", "      "},
    // Q
    {" QQQ  ", "Q   Q ", "Q   Q ", "Q   Q ", " QQQQ ", "    Q ", "      "},
    // R
    {"RRRR  ", "R   R ", "R   R ", "RRRR  ", "R   R ", "R    R", "      "},
    // S
    {" SSSS ", "S     ", "S     ", " SSSS ", "     S ", " SSSS ", "      "},
    // T
    {"TTTTT ", "  T   ", "  T   ", "  T   ", "  T   ", "      ", "      "},
    // U
    {"U   U ", "U   U ", "U   U ", "U   U ", " UUUU ", "      ", "      "},
    // V
    {"V   V ", "V   V ", "V   V ", " V V  ", "  V   ", "      ", "      "},
    // W
    {"W   W ", "W   W ", "W W W ", "WW WW ", "W   W ", "      ", "      "},
    // X
    {"X   X ", " X X  ", "  X   ", " X X  ", "X   X ", "      ", "      "},
    // Y
    {"Y   Y ", " Y Y  ", "  Y   ", "  Y   ", "  Y   ", "      ", "      "},
    // Z
    {"ZZZZZ ", "   Z  ", "  Z   ", " Z    ", "ZZZZZ ", "      ", "      "},
};

void convertToUppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void printAsciiArt(char *input) {
    for (int line = 0; line < ASCII_ART_HEIGHT; line++) {
        for (int i = 0; input[i] != '\0'; i++) {
            char currentChar = input[i];
            if (currentChar < 'A' || currentChar > 'Z') {
                currentChar = 0; // default space for unsupported characters
            } else {
                currentChar -= 'A' + 1; // Get index for ASCII Art array
            }
            printf("%s", asciiArt[currentChar][line]);
        }
        printf("\n");
    }
}

// Main program driver
int main() {
    char input[100];
    
    printf("Enter a string to convert to ASCII Art (A-Z): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    convertToUppercase(input);

    printf("\nYour ASCII Art representation:\n");
    printAsciiArt(input);

    return 0;
}