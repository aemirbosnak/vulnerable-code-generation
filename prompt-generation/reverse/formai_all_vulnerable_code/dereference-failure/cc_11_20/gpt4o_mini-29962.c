//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 10
#define CHAR_WIDTH 5

void print_character(char c) {
    switch (c) {
        case 'A':
            printf("  A  \n A A \nAAAAA\nA   A\nA   A\n");
            break;
        case 'B':
            printf("BBBB \nB   B\nBBBB \nB   B\nBBBB \n");
            break;
        case 'C':
            printf(" CCC \nC   C\nC    \nC   C\n CCC \n");
            break; 
        case 'D':
            printf("DDDD \nD   D\nD   D\nD   D\nDDDD \n");
            break; 
        case 'E':
            printf("EEEEE\nE    \nEEEEE\nE    \nEEEEE\n");
            break; 
        case 'F':
            printf("EEEEE\nE    \nEEE  \nE    \nE    \n");
            break;
        case 'G':
            printf(" GGG \nG   G\nG    \nG  GG\n GGG \n");
            break;
        case 'H':
            printf("H   H\nH   H\nHHHHH\nH   H\nH   H\n");
            break;
        case 'I':
            printf("III \n I  \n I  \n I  \nIII \n");
            break;
        case 'J':
            printf("  JJJ\n    J\n    J\nJ   J\n JJJ \n");
            break;
        case 'K':
            printf("K   K\nK  K \nKK   \nK  K \nK   K\n");
            break;
        case 'L':
            printf("L    \nL    \nL    \nL    \nLLLLL\n");
            break;
        case 'M':
            printf("M   M\nMM MM\nM M M\nM   M\nM   M\n");
            break;
        case 'N':
            printf("N   N\nN N N\nN  NN\nN   N\nN   N\n");
            break;
        case 'O':
            printf(" OOO \nO   O\nO   O\nO   O\n OOO \n");
            break;
        case 'P':
            printf("PPPP \nP   P\nPPPP \nP    \nP    \n");
            break;
        case 'Q':
            printf(" QQQ \nQ   Q\nQ   Q\n QQQ \n    Q\n");
            break;
        case 'R':
            printf("RRRR \nR   R\nRRRR \nR R  \nR  R \n");
            break;
        case 'S':
            printf(" SSS \nS   S\n SSS \n    S\n SSS \n");
            break;
        case 'T':
            printf("TTTTT\n  T  \n  T  \n  T  \n  T  \n");
            break;
        case 'U':
            printf("U   U\nU   U\nU   U\nU   U\n UUU \n");
            break;
        case 'V':
            printf("V   V\nV   V\n V V \n V V \n  V  \n");
            break;
        case 'W':
            printf("W   W\nW   W\nW W W\nWW WW\nW   W\n");
            break;
        case 'X':
            printf("X   X\n X X \n  X  \n X X \nX   X\n");
            break;
        case 'Y':
            printf("Y   Y\n Y Y \n  Y  \n  Y  \n  Y  \n");
            break;
        case 'Z':
            printf("ZZZZZ\n   Z \n  Z  \n Z   \nZZZZZ\n");
            break;
        case ' ':
            printf("     \n     \n     \n     \n     \n");
            break;
        default:
            break;
    }
}

void print_text_as_ascii_art(const char *text) {
    for (size_t i = 0; i < strlen(text); i++) {
        print_character(text[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Transform the input into ASCII art
    printf("\nASCII Art Output:\n\n");
    for (int i = 1; i < argc; i++) {
        print_text_as_ascii_art(argv[i]);
    }

    return EXIT_SUCCESS;
}