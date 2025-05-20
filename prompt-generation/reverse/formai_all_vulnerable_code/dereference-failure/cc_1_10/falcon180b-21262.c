//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
    int mistakes;
} Text;

void init_text(Text *t) {
    t->text = malloc(100 * sizeof(char));
    t->length = 0;
    t->mistakes = 0;
}

void free_text(Text *t) {
    free(t->text);
}

void print_text(Text *t) {
    printf("%s\n", t->text);
}

void add_char(Text *t, char c) {
    t->text = realloc(t->text, t->length + 2);
    t->text[t->length++] = c;
    t->text[t->length] = '\0';
}

void backspace(Text *t) {
    if (t->length > 0) {
        t->length--;
        t->text[t->length] = '\0';
    }
}

int main() {
    srand(time(NULL));
    int max_length = rand() % 100 + 1;
    Text text;
    init_text(&text);

    char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};

    int word_index = rand() % 20;
    char *word = words[word_index];
    int word_length = strlen(word);

    for (int i = 0; i < word_length; i++) {
        add_char(&text, word[i]);
    }

    int mistakes = 0;
    int correct_chars = 0;

    while (text.length < max_length) {
        char c = rand() % 26 + 'a';
        if (c == word[text.length % word_length]) {
            add_char(&text, c);
            correct_chars++;
        } else {
            add_char(&text, c);
            mistakes++;
        }

        if ((text.length % 10) == 0) {
            printf("Current length: %d\n", text.length);
        }
    }

    printf("You made %d mistakes.\n", mistakes);
    printf("You typed %d correct characters.\n", correct_chars);

    free_text(&text);

    return 0;
}