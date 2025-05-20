//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysteriousFunction(char* input) {
    int length = strlen(input);
    char sanitized[length + 1];
    
    int i, j;
    for(i = 0, j = 0; i < length; i++, j++) {
        if(input[i] == 'c' && input[i+1] == '=') {
            sanitized[j] = '\\';
            j++;
            sanitized[j] = '0';
            j++;
            sanitized[j] = '3';
            j++;
            sanitized[j] = 'A';
            i++;
        } else if(input[i] == 'h' && input[i+1] == 'r' && input[i+2] == 'e' && input[i+3] == 'f') {
            sanitized[j] = 'h';
            j++;
            sanitized[j] = 'r';
            j++;
            sanitized[j] = 'e';
            j++;
            sanitized[j] = 'f';
            i += 3;
        } else if(input[i] == '&' && input[i+1] == 'a' && input[i+2] == 'm' && input[i+3] == 'p' && input[i+4] == ';') {
            sanitized[j] = '&';
            j++;
            sanitized[j] = 'a';
            j++;
            sanitized[j] = 'm';
            j++;
            sanitized[j] = 'p';
            j++;
            
            i += 4;
        } else {
            sanitized[j] = input[i];
        }
    }
    sanitized[j] = '\0';
    printf("Sanitized URL: %s", sanitized);
}

int main() {
    char input[1000];

    printf("Enter a URL to sanitize:\n");
    fgets(input, 1000, stdin);
                
    mysteriousFunction(input);
    
    return 0;
}