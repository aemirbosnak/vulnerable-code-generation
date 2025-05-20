#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input1[100], input2[100], input3[100];

    printf("Enter first input: ");
    fgets(input1, sizeof(input1), stdin);
    for (int i = 0; input1[i]; i++) {
        if (input1[i] == ';' || input1[i] == '<' || input1[i] == '>' || input1[i] == '|' || input1[i] == '&') {
            input1[i] = ' ';
        }
    }

    printf("Enter second input: ");
    fgets(input2, sizeof(input2), stdin);
    for (int i = 0; input2[i]; i++) {
        if (input2[i] == ';' || input2[i] == '<' || input2[i] == '>' || input2[i] == '|' || input2[i] == '&') {
            input2[i] = ' ';
        }
    }

    printf("Enter third input: ");
    fgets(input3, sizeof(input3), stdin);
    for (int i = 0; input3[i]; i++) {
        if (input3[i] == ';' || input3[i] == '<' || input3[i] == '>' || input3[i] == '|' || input3[i] == '&') {
            input3[i] = '_';
        }
    }

    printf("Sanitized inputs:\n");
    printf("Input 1: %s\n", input1);
    printf("Input 2: %s\n", input2);
    printf("Input 3: %s\n", input3);

    return 0;
}
