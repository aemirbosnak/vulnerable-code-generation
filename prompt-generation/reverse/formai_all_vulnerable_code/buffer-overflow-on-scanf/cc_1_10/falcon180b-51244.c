//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, " \n\r\t.?!;:");
        while (token!= NULL) {
            if (strlen(token) <= MAX_WORD_LEN) {
                int i;
                for (i = 0; i < num_words; i++) {
                    if (strcmp(dictionary[i].word, token) == 0) {
                        dictionary[i].count++;
                        break;
                    }
                }
                if (i == num_words) {
                    strcpy(dictionary[num_words].word, token);
                    dictionary[num_words].count = 1;
                    num_words++;
                }
            }
            token = strtok(NULL, " \n\r\t.?!;:");
        }
    }
    fclose(fp);
}

void translate_sentence(char* sentence) {
    char word[MAX_WORD_LEN];
    char* token = strtok(sentence, " \n\r\t.?!;:");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(dictionary[i].word, token) == 0) {
                printf("%s ", dictionary[i].word);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " \n\r\t.?!;:");
    }
    printf("\n");
}

int main() {
    char filename[100];
    printf("Enter the name of the dictionary file: ");
    scanf("%s", filename);
    load_dictionary(filename);

    char sentence[1000];
    while (1) {
        printf("Enter a sentence to translate: ");
        fgets(sentence, sizeof(sentence), stdin);
        translate_sentence(sentence);
    }

    return 0;
}