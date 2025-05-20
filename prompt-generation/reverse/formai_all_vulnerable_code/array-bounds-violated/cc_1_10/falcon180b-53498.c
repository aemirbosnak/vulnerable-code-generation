//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char input[MAX_LEN];
    int i = 0;
    int len = 0;

    printf("Enter your input: ");
    fgets(input, MAX_LEN, stdin);

    // Remove leading and trailing white spaces
    while (isspace(input[i])) {
        i++;
    }
    len = strlen(input) - 1;
    while (isspace(input[len])) {
        len--;
    }
    input[len] = '\0';

    // Check for SQL injection attacks
    char *token = strtok(input, "'");
    while (token!= NULL) {
        if (strstr(token, "SELECT")!= NULL || strstr(token, "UPDATE")!= NULL || strstr(token, "DELETE")!= NULL) {
            printf("SQL injection attack detected!\n");
            exit(1);
        }
        token = strtok(NULL, "'");
    }

    // Check for XSS attacks
    char *script = strstr(input, "<script>");
    if (script!= NULL) {
        printf("XSS attack detected!\n");
        exit(1);
    }

    // Check for buffer overflow attacks
    if (len > MAX_LEN - 1) {
        printf("Buffer overflow attack detected!\n");
        exit(1);
    }

    printf("Your input is safe: %s\n", input);

    return 0;
}