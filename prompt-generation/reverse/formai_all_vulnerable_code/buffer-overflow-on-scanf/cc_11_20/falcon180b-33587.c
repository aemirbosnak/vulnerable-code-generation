//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize the URL
void sanitize_url(char *url) {
    int i, j;
    char *p;
    char *q;

    // Remove leading spaces
    while (isspace(*url)) {
        url++;
    }

    // Remove trailing spaces
    j = strlen(url) - 1;
    while (isspace(url[j])) {
        url[j] = '\0';
        j--;
    }

    // Remove all special characters except -._~:/?#[]@!$&'()*+,;=%
    p = url;
    q = malloc(strlen(url) + 1);
    j = 0;
    while (*p) {
        if (isalnum(*p) || *p == '-' || *p == '_' || *p == '.' || *p == '~' || *p == ':' || *p == '/' || *p == '?' || *p == '#' || *p == '[' || *p == ']' || *p == '@' || *p == '!' || *p == '$' || *p == '&' || *p == '\'' || *p == '(' || *p == ')' || *p == '*' || *p == '+' || *p == ',') {
            q[j] = tolower(*p);
            j++;
        }
        p++;
    }
    q[j] = '\0';
    strcpy(url, q);
    free(q);
}

int main() {
    char url[100];

    printf("Enter the URL: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}