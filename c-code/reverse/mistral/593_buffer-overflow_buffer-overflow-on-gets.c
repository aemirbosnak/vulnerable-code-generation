#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAP_SIZE 256
char map[MAP_SIZE] = {
    'Aa','Bb','Cc','Dd','Ee','Ff','Gg','Hh','Ii','Jj','Kk','Ll','Mm','Nn','Oo','Pp','Qq','Rr','Ss','Tt','Uu','Vv','Ww','Xx','Yy','Zz',
    ' ',',','.','0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','^','&','*','(',')','-','_','+','=','{','}','[',']','|','\\',':',';','"','\'','<','>','.','?','/','~',
    '\0'
};

int main() {
    char input[100];
    printf("Enter a string: ");
    gets(input);

    for (int i = 0; input[i] != '\0'; ++i) {
        if (isalpha(input[i])) {
            putchar(map[(int)toupper(input[i]) * 27 + (int)toupper(input[i+1]) % 27]);
            i++;
        } else if (isdigit(input[i])) {
            putchar(map[(int)input[i] + 13]);
        } else if (input[i] == ' ') {
            putchar(map[58]);
        } else {
            printf("Unknown character: %c\n", input[i]);
        }
    }

    return 0;
}
