//FormAI DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

struct sentence {
    char words[MAX_WORDS][50];
    int num_words;
};

void make_lowercase(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
}

int contains(char* sentence, char* word) {
    char* token = strtok(sentence, " ");
    while(token) {
        if(strcmp(token, word) == 0) {
            return 1;
        }
        make_lowercase(token);
        if(strcmp(token, word) == 0) {
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    char input_text[10000];
    char keyword[50];
    struct sentence sentences[MAX_SENTENCES];
    int i, j, num_sentences = 0;

    printf("Enter text to summarize: \n");
    fgets(input_text, 10000, stdin);
    input_text[strlen(input_text)-1] = '\0'; // remove newline

    printf("Enter keyword to summarize around: \n");
    fgets(keyword, 50, stdin);
    keyword[strlen(keyword)-1] = '\0'; // remove newline
    make_lowercase(keyword);

    char* token = strtok(input_text, ".!?"); // split input_text into sentences
    while(token) {
        char* word_token = strtok(token, " "); // split sentence into words
        i = 0;
        while(word_token) {
            make_lowercase(word_token);
            strcpy(sentences[num_sentences].words[i], word_token);
            i++;
            word_token = strtok(NULL, " ");
        }
        sentences[num_sentences].num_words = i;
        num_sentences++;
        token = strtok(NULL, ".!?");
    }

    printf("Summary of text containing keyword '%s':\n", keyword);
    for(i = 0; i < num_sentences; i++) {
        if(contains(sentences[i].words[0], keyword)) {
            printf("%s", sentences[i].words[0]); // print first word
            for(j = 1; j < sentences[i].num_words; j++) {
                printf(" %s", sentences[i].words[j]); // print rest of words
            }
            printf(". "); // add period and space
        }
    }

    return 0;
}