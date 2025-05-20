//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_SENTENCE_SIZE 100
#define MAX_FILES 10

int main() {
    FILE *fp[MAX_FILES];
    char filename[MAX_FILES][100];
    int i, j, k, n, count[MAX_FILES] = {0};
    char sentence[MAX_SENTENCE_SIZE];
    char word[MAX_WORD_SIZE];
    char delimiter[] = ",.!?;:\"'()[]{}<>";

    // Get filenames from user
    for (i = 0; i < MAX_FILES; i++) {
        printf("Enter filename %d: ", i + 1);
        scanf("%s", filename[i]);
        fp[i] = fopen(filename[i], "r");
        if (fp[i] == NULL) {
            printf("Error opening file %s\n", filename[i]);
            return 1;
        }
    }

    // Read sentences from files
    for (i = 0; i < MAX_FILES; i++) {
        while (fgets(sentence, MAX_SENTENCE_SIZE, fp[i])!= NULL) {
            // Remove leading/trailing spaces
            j = strlen(sentence) - 1;
            while (j >= 0 && isspace(sentence[j])) {
                sentence[j] = '\0';
                j--;
            }
            k = 0;
            while (k < strlen(sentence) && isspace(sentence[k])) {
                k++;
            }
            strcpy(sentence, &sentence[k]);

            // Count words in sentence
            n = 0;
            for (j = 0; j < strlen(sentence); j++) {
                if (strchr(delimiter, sentence[j]) == NULL) {
                    strncpy(word, &sentence[j], MAX_WORD_SIZE);
                    count[i] += 1;
                } else if (n > 0) {
                    n = 0;
                }
            }
        }
        fclose(fp[i]);
    }

    // Print word count for each file
    for (i = 0; i < MAX_FILES; i++) {
        printf("File %s: %d words\n", filename[i], count[i]);
    }

    return 0;
}