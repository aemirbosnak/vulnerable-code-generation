//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void printIndent(int level) { // function prints indents based on nesting level
    int i;
    for (i = 0; i < level; i++)
        putchar('\t');
}

int main() {
    int i, c;
    int inTag = 0;
    int inComment = 0;
    int inQuotes = 0;
    char line[MAX_LENGTH];
    int level = 0;

    while (fgets(line, MAX_LENGTH, stdin) != NULL) {
        i = 0;
        while (line[i] != '\0') {
            c = line[i];
            if (inComment) {
                putchar(c);
                if (c == '>' && line[i-1] == '-')
                    inComment = 0;
            } else if (inQuotes) {
                putchar(c);
                if (c == inQuotes)
                    inQuotes = 0;
            } else if (inTag) {
                putchar(c);
                if (c == '>')
                    inTag = 0;
            } else {
                switch (c) {
                    case '<':
                        if (line[i+1] == '!' && line[i+2] == '-' && line[i+3] == '-') {
                            inComment = 1;
                            printIndent(level);
                            putchar(c);
                        } else {
                            printIndent(level);
                            inTag = 1;
                            putchar(c);
                            if (line[i+1] == '/')
                                level--;
                            else
                                level++;
                        }
                        break;
                    case '"':
                    case '\'':
                        inQuotes = c;
                        putchar(c);
                        break;
                    default:
                        putchar(c);
                        break;
                }
            }
            i++;
        }
    }

    return 0;
}