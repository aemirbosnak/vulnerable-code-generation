//FormAI DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define DICTSIZE 25000

struct dict {
    char* word;
    int count;
} dictionary[DICTSIZE];

int compare(const void* a, const void* b) {
    return strcmp((*(struct dict*)a).word, (*(struct dict*)b).word);
}

int check_word(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i]))
            return 0;
    }
    return 1;
}

int search_dict(char* word, int n) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(word, dictionary[mid].word) < 0)
            high = mid - 1;
        else if (strcmp(word, dictionary[mid].word) > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    FILE* fp;
    char word[MAXWORD], tmp[MAXWORD];
    int i, j, ndict = 0, nlines = 0, nwords = 0;

    fp = fopen("dictionary.txt", "r");
    while (fscanf(fp, "%s", word) != EOF) {
        if (check_word(word)) {
            dictionary[ndict].word = strdup(word);
            dictionary[ndict++].count = 1;
        }
    }
    fclose(fp);

    qsort(dictionary, ndict, sizeof(struct dict), compare);

    printf("Enter text followed by ctrl-d to spell check:\n");
    while (scanf("%s", word) != EOF) {
        nwords++;
        if (!check_word(word))
            continue;
        for (i = 0; word[i] && islower(word[i]); i++)
            word[i] = toupper(word[i]);
        j = search_dict(word, ndict);
        if (j >= 0)
            dictionary[j].count++;
        else if (++nlines <= 3)
            printf("Possible spelling error: %s\n", word);
    }
    printf("\n");
    for (i = 0; i < ndict; i++) {
        if (dictionary[i].count == 1 && ++nlines <= 10) {
            for (j = 0; j < strlen(dictionary[i].word); j++)
                tmp[j] = tolower(dictionary[i].word[j]);
            tmp[j] = '\0';
            printf("Possible misspelled word: %s\n", tmp);
        }
    }
    if (nlines == 0)
        printf("No spelling errors found!\n");

    return 0;
}