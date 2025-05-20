//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000
#define MAX_NUM_VALUES 10000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

void createIndex(char *filename, int numKeys) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    KeyValuePair *index = malloc(numKeys * sizeof(KeyValuePair));
    int numValues = 0;
    while (fscanf(fp, "%s %s", index[numValues].key, index[numValues].value)!= EOF) {
        numValues++;
    }
    fclose(fp);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (int i = 0; i < numValues; i++) {
        fprintf(fp, "%s %s\n", index[i].key, index[i].value);
    }

    fclose(fp);
}

void searchIndex(char *filename, char *searchKey) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char line[MAX_VALUE_SIZE];
    while (fgets(line, MAX_VALUE_SIZE, fp)!= NULL) {
        char *key = strtok(line, " ");
        char *value = strtok(NULL, " ");

        if (strcmp(key, searchKey) == 0) {
            printf("%s\n", value);
        }
    }

    fclose(fp);
}

int main() {
    char filename[MAX_KEY_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    int numKeys;
    printf("Enter number of keys to index: ");
    scanf("%d", &numKeys);

    createIndex(filename, numKeys);

    char searchKey[MAX_KEY_SIZE];
    printf("Enter key to search: ");
    scanf("%s", searchKey);

    searchIndex(filename, searchKey);

    return 0;
}