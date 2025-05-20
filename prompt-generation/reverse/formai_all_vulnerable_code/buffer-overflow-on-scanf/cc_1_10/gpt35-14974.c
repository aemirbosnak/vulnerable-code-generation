//FormAI DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char *fileName);
void indent(int depth);
void addIndent();
void reduceIndent();

int indentLevel = 0;

int main() {
    char fileName[100];
    printf("Enter the HTML file name: ");
    scanf("%s", fileName);
    beautifyHTML(fileName);
    return 0;
}

void beautifyHTML(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("ERROR: Could not open file '%s'.\n", fileName);
        exit(1);
    }

    int c;
    int isNewLine = 1;
    int isTag = 0; // 0 -> Not a tag, 1 -> Opening tag, 2 -> Closing tag, 3 -> Single tag
    int isComment = 0;
    int isScript = 0;
    char tag[100] = {'\0'};
    int index = 0;

    while((c = fgetc(fp)) != EOF) {
        if(isNewLine) {
            indent(indentLevel);
            isNewLine = 0;
        }
        if(!isComment && !isScript) {
            if(c == '<') {
                isTag = 1;
                memset(tag, '\0', strlen(tag)); // Clearing the tag buffer
                index = 0;
            }
            else if (c == '>') {
                if(isTag == 1 || isTag == 3) { // Opening or single tag
                    isTag = 3;
                    addIndent();
                }
                else if(isTag == 2) { // Closing tag
                    reduceIndent();
                    addIndent();
                }
                printf("%c\n", c);
                isNewLine = 1;
            }
            else {
                if(isTag != 0) {
                    // Collecting the tag name
                    if(c == '/') {
                        isTag = 2;
                        reduceIndent();
                    }
                    else if(c == ' ') {
                        isTag = 3;
                    }
                    else {
                        tag[index++] = c;
                    }
                }
                else if(c == '\n') {
                    isNewLine = 1;
                }
                else if (c == '<') {
                    isNewLine = 1;
                    indent(indentLevel);
                }
                printf("%c", c);
            }
            if(!isspace(c) && isTag == 1) {
                // Opening tag found
                printf("\n");
                isNewLine = 1;
                isTag = 0;
            }
        }
        else if(isComment) {
            if(c == '-' && fgetc(fp) == '-' && fgetc(fp) == '>') {
                printf("-->\n");
                isNewLine = 1;
                isComment = 0;
            }
            printf("%c", c);
        }
        else if(isScript) {
            if(c == '<' && fgetc(fp) == '/' && fgetc(fp) == 's' && fgetc(fp) == 'c' && fgetc(fp) == 'r' && fgetc(fp) == 'i' && fgetc(fp) == 'p' && fgetc(fp) == 't' && fgetc(fp) == '>') {
                isScript = 0;
                printf("</script>\n");
                isNewLine = 1;
            }
            printf("%c", c);
        }
        if(c == '<' && fgetc(fp) == '!' && fgetc(fp) == '-' && fgetc(fp) == '-') {
            // Comment found
            isComment = 1;
            printf("<!--");
            isNewLine = 1;
        }
        else if(c == '<' && fgetc(fp) == 's' && fgetc(fp) == 'c' && fgetc(fp) == 'r' && fgetc(fp) == 'i' && fgetc(fp) == 'p' && fgetc(fp) == 't' && fgetc(fp) == '>') {
            // Script found
            isScript = 1;
            printf("<script>");
            isNewLine = 1;
        }
    }

    fclose(fp);
}

void indent(int depth) {
    for(int i = 0; i < depth; i++) {
        printf("  ");
    }
}

void addIndent() {
    indentLevel++;
}

void reduceIndent() {
    if(indentLevel > 0) {
        indentLevel--;
    }
}