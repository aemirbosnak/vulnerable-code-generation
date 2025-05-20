#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void replace(char *str, char oldChar, char newChar) {
    int i, j;
    for (i = 0; str[i] != '\0'; ++i) {
        for (j = i; str[j] != '\0'; ++j) {
            if (str[i] == oldChar && str[j] == oldChar + 1) {
                str[i] = newChar;
                for (; j < strlen(str); ++j) {
                    str[j] = str[j + 1];
                }
                str[strlen(str) - 1] = '\0';
                break;
            }
        }
    }
}

int main() {
    char input[10];
    char oldChar = 'a', newChar = 'b';
    gets(input);
    replace(input, oldChar, newChar);
    printf("Replaced string: %s\n", input);
    return 0;
}
