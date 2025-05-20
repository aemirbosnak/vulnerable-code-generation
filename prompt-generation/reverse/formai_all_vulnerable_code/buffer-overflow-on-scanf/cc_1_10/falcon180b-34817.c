//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Pair;

int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return strcmp(p1->key, p2->key);
}

void search(char *key) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    Pair *pairs = NULL;
    int count = 0;

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        char *key_value_str = strtok(line, " ");
        while (key_value_str!= NULL) {
            char *key = strtok(key_value_str, ":");
            int value = atoi(strtok(NULL, ":"));

            Pair *new_pair = (Pair *)malloc(sizeof(Pair));
            new_pair->key = key;
            new_pair->value = value;
            pairs = (Pair *)realloc(pairs, sizeof(Pair) * ++count);
            pairs[count - 1] = *new_pair;

            free(new_pair);
        }
    }

    fclose(file);

    if (count == 0) {
        printf("No results found.\n");
    } else {
        qsort(pairs, count, sizeof(Pair), compare);
        printf("Results:\n");
        for (int i = 0; i < count; i++) {
            printf("%s: %d\n", pairs[i].key, pairs[i].value);
        }
    }

    free(pairs);
}

int main() {
    char key[MAX_SIZE];
    printf("Enter search key: ");
    scanf("%s", key);

    search(key);

    return 0;
}