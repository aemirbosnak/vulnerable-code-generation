#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    int count = 0;
    const char *keywords[] = {"advertising", "winning", "watches", "free"};
    int keyword_count = sizeof(keywords) / sizeof(keywords[0]);

    while (fgets(buffer, sizeof(buffer), stdin)) {
        for (int i = 0; i < keyword_count; i++) {
            if (strstr(buffer, keywords[i])) {
                count++;
            }
        }
    }

    if (count > 0) {
        printf("Warning: Spam detected!\n");
    }

    return 0;
}
