//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEADER_SIZE 256
#define NUM_RULES 5

// Rule structure
typedef struct {
    const char *key;
    size_t key_len;
    const char *value;
    size_t value_len;
} Rule;

Rule rules[NUM_RULES] = {
    {"From", 3, "spammer@example.com", 13},
    {"Subject", 6, "Win free money", 11},
    {"Subject", 5, "Viagra", 5},
    {"To", 2, "stranger@example.com", 12},
    {"Content-Type", 10, "text/html", 7}
};

void check_spam(const char *header, size_t header_len) {
    size_t i;
    for (i = 0; i < NUM_RULES; i++) {
        const Rule *rule = &rules[i];
        size_t key_len = rule->key_len;
        size_t value_len = rule->value_len;

        if (header_len < key_len + value_len) {
            continue;
        }

        if (strncmp(header, rule->key, key_len) == 0 &&
            strncmp(header + key_len, rule->value, value_len) == 0) {
            printf("Spam detected!\n");
            return;
        }
    }
}

int main() {
    char header[MAX_HEADER_SIZE];
    size_t header_len;

    while (fgets(header, MAX_HEADER_SIZE, stdin) != NULL) {
        header_len = strlen(header);

        // Remove newline character
        if (header[header_len - 1] == '\n') {
            header[header_len - 1] = '\0';
            header_len--;
        }

        check_spam(header, header_len);
    }

    return 0;
}