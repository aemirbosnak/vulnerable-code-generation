//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    int length;
} URL;

URL *create_url(char *url) {
    URL *result = malloc(sizeof(URL));
    result->url = strdup(url);
    result->length = strlen(url);
    return result;
}

void sanitize_url(URL *url) {
    int i;
    for (i = 0; i < url->length; i++) {
        if (!isalnum(url->url[i])) {
            if (url->url[i] == '%') {
                int j = 0;
                while (url->url[i + j]!= '\0' && isxdigit(url->url[i + j])) {
                    j++;
                }
                if (j == 2) {
                    i += 2;
                } else {
                    url->url[i] = '\0';
                    break;
                }
            } else {
                url->url[i] = '\0';
                break;
            }
        }
    }
}

void print_url(URL *url) {
    printf("%s\n", url->url);
}

int main() {
    char input[MAX_URL_LENGTH];
    URL *url;

    while (fgets(input, MAX_URL_LENGTH, stdin)!= NULL) {
        if (strlen(input) > 0) {
            url = create_url(input);
            sanitize_url(url);
            print_url(url);
            free(url->url);
            free(url);
        }
    }

    return 0;
}