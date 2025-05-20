//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_TYPING_TIME 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void loadWords(Word *words) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }
    fclose(file);
}

int main() {
    Word words[MAX_WORDS];
    loadWords(words);
    srand(time(NULL));
    int currentWord = rand() % MAX_WORDS;
    char *word = words[currentWord].word;
    int length = words[currentWord].length;
    char buffer[MAX_WORD_LENGTH];
    int index = 0;
    for (int i = 0; i < length; i++) {
        buffer[index++] = '*';
    }
    buffer[index] = '\0';
    printf("Type the following word:\n%s\n", buffer);
    int startTime = time(NULL);
    while (time(NULL) - startTime < MAX_TYPING_TIME) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        if (isalpha(c)) {
            if (index < length) {
                if (tolower(c) == tolower(word[index])) {
                    index++;
                }
            }
        }
    }
    printf("\n");
    if (index == length) {
        printf("Congratulations! You typed the word correctly.\n");
    } else {
        printf("Sorry, you did not type the word correctly.\n");
    }
    return 0;
}