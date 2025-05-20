//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>

typedef struct {
    char str1[50], str2[50];
    int dist;
} _pair;

void _delete(char *str, int pos) {
    int i = 0;
    char *newStr = (char *) malloc((strlen(str) - 1) * sizeof(char));

    for (; i < pos; i++) {
        newStr[i] = str[i];
    }

    for (int j = pos + 1; j < strlen(str); j++) {
        newStr[i + (j - pos)] = str[j];
        i++;
    }

    free(str);
    strcpy(str, newStr);
    free(newStr);
}

int _subtract(_pair *pair, int pos) {
    _delete(pair->str1, pos);
    _delete(pair->str2, pos);
    pair->dist--;
}

int main() {
    _pair puzzle;
    char str1[50], str2[50];

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    strcpy(puzzle.str1, str1);
    strcpy(puzzle.str2, str2);

    for (int i = 0; i < strlen(str1); i++) {
        for (int j = 0; i + j < strlen(str2); j++) {
            if (str1[i] == str2[i + j]) {
                _subtract(&puzzle, i);
                break;
            }
        }
    }

    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, puzzle.dist);

    return 0;
}