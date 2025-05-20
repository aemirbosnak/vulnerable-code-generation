//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if character is valid
int isValid(char c) {
    if(isalpha(c) || isdigit(c) || c == '.' || c == '-')
        return 1;
    return 0;
}

// function to sanitize URL
void sanitizeURL(char url[]) {
    int i, j;
    char temp[100];
    
    // remove leading spaces
    i = 0;
    while(url[i] == ' ')
        i++;
    strcpy(url, &url[i]);
    
    // remove trailing spaces
    i = strlen(url)-1;
    while(url[i] == ' ')
        i--;
    url[i+1] = '\0';
    
    // remove duplicate slashes
    i = j = 0;
    while(url[i] != '\0') {
        if(url[i] == '/' && url[i+1] == '/')
            i++;
        temp[j++] = url[i++];
    }
    temp[j] = '\0';
    strcpy(url, temp);
    
    // convert characters to lower case
    i = 0;
    while(url[i] != '\0') {
        url[i] = tolower(url[i]);
        i++;
    }
    
    // remove invalid characters
    i = j = 0;
    while(url[i] != '\0') {
        if(isValid(url[i]))
            temp[j++] = url[i];
        i++;
    }
    temp[j] = '\0';
    strcpy(url, temp);
}

int main() {
    char url[100];
    
    printf("Enter URL: \n");
    scanf("%[^\n]s", url);
    
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}