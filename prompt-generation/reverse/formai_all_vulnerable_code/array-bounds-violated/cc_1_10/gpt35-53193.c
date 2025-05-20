//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for the input string and the maximum number of attributes for the resume
#define MAX_INPUT_LENGTH 1000
#define MAX_ATTRIBUTES 10

// Function to parse the resume and extract the relevant attributes
void parseResume(char *input) {
    // Tokenize the input string by splitting it using the delimiter ","
    char *token = strtok(input, ",");
    char *attributes[MAX_ATTRIBUTES];
    int attributeCount = 0;
    
    // Iterate through each token and check if it is a relevant attribute
    while (token != NULL) {
        if (strstr(token, "Education")) {
            attributes[attributeCount++] = "Education";
        } else if (strstr(token, "Experience")) {
            attributes[attributeCount++] = "Experience";
        } else if (strstr(token, "Skills")) {
            attributes[attributeCount++] = "Skills";
        } else if (strstr(token, "Certifications")) {
            attributes[attributeCount++] = "Certifications";
        }
        
        token = strtok(NULL, ",");
    }
    
    // Print the extracted attributes
    printf("Resume Attributes:\n");
    for (int i = 0; i < attributeCount; i++) {
        printf("- %s\n", attributes[i]);
    }
}

int main() {
    // Take user input for the resume text
    char input[MAX_INPUT_LENGTH];
    printf("Enter Resume Text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove the newline character from the input string
    int inputLength = strlen(input) - 1;
    if (input[inputLength] == '\n') {
        input[inputLength] = '\0';
    }
    
    // Parse the resume and extract the relevant attributes
    parseResume(input);
    
    return 0;
}