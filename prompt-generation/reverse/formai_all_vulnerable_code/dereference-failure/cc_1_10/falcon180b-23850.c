//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *key;
    char *value;
    KeyValuePair *pairs;
    int count = 0;
    int i = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    pairs = malloc(count * sizeof(KeyValuePair));
    if (pairs == NULL) {
        printf("Error: could not allocate memory for pairs\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ":");
        key = malloc(MAX_KEY_LENGTH * sizeof(char));
        value = malloc(MAX_VALUE_LENGTH * sizeof(char));
        strcpy(key, token);
        strcpy(value, strtok(NULL, ":"));
        pairs[count].key = key;
        pairs[count].value = value;
        count++;
    }

    fclose(fp);

    printf("Key-value pairs:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %s\n", pairs[i].key, pairs[i].value);
    }

    free(pairs);
    return 0;
}