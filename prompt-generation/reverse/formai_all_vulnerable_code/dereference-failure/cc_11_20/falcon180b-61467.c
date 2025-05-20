//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict;
    struct word words[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LEN];
    char *token;
    
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_WORD_LEN, dict)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL || strlen(token) == 0)
            continue;
        if (num_words >= MAX_WORDS) {
            printf("Dictionary too large.\n");
            exit(1);
        }
        words[num_words].english = strdup(token);
        token = strtok(NULL, " ");
        if (token == NULL || strlen(token) == 0) {
            printf("Invalid dictionary entry.\n");
            exit(1);
        }
        words[num_words].alien = strdup(token);
        num_words++;
    }
    
    fclose(dict);
    
    printf("Enter a sentence to translate:\n");
    char sentence[MAX_WORD_LEN];
    fgets(sentence, MAX_WORD_LEN, stdin);
    
    char *tokens[MAX_WORD_LEN];
    int num_tokens = 0;
    token = strtok(sentence, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_WORD_LEN) {
            printf("Sentence too long.\n");
            exit(1);
        }
        tokens[num_tokens++] = strdup(token);
        token = strtok(NULL, " ");
    }
    
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], words[j].english) == 0) {
                printf("%s ", words[j].alien);
                break;
            }
        }
    }
    
    printf("\n");
    
    for (int i = 0; i < num_tokens; i++)
        free(tokens[i]);
    
    for (int i = 0; i < num_words; i++) {
        free(words[i].english);
        free(words[i].alien);
    }
    
    return 0;
}