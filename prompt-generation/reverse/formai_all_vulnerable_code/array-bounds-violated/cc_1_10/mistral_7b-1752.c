//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_LENGTH 50
#define NUM_STRINGS 10

typedef struct {
    char str[STRING_LENGTH + 1];
    int len;
    int unique_chars;
} StringStat;

void generate_random_string(char* str) {
    int length = rand() % STRING_LENGTH;
    for (int i = 0; i < length; ++i) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
}

int main() {
    srand(time(NULL));
    StringStat stats[NUM_STRINGS];

    for (int i = 0; i < NUM_STRINGS; ++i) {
        char str[STRING_LENGTH + 1];
        generate_random_string(str);

        int len = strlen(str);
        int unique_chars = 1;

        // Calculate unique characters
        for (int j = 0; j < len; ++j) {
            if (str[j] != str[j - 1] && str[j] != '\0') {
                ++unique_chars;
            }
        }

        // Copy data to stats array
        strcpy(stats[i].str, str);
        stats[i].len = len;
        stats[i].unique_chars = unique_chars;
    }

    // Print statistics for each generated string
    for (int i = 0; i < NUM_STRINGS; ++i) {
        printf("String %d:\n", i + 1);
        printf("Length: %d\n", stats[i].len);
        printf("Unique Characters: %d\n", stats[i].unique_chars);
        printf("String: %s\n", stats[i].str);
        printf("\n");
    }

    return 0;
}