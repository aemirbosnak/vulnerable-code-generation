//FormAI DATASET v1.0 Category: Browser Plugin ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure representing a URL
struct Url{
    char protocol[10];
    char domain[50];
    char path[100];
};

// Function to parse the url and return a Url structure
struct Url parseUrl(char* url){
    struct Url parsedUrl;
    int i = 0, j = 0;

    // Parse protocol
    while(url[i] != ':' && url[i] != '\0' && i < 10){
        // converting to upper case
        parsedUrl.protocol[i] = toupper(url[i]);
        i++;
    }
    parsedUrl.protocol[i] = '\0';
    if(url[i] == '\0')
        return parsedUrl; // url is invalid

    // skip colon and two slashes
    i += 3;

    // Parse domain
    j = 0;
    while(url[i] != '/' && url[i] != '\0' && j < 50){
        parsedUrl.domain[j] = url[i];
        i++;
        j++;
    }
    parsedUrl.domain[j] = '\0';
    if(url[i] == '\0')
        return parsedUrl; // url is invalid

    // Parse path
    j = 0;
    while(url[i] != '\0' && j < 100){
        parsedUrl.path[j] = url[i];
        i++;
        j++;
    }
    parsedUrl.path[j] = '\0';

    return parsedUrl;
}

// Function to print the Url structure
void printUrl(struct Url parsedUrl){
    printf("Protocol: %s\n", parsedUrl.protocol);
    printf("Domain: %s\n", parsedUrl.domain);
    printf("Path: %s\n", parsedUrl.path);
}

// Main program
int main(){

    char inputUrl[200];

    // Read input url from user
    printf("Enter the url: ");
    scanf("%s", inputUrl);

    // Parse the url
    struct Url parsedUrl = parseUrl(inputUrl);

    // Print the parsed url
    printUrl(parsedUrl);

    return 0;
}