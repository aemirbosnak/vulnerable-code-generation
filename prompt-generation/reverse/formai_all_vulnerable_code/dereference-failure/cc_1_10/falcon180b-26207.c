//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to trim leading and trailing whitespace from a string
char *trim(char *str) {
    char *end;
    if (str == NULL) {
        return NULL;
    }
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
    while (isspace(*str)) {
        str++;
    }
    return str;
}

// Function to parse an HTML tag and return its name and attributes
void parse_tag(char *line, char **tag_name, char **attributes) {
    char *start = line;
    char *end = line;
    while (*end!= '<') {
        end++;
    }
    *end = '\0';
    *tag_name = trim(start);
    start = end + 1;
    while (*start!= '>') {
        start++;
    }
    *start = '\0';
    *attributes = trim(start + 1);
}

// Function to format an HTML tag
void format_tag(char *tag_name, char *attributes, char *formatted_tag) {
    strcpy(formatted_tag, "<");
    strcat(formatted_tag, tag_name);
    if (attributes!= NULL && strlen(attributes) > 0) {
        strcat(formatted_tag, " ");
        strcat(formatted_tag, attributes);
    }
    strcat(formatted_tag, ">");
}

// Function to format a line of HTML code
void format_line(char *line, char *formatted_line) {
    char tag_name[MAX_LINE_LENGTH];
    char attributes[MAX_LINE_LENGTH];
    parse_tag(line, &tag_name, &attributes);
    format_tag(tag_name, attributes, formatted_line);
}

// Function to format an HTML file
void format_html(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char formatted_line[MAX_LINE_LENGTH];
        format_line(line, formatted_line);
        fputs(formatted_line, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", argv[1]);
        return 1;
    }
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file %s\n", argv[2]);
        return 1;
    }
    format_html(input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    return 0;
}