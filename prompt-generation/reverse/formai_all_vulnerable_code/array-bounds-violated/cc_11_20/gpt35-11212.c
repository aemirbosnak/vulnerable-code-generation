//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
    char url[MAX_LEN];
    printf("Enter URL: ");
    fgets(url, MAX_LEN, stdin);

    int len = strlen(url);
    if (url[len-1] == '\n') url[len-1] = '\0';

    char* protocol = strtok(url, "://");
    char* domain = strtok(NULL, "/");
    char* path = strtok(NULL, "");

    if (protocol == NULL || domain == NULL) {
        printf("Invalid URL!\n");
        return 0;
    }

    int valid_domain = 0;
    char* ptr = domain;
    while (*ptr != '\0') {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '9') ||
            *ptr == '.' || *ptr == '-') {
            valid_domain = 1;
        } else {
            valid_domain = 0;
            break;
        }
        ptr++;
    }

    if (valid_domain == 0) {
        printf("Invalid domain!\n");
        return 0;
    }

    if (path != NULL) {
        char new_url[MAX_LEN];
        strcpy(new_url, protocol);
        strcat(new_url, "://");
        strcat(new_url, domain);
        strcat(new_url, "/");
        char* trimmed = strtok(path, "?");
        strcat(new_url, trimmed);
        printf("Sanitized URL: %s\n", new_url);
    } else {
        printf("Sanitized URL: %s\n", url);
    }

    return 0;
}