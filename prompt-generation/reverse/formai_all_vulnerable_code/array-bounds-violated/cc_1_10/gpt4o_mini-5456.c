//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100
#define CHAR_HEIGHT 5
#define CHAR_WIDTH 5

// ASCII representations of characters A-Z, a-z, and space
const char *ascii_art[52] = {
    // A-Z
    "  A  \n A A \nAAAAA\nA   A\nA   A\n",  // A
    "BBBB \nB   B\nBBBBB\nB   B\nBBBB \n",  // B
    " CC  \nC   C\nC    \nC   C\n CC  \n",  // C
    "DDDD \nD   D\nD   D\nD   D\nDDDD \n",  // D
    "EEEEE\nE    \nEEEEE\nE    \nEEEEE\n",  // E
    "FFFFF\nF    \nFFFFF\nF    \nF    \n",  // F
    " GG  \nG   G\nG  GG\nG   G\n GG  \n",  // G
    "H   H\nH   H\nHHHHH\nH   H\nH   H\n",  // H
    " III \n  I  \n  I  \n  I  \n III \n",  // I
    "   J \n   J \n   J \nJ  J \n JJ  \n",  // J
    "K   K\nK  K \nKKK  \nK  K \nK   K\n",  // K
    "L    \nL    \nL    \nL    \nLLLLL\n",  // L
    "M     M\nMM   MM\nM M M M\nM     M\nM     M\n",  // M
    "N    N\nN N  N\nN  N N\nN   NN\nN    N\n",  // N
    " OOO \nO   O\nO   O\nO   O\n OOO \n",  // O
    "PPPP \nP   P\nPPPP \nP    \nP    \n",  // P
    " QQQ \nQ   Q\nQ   Q\n QQQ \n    Q\n",  // Q
    "RRRR \nR   R\nRRRR \nR R  \nR  RR\n",  // R
    "SSSSS\nS    \nSSSS \n    S\nSSSSS\n",  // S
    "TTTTT\n  T  \n  T  \n  T  \n  T  \n",  // T
    "U   U\nU   U\nU   U\nU   U\n UUU \n",  // U
    "V   V\nV   V\nV   V\n V V \n  V  \n",  // V
    "W     W\nW     W\nW  W  W\n W W W \n  W W  \n",  // W
    "X   X\n X X \n  X  \n X X \nX   X\n",  // X
    "Y   Y\n Y Y \n  Y  \n  Y  \n  Y  \n",  // Y
    "ZZZZZ\n   Z \n  Z  \n Z   \nZZZZZ\n",  // Z
    // a-z
    "     \n     \n     \n     \n     \n",  // Space
    " a  \n a a \naaaaa\na   a\na   a\n",  // a
    "bbbbb\nb    \nbbbb \nb    \nbbbb \n",  // b
    " ccc \nc    \nc    \nc    \n ccc \n",  // c
    "ddddd\nd    d\n ddddd\nd    d\nddddd\n",  // d
    "eeeee\ne    \neee  \ne    \neeeee\n",  // e
    "fffff\nf    \nffff \nf    \nf    \n",  // f
    " ggg \ng   g\nggggg\ng   g\ngggg \n",  // g
    "h   h\nh   h\nhhhhh\nh   h\nh   h\n",  // h
    " iii \n  i  \n  i  \n  i  \n iii \n",  // i
    "   j \n   j \n   j \nj  j \njjjj\n",  // j
    "k  k \nk k k\nkkk  \nk k k\nk   k\n",  // k
    "l    \nl    \nl    \nl    \nll   \n",  // l
    "m    m\nmm  mm\nm m m m\nm     m\nm     m\n",  // m
    "n    n\nn n  n\nn  n n\nn   nn\nn    n\n",  // n
    " ooo \no   o\no   o\no   o\n ooo \n",  // o
    "ppppp\np   p\nppppp\np    \np    \n",  // p
    " qqq \nq   q\nq   q\n qqq \n    q\n",  // q
    "rrrrr\nr   r\nrrrr \nr  r \nr   r\n",  // r
    " sssss\ns     \ns  sss\n      s\nsssss\n",  // s
    "tttttt\n  t  \n  t  \n  t  \n  t  \n",  // t
    "u   u\nu   u\nu   u\nu   u\n uuu \n",  // u
    "v   v\nv   v\nv   v\n v v \n  v  \n",  // v
    "w     w\nw   w w\nw w w w\n w w w \n  w w  \n",  // w
    "x   x\n x x \n  x  \n x x \nx   x\n",  // x
    "y   y\n y y \n  y  \n  y  \n  y  \n",  // y
    "zzzzzz\n     z\n   z \n z   \nzzzzzz\n"   // z
};

// Function to convert a character to its ASCII art representation
void printAsciiArt(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        printf("%s", ascii_art[ch - 'A']);
    } else if (ch >= 'a' && ch <= 'z') {
        printf("%s", ascii_art[ch - 'a' + 26]);
    } else {
        printf("%s", ascii_art[52]); // space for characters that are not mapped
    }
}

// Function to convert a string to ASCII art line by line
void textToAsciiArt(const char *text) {
    for (int i = 0; i < CHAR_HEIGHT; i++) {
        for (int j = 0; text[j] != '\0'; j++) {
            printAsciiArt(text[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char line[MAXLINE];
    printf("Enter text: ");
    fgets(line, MAXLINE, stdin);

    // Remove newline character from the input line
    line[strcspn(line, "\n")] = 0;

    // Print ASCII art representation of the input text
    textToAsciiArt(line);
    return 0;
}