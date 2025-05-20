//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Function to remove leading and trailing whitespaces from a string
void trim(char *str) {
    int start, end;
    start = 0;
    end = strlen(str) - 1;
    while (isspace(str[start])) {
        start++;
    }
    while (isspace(str[end])) {
        end--;
        str[end] = '\0';
    }
}

// Function to read a line of input from the user
void read_line(char *buffer) {
    printf("Enter a line of text: ");
    fgets(buffer, MAX_LINE_SIZE, stdin);
    trim(buffer);
}

// Function to translate a line of text into Cat language
void translate(char *input, char *output) {
    strcpy(output, "");
    char *word;
    char *token;
    token = strtok(input, " ");
    while (token!= NULL) {
        word = strtok(token, " ");
        while (*word!= '\0') {
            if (isalpha(*word)) {
                *word = toupper(*word);
            }
            word++;
        }
        strcat(output, token);
        strcat(output, " ");
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_LINE_SIZE];
    char output[MAX_LINE_SIZE];
    printf("Welcome to the Cat Language Translator!\n");
    while (1) {
        read_line(input);
        translate(input, output);
        printf("Original text: %s\n", input);
        printf("Translated text: %s\n\n", output);
    }
    return 0;
}