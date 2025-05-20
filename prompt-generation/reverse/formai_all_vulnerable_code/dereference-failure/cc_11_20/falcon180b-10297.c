//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char* argv[]) {
    FILE* input_file;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    struct word_count* word_list = malloc(MAX_WORDS * sizeof(struct word_count));

    if(argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if(input_file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), input_file)!= NULL) {
        int i = 0;
        while(line[i]!= '\0') {
            if(isalpha(line[i])) {
                strncpy(word, &line[i], MAX_WORD_LENGTH);
                word[MAX_WORD_LENGTH-1] = '\0';
                for(int j = 0; j < strlen(word); j++) {
                    word[j] = tolower(word[j]);
                }
                if(strlen(word) > 0) {
                    int found = 0;
                    for(int k = 0; k < word_count; k++) {
                        if(strcmp(word_list[k].word, word) == 0) {
                            word_list[k].count++;
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        strcpy(word_list[word_count].word, word);
                        word_list[word_count].count = 1;
                        word_count++;
                    }
                }
            }
            i++;
        }
    }

    fclose(input_file);

    printf("Word\tCount\n");
    for(int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_list[i].word, word_list[i].count);
    }

    free(word_list);
    return 0;
}