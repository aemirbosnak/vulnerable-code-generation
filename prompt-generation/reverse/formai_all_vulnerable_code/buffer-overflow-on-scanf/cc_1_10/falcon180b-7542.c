//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else if (c == '.' || c == '_' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

void sanitize_url(char* url) {
    int i, j;
    char* valid_url = malloc(MAX_URL_LENGTH);
    valid_url[0] = '\0';

    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            strncat(valid_url, &url[i], 1);
        } else {
            strncat(valid_url, "%", 1);
            j = 0;
            while (isxdigit(url[i]) && i < strlen(url)) {
                i++;
                j++;
            }
            sprintf(&valid_url[strlen(valid_url)], "%%%02X", (int)url[i]);
            i += j - 1;
        }
    }

    strcpy(url, valid_url);
    free(valid_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}