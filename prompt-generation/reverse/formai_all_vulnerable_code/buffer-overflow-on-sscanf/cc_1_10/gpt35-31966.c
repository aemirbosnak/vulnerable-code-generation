//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitizeUrl(char *url) {
    char *temp = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    char *p = url;
    int i = 0;

    while (*p) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '.' || *p == '-' || *p == '/') {
            temp[i++] = *p;
        }
        p++;
    }
    temp[i] = '\0';
    strcpy(url, temp);
    free(temp);
}

int isUrlMalformed(char *url) {
    char domain[MAX_URL_LENGTH];
    sscanf(url, "http://%[^/]", domain);
    printf("DOMAIN: %s\n", domain);
    
    if (strlen(domain) < 3) {
        return 1;
    }

    if (isdigit(domain[0])) {
        return 1;
    }

    int countDots = 0;
    for (int i = 0; i < strlen(domain); i++) {
        if (domain[i] == '.') {
            countDots++;
        }
        else if (!isdigit(domain[i]) && !isupper(domain[i]) && !islower(domain[i])) {
            return 1;
        }
    }

    if (countDots < 1) {
        return 1;
    }

    char *path = strstr(url, "/");
    if (path == NULL) {
        return 1;
    }

    path++;
    int pathSegments = 0;
    while (*path) {
        if (*path == '/') {
            pathSegments++;
        }
        path++;
    }

    if (pathSegments > 4) {
        return 1;
    }

    return 0;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitizeUrl(url);

    if (isUrlMalformed(url)) {
        printf("Invalid URL!\n");
    }
    else {
        printf("Good URL!\n");
    }

    printf("Sanitized URL: %s\n", url);

    return 0;
}