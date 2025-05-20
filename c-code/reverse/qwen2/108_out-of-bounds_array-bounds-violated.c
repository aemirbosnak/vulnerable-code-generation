#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void sanitize(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';' || str[i] == '<' || str[i] == '>' || str[i] == '|' || str[i] == '&') {
            str[i] = ' ';
        }
    }
}

int main() {
    char input1[256];
    char input2[256];
    char input3[256];

    printf("Enter string 1: ");
    fgets(input1, sizeof(input1), stdin);
    sanitize(input1);

    printf("Enter string 2: ");
    fgets(input2, sizeof(input2), stdin);
    sanitize(input2);

    printf("Enter string 3: ");
    fgets(input3, sizeof(input3), stdin);
    for (int i = 0; input3[i] != '\0'; i++) {
        if (input3[i] == ';' || input3[i] == '<' || input3[i] == '>' || input3[i] == '|' || input3[i] == '&') {
            input3[i] = '_';
        }
    }

    printf("Sanitized strings:\n");
    printf("String 1: %s", input1);
    printf("String 2: %s", input2);
    printf("String 3: %s", input3);

    return 0;
}
