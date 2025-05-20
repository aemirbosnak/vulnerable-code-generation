//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char html[10000];
    char output[10000];
    int indent_level = 0;
    int i = 0, j = 0;

    printf("Enter the HTML code to be beautified: ");
    fgets(html, 10000, stdin);

    while (html[i] != '\0') {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                // end tag
                indent_level--;
                j--;
                for (int k=0; k<indent_level; k++) {
                    output[j++] = '\t';
                }
                while (html[i] != '>') {
                    output[j++] = html[i++];
                }
            } else {
                // start tag
                indent_level++;
                for (int k=0; k<indent_level-1; k++) {
                    output[j++] = '\t';
                }
                while (html[i] != '>') {
                    output[j++] = html[i++];
                }
                output[j++] = '>';
            }
        } else {
            // text or comment
            if (html[i] == '<' && html[i+1] == '!') {
                // comment
                for (int k=0; k<indent_level; k++) {
                    output[j++] = '\t';
                }
                while (html[i] != '>') {
                    output[j++] = html[i++];
                }
                output[j++] = '>';
            } else {
                // text
                for (int k=0; k<indent_level; k++) {
                    output[j++] = '\t';
                }
                while (html[i] != '<' && html[i] != '\0') {
                    output[j++] = html[i++];
                }
                i--;
            }
        }
        i++;
    }

    output[j] = '\0';

    printf("Beautified output:\n%s", output);

    return 0;
}