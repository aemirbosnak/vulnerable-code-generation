//FormAI DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024];
    char output[1024];
    char tagStack[64][16];
    int i = 0, stackTop = -1, tagStart = 0, len;

    printf("Enter the HTML code to beautify:\n");
    fgets(input, 1024, stdin);

    len = strlen(input);
    for (i = 0; i < len; i++) {
        if (input[i] == '<') {
            // push tag onto stack
            tagStart = i + 1;
            while (input[i++] != '>') {
                if (input[i] == ' ' || input[i] == '/' || input[i] == '>') {
                    strncpy(tagStack[++stackTop], &input[tagStart], i - tagStart);
                    tagStack[stackTop][i - tagStart] = '\0';
                    break;
                }
            }
            i--;
            strcat(output, "<");
            strcat(output, tagStack[stackTop]);
            strcat(output, ">");

            if (input[i+1] != '\n') {
                strcat(output, "\n");
            }
        }
        else if (input[i] == '>') {
            strcat(output, ">");
            if (input[i+1] != '\n') {
                strcat(output, "\n");
            }
        }
        else {
            strncat(output, &input[i], 1);
            if (input[i] == '\n' && tagStack[stackTop][0] != 'b') {
                strcat(output, "\t");
            }
        }

        if (input[i] == '<' && input[i+1] == '/') {
            // pop tag from stack
            stackTop--;
        }
    }

    printf("Beautified HTML code:\n%s", output);

    return 0;
}