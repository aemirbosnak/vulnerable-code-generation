//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

// Function to remove leading/trailing whitespace from a string
void trim(char* str) {
    int i;
    int j;
    int len;
    
    len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (!isspace(str[i])) {
            strcat(str, str + i);
            len = strlen(str);
            break;
        }
        if (!isspace(str[j])) {
            str[j] = '\0';
            break;
        }
    }
}

// Function to extract metadata from a file
void extract_metadata(FILE* file, char* filename) {
    char line[MAX_LINE];
    char* key;
    char* value;
    int in_comment;
    
    in_comment = 0;
    while (fgets(line, MAX_LINE, file)!= NULL) {
        // Remove leading/trailing whitespace from line
        trim(line);
        
        // Check if line is a comment
        if (line[0] == '#') {
            in_comment = 1;
        } else if (in_comment && line[0] == '\n') {
            in_comment = 0;
        } else if (in_comment) {
            continue;
        }
        
        // Extract key-value pairs from line
        key = strtok(line, "=");
        if (key == NULL) {
            continue;
        }
        value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }
        
        // Print key-value pair
        printf("%s: %s\n", key, value);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
    
    char filename[MAX_LINE];
    strcpy(filename, argv[1]);
    extract_metadata(file, filename);
    
    fclose(file);
    return 0;
}