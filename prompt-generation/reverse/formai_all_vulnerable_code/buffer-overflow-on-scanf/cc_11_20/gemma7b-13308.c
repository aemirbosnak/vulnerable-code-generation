//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    int state = 0;
    char keyword[MAX_BUFFER_SIZE];

    printf("Enter C syntax: ");
    scanf("%s", buffer);

    while (buffer[i] != '\0') {
        switch (state) {
            case 0:
                if (buffer[i] == '{' || buffer[i] == '(') {
                    state = 1;
                } else if (buffer[i] == ' ') {
                    state = 2;
                } else if (buffer[i] == '"') {
                    state = 3;
                } else {
                    printf("Error: Unexpected character.\n");
                    exit(1);
                }
                break;
            case 1:
                if (buffer[i] == '}' || buffer[i] == ')') {
                    state = 0;
                } else if (buffer[i] == ' ') {
                    state = 2;
                } else {
                    printf("Error: Missing closing bracket.\n");
                    exit(1);
                }
                break;
            case 2:
                if (buffer[i] == ' ') {
                    state = 0;
                } else if (buffer[i] == '"') {
                    state = 3;
                } else {
                    printf("Error: Unexpected character.\n");
                    exit(1);
                }
                break;
            case 3:
                if (buffer[i] == '"') {
                    state = 0;
                } else {
                    printf("Error: Missing closing quotation mark.\n");
                    exit(1);
                }
                break;
        }

        i++;
    }

    printf("Syntax parsed successfully.\n");

    return 0;
}