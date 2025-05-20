//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

void sanitize(char *url) {
    int i = 0, j = 0;
    char temp[MAX_LENGTH];

    while (url[i] != '\0') {
        if ((i > 0 && (url[i] == ':' || url[i] == '/')) || url[i] >= 'A' && url[i] <= 'Z' || url[i] >= 'a' && url[i] <= 'z' || url[i] >= '0' && url[i] <= '9') {
            temp[j++] = url[i];
        }

        if ((url[i] == '?') || (url[i] == '#')) {
            temp[j] = '\0';
            printf("Sanitized URL: %s\n", temp);
            i = strlen(url) + 1;
            break;
        }

        if (url[i] == '&') {
            i++;
            while (url[i] != '=') {
                i++;
            }
            i++;
            continue;
        }

        if (url[i] == '+' && (i > 0 && (url[i-1] != '='))) {
            temp[j++] = ' ';
            i++;
            continue;
        }

        if (url[i] == '%' && i < strlen(url) - 2) {
            if (isxdigit(url[i+1]) && isxdigit(url[i+2])) {
                char hex = (url[i+1] >= 'A' ? url[i+1] - 'A' + 10 : url[i+1] - '0');
                hex *= 16;
                hex += (url[i+2] >= 'A' ? url[i+2] - 'A' + 10 : url[i+2] - '0');
                temp[j++] = hex;
                i += 2;
                continue;
            }
        }

        i++;
    }

    if (i == strlen(url)) {
        temp[j++] = url[i];
        temp[j] = '\0';
    }
}

int main() {
    char url[MAX_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize(url);

    return 0;
}