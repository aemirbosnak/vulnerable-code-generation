//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
char* beautify_html(char* input);
char* beautify_tag(char* tag);
char* beautify_attribute(char* attribute);

int main() {
    char input[100000];
    printf("Enter your HTML code: ");
    fgets(input, sizeof(input), stdin);
    
    char* output = beautify_html(input);
    
    printf("Beautified HTML:\n%s", output);
    
    return 0;
}

char* beautify_html(char* input) {
    char* output = malloc(strlen(input) + 1);
    strcpy(output, input);
    
    // Replace < with &lt;
    char* temp = output;
    while (*temp!= '\0') {
        if (*temp == '<') {
            strcat(output, "&lt;");
        } else {
            strcat(output, temp);
        }
        temp++;
    }
    
    return output;
}

char* beautify_tag(char* tag) {
    char* output = malloc(strlen(tag) + 1);
    strcpy(output, tag);
    
    // Replace < with &lt;
    char* temp = output;
    while (*temp!= '\0') {
        if (*temp == '<') {
            strcat(output, "&lt;");
        } else {
            strcat(output, temp);
        }
        temp++;
    }
    
    // Add closing tag
    strcat(output, "</");
    strcat(output, tag);
    strcat(output, ">");
    
    return output;
}

char* beautify_attribute(char* attribute) {
    char* output = malloc(strlen(attribute) + 1);
    strcpy(output, attribute);
    
    // Replace " with &quot;
    char* temp = output;
    while (*temp!= '\0') {
        if (*temp == '"') {
            strcat(output, "&quot;");
        } else {
            strcat(output, temp);
        }
        temp++;
    }
    
    return output;
}