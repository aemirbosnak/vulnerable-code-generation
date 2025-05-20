//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024

void analyze(char *str) {
    int i, j, k;
    char c, prev_c;
    int count[26] = {0};
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        c = str[i];
        prev_c = i == 0 ? '\0' : str[i - 1];
        count[c - 'a']++;

        if (prev_c == ' ' && c == ' ') {
            count['space']++;
        } else if (prev_c == ' ' && c != ' ') {
            count['space']--;
        }

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count['vowel']++;
        } else {
            count['consonant']++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (count[i] > 2) {
            printf("The letter %c appears %d times\n", i + 'a', count[i]);
        }
    }

    if (count['space'] > 2) {
        printf("The space character appears %d times\n", count['space']);
    }

    if (count['vowel'] > 2) {
        printf("The vowel character appears %d times\n", count['vowel']);
    }

    if (count['consonant'] > 2) {
        printf("The consonant character appears %d times\n", count['consonant']);
    }
}

int main() {
    char str[] = "Hello World! How are you today?";
    analyze(str);
    return 0;
}