#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    printf("Enter text: ");
    gets(input);
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (islower(input[i])) {
            switch (input[i]) {
                case 'a': printf("%c", 'A'); break;
                case 'b': printf("%c", 'B'); break;
                case 'c': printf("%c", 'C'); break;
                case 'd': printf("%c", 'D'); break;
                case 'e': printf("%c", 'E'); break;
                case 'f': printf("%c", 'F'); break;
                case 'g': printf("%c", 'G'); break;
                case 'h': printf("%c", 'H'); break;
                case 'i': printf("%c", 'I'); break;
                case 'j': printf("%c", 'J'); break;
                case 'k': printf("%c", 'K'); break;
                case 'l': printf("%c", 'L'); break;
                case 'm': printf("%c", 'M'); break;
                case 'n': printf("%c", 'N'); break;
                case 'o': printf("%c", 'O'); break;
                case 'p': printf("%c", 'P'); break;
                case 'q': printf("%c", 'Q'); break;
                case 'r': printf("%c", 'R'); break;
                case 's': printf("%c", 'S'); break;
                case 't': printf("%c", 'T'); break;
                case 'u': printf("%c", 'U'); break;
                case 'v': printf("%c", 'V'); break;
                case 'w': printf("%c", 'W'); break;
                case 'x': printf("%c", 'X'); break;
                case 'y': printf("%c", 'Y'); break;
                case 'z': printf("%c", 'Z'); break;
            }
        } else {
            printf("%c", input[i]);
        }
    }
    
    return 0;
}
