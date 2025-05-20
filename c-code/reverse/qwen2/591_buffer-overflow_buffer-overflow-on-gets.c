#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    int i = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            switch(tolower(input[i])) {
                case 'a': printf("Xy"); break;
                case 'b': printf("Zw"); break;
                case 'c': printf("Uv"); break;
                case 'd': printf("Ts"); break;
                case 'e': printf("Rq"); break;
                case 'f': printf("Op"); break;
                case 'g': printf("Nl"); break;
                case 'h': printf("Kj"); break;
                case 'i': printf("Hg"); break;
                case 'j': printf("Ef"); break;
                case 'k': printf("Cd"); break;
                case 'l': printf("Ab"); break;
                case 'm': printf("Yx"); break;
                case 'n': printf("Wv"); break;
                case 'o': printf("Ut"); break;
                case 'p': printf("Rs"); break;
                case 'q': printf("Qr"); break;
                case 'r': printf("Pq"); break;
                case 's': printf("Oo"); break;
                case 't': printf("Nn"); break;
                case 'u': printf("Mm"); break;
                case 'v': printf("Ll"); break;
                case 'w': printf("Kk"); break;
                case 'x': printf("Jj"); break;
                case 'y': printf("Ii"); break;
                case 'z': printf("Hh"); break;
                default: printf("Error"); break;
            }
        } else {
            printf("%c", input[i]);
        }
        i++;
    }
    return 0;
}
