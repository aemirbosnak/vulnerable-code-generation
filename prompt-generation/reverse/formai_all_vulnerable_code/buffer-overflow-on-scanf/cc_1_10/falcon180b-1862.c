//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define NUM_KEYS 10
#define NUM_VALUES 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

void createIndex(char *filename, KeyValuePair *index) {
    FILE *file;
    char line[MAX_VALUE_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_VALUE_LENGTH, file)!= NULL) {
        if (i >= NUM_KEYS) {
            printf("Error: Too many keys.\n");
            exit(1);
        }
        strcpy(index[i].key, line);
        i++;
    }

    fclose(file);
}

void searchIndex(char *filename, char *key, KeyValuePair *index) {
    FILE *file;
    char line[MAX_VALUE_LENGTH];
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_VALUE_LENGTH, file)!= NULL) {
        if (strcmp(line, key) == 0) {
            printf("Value: %s\n", index[i].value);
            break;
        }
        i++;
    }

    fclose(file);
}

int main() {
    char filename[MAX_VALUE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    KeyValuePair index[NUM_KEYS];
    createIndex(filename, index);

    char key[MAX_KEY_LENGTH];
    while (1) {
        printf("Enter key to search: ");
        scanf("%s", key);
        searchIndex(filename, key, index);
    }

    return 0;
}