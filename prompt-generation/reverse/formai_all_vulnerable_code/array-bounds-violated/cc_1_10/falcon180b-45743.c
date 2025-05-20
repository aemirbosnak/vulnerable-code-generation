//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s.\n", filename);
        return;
    }

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            words[num_words][strlen(words[num_words]) - 1] = '\0';
            num_words++;
        } else {
            strncat(words[num_words], &ch, 1);
        }
    }

    fclose(file);
}

void remove_punctuation(char* word) {
    int i = 0;
    while (word[i]) {
        if (!isalnum(word[i])) {
            word[i] = '\0';
        } else {
            i++;
        }
    }
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename);

    for (int i = 0; i < num_words; i++) {
        remove_punctuation(words[i]);
        printf("%s ", words[i]);
    }

    return 0;
}