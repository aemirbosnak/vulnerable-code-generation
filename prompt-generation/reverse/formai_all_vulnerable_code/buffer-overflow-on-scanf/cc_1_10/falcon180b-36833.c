//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int length;
} Word;

Word generate_random_word(int min_length, int max_length) {
    Word word;
    int length = rand() % (max_length - min_length + 1) + min_length;
    word.word = malloc(length+1);
    for(int i=0; i<length; i++) {
        char c = rand() % 26 + 'a';
        word.word[i] = tolower(c);
    }
    word.word[length] = '\0';
    word.length = length;
    return word;
}

int main() {
    srand(time(NULL));
    int num_words;
    printf("Enter the number of words you want to generate: ");
    scanf("%d", &num_words);
    Word *words = malloc(num_words * sizeof(Word));
    for(int i=0; i<num_words; i++) {
        words[i] = generate_random_word(5, 10);
    }
    printf("Enter the prefix to search for: ");
    char prefix[MAX_WORD_LENGTH];
    scanf("%s", prefix);
    int count = 0;
    for(int i=0; i<num_words; i++) {
        if(strstr(words[i].word, prefix)!= NULL) {
            printf("%s\n", words[i].word);
            count++;
        }
    }
    if(count == 0) {
        printf("No words found with prefix '%s'\n", prefix);
    }
    free(words);
    return 0;
}