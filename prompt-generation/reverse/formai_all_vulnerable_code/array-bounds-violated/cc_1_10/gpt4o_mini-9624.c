//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 5
#define MAX_LENGTH 100

// ASCII representations of characters A-Z and space
const char *ascii_art[27][MAX_HEIGHT] = {
    // A
    {
        "  A  ",
        " A A ",
        "AAAAA",
        "A   A",
        "A   A"
    },
    // B
    {
        "BBBB ",
        "B   B",
        "BBBB ",
        "B   B",
        "BBBB "
    },
    // C
    {
        " CCC ",
        "C   C",
        "C    ",
        "C   C",
        " CCC "
    },
    // D
    {
        "DDDD ",
        "D   D",
        "D   D",
        "D   D",
        "DDDD "
    },
    // E
    {
        "EEEEE",
        "E    ",
        "EEEEE",
        "E    ",
        "EEEEE"
    },
    // F
    {
        "FFFFF",
        "F    ",
        "FFFF ",
        "F    ",
        "F    "
    },
    // G
    {
        " GGG ",
        "G    ",
        "G  GG",
        "G   G",
        " GGG "
    },
    // H
    {
        "H   H",
        "H   H",
        "HHHHH",
        "H   H",
        "H   H"
    },
    // I
    {
        "IIIII",
        "  I  ",
        "  I  ",
        "  I  ",
        "IIIII"
    },
    // J
    {
        "JJJJJ",
        "    J",
        "    J",
        "J   J",
        " JJJ "
    },
    // K
    {
        "K   K",
        "K  K ",
        "KK   ",
        "K  K ",
        "K   K"
    },
    // L
    {
        "L    ",
        "L    ",
        "L    ",
        "L    ",
        "LLLLL"
    },
    // M
    {
        "M   M",
        "MM MM",
        "M M M",
        "M   M",
        "M   M"
    },
    // N
    {
        "N   N",
        "NN  N",
        "N N N",
        "N  NN",
        "N   N"
    },
    // O
    {
        " OOO ",
        "O   O",
        "O   O",
        "O   O",
        " OOO "
    },
    // P
    {
        "PPPP ",
        "P   P",
        "PPPP ",
        "P    ",
        "P    "
    },
    // Q
    {
        " QQQ ",
        "Q   Q",
        "Q   Q",
        " QQQ ",
        "    Q"
    },
    // R
    {
        "RRRR ",
        "R   R",
        "RRRR ",
        "R R  ",
        "R  RR"
    },
    // S
    {
        " SSS ",
        "S    ",
        " SSS ",
        "    S",
        " SSS "
    },
    // T
    {
        "TTTTT",
        "  T  ",
        "  T  ",
        "  T  ",
        "  T  "
    },
    // U
    {
        "U   U",
        "U   U",
        "U   U",
        "U   U",
        " UUU "
    },
    // V
    {
        "V   V",
        "V   V",
        "V   V",
        " V V ",
        "  V  "
    },
    // W
    {
        "W   W",
        "W   W",
        "W W W",
        "WW WW",
        "W   W"
    },
    // X
    {
        "X   X",
        " X X ",
        "  X  ",
        " X X ",
        "X   X"
    },
    // Y
    {
        "Y   Y",
        " Y Y ",
        "  Y  ",
        "  Y  ",
        "  Y  "
    },
    // Z
    {
        "ZZZZZ",
        "   Z ",
        "  Z  ",
        " Z   ",
        "ZZZZZ"
    },
    // space
    {
        "     ",
        "     ",
        "     ",
        "     ",
        "     "
    }
};

// Function to convert text to ASCII art
void text_to_ascii_art(const char *text) {
    int length = strlen(text);
    for (int row = 0; row < MAX_HEIGHT; row++) {
        for (int i = 0; i < length; i++) {
            char ch = (text[i] >= 'A' && text[i] <= 'Z') ? text[i] - 'A' : (text[i] == ' ') ? 26 : ' ';
            printf("%s ", ascii_art[ch][row]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char input[MAX_LENGTH];

    printf("Enter text (uppercase letters and spaces only): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    text_to_ascii_art(input);
    return 0;
}