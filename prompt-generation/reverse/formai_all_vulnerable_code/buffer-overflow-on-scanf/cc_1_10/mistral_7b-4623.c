//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct {
    char *str;
    struct cell *next;
} cell;

typedef cell *bucket;

bucket hash_table[TABLE_SIZE];

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void insert(char *str) {
    unsigned long index = hash(str);
    bucket bucket_ptr = hash_table[index];

    if (bucket_ptr == NULL) {
        hash_table[index] = malloc(sizeof(cell));
        hash_table[index]->str = strdup(str);
        hash_table[index]->next = NULL;
    } else {
        cell *current = hash_table[index];

        while (current != NULL) {
            if (strcmp(str, current->str) == 0) {
                printf("Anagram already exists: %s\n", str);
                free(str);
                return;
            }

            current = current->next;
        }

        hash_table[index] = malloc(sizeof(cell));
        hash_table[index]->str = strdup(str);
        hash_table[index]->next = NULL;
    }
}

void find_anagrams(char *words[], int num_words) {
    int i, j;
    char temp[100];

    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            strcpy(temp, words[i]);
            int k;

            for (k = 0; words[j][k] != '\0'; k++) {
                temp[k] = words[j][k];
                words[j][k] = words[i][k];
                words[i][k] = temp[k];

                unsigned long h1 = hash(words[i]);
                unsigned long h2 = hash(words[j]);

                if (h1 != h2) {
                    strcpy(temp, words[i]);
                    strcpy(words[i], words[j]);
                    strcpy(words[j], temp);
                    continue;
                }

                if (strcmp(words[i], words[j]) == 0) {
                    printf("Anagrams found: %s and %s\n", words[i], words[j]);
                    break;
                }

                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

int main() {
    int num_words;
    char *words[100];

    printf("Enter number of words: ");
    scanf("%d", &num_words);

    printf("Enter %d words:\n", num_words);

    for (int i = 0; i < num_words; i++) {
        words[i] = malloc(100 * sizeof(char));
        scanf("%s", words[i]);

        insert(words[i]);
    }

    find_anagrams(words, num_words);

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}