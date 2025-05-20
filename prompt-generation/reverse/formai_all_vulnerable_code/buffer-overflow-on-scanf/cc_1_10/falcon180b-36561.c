//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Function to remove leading and trailing spaces
void trim(char* str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
}

// Function to split a string into words
int split_string(char* str, char** words) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to parse a resume line by line
void parse_resume(FILE* resume_file) {
    char line[MAX_LINE_SIZE];
    char* words[10];
    int word_count;

    // Read each line of the resume
    while (fgets(line, MAX_LINE_SIZE, resume_file)!= NULL) {
        // Remove leading and trailing spaces
        trim(line);

        // Split the line into words
        word_count = split_string(line, words);

        // Process each word
        for (int i = 0; i < word_count; i++) {
            printf("%s ", words[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE* resume_file;
    char filename[MAX_LINE_SIZE];

    // Get the resume file name from the user
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    // Open the resume file for reading
    resume_file = fopen(filename, "r");
    if (resume_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Parse the resume
    parse_resume(resume_file);

    // Close the resume file
    fclose(resume_file);

    return 0;
}