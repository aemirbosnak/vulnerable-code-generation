//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_' || c == '-');
}

bool is_romantic(char *url) {
    int length = strlen(url);

    if (length > MAX_LENGTH) {
        return false;
    }

    int i;
    bool contains_alnum = false;

    for (i = 0; i < length; i++) {
        if (is_alnum(url[i])) {
            contains_alnum = true;
            continue;
        }

        switch (url[i]) {
            case ' ':
                if (i > 0 && i < length - 1 && is_alnum(url[i - 1]) && is_alnum(url[i + 1])) {
                    continue;
                }
                return false;
            case '/':
                if (i > 0 && url[i - 1] != '/') {
                    continue;
                }
                if (i < length - 1 && is_alnum(url[i + 1])) {
                    continue;
                }
                return false;
            case '?':
                if (i > 0 && is_alnum(url[i - 1])) {
                    return false;
                }
                if (i < length - 1 && is_alnum(url[i + 1])) {
                    continue;
                }
                if (length - i > 2 && url[i + 1] == '&' && is_alnum(url[i + 2])) {
                    continue;
                }
                return false;
            case '#':
                if (i > 0 && is_alnum(url[i - 1])) {
                    return false;
                }
                if (i < length - 1 && is_alnum(url[i + 1])) {
                    continue;
                }
                return false;
            default:
                return false;
        }
    }

    if (!contains_alnum) {
        return false;
    }

    return true;
}

int main() {
    char url[MAX_LENGTH];

    printf("Enter a romantic URL: ");
    scanf("%s", url);

    if (is_romantic(url)) {
        printf("This URL is romantic.\n");
    } else {
        printf("This URL is not romantic.\n");
    }

    return 0;
}