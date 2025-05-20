//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

// Function to remove trailing newline from a string
char* remove_newline(char* str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
}

// Function to trim whitespace from a string
char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
    return str;
}

// Function to split a string into an array of strings
char** split(char* str, const char delimiter) {
    int count = 0;
    char* token = strtok(str, delimiter);
    while (token!= NULL) {
        count++;
        token = strtok(NULL, delimiter);
    }
    char** result = (char**)malloc(sizeof(char*) * count);
    count = 0;
    token = strtok(str, delimiter);
    while (token!= NULL) {
        result[count] = trim(token);
        count++;
        token = strtok(NULL, delimiter);
    }
    return result;
}

// Function to parse a line of text as a key-value pair
void parse_line(char* line, const char delimiter, const char key_delimiter, void (*callback)(char*, char*)) {
    char* key = NULL;
    char* value = NULL;
    char** tokens = split(line, delimiter);
    int count = 0;
    while (tokens[count]!= NULL) {
        if (count == 0) {
            key = trim(tokens[count]);
        } else if (count == 1) {
            value = trim(tokens[count]);
        }
        count++;
    }
    if (key!= NULL && value!= NULL) {
        callback(key, value);
    }
    for (int i = 0; i < count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

// Function to parse a resume
void parse_resume(FILE* file, void (*callback)(char*, char*)) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* trimmed_line = remove_newline(line);
        parse_line(trimmed_line, ',', ':', callback);
        free(trimmed_line);
    }
}

// Callback function to process name
void process_name(char* key, char* value) {
    printf("Name: %s\n", value);
}

// Callback function to process education
void process_education(char* key, char* value) {
    printf("Education: %s\n", value);
}

// Callback function to process experience
void process_experience(char* key, char* value) {
    printf("Experience: %s\n", value);
}

// Callback function to process skills
void process_skills(char* key, char* value) {
    printf("Skills: %s\n", value);
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    parse_resume(file, process_name);
    parse_resume(file, process_education);
    parse_resume(file, process_experience);
    parse_resume(file, process_skills);
    fclose(file);
    return 0;
}