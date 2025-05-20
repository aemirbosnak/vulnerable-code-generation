//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: medieval
/*
 * Program: Medieval C Syntax Parser
 * Description: Parses C syntax and prints a medieval-style translation
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>

int main() {
    char c;
    int i = 0;
    char line[100];

    printf("Enter C syntax: ");
    scanf("%s", line);

    while (line[i] != '\0') {
        c = line[i];
        if (c == ' ') {
            printf(" ");
        } else if (c == '(') {
            printf("thou hast entered ");
        } else if (c == ')') {
            printf(" and it is good!\n");
        } else if (c == '+') {
            printf("thou hast added ");
        } else if (c == '-') {
            printf("thou hast subtracted ");
        } else if (c == '*') {
            printf("thou hast multiplied ");
        } else if (c == '/') {
            printf("thou hast divided ");
        } else if (c == '%') {
            printf("thou hast found the modulo of ");
        } else if (c == '=') {
            printf("thou hast assigned ");
        } else if (c == '>') {
            printf("thou hast compared ");
        } else if (c == '<') {
            printf("thou hast compared ");
        } else if (c == '!') {
            printf("thou hast found the logical negation of ");
        } else {
            printf("%c", c);
        }
        i++;
    }

    return 0;
}