//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>

// This C program is an exciting metadata extractor
// that scans a given source code file and extracts
// information about the functions defined therein.

int main() {

    char filename[50];
    printf("Enter the file name: ");

    // get the filename from the user
    scanf("%s", filename);

    // open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("\n\nFunction Name\t|\tReturn Type\t|\tArguments\n");

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        char * token;
        char * temp = line;
        int index = 0;
        int flag = 0;

        // scan each line for function definitions
        while ((token = strsep(&temp, " \t\n")) != NULL) {
            if (flag == 0 && index == 0 && strcmp(token, "static") != 0) {
                printf("%s\t\t|\t", token);
                flag = 1;
            }
            else if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || 
                    strcmp(token, "char") == 0 || strcmp(token, "double") == 0 || 
                    strcmp(token, "void") == 0) {
                printf("%s\t\t|\t", token);
            }
            else if (*token == '(' || *token == ')') {
                continue;
            }
            else if (*token == '{') {
                printf("\n");
                break;
            }
            else {
                printf("%s ", token);
            }
            index++;
        }
    }

    fclose(fp);
    if (line)
        free(line);

    return 0;
}