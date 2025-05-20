//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

#define IN 1
#define OUT 0

typedef struct WordFreq {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

void remove_punctuations(char *s);
int get_word_count(FILE *fp);
void calculate_word_frequency(FILE *fp, WordFreq *arr, int count);
void sort_word_frequency(WordFreq *arr, int count);

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    int count;
    WordFreq arr[MAX_WORD_LEN];

    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    count = get_word_count(fp);
    rewind(fp);

    calculate_word_frequency(fp, arr, count);
    sort_word_frequency(arr, count);

    printf("\n\nWord Frequency: \n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", arr[i].word, arr[i].count);
    }

    fclose(fp);

    return 0;
}

// Remove punctuations from the given string
void remove_punctuations(char *s) {
    char *p = s;
    while (*p) {
        if (ispunct(*p)) {
            *p = ' ';
        }
        p++;
    }
}

// Get the total number of words in the file
int get_word_count(FILE *fp) {
    int count = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            count++;
        }
    }

    return count;
}

// Calculate the frequency of each word in the file
void calculate_word_frequency(FILE *fp, WordFreq *arr, int count) {
    char word[MAX_WORD_LEN];
    int state = OUT;
    int len = 0;
    char c;

    for (int i = 0; i < count; i++) {
        arr[i].count = 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c) || ispunct(c)) {
            if (state == IN) {
                word[len] = '\0';
                remove_punctuations(word);
                for (int i = 0; i < count; i++) {
                    if (strcmp(word, arr[i].word) == 0) {
                        arr[i].count++;
                        break;
                    }
                    else if (strlen(arr[i].word) == 0) {
                        strcpy(arr[i].word, word);
                        arr[i].count = 1;
                        break;
                    }
                }
                len = 0;
                state = OUT;
            }
        }
        else {
            state = IN;
            word[len] = tolower(c);
            len++;
        }
    }
}

// Sort the array of WordFreq structures in descending order based on the frequency
void sort_word_frequency(WordFreq *arr, int count) {
    WordFreq temp;

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i].count < arr[j].count) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}