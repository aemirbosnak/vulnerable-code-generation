//FormAI DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int words[MAX_WORDS] = {0};
    int totalWords = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, 1000, file)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        int i = 0, j = 0;
        while (line[i]) {
            if (isalnum(line[i])) {
                word[j] = tolower(line[i]);
                j++;
            } else if (j != 0) {
                word[j] = '\0';
                int match = 0;
                for (int k = 0; k < totalWords; k++) {
                    if (strcmp(word, argv[k + 2]) == 0) {
                        match = 1;
                        words[k]++;
                        break;
                    }
                }
                if (!match && totalWords < MAX_WORDS) {
                    strcpy(argv[totalWords + 2], word);
                    words[totalWords]++;
                    totalWords++;
                }
                j = 0;
            }
            i++;
        }
        if (j != 0) {
            word[j] = '\0';
            int match = 0;
            for (int k = 0; k < totalWords; k++) {
                if (strcmp(word, argv[k + 2]) == 0) {
                    match = 1;
                    words[k]++;
                    break;
                }
            }
            if (!match && totalWords < MAX_WORDS) {
                strcpy(argv[totalWords + 2], word);
                words[totalWords]++;
                totalWords++;
            }
        }
    }

    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", argv[i + 2], words[i]);
    }

    fclose(file);
    return 0;
}