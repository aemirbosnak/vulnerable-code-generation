//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void sanitize_url(char* url) {
    int i, j;
    char* temp = (char*) malloc(MAX_LENGTH * sizeof(char));
    
    // remove any leading or trailing whitespace
    sscanf(url, "%s", temp);
    memset(url, 0, strlen(url));
    strcpy(url, temp);
    
    // remove any unnecessary characters from the beginning of the URL
    strcpy(temp, url);
    for (i = 0, j = 0; i < strlen(temp) && j < MAX_LENGTH; i++) {
        if (isalnum(temp[i]) || temp[i] == '/' || temp[i] == ':') {
            url[j++] = temp[i];
        }
    }
    url[j] = '\0';
    
    // add "http://" prefix if it's missing
    if (strncmp(url, "http://", 7) != 0) {
        strcpy(temp, url);
        memset(url, 0, strlen(url));
        strcpy(url, "http://");
        strcat(url, temp);
    }
    
    free(temp);
}

int main() {
    char url[MAX_LENGTH];
    
    printf("Please enter the URL to be sanitized: ");
    fgets(url, MAX_LENGTH, stdin);
    if (strlen(url) > 0 && url[strlen(url) - 1] == '\n') {
        url[strlen(url) - 1] = '\0';
    }
    
    sanitize_url(url);
    printf("The sanitized URL is: %s\n", url);
    
    return 0;
}