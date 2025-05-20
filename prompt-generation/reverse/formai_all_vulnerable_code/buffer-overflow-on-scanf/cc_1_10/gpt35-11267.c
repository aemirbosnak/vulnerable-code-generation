//FormAI DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 /* Maximum size of input HTML file */

/* Function to beautify HTML code */
void beautifyHTML(char *filename) {
    FILE *fp; /* Input file pointer */
    char inputHTML[MAX_SIZE]; /* Input HTML code */
    char outputHTML[MAX_SIZE]; /* Output HTML code */
    int indentLevel = 0; /* Starting indentation level */
    int i = 0; /* Looping variable */
    
    /* Read input HTML file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    } else {
        fgets(inputHTML, MAX_SIZE, fp);
        fclose(fp);
    }
    
    /* Remove extra whitespace and newline characters */
    for (i = 0; i < strlen(inputHTML); i++) {
        if (inputHTML[i] == ' ' && inputHTML[i+1] == ' ') {
            /* Remove extra spaces */
            memmove(&inputHTML[i], &inputHTML[i+1], strlen(inputHTML) - i);
            i--;
        } else if (inputHTML[i] == '\n' || inputHTML[i] == '\r') {
            /* Remove newline characters */
            memmove(&inputHTML[i], &inputHTML[i+1], strlen(inputHTML) - i);
            i--;
        }
    }
    
    /* Add indentation to HTML */
    for (i = 0; i < strlen(inputHTML); i++) {
        outputHTML[i] = inputHTML[i];
        if (inputHTML[i] == '<' && inputHTML[i+1] != '/') {
            /* Starting tag */
            if (inputHTML[i+1] == '!' || inputHTML[i+1] == '?') {
                /* Declaration or comment tag */
                indentLevel--;
            } else {
                /* Normal tag */
                indentLevel++;
            }
            outputHTML[i+1] = '\n';
            for (int j = 0; j < indentLevel; j++) {
                strcat(outputHTML, "\t"); /* Add tab indentation */
            }
            i = strlen(outputHTML) - 1;
        } else if (inputHTML[i] == '<' && inputHTML[i+1] == '/') {
            /* Ending tag */
            indentLevel--;
            outputHTML[i+1] = '\n';
            for (int j = 0; j < indentLevel; j++) {
                strcat(outputHTML, "\t"); /* Add tab indentation */
            }
            i = strlen(outputHTML) - 1;
        }
    }
    
    /* Write output HTML to file */
    fp = fopen("output.html", "w");
    if (fp == NULL) {
        printf("Could not open file output.html\n");
        exit(1);
    } else {
        fputs(outputHTML, fp);
        fclose(fp);
    }
    
    printf("HTML beautification successful! Output written to output.html\n");
}

int main() {
    char filename[MAX_SIZE];
    
    printf("Please enter the input HTML filename/path: ");
    scanf("%s", filename);
    
    beautifyHTML(filename);
    
    return 0;
}