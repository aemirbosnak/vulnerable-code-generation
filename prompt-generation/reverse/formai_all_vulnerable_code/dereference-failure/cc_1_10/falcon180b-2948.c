//Falcon-180B DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_count = 0;

void read_file(FILE *file) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH) {
                printf("Error: Word is too long\n");
                return;
            }
            words[word_count][i++] = tolower(ch);
        } else if (isspace(ch)) {
            words[word_count][i] = '\0';
            word_count++;
            i = 0;
        }
    }
}

void count_words(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return;
    }
    read_file(file);
    printf("Total words: %d\n", word_count);
}

void reverse_words(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return;
    }
    read_file(file);
    for (int i = 0; i < word_count / 2; i++) {
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[word_count - i - 1]);
        strcpy(words[word_count - i - 1], temp);
    }
    printf("Reversed words:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

void main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("1. Count words\n2. Reverse words\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            count_words(filename);
            break;
        case 2:
            reverse_words(filename);
            break;
        default:
            printf("Invalid choice\n");
    }
}