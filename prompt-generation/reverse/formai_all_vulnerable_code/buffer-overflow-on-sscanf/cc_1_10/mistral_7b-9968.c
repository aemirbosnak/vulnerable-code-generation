//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STYLES 10
#define MAX_STYLE_LEN 50
#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char style_name[MAX_STYLE_LEN];
    int (*word_counter)(const char *text, int *num_words, int max_words);
} Style;

int plain_counter(const char *text, int *num_words, int max_words) {
    int words = 0;
    for (; *text && max_words > words; text++) {
        if (isspace(*text)) {
            words++;
            continue;
        }
        if (text[0] == '\'' && text[1] == ' ') {
            text++;
            continue;
        }
        if (text[0] == '\'' && text[1] == '\'') {
            text++;
            continue;
        }
    }

    if (num_words)
        *num_words = words;
    return words;
}

int capital_counter(const char *text, int *num_words, int max_words) {
    int words = 0;
    for (; *text && max_words > words; text++) {
        if (isalpha(*text)) {
            if (words == 0)
                printf("%s:", text);
            putchar(toupper(*text));
        } else if (isspace(*text) || *text == '\0') {
            words++;
            putchar('\n');
            if (num_words)
                *num_words = words;
        }
    }

    return words;
}

int underline_counter(const char *text, int *num_words, int max_words) {
    int words = 0;
    for (; *text && max_words > words; text++) {
        if (isspace(*text)) {
            words++;
            putchar('\n');
            if (num_words)
                *num_words = words;
            for (int i = 0; text[i] != '\0'; i++)
                putchar('_');
            putchar(' ');
            continue;
        }
    }

    return words;
}

Style styles[MAX_STYLES] = {
    {"Plain", plain_counter},
    {"Capital", capital_counter},
    {"Underline", underline_counter}
};

int main() {
    char text[MAX_WORD_LEN * MAX_WORDS];
    int num_words = 0;
    int max_words = MAX_WORDS;

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);

    if (sscanf(text, "%s %n", text, &text[strlen(text)]) == 1)
        text[strlen(text) - 1] = '\0';

    printf("Total words: %d\n", styles[0].word_counter(text, &num_words, max_words));

    printf("\nChoose a style:\n");
    for (int i = 0; i < MAX_STYLES; i++)
        printf("%d. %s\n", i + 1, styles[i].style_name);

    int choice;
    scanf("%d", &choice);

    printf("\nText with %s style:\n", styles[choice - 1].style_name);
    styles[choice - 1].word_counter(text, NULL, 0);

    return 0;
}