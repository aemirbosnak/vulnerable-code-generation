//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_NUM_WORDS 1000

int word_count(char *text) {
    int num_words = 0;
    char word[MAX_WORD_LEN];
    char delim[] = ",.!?;:\"'`[]{}()";
    char *p;

    p = strtok(text, delim);
    while (p!= NULL) {
        strcpy(word, p);
        num_words++;
        p = strtok(NULL, delim);
    }

    return num_words;
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    char text[MAX_NUM_WORDS];
    int num_words;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    if (file_size > MAX_NUM_WORDS) {
        printf("File too large.\n");
        fclose(fp);
        return 1;
    }

    fread(text, 1, file_size, fp);
    fclose(fp);

    num_words = word_count(text);

    printf("Number of words in file: %d\n", num_words);

    return 0;
}