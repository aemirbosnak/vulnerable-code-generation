#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

void translateCharacter(char c) {
    if (isalpha(c)) {
        char upper = toupper(c);
        switch (upper) {
            case 'A': printf("XQ"); break;
            case 'B': printf("YR"); break;
            case 'C': printf("ZS"); break;
            case 'D': printf("AT"); break;
            case 'E': printf("BU"); break;
            case 'F': printf("CV"); break;
            case 'G': printf("DW"); break;
            case 'H': printf("EX"); break;
            case 'I': printf("FY"); break;
            case 'J': printf("GZ"); break;
            case 'K': printf("HA"); break;
            case 'L': printf("HB"); break;
            case 'M': printf("HC"); break;
            case 'N': printf("HD"); break;
            case 'O': printf("HE"); break;
            case 'P': printf("HF"); break;
            case 'Q': printf("HG"); break;
            case 'R': printf("HH"); break;
            case 'S': printf("HI"); break;
            case 'T': printf("HJ"); break;
            case 'U': printf("HK"); break;
            case 'V': printf("HL"); break;
            case 'W': printf("HM"); break;
            case 'X': printf("HN"); break;
            case 'Y': printf("HO"); break;
            case 'Z': printf("HP"); break;
            default: printf("Error: Unknown character\n");
        }
    } else {
        printf("%c", c);
    }
}

int main() {
    char input[1024];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    int i = 0;
    while (input[i] != '\0') {
        translateCharacter(input[i]);
        i++;
    }
    return 0;
}
