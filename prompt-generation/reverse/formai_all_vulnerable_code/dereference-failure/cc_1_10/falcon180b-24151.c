//Falcon-180B DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void process_line(char *line);
bool is_valid_ip(char *ip);
int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *filename = argv[1];

    // Check if filename is provided
    if (filename == NULL) {
        fprintf(stderr, "Error: Filename not provided.\n");
        return 1;
    }

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        return 2;
    }

    // Read each line and process
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        process_line(line);
    }

    // Close the file
    if (fclose(file)!= 0) {
        fprintf(stderr, "Error: Could not close file '%s'.\n", filename);
        return 3;
    }

    return 0;
}

// Process each line and print IP addresses
void process_line(char *line) {
    char *ip;
    char *token;
    char *saveptr = NULL;

    // Remove leading/trailing whitespace
    line[strcspn(line, "\n")] = '\0';

    // Tokenize the line
    token = strtok_r(line, " \t", &saveptr);
    while (token!= NULL) {
        // Check if token is a valid IP address
        if (is_valid_ip(token)) {
            // Print the IP address
            printf("IP address: %s\n", token);
        }
        token = strtok_r(NULL, " \t", &saveptr);
    }
}

// Check if a string is a valid IP address
bool is_valid_ip(char *ip) {
    char *dot;
    int i;

    // Check for correct length
    if (strlen(ip)!= 15) {
        return false;
    }

    // Check for correct format
    dot = strchr(ip, '.');
    if (dot == NULL || dot[1] == '.' || dot[2] == '.') {
        return false;
    }

    // Check each octet
    for (i = 0; i < 4; i++) {
        dot = strchr(ip, '.') + 1;
        if (sscanf(dot, "%d", &i)!= 1 || i < 0 || i > 255) {
            return false;
        }
    }

    // Valid IP address
    return true;
}