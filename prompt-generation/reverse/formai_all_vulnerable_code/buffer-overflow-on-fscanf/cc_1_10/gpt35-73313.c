//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char dictionary[1000][30];
int dictSize = 0;

void loadDictionary() {
    char word[30];
    FILE *dictFile = fopen("dictionary.txt", "r");
    while (fscanf(dictFile, "%s", word) != EOF) {
        strcpy(dictionary[dictSize], word);
        dictSize++;
    }
    fclose(dictFile);
}

int isMisspelled(char *word) {
    int i, j, len, count;
    char temp[30];
    len = strlen(word);
    for (i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
    for (j = 0; j < dictSize; j++) {
        strcpy(temp, dictionary[j]);
        for (i = 0, count = 0; word[i] != '\0' && temp[i] != '\0'; i++) {
            if (word[i] != temp[i]) {
                count++;
                if (count > 1)
                    break;
            }
        }
        if (count == 1)
            return 0;
    }
    return 1;
}

int main() {
    int i, len, errors = 0;
    char text[1000], word[30];
    loadDictionary();
    printf("Enter your text: ");
    fgets(text, 1000, stdin);
    printf("Misspelled words:\n");
    for (i = 0, len = 0; i <= strlen(text); i++) {
        if (isalpha(text[i])) {
            word[len++] = text[i];
        }
        else {
            word[len] = '\0';
            if (len > 0 && isMisspelled(word)) {
                errors++;
                printf("%s\n", word);
            }
            len = 0;
        }
    }
    printf("%d spelling error(s) found.\n", errors);
    return 0;
}