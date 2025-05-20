//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

void count_words(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    int word_count[26];

    while (fgets(line, sizeof(line), fp)) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            line[i] = tolower(line[i]);
        }

        int j;
        for (j = 0; j < 26; j++) {
            if (isalpha(line[j])) {
                word[j] = line[j];
            } else {
                break;
            }
        }
        word[j] = '\0';

        if (strlen(word) > 0) {
            int count = 0;
            for (int i = 0; i < len; i++) {
                if (line[i] == word[count]) {
                    count++;
                } else {
                    break;
                }
            }
            word_count[word[0] - 'a'] += count;
        }
    }

    fclose(fp);

    for (int i = 0; i < 26; i++) {
        int count = word_count[i];
        if (count > 0) {
            printf("%c: %d\n", (char)(i + 'a'), count);
        }
    }
}

int main() {
    count_words("log.txt");
    return 0;
}