//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function for counting the number of words in a string
int countWords(char *str) {
    int count = 0;
    char *token;

    token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function for extracting URLs from a string
void extractUrls(char *str, void (*callback)(char *)) {
    char *token;
    char url[MAX_URL_LENGTH];
    int i = 0;

    // Extract URLs using regular expression
    while ((token = strsep(&str, " "))!= NULL) {
        if (isalpha(token[0])) {
            strcat(url, "http://");
            strcat(url, token);
            strcat(url, ".com");
            callback(url);
        }
    }
}

// Callback function for displaying extracted URLs
void displayUrl(char *url) {
    printf("%s\n", url);
}

int main() {
    char input[MAX_URL_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_URL_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Extract URLs from input string
    extractUrls(input, displayUrl);

    return 0;
}