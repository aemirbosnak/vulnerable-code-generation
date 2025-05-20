//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char ASCII_ART[11][8][9] = {
   { // A
    "  /\\  ",
    " /  \\ ",
    "/____\\",
    "|    |",
    "|    |",
    "|____|",
    "",
    ""
  },
  { // B
    "|\\___\\",
    "|____\\",
    "|\\___\\",
    "|____\\",
    "|\\___\\",
    "|____\\",
    "",
    ""
  },
  { // C
    "  _____",
    " / ____|",
    "| |",
    "| |",
    "| |____",
    " \\_____|",
    "",
    ""
  },
  { // D
    "|\\___ \\",
    "| |   \\ \\",
    "| |   | |",
    "| |   / /",
    "| |__/ /",
    "|_____/",
    "",
    ""
  },
  { // E
    "|------",
    "|___",
    "|----",
    "|___",
    "|----",
    "|______",
    "",
    ""
  },
  { // F
    "|------",
    "|___",
    "|----",
    "|___",
    "|-",
    "|-",
    "",
    ""
  },
  { // G
    "  _____",
    " / ____|",
    "| |",
    "| |",
    "| |  __",
    " \\___\\_\\",
    "",
    ""
  },
  { // H
    "|\\    /|",
    "|\\___\\ |",
    "|    | |",
    "|    | |",
    "|___/ |",
    "|     |",
    "",
    ""
  },
  { // I
    " /\\ ",
    " | |",
    " | |",
    " | |",
    " | |",
    " \\/",
    "",
    ""
  },
  { // J
    "       /\\",
    "      / |",
    "     / /",
    "    / /",
    " __/ /",
    "|___/ ",
    "",
    ""
  },
  { // K
    "|\\    /|",
    "| \\  / |",
    "|\\ \\/ /_",
    "| \\  / /",
    "|  \\/ /_",
    "|____/ ",
    "",
    ""
  },
};

// A function to print the ASCII Art of a given character
void printASCII(char ch) {
    switch (toupper(ch)) {
        case 'A':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[0][i]);
            }
            break;
        case 'B':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[1][i]);
            }
            break;
        case 'C':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[2][i]);
            }
            break;
        case 'D':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[3][i]);
            }
            break;
        case 'E':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[4][i]);
            }
            break;
        case 'F':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[5][i]);
            }
            break;
        case 'G':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[6][i]);
            }
            break;
        case 'H':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[7][i]);
            }
            break;
        case 'I':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[8][i]);
            }
            break;
        case 'J':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[9][i]);
            }
            break;
        case 'K':
            for(int i=0; i<8; i++) {
                printf("%s\n", ASCII_ART[10][i]);
            }
            break;
        default:
            printf("Invalid input!\n");
    }
}

int main() {
    char input[256];
    printf("Enter a string:\n");
    scanf("%s", input);

    // Printing the ASCII Art for each character in the input string
    for(int i=0; i<strlen(input); i++) {
        printASCII(input[i]);
    }

    return 0;
}