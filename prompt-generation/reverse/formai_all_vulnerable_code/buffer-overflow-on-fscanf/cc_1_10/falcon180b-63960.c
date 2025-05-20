//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_t {
    char word[MAX_WORD_LENGTH+1];
    int count;
};

struct word_t dictionary[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    int i;
    for(i=0; i<num_words; i++) {
        if(strcmp(dictionary[i].word, word) == 0) {
            dictionary[i].count++;
            return;
        }
    }
    if(num_words >= MAX_WORDS) {
        printf("Error: Dictionary is full.\n");
        exit(1);
    }
    strcpy(dictionary[num_words].word, word);
    dictionary[num_words].count = 1;
    num_words++;
}

void read_dictionary(FILE* fp) {
    char word[MAX_WORD_LENGTH+1];
    while(fscanf(fp, "%s", word)!= EOF) {
        add_word(word);
    }
}

void spell_check(FILE* fp) {
    char word[MAX_WORD_LENGTH+1];
    int i;
    while(fscanf(fp, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character
        for(i=0; i<num_words; i++) {
            if(strcmp(dictionary[i].word, word) == 0) {
                printf("%s (%d)\n", word, dictionary[i].count);
                break;
            }
        }
        if(i == num_words) {
            printf("%s (0)\n", word);
        }
    }
}

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("Usage: %s dictionary_file input_file\n", argv[0]);
        exit(1);
    }
    FILE* fp1 = fopen(argv[1], "r");
    if(fp1 == NULL) {
        printf("Error: Cannot open dictionary file.\n");
        exit(1);
    }
    FILE* fp2 = fopen(argv[2], "r");
    if(fp2 == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }
    read_dictionary(fp1);
    fclose(fp1);
    spell_check(fp2);
    fclose(fp2);
    return 0;
}