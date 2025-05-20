//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_file(FILE *fp) {
    char ch;
    int i = 0;

    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            words[num_words][i] = tolower(ch);
            i++;
        } else if(i > 0) {
            words[num_words][i] = '\0';
            num_words++;
            i = 0;
        }
    }

    if(i > 0) {
        words[num_words][i] = '\0';
        num_words++;
    }
}

void sort_words() {
    int i, j;
    char temp[MAX_WORD_LENGTH];

    for(i = 0; i < num_words - 1; i++) {
        for(j = i + 1; j < num_words; j++) {
            if(strcmp(words[i], words[j]) > 0) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

void print_words() {
    int i;

    for(i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    FILE *fp;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    read_file(fp);
    sort_words();
    print_words();

    fclose(fp);

    return 0;
}