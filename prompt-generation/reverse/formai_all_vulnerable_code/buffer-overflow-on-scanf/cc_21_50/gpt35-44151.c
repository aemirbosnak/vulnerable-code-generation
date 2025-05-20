//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
    char dictionary[1000][50], word[50];
    int i = 0, j = 0, n = 0, found = 0;

    printf("Enter number of words in dictionary: ");
    scanf("%d", &n);

    printf("Enter dictionary words: \n");
    for(i = 0; i < n; i++) {
        scanf("%s", dictionary[i]);
    }

    printf("\nEnter word to check: ");
    scanf("%s", word);

    printf("\nPossible corrections:\n");

    //deletion
    for(i = 0; i < strlen(word)+1; i++) {
        char temp[50];

        for(j = 0; j < i; j++) {
            temp[j] = word[j];
        }

        for(j = i+1; j < strlen(word)+1; j++) {
            temp[j-1] = word[j];
        }

        for(j = 0; j < n; j++) {
            if(strcmp(temp, dictionary[j]) == 0) {
                printf("%s\n", temp);
                found = 1;
            }
        }
    }

    //insertion
    for(i = 0; i < strlen(word)+1; i++) {
        char temp[50];

        for(j = 0; j < i; j++) {
            temp[j] = word[j];
        }

        temp[i] = '-';

        for(j = i; j < strlen(word)+1; j++) {
            temp[j+1] = word[j];
        }

        for(j = 0; j < n; j++) {
            if(strcmp(temp, dictionary[j]) == 0) {
                printf("%s\n", temp);
                found = 1;
            }
        }
    }

    //transposition
    for(i = 0; i < strlen(word)-1; i++) {
        char temp[50];

        for(j = 0; j < i; j++) {
            temp[j] = word[j];
        }

        temp[i] = word[i+1];
        temp[i+1] = word[i];

        for(j = i+2; j < strlen(word); j++) {
            temp[j] = word[j];
        }

        for(j = 0; j < n; j++) {
            if(strcmp(temp, dictionary[j]) == 0) {
                printf("%s\n", temp);
                found = 1;
            }
        }
    }

    //substitution
    for(i = 0; i < strlen(word); i++) {
        for(j = 0; j < n; j++) {
            char temp[50];
            strcpy(temp, word);
            temp[i] = dictionary[j][0];

            if(strcmp(temp, dictionary[j]) == 0) {
                printf("%s\n", temp);
                found = 1;
            }
        }
    }

    if(found == 0) {
        printf("No possible corrections found.\n");
    }

    return 0;
}