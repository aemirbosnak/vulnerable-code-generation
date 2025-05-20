//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define a function to replace all special characters with '-' */
void replaceSpecialChars(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9'))
            s[i] = '-';
    }
}

/* Define a function to remove all duplicate '-' characters */
void removeDuplicateHyphens(char *s) {
    int i,j;
    for (i = 0; s[i] != '\0';) {
        if (s[i] == '-' && s[i+1] == '-') {
            for (j = i; s[j] != '\0'; j++)
                s[j] = s[j+1];
        }
        else i++;
    }
}

/* Define a function to sanitize a URL */
void sanitizeUrl(char *url) {
    int i;
    /* Replace all whitespace characters with '-' */
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == ' ') url[i] = '-';
    }
    /* Replace all uppercase characters with lowercase */
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] >= 'A' && url[i] <= 'Z') url[i] += 32;
    }
    /* Replace all special characters with '-' */
    replaceSpecialChars(url);
    /* Remove all duplicate '-' */
    removeDuplicateHyphens(url);
}

int main() {
    char url[100];
    printf("Enter URL: ");
    scanf("%[^\n]", url);  /* Read input string until newline */
    sanitizeUrl(url); /* Sanitize the URL */
    printf("Sanitized URL: %s\n", url); /* Print the sanitized URL */
    return 0;
}