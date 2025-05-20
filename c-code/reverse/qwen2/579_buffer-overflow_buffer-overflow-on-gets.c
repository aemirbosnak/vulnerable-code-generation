#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 1024

int is_spam(const char *msg) {
    const char *keywords[] = {"advertising", "winning", "watches", "free"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_keywords; ++i) {
        if (strstr(msg, keywords[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char msg[MAX_MSG_LEN];

    printf("Enter your message: ");
    fgets(msg, sizeof(msg), stdin);

    if (is_spam(msg)) {
        printf("This message is flagged as spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}
