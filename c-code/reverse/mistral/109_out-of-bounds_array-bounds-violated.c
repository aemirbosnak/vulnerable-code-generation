#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input1[100], input2[100], input3[100];

    printf("Enter first input: ");
    fgets(input1, sizeof(input1), stdin);
    for (int i = 0; input1[i]; i++) {
        if (input1[i] == '\n') {
            input1[i] = '\0';
        } else if (input1[i] == ';' || input1[i] == '<' || input1[i] == '>' || input1[i] == '|' || input1[i] == '&') {
            input1[i] = ' ';
        }
    }
    printf("Sanitized first input: %s\n", input1);

    printf("Enter second input: ");
    fgets(input2, sizeof(input2), stdin);
    for (int i = 0; input2[i]; i++) {
        if (input2[i] == '\n') {
            input2[i] = '\0';
        } else if (input2[i] == ';' || input2[i] == '<' || input2[i] == '>' || input2[i] == '|' || input2[i] == '&') {
            input2[i] = ' ';
        }
    }
    printf("Sanitized second input: %s\n", input2);

    printf("Enter third input: ");
    fgets(input3, sizeof(input3), stdin);
    for (int i = 0; input3[i]; i++) {
        if (input3[i] == '\n') {
            input3[i] = '\0';
        } else if (input3[i] != '_') {
            input3[i] = '_';
        }
    }
    printf("Sanitized third input: %s\n", input3);

    return 0;
}
