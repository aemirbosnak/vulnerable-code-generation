//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 2

int main(void) {
    FILE *fp;
    char *fileName = "index.html"; // input file name
    char *newFileName = "index_new.html"; // output file name
    char *buffer, *temp;
    long fileSize;

    // open input file
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    // allocate memory for file content
    buffer = (char*) malloc(sizeof(char) * (fileSize + 1));
    if (buffer == NULL) {
        printf("Error: unable to allocate memory.\n");
        fclose(fp);
        return 1;
    }

    // read file content into buffer
    if (fread(buffer, 1, fileSize, fp) != fileSize) {
        printf("Error: unable to read file.\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    // close input file
    fclose(fp);

    // allocate memory for output file content
    temp = (char*) malloc(sizeof(char) * (fileSize * 2 + 1)); // assuming output size could be double of input size
    if (temp == NULL) {
        printf("Error: unable to allocate memory.\n");
        free(buffer);
        return 1;
    }

    // beautify HTML code
    int i = 0;
    int j = 0;
    int depth = 0;
    while(buffer[i] != '\0') {
        if(buffer[i] == '<') {
            // opening tag
            if(buffer[i+1] != '/') {
                for(int k = 0; k < depth; k++) {
                    temp[j++] = ' ';
                }
                depth += TAB_SIZE;
                strncpy(temp + j, buffer + i, strstr(buffer + i, ">") - buffer - i + 1);
                j += strstr(buffer + i, ">") - buffer - i + 1;
            }
            // closing tag
            else {
                depth -= TAB_SIZE;
                for(int k = 0; k < depth; k++) {
                    temp[j++] = ' ';
                }
                strncpy(temp + j, buffer + i, strstr(buffer + i, ">") - buffer - i + 1);
                j += strstr(buffer + i, ">") - buffer - i + 1;
            }
            i += strstr(buffer + i, ">") - buffer + 1;
        }
        else {
            temp[j++] = buffer[i++];
        }
    }

    // write output to file
    fp = fopen(newFileName, "w");
    if (fp == NULL) {
        printf("Error: unable to create output file.\n");
        free(buffer);
        free(temp);
        return 1;
    }
    fwrite(temp, 1, j, fp);
    fclose(fp);

    // free memory
    free(buffer);
    free(temp);

    printf("File beautified successfully.\n");

    return 0;
}