#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char input[20];
    printf("Enter a string: ");
    gets(input);
    
    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case 'a': input[i] = 'A'; break;
            case 'b': input[i] = 'B'; break;
            case 'c': input[i] = 'C'; break;
            case 'd': input[i] = 'D'; break;
            case 'e': input[i] = 'E'; break;
            case 'f': input[i] = 'F'; break;
            case 'g': input[i] = 'G'; break;
            case 'h': input[i] = 'H'; break;
            case 'i': input[i] = 'I'; break;
            case 'j': input[i] = 'J'; break;
            case 'k': input[i] = 'K'; break;
            case 'l': input[i] = 'L'; break;
            case 'm': input[i] = 'M'; break;
            case 'n': input[i] = 'N'; break;
            case 'o': input[i] = 'O'; break;
            case 'p': input[i] = 'P'; break;
            case 'q': input[i] = 'Q'; break;
            case 'r': input[i] = 'R'; break;
            case 's': input[i] = 'S'; break;
            case 't': input[i] = 'T'; break;
            case 'u': input[i] = 'U'; break;
            case 'v': input[i] = 'V'; break;
            case 'w': input[i] = 'W'; break;
            case 'x': input[i] = 'X'; break;
            case 'y': input[i] = 'Y'; break;
            case 'z': input[i] = 'Z'; break;
            default: break;
        }
    }
    
    printf("Modified string: %s\n", input);
    
    return 0;
}
