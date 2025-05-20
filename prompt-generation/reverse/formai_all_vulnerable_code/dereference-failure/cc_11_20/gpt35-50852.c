//FormAI DATASET v1.0 Category: Browser Plugin ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void paranoid(char *url) {
    int i, j;
    int flag = 0;
    char *host, *path, *params;
    char *schemes[6] = {"http:", "https:", "ftp:", "file:", "about:", "data:"};

    // Check if the URL starts with a valid scheme
    for(i = 0; i < 6; i++) {
        if(strncmp(url, schemes[i], strlen(schemes[i])) == 0) {
            flag = 1;
            break;
        }
    }

    if(!flag) {
        printf("URL is not using a valid scheme.");
        return;
    }

    // Separate the host, path, and parameters from the URL
    host = strstr(url, "//");
    if(host != NULL) {
        host += 2;
    } else {
        host = url;
    }

    path = strchr(host, '/');
    if(path != NULL) {
        params = strchr(path, '?');
        if(params != NULL) {
            *params = '\0';
            params++;
        }
        *path = '\0';
        path++;
    } else {
        host[strlen(host)] = '/';
        host[strlen(host)+1] = '\0';
        path = "";
        params = "";
    }

    // Check the characters in the host, path, and parameters strings
    for(i = 0; i < strlen(host); i++) {
        if(!(isalnum(host[i]) || host[i] == '.' || host[i] == '-' || host[i] == '_')) {
            printf("Invalid character %c found in host.", host[i]);
            return;
        }
    }

    for(i = 0; i < strlen(path); i++) {
        if(!(isalnum(path[i]) || path[i] == '.' || path[i] == '-' || path[i] == '_' || path[i] == '/' || path[i] == '?' || path[i] == '=' || path[i] == '&')) {
            printf("Invalid character %c found in path.", path[i]);
            return;
        }
    }

    for(i = 0; i < strlen(params); i++) {
        if(!(isalnum(params[i]) || params[i] == '.' || params[i] == '-' || params[i] == '_' || params[i] == '=' || params[i] == '&')) {
            printf("Invalid character %c found in parameters.", params[i]);
            return;
        }
    }

    // Check if the host is a valid domain name or IP address
    int dotCount = 0;
    int numCount = 0;

    for(i = 0; i < strlen(host); i++) {
        if(host[i] == '.') {
            dotCount++;
            if(numCount > 0 && numCount <= 3) {
                numCount = 0;
            }
        } else if(isdigit(host[i])) {
            numCount++;
            if(numCount > 3) {
                printf("Invalid IP address format.");
                return;
            }
        } else {
            printf("Invalid character %c found in host.", host[i]);
            return;
        }
    }

    if(dotCount != 3 && numCount == 0) {
        printf("Invalid domain name format.");
        return;
    }

    printf("URL is valid and has been sanitized.");
}

int main() {
    char url[MAX_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_LENGTH, stdin);

    url[strcspn(url, "\n")] = '\0';

    paranoid(url);

    return 0;
}