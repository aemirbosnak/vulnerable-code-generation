//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <ctype.h>

#define ROWS 5
#define COLS 5

void printAsciiArt(char *input) {
    // convert input to all uppercase
    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }

    // create 2d array for each letter
    char *asciiArt[ROWS][26] = {
        {
            "  #### ",
            " ##  ##",
            "   ##  ",
            "   ##  ",
            " ######",
        },
        {
            "###### ",
            "     ##",
            " ######",
            "##     ",
            "###### ",
        },
        {
            " ######",
            "##     ",
            " ######",
            "##     ",
            " ######",
        },
        {
            "###### ",
            "##     ",
            "###### ",
            "##     ",
            "###### ",
        },
        {
            "#######",
            "##     ",
            "#######",
            "##     ",
            "#######",
        },
        {
            "#######",
            "##     ",
            "#######",
            "##     ",
            "##     ",
        },
        {
            " ######",
            "##     ",
            "## ####",
            "##   ##",
            " ######",
        },
        {
            "##   ##",
            "##   ##",
            "###### ",
            "##   ##",
            "##   ##",
        },
        {
            "#######",
            "   ##  ",
            "   ##  ",
            "   ##  ",
            "#######",
        },
        {
            "   ##  ",
            "   ##  ",
            "   ##  ",
            "## ##  ",
            " ######",
        },
        {
            "##   ##",
            "## ##  ",
            "####   ",
            "## ##  ",
            "##   ##",
        },
        {
            "##     ",
            "##     ",
            "##     ",
            "##     ",
            "###### ",
        },
        {
            "##   ##",
            "### ###",
            "#######",
            "## # ##",
            "##   ##",
        },
        {
            "##   ##",
            "###  ##",
            "## # ##",
            "##  ###",
            "##   ##",
        },
        {
            " ######",
            "##   ##",
            "##   ##",
            "##   ##",
            " ######",
        },
        {
            "###### ",
            "##     ",
            "###### ",
            "##     ",
            "##     ",
        },
        {
            " ######",
            "##   ##",
            "##   ##",
            "##  ###",
            " ######",
        },
        {
            "###### ",
            "##     ",
            "###### ",
            "##     ",
            "##     ",
        },
        {
            " ######",
            "##     ",
            " ######",
            "     ##",
            "###### ",
        },
        {
            "#######",
            "   ##  ",
            "   ##  ",
            "   ##  ",
            "   ##  ",
        },
        {
            "##   ##",
            "##   ##",
            "##   ##",
            "##   ##",
            " ######",
        },
        {
            "##   ##",
            "##   ##",
            " ## ## ",
            "  ###  ",
            "  ##   ",
        },
        {
            "##   ##",
            "##   ##",
            "## # ##",
            "#####  ",
            "##   ##",
        },
        {
            "##   ##",
            "##   ##",
            " ######",
            "  #### ",
            "##   ##",
        },
    };

    // print ascii art for each letter
    for (int i = 0; input[i]; i++) {
        int letterIndex = input[i] - 65;

        // print each row of the letter
        for (int j = 0; j < ROWS; j++) {
            printf("%s\n", asciiArt[j][letterIndex]);
        }

        // add space between letters
        printf("\n");
    }
}

int main() {
    char input[50];

    printf("Enter a word or phrase to be converted to ASCII art:\n");
    fgets(input, 50, stdin);

    printf("\n");

    printAsciiArt(input);

    return 0;
}