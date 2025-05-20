//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_USERS 10

void beautify_html(const char *input, char *output) {
    int indent_level = 0;
    char line[MAX_LINE_LENGTH];
    const char *current = input;
    
    while (*current) {
        // Skip whitespace
        while (*current && (*current == ' ' || *current == '\n' || *current == '\r')) {
            current++;
        }
        
        // Check for the start of a tag
        if (*current == '<') {
            if (*(current + 1) == '/') {
                // Closing tag
                indent_level--;
                snprintf(line, sizeof(line), "\n%*s%s", indent_level * 2, "", current);
                current += strcspn(current, ">") + 1;
            } else {
                // Opening tag
                snprintf(line, sizeof(line), "\n%*s%s", indent_level * 2, "", current);
                current += strcspn(current, ">") + 1;
                indent_level++;
            }
        } else {
            // Text content
            const char *text_start = current;
            current += strcspn(current, "<");
            snprintf(line, sizeof(line), "\n%*s%.*s", indent_level * 2, "", (int)(current - text_start), text_start);
        }
        
        strcat(output, line);
    }
}

int main() {
    char input[MAX_LINE_LENGTH * 10];
    char output[MAX_LINE_LENGTH * 10] = "";
    char username[20];
    int num_users = 0;
    
    printf("Welcome to the Multiplay HTML Beautifier!\n");
    
    while (num_users < MAX_USERS) {
        printf("Enter your username (or type 'exit' to quit): ");
        scanf("%s", username);
        
        if (strcmp(username, "exit") == 0) {
            break;
        }
        
        printf("%s, please enter your HTML code (end with an empty line):\n", username);
        
        // Read HTML code
        strcpy(input, "");
        while (1) {
            char line[MAX_LINE_LENGTH];
            fgets(line, sizeof(line), stdin);
            if (strcmp(line, "\n") == 0) break; // Stop on empty line
            strcat(input, line);
        }
        
        // Beautify the HTML
        beautify_html(input, output);
        
        // Output the beautified HTML
        printf("\nBeautified HTML for user '%s':\n%s\n", username, output);
        
        // Clear output for the next user
        memset(output, 0, sizeof(output));
        
        num_users++;
    }
    
    printf("Thank you for using the Multiplay HTML Beautifier!\n");
    return 0;
}