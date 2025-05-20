//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>
#include <string.h>

// Define the ASCII art patterns for characters A to Z and space
const char *ascii_art[] = {
    "   A   \n  A A  \n AAAAA \nA     A\n",
    "   B   \n  BBBB  \n B   B \n BBBBB \n",
    "  CCCC  \n C     \n C     \n  CCCC  \n",
    " DDDD  \n D   D \n D   D \n  DDDD  \n",
    "EEEEE \nE     \nEEEEE \nE     \nEEEEE \n",
    "FFFFF \nF     \nFFFFF \nF     \nF     \n",
    " GGGG \nG     \nG  GGG \n GGGG \n",
    "H     H\nHHHHHHH\nH     H\nH     H\n",
    " II  \n II  \n II  \nIIIIII \n",
    "JJJJJ \n   J  \n   J  \nJJJJ  \n",
    "  K   \n K K  \nKKK   \nK K   \n",
    "LLLL  \n LLLL \n    L\n LLLL \n",
    " M    M \nMM  MM \n M  M  \nM    M \n",
    " N    N \nNN    N\nN N  N \nN  N N\n",
    " OOOO \nO    O\nO    O\n OOOO \n",
    "PPP   \nP  P  \nPPPP  \nP     \n",
    " QQ   \nQ  Q  \nQ   Q \n QQ Q \n",
    "RRR    \nR   R  \nRRR   \nR    R \n",
    " SSS \nS    \n SSS \n     S\n SSS \n",
    " TTTTT  \n   T    \n   T    \n   T    \n",
    " U    U \nU    U\n UUUU  \n",
    " V    V \nV    V\n V V  \n  V   \n",
    "X    X\n X  X \n  XX  \nX    X\n",
    " YYYYY  \n  Y     \n  Y     \n   Y    \n",
    " ZZZZZ \n    Z  \n  Z   \nZZZZZZZ\n",
    "       \n       \n       \n       \n"
};

// Function to display ASCII art for a given character
void display_char_art(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        printf("%s", ascii_art[ch - 'A']);
    } else if (ch == ' ') {
        printf("%s", ascii_art[26]);
    } else {
        printf("Unsupported character: %c\n", ch);
    }
}

// Main function to accept user input and generate ASCII art
int main() {
    char input[100];
    printf("Enter a string (A-Z or space): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Generate ASCII art for each character in the input
    for (int i = 0; i < strlen(input); i++) {
        display_char_art(input[i]);
        // Print a space between each character for better readability
        printf("\n");
    }
    
    return 0;
}