//FormAI DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 256 //Maximum character count for file upload

int main() {
    char file_name[20];
    FILE *file_pointer;

    printf("Enter the name of file to upload: ");
    scanf("%s", file_name);

    //Paranoid file name checking
    //Checking if the file name is too long
    if (strlen(file_name) >= 20) {
        printf("File name is too long! Please try again\n");
        return 0;
    }

    //Checking if the file name contains any suspicious characters
    for (int i = 0; i < strlen(file_name); i++) {
        if (!isalnum(file_name[i]) && file_name[i] != '_' && file_name[i] != '.') {
            printf("File name contains illegal characters! Please try again\n");
            return 0;
        }
    }

    printf("Uploading file...\n");

    file_pointer = fopen(file_name, "w");

    if (file_pointer == NULL) {
        printf("Error uploading file! Please try again\n");
        return 0;
    }

    char content[MAX_SIZE];

    printf("Enter the content to upload: ");
    scanf(" %[^\n]s", content);

    //Paranoid content checking
    //Checking if the content is too long
    if (strlen(content) >= MAX_SIZE) {
        printf("Content is too long! Please try again\n");
        return 0;
    }

    //Checking if the content contains any suspicious characters
    for (int i = 0; i < strlen(content); i++) {
        if (!isalnum(content[i]) && content[i] != ' ' && content[i] != '\t' && content[i] != '\n') {
            printf("Content contains illegal characters! Please try again\n");
            return 0;
        }
    }

    fprintf(file_pointer, "%s", content);

    fclose(file_pointer);

    printf("File uploaded successfully!\n");

    return 0;
}