//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64
#define MAX_EMAIL_LENGTH 256
#define MAX_LINES 1000

typedef struct {
    char *token;
    int count;
} Token;

int main() {
    FILE *fp;
    char line[MAX_LINES];
    char email[MAX_EMAIL_LENGTH];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;
    int is_spam = 0;
    int i;

    // Open the input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the input file line by line
    while (fgets(line, MAX_LINES, fp)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Extract email address from line
        if (sscanf(line, "From: %s\n", email) == 1) {
            // Extract tokens from email address
            num_tokens = 0;
            char *token = strtok(email, "@");
            while (token!= NULL) {
                if (num_tokens >= MAX_TOKENS) {
                    break;
                }
                tokens[num_tokens].token = strdup(token);
                tokens[num_tokens].count = 1;
                num_tokens++;
                token = strtok(NULL, "@");
            }

            // Check if email is spam based on token frequencies
            for (i = 0; i < num_tokens; i++) {
                if (tokens[i].count > 3) {
                    is_spam = 1;
                    break;
                }
            }
        }
    }

    // Close the input file
    fclose(fp);

    // Print the result
    if (is_spam) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}