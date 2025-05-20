//FormAI DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512

int indent_level = 0;

void print_indentation() {
    int i;
    for(i = 0; i < indent_level; i++) {
        printf("    ");
    }
}

void newline_and_indent() {
    printf("\n");
    print_indentation();
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s file_name\n", argv[0]);
        return 1;
    }
    
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }
    
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int len = strlen(line);
        if(line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        int i;
        for(i = 0; i < len; i++) {
            char c = line[i];
            switch(c) {
                case '<':
                    if(line[i+1] == '/') {
                        indent_level--;
                    }
                    
                    newline_and_indent();
                    printf("%c", c);
                    
                    if(line[i+1] != '/' && line[i+1] != ' ') {
                        indent_level++;
                    }
                    
                    break;
                case '>':
                    printf("%c", c);
                    if(line[i-1] != '/') {
                        indent_level--;
                    }
                    break;
                case '/':
                    if(line[i-1] == '<' && line[i+1] == '>') {
                        printf("%s", "/>");
                    } else {
                        printf("%c", c);
                    }
                    break;
                default:
                    printf("%c", c);
                    break;
            }
        }
    }
    
    fclose(fp);
    printf("\n");
    return 0;
}