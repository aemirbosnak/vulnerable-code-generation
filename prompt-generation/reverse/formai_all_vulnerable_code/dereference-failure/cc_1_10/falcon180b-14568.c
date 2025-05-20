//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function to tokenize a line of text
void tokenize(char* line, char** tokens) {
    int num_tokens = 0;
    char* token = strtok(line, " \t\n\r\f\v");
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " \t\n\r\f\v");
    }
}

// Function to parse a resume line by line
void parse_resume(FILE* resume_file, char** name, char** email, char** experience, char** education) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, resume_file)!= NULL) {
        // Tokenize the line
        char* tokens[10];
        int num_tokens = 0;
        tokenize(line, tokens);

        // Check if the line contains the name
        if (strcmp(tokens[0], "Name:") == 0) {
            strcpy(*name, tokens[1]);
        }
        // Check if the line contains the email
        else if (strcmp(tokens[0], "Email:") == 0) {
            strcpy(*email, tokens[1]);
        }
        // Check if the line contains work experience
        else if (strcmp(tokens[0], "Experience:") == 0) {
            strcpy(*experience, line);
        }
        // Check if the line contains education
        else if (strcmp(tokens[0], "Education:") == 0) {
            strcpy(*education, line);
        }
    }
}

// Function to print the parsed resume
void print_resume(char* name, char* email, char* experience, char* education) {
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Experience: %s\n", experience);
    printf("Education: %s\n", education);
}

int main() {
    char name[MAX_WORD_SIZE] = {0};
    char email[MAX_WORD_SIZE] = {0};
    char experience[MAX_LINE_SIZE] = {0};
    char education[MAX_LINE_SIZE] = {0};

    FILE* resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        printf("Error: Could not open resume file.\n");
        return 1;
    }

    parse_resume(resume_file, &name, &email, experience, education);

    print_resume(name, email, experience, education);

    fclose(resume_file);
    return 0;
}