//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void strtolower(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to trim whitespace from a string
void trim(char* str) {
    int i = 0;
    while (isspace(str[i])) {
        i++;
    }
    int j = strlen(str) - 1;
    while (isspace(str[j])) {
        j--;
        str[j] = '\0';
    }
}

// Function to remove HTML tags from a string
void remove_html_tags(char* str) {
    char* start = str;
    char* end = str;
    int in_tag = 0;
    while (*end) {
        if (*end == '<') {
            in_tag = 1;
        } else if (*end == '>') {
            in_tag = 0;
        }
        if (!in_tag) {
            *end = '\0';
        }
        end++;
    }
    str = start;
}

// Function to beautify an HTML string
void beautify_html(char* html) {
    int i = 0;
    while (html[i]) {
        if (html[i] == '<') {
            int j = i + 1;
            while (html[j] && html[j]!= '>') {
                j++;
            }
            if (html[j] == '>') {
                html[j] = '\0';
                remove_html_tags(html + i + 1);
                i = j;
            }
        }
        i++;
    }
}

// Function to print an HTML string
void print_html(char* html) {
    printf("<html>\n<head>\n<title>HTML Beautifier</title>\n</head>\n<body>\n");
    printf("%s\n", html);
    printf("</body>\n</html>\n");
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* html = NULL;
    int size = 0;
    char* buffer = NULL;
    int buffer_size = 0;

    // Read the file into memory
    while ((buffer = realloc(buffer, buffer_size + 1024))!= NULL) {
        buffer_size += fread(buffer + buffer_size, 1, 1024, file);
    }

    // Close the file
    fclose(file);

    // Convert the buffer to a string
    html = malloc(buffer_size + 1);
    strcpy(html, buffer);
    free(buffer);

    // Beautify the HTML string
    beautify_html(html);

    // Print the beautified HTML string
    print_html(html);

    // Free memory
    free(html);

    return 0;
}