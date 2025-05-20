//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} String;

typedef struct {
    String *strings;
    int count;
} StringArray;

int main() {
    StringArray spam = {.strings = NULL, .count = 0};
    StringArray ham = {.strings = NULL, .count = 0};

    FILE *spamFile = fopen("spam.txt", "r");
    if (spamFile == NULL) {
        perror("Error opening spam.txt");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, spamFile)) != -1) {
        spam.strings = realloc(spam.strings, (spam.count + 1) * sizeof(String));
        spam.strings[spam.count].text = malloc(nread + 1);
        strcpy(spam.strings[spam.count].text, line);
        spam.strings[spam.count++].length = nread;
    }
    fclose(spamFile);

    FILE *hamFile = fopen("ham.txt", "r");
    if (hamFile == NULL) {
        perror("Error opening ham.txt");
        return EXIT_FAILURE;
    }

    line = NULL;
    len = 0;
    nread;
    while ((nread = getline(&line, &len, hamFile)) != -1) {
        ham.strings = realloc(ham.strings, (ham.count + 1) * sizeof(String));
        ham.strings[ham.count].text = malloc(nread + 1);
        strcpy(ham.strings[ham.count].text, line);
        ham.strings[ham.count++].length = nread;
    }
    fclose(hamFile);

    char *test = "This is a test message.";
    int testLength = strlen(test);

    int spamScore = 0;
    int hamScore = 0;
    for (int i = 0; i < testLength; i++) {
        for (int j = 0; j < spam.count; j++) {
            if (strstr(test, spam.strings[j].text) != NULL) {
                spamScore += spam.strings[j].length;
            }
        }

        for (int j = 0; j < ham.count; j++) {
            if (strstr(test, ham.strings[j].text) != NULL) {
                hamScore += ham.strings[j].length;
            }
        }
    }

    printf("Spam score: %d\n", spamScore);
    printf("Ham score: %d\n", hamScore);

    if (spamScore > hamScore) {
        printf("The message is spam.\n");
    } else {
        printf("The message is ham.\n");
    }

    for (int i = 0; i < spam.count; i++) {
        free(spam.strings[i].text);
    }
    free(spam.strings);

    for (int i = 0; i < ham.count; i++) {
        free(ham.strings[i].text);
    }
    free(ham.strings);

    return EXIT_SUCCESS;
}