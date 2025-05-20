//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <string.h>

int detectIntrusion(char *input, int pos, int level, int count) {
    char buffer[20];
    sprintf(buffer, "Level %d", level);
    printf("%*c", level * 2, ' '); // indent output based on level
    printf("%s:\n", buffer); 

    int i;
    for (i = pos; i < strlen(input); i++) {
        printf("%*cScanning character: %c\n", level * 2, ' ', input[i]);

        if (i + 1 < strlen(input) && input[i] == '/' && input[i+1] == '*') {
            count++;
            printf("%*cFound start of comment block! Count incremented to %d.\n", level * 2, ' ', count);
            i++;
            level++;
            i = detectIntrusion(input, i+1, level, count);
            level--;
        } else if (i + 1 < strlen(input) && input[i] == '*' && input[i+1] == '/') {
            count--;
            printf("%*cFound end of comment block! Count decremented to %d.\n", level * 2, ' ', count);
            i++;
            if (count < 0) {
                printf("%*cINTRUSION DETECTED: Unmatched ending comment block.\n", level * 2, ' ');
                return i;
            }
        } else if (count > 0) {
            continue; // ignore chars inside comment block
        } else if (i + 1 < strlen(input) && input[i] == '/' && input[i+1] == '/') {
            printf("%*cFound start of single-line comment. Skipping remaining characters in line.\n", level * 2, ' ');
            while (i < strlen(input) && input[i] != '\n') {
                i++;
            }
        } else if (i + 1 < strlen(input) && input[i] == '"' && input[i+1] != '"') {
            printf("%*cFound start of string literal. Skipping characters until end of string.\n", level * 2, ' ');
            while (i < strlen(input) && input[i] != '"' && (i == 0 || input[i-1] != '\\')) {
                i++;
            }
            if (i == strlen(input) || input[i] != '"') {
                printf("%*cINTRUSION DETECTED: Unmatched string literal.\n", level * 2, ' ');
                return i;
            }
        } else if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
            printf("%*cFound opening bracket %c. Recursively scanning for matching closing bracket...\n", level * 2, ' ', input[i]);
            i = detectIntrusion(input, i+1, level+1, 0) - 1;
        } else if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
            printf("%*cFound matching closing bracket %c.\n", level * 2, ' ', input[i]);
            return i;
        }
    }

    if (count > 0) {
        printf("%*cINTRUSION DETECTED: Unmatched starting comment block.\n", level * 2, ' ');
        return i;
    }

    return i;
}

int main() {
    char input[500];

    printf("Enter C code (max 500 characters): ");
    fgets(input, 500, stdin);
    input[strlen(input)-1] = '\0'; // remove newline character from input string

    int i = detectIntrusion(input, 0, 1, 0);
    if (i == strlen(input)) {
        printf("No intrusion detected.\n");
    } else {
        printf("Intrusion detected at character %d.\n", i);
    }

    return 0;
}