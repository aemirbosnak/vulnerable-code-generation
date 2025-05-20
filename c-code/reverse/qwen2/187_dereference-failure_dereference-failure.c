#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

char translateAlienToEnglish(char c) {
    switch (tolower(c)) {
        case 'a': return 'A';
        case 'b': return 'B';
        case 'c': return 'C';
        case 'd': return 'D';
        case 'e': return 'E';
        case 'f': return 'F';
        case 'g': return 'G';
        case 'h': return 'H';
        case 'i': return 'I';
        case 'j': return 'J';
        case 'k': return 'K';
        case 'l': return 'L';
        case 'm': return 'M';
        case 'n': return 'N';
        case 'o': return 'O';
        case 'p': return 'P';
        case 'q': return 'Q';
        case 'r': return 'R';
        case 's': return 'S';
        case 't': return 'T';
        case 'u': return 'U';
        case 'v': return 'V';
        case 'w': return 'W';
        case 'x': return 'X';
        case 'y': return 'Y';
        case 'z': return 'Z';
        default: return c;
    }
}

int main() {
    char alienString[] = "Hello World!";
    for (int i = 0; alienString[i] != '\0'; i++) {
        printf("%c", translateAlienToEnglish(alienString[i]));
    }
    return 0;
}
