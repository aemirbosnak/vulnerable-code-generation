//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

//Function to remove white spaces and empty lines
char *removeWhiteSpaces(char *str) {
    char *newStr = malloc(sizeof(char) * SIZE);
    int i, j;

    for(i = 0, j = 0; str[i] != '\0'; i++) {
        if(!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')) {
            newStr[j++] = str[i];
        }
    }

    newStr[j] = '\0';
    free(str);

    return newStr;
}

//Function to add indentation
char *addIndentation(char *str, int tabs) {
    char *newStr = malloc(sizeof(char) * SIZE);
    int i, j = 0;

    for(i = 0; i < tabs; i++) {
        newStr[j++] = '\t';
    }

    for(i = 0; str[i] != '\0'; i++) {
        newStr[j++] = str[i];

        //Add newline character after a closing tag
        if(str[i] == '>' && (str[i+1] == '<' || str[i+1] == '/')) {
            newStr[j++] = '\n';
            
            //Add additional indentation for ending tags
            if(str[i+1] == '/') {
                tabs--;
            }
            newStr = addIndentation(newStr, tabs);
            newStr[j++] = str[++i]; //Add following character
        }

        //Add newline and indentation for open tags
        if(str[i] == '<' && str[i+1] != '/' && str[i+1] != '!') {
            newStr[j++] = '\n';
            newStr = addIndentation(newStr, tabs+1);
        }
    }

    newStr[j] = '\0';
    free(str);

    return newStr;
}

int main() {
    char buffer[SIZE];
    int tabs = 0,len;
    FILE *fp, *fp2;
    char filename[100],outputFilename[100];

    printf("Enter the source file name: ");
    scanf("%s", &filename);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    printf("Enter the output file name: ");
    scanf("%s", &outputFilename);

    fp2=fopen(outputFilename,"w");

    while(fgets(buffer, SIZE, fp) != NULL) {
        len=strlen(buffer);
        if(len-1>0) {   
            buffer[len-1]='\0';  //remove newline character from fgets()

            //Remove whitespace from line
            char *newLine = removeWhiteSpaces(buffer);

            //Add indentation to line
            char *indentedLine = addIndentation(newLine, tabs);

            //Print indented line to output file
            fprintf(fp2, "%s", indentedLine);

            if(strstr(indentedLine, "</") != NULL) {
                tabs--;
            }

            if(strstr(indentedLine, "/>") == NULL && strstr(indentedLine, "<!") == NULL && strstr(indentedLine, "</") == NULL) {
                tabs++;
            }

            //Free memory used for newLine and indentedLine
            free(newLine);
            free(indentedLine);
        }
    }

    fclose(fp);
    fclose(fp2);

    printf("File beautified successfully!\n");

    return 0;
}