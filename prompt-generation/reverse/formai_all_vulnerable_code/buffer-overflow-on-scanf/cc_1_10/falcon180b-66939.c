//Falcon-180B DATASET v1.0 Category: File handling ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_SIZE];
    int count;
} WordCount;

void readFile(char *filename, char *buffer) {
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    fread(buffer, file_size, 1, fp);
    fclose(fp);
}

void processWords(char *buffer, WordCount *word_counts) {
    char *token = strtok(buffer, " \n\t\r\f\v,.?!;:");
    while(token!= NULL) {
        int i = 0;
        while(i < MAX_WORDS && word_counts[i].count > 0) {
            i++;
        }
        if(i < MAX_WORDS) {
            strcpy(word_counts[i].word, token);
            word_counts[i].count = 1;
        } else {
            printf("Max number of words reached\n");
        }
        token = strtok(NULL, " \n\t\r\f\v,.?!;:");
    }
}

void writeFile(char *filename, WordCount *word_counts) {
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for(int i = 0; i < MAX_WORDS; i++) {
        if(word_counts[i].count > 0) {
            fprintf(fp, "%s %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
    fclose(fp);
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    char buffer[MAX_SIZE];
    readFile(filename, buffer);
    WordCount word_counts[MAX_WORDS];
    processWords(buffer, word_counts);
    char output_filename[MAX_SIZE];
    printf("Enter output filename: ");
    scanf("%s", output_filename);
    writeFile(output_filename, word_counts);
    printf("Done.\n");
    return 0;
}