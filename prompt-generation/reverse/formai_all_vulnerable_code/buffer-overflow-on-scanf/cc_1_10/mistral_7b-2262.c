//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VOWELS "AEIOU"
#define PURRS "RRR"
#define HISS "SSS"

void translateWord(char *word) {
    int i, j, len;
    char temp[strlen(word) + 1];
    strcpy(temp, word);

    len = strlen(word);
    for (i = 0; i < len; i++) {
        if (isalpha(temp[i])) {
            if (strchr(VOWELS, toupper(temp[i]))) {
                temp[i] = toupper(temp[i]) + '0'; // Replace with meow sound
                temp[i + 1] = 'M';
                i++;
            } else {
                for (j = i; j < len && isalpha(temp[j]); j++) {
                    if (strpbrk(PURRS, temp + j) && j < len - 1) {
                        int clusterLen = j - i;
                        memmove(temp + i, temp + j + clusterLen, strlen(temp + j + clusterLen + 1) + 1);
                        strcat(temp, PURRS);
                        i += clusterLen + 1;
                        break;
                    }
                }
                if (i < len - 1 && isalpha(temp[i + 1])) {
                    temp[i] = HISS;
                    i++;
                }
            }
        }
    }

    printf("%s ", temp);
}

int main() {
    char sentence[100][100];
    int i, numSentences;

    printf("Enter the number of sentences: ");
    scanf("%d", &numSentences);

    for (i = 0; i < numSentences; i++) {
        printf("Enter sentence %d: ", i + 1);
        scanf("%s", sentence[i]);

        // Tokenize the sentence using space as delimiter
        char *token = strtok(sentence[i], " ");
        while (token != NULL) {
            translateWord(token);
            token = strtok(NULL, " ");
        }

        printf("MREOW!\n");
    }

    return 0;
}