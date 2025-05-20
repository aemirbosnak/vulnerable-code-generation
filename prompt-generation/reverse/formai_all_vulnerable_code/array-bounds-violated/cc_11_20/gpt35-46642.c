//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() {
    char word[MAX], sentence[MAX];
    int count[MAX], i, j, len, freq, index;

    printf("Enter a sentence: ");
    fgets(sentence, MAX, stdin);

    len = strlen(sentence);

    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    for (i = 0; i < strlen(sentence); i++) {
        if(ispunct(sentence[i])) {
            sentence[i] = ' ';
        }
    }

    i = 0;
    j = 0;

    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            word[j] = sentence[i];
            j++;
        } else {
            word[j] = '\0';
            j = 0;

            freq = 1;

            for (index = i + 1; index < len; index++) {
                if (sentence[index] != ' ') {
                    strncpy(word, sentence + index, strlen(word));
                    if (strcmp(word, sentence + i) == 0) {
                        freq++;
                    }
                } else {
                    break;
                }
            }

            for (index = 0; index < strlen(word); index++) {
                word[index] = tolower(word[index]);
            }

            for (index = 0; index <= MAX; index++) {
                if (count[index] == 0) {
                    strcpy(word, sentence + i);
                    count[index] = freq;
                    break;
                } else if (strcmp(word, sentence + i) == 0) {
                    count[index] = freq;
                    break;
                }
            }
        }
        i++;
    }

    printf("\nWord\tFrequency\n");
    printf("--------------------\n");

    for (i = 0; i <= MAX; i++) {
        if (count[i] != 0) {
            printf("%s\t%d\n", sentence + i, count[i]);
        } else {
            break;
        }
    }

    return 0;
}