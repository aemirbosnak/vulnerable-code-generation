//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>

void sanitizeUrl(char *url); // function prototype

int main() {
    char inputUrl[1000]; // variable to store the user input
    printf("Enter a URL: ");
    gets(inputUrl); // get the user input URL

    sanitizeUrl(inputUrl); // call the function to sanitize the URL

    printf("Sanitized URL: %s", inputUrl); // print the sanitized URL
    
    return 0;
}

void sanitizeUrl(char *url) {
    // remove any spaces in the URL
    char *temp = url, *writePointer = url;
    while (*temp == ' ') {
        temp++; // skip initial spaces
    }
    while (*temp != '\0') {
        if (*temp != ' ') {
            *writePointer = *temp;
            writePointer++;
        }
        temp++;
    }
    *writePointer = '\0'; // add null terminator
    
    int length = strlen(url);
    if (length > 7) { // check if it's a valid URL
        // remove any duplicate slashes
        char *p = url;
        while (*p != '\0') {
            if (*p == '/' && *(p+1) == '/') {
                char *temp = p+2;
                while (*temp == '/') {
                    temp++;
                }
                memmove(p+1, temp, strlen(temp)+1); // shift everything after the duplicate slashes
            }
            p++;
        }
        // remove any trailing slashes
        while (*(p-1) == '/') {
            length--;
            p--;
            *p = '\0';
        }
        // remove http:// or https:// if present
        if (strncmp(url, "http://", 7) == 0) {
            memmove(url, url+7, length-6);
            length -= 7;
            *(url+length) = '\0';
        }
        else if (strncmp(url, "https://", 8) == 0) {
            memmove(url, url+8, length-7);
            length -= 8;
            *(url+length) = '\0';
        }
    }
}