//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char word[20];
    int freq;
} dict;

typedef struct {
    char word[20];
    int line_num;
} error;

int compare(const void *w1, const void *w2) {
    dict *word1 = (dict *)w1;
    dict *word2 = (dict *)w2;
    return strcmp(word1->word, word2->word);
}

void check_spelling(char *filename, dict dictionary[], int dict_size, error errors[], int *num_errors) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char line[100];
    int line_num = 0;
    while(fgets(line, sizeof(line), file)) {
        line_num++;
        char *word = strtok(line, " \n\r\t.,;?!\"");
        while(word != NULL) {
            int is_valid = 0;
            for(int i = 0; i < strlen(word); i++) {
                if(isalpha(word[i])) {
                    is_valid = 1;
                    word[i] = tolower(word[i]);
                }
                else {
                    is_valid = 0;
                    break;
                }
            }
            if(is_valid) {
                int found = 0;
                for(int i = 0; i < dict_size; i++) {
                    if(strcmp(word, dictionary[i].word) == 0) {
                        found = 1;
                        dictionary[i].freq++;
                        break;
                    }
                }
                if(!found) {
                    strcpy(errors[*num_errors].word, word);
                    errors[*num_errors].line_num = line_num;
                    (*num_errors)++;
                }
            }
            word = strtok(NULL, " \n\r\t.,;?!\"");
        }
    }
    fclose(file);
}

int main() {
    dict dictionary[100];
    error errors[100];
    int dict_size = 0, num_errors = 0;

    FILE *dict_file = fopen("dictionary.txt", "r");
    if(dict_file == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }
    char dict_word[20];
    while(fscanf(dict_file, "%s", dict_word) != EOF) {
        strcpy(dictionary[dict_size].word, dict_word);
        dictionary[dict_size].freq = 0;
        dict_size++;
    }
    fclose(dict_file);

    check_spelling("sample.txt", dictionary, dict_size, errors, &num_errors);

    qsort(dictionary, dict_size, sizeof(dict), compare);

    printf("Dictionary words sorted:\n");
    for(int i = 0; i < dict_size; i++) {
        printf("%s : %d\n", dictionary[i].word, dictionary[i].freq);
    }
    printf("\n");

    printf("Errors found:\n");
    for(int i = 0; i < num_errors; i++) {
        printf("%s in line %d\n", errors[i].word, errors[i].line_num);
    }
    return 0;
}