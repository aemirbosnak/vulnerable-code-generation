//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

char* sanitize_url(char* url) {
    char* new_url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);
    int i, j;

    for(i = 0, j = 0; url[i] != '\0'; i++, j++) {
        if(url[i] == ' ') {
            new_url[j++] = '%';
            new_url[j++] = '2';
            new_url[j] = '0';
        }
        else if(url[i] == '&') {
            new_url[j++] = '%';
            new_url[j++] = '2';
            new_url[j] = '6';
        }
        else if(url[i] == '+') {
            new_url[j] = ' ';
        }
        else if(url[i] == '?') {
            new_url[j++] = '%';
            new_url[j++] = '3';
            new_url[j] = 'F';
        }
        else if(url[i] == '%') {
            if(url[i+1] < 48 || (url[i+1] > 57 && url[i+1] < 65) || (url[i+1] > 70 && url[i+1] < 97) || url[i+1] > 102) {
                printf("Invalid URL format!\n");
                exit(0);
            }
            if(url[i+2] < 48 || (url[i+2] > 57 && url[i+2] < 65) || (url[i+2] > 70 && url[i+2] < 97) || url[i+2] > 102) {
                printf("Invalid URL format!\n");
                exit(0);
            }
            new_url[j] = url[i];
            new_url[j+1] = url[i+1];
            new_url[j+2] = url[i+2];
            i += 2;
        }
        else {
            new_url[j] = url[i];
        }
    }

    new_url[j] = '\0';

    return new_url;
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter the URL: ");
    scanf("%[^\n]s", url);

    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}