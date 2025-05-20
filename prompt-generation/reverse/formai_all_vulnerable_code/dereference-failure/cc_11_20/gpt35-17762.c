//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1024

typedef enum {
    NONE,
    ELEMENT_OPEN,
    ELEMENT_CLOSE
} tag_status;

int main () {
    char buffer[MAX_SIZE];
    FILE *input_file;
    input_file = fopen("input.xml", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    char element[MAX_SIZE];
    int line_no = 0;
    tag_status status = NONE;
    int indentation_level = 0;
    while(fgets(buffer, MAX_SIZE, input_file) != NULL) {
        line_no++;

        // Removing whitespace
        char trimmed[MAX_SIZE];
        int i,j;
        for(i=0, j=0; buffer[i]!='\0'; i++){
            if(buffer[i] == ' ' || buffer[i] == '\t') {
                // Ignore whitespace
                continue;
            } else {
                trimmed[j++] = buffer[i];
            }
        }
        trimmed[j] = '\0';

        // Parsing line
        for(i=0; i<j; i++) {
            if(status == ELEMENT_OPEN) {
                if(trimmed[i]==' ') {
                    // Ignore space after tag
                    continue;
                }else if(trimmed[i]=='/') {
                    status = ELEMENT_CLOSE;
                } else {
                    element[strlen(element)] = trimmed[i];
                    status = NONE;
                }
            }else if(status == ELEMENT_CLOSE) {
                // Check if we closing the right tag
                if(trimmed[i] != '>' || element[i]!='<'){
                    printf("Error: Wrong closing tag on line %d\n", line_no);
                    exit(1);
                } else {
                    // We are done with this tag, reset everything
                    element[0] = '\0';
                    status = NONE;
                    indentation_level--;
                }
            }else if(trimmed[i]=='<') {
                // New element opening
                status = ELEMENT_OPEN;
                element[0] = '\0';
                indentation_level++;
            }
        }
        printf("%*s%s", indentation_level, "", trimmed);
    }
    fclose(input_file);
    return 0;
}