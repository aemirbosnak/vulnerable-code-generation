//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048
#define MAX_FILTER_LENGTH 1024

typedef struct {
    char *filter;
    int filter_length;
    char *replacement;
    int replacement_length;
} filter_t;

int main(int argc, char *argv[]) {

    if (argc!= 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    filter_t filters[] = {
        {"http://", 7, "https://", 8},
        {"www.", 4, "", 0},
        {".com", 4, ".org", 5},
        {"&", 1, "&amp;", 5},
        {"<", 1, "&lt;", 4},
        {">", 1, "&gt;", 4}
    };

    int num_filters = sizeof(filters) / sizeof(filters[0]);

    for (int i = 0; i < num_filters; i++) {
        char *url_copy = strdup(url);
        char *filter = filters[i].filter;
        int filter_length = filters[i].filter_length;
        char *replacement = filters[i].replacement;
        int replacement_length = filters[i].replacement_length;

        char *pos = strstr(url_copy, filter);

        while (pos!= NULL) {
            memmove(pos + replacement_length, pos + filter_length, strlen(pos) - filter_length + 1);
            memcpy(pos, replacement, replacement_length);
            pos += replacement_length;
            pos = strstr(pos, filter);
        }

        printf("%s\n", url_copy);
        free(url_copy);
    }

    return 0;
}