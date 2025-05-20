//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wordFrequency(char str[]) {
    int i, j, k, count;
    int wordsCount = 0;

    char words[100][25];
    char temp[25];

    for(i = 0; i <= (strlen(str)); i++) {
        if(str[i] == ' ' || str[i] == '\0') {
            words[wordsCount][j] = '\0';
            wordsCount++;
            j = 0;
        } else {
            words[wordsCount][j] = str[i];
            j++;
        }
    }

    for(i = 0; i < wordsCount; i++) {
        for(k = i + 1; k < wordsCount; k++) {
            if(strcmp(words[i], words[k]) > 0) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[k]);
                strcpy(words[k], temp);
            }
        }
    }

    for(i = 0; i < wordsCount; i++) {
        count = 1;
        if(words[i][0] != '\0') {
            for(j = i + 1; j < wordsCount; j++) {
                if(strcmp(words[i], words[j]) == 0) {
                    count++;
                    words[j][0] = '\0';
                }
            }
            printf("%s: %d times.\n", words[i], count);
        }
    }
}

int main() {
    char str[1000];

    printf("Enter the string: ");
    fgets(str, 1000, stdin);

    printf("Word frequency in the given string is:\n");
    wordFrequency(str);

    return 0;
}