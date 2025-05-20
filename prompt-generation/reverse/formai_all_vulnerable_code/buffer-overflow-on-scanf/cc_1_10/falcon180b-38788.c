//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readWords(FILE* file, WordCount words[]) {
    char line[1000];
    char* token;
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i = 0;
        token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            strcpy(words[i].word, token);
            words[i].count = 1;
            i++;
            token = strtok(NULL, ",.!?;:");
        }
    }
}

void printWords(WordCount words[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* file;
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    WordCount words[100];
    readWords(file, words);
    printf("Enter the number of top words to display: ");
    int n;
    scanf("%d", &n);
    printf("Top %d words:\n", n);
    printWords(words, n);
    fclose(file);
    return 0;
}