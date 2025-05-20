//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} KeyValue;

int compare(const void *a, const void *b) {
    KeyValue *key1 = (KeyValue *) a;
    KeyValue *key2 = (KeyValue *) b;

    return strcmp(key1->key, key2->key);
}

int search(KeyValue *arr, int size, char *key) {
    KeyValue keyVal;
    keyVal.key = key;
    keyVal.value = -1;

    int result = bsearch(&keyVal, arr, size, sizeof(KeyValue), compare);

    if (result!= -1) {
        return arr[result].value;
    } else {
        return -1;
    }
}

int main() {
    KeyValue arr[MAX_SIZE];
    int size = 0;

    char key[100];
    int value;

    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", key, &value)!= EOF) {
        if (size >= MAX_SIZE) {
            printf("Maximum size reached\n");
            break;
        }

        arr[size].key = strdup(key);
        arr[size].value = value;
        size++;
    }

    fclose(fp);

    int searchKey;
    printf("Enter the key to search: ");
    scanf("%s", searchKey);

    int result = search(arr, size, searchKey);

    if (result == -1) {
        printf("Key not found\n");
    } else {
        printf("Value: %d\n", result);
    }

    for (int i = 0; i < size; i++) {
        free(arr[i].key);
    }

    return 0;
}