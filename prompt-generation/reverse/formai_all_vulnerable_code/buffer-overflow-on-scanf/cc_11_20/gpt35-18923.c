//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

int main() {
    char filename[50];
    char input[MAXCHAR];
    char output[MAXCHAR];
    FILE *fp;

    // get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // open the file
    fp = fopen(filename, "r");

    // check if the file exists
    if (fp == NULL) {
        printf("File not found.");
        exit(1);
    }

    // read the contents of the file
    fgets(input, MAXCHAR, fp);

    // close the file
    fclose(fp);

    // initialize the output string
    strcpy(output, "");

    // iterate through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // if the current character is a '<' and the next character is not a '/', add a newline and increase the indent level
        if (input[i] == '<' && input[i+1] != '/') {
            strcat(output, "\n");
            strcat(output, "    ");
            strcat(output, &input[i]);
            // iterate through the rest of the string to find the end tag
            for (int j = i+1; j < strlen(input); j++) {
                if (input[j] == '>') {
                    i = j;
                    break;
                }
            }
        }
        // if the current character is a '<' and the next character is a '/', decrease the indent level
        else if (input[i] == '<' && input[i+1] == '/') {
            strcat(output, &input[i]);
            strcat(output, "\n");
            for (int k = 0; k < 4; k++) {
                output[strlen(output)-2] = ' ';
            }
            // iterate through the rest of the string to find the end tag
            for (int j = i+1; j < strlen(input); j++) {
                if (input[j] == '>') {
                    i = j;
                    break;
                }
            }
        }
        // if the current character is a whitespace, ignore it
        else if (input[i] == ' ') {
            continue;
        }
        // if the current character is anything else, add it to the output string
        else {
            strncat(output, &input[i], 1);
        }
    }

    // print the beautified HTML
    printf("%s", output);

    return 0;
}