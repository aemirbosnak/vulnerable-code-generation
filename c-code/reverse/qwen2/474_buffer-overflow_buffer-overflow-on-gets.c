#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void replace(char *str, char oldChar, char newChar) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char buffer[50];
    printf("Enter a string: ");
    gets(buffer);
    replace(buffer, 'a', 'A');
    printf("Modified string: %s\n", buffer);
    return 0;
}
