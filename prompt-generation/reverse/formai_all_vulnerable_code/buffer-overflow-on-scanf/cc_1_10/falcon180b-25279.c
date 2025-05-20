//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_KEY_NUM 1000
#define MAX_VALUE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} KeyValue;

int key_compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    int num_keys, i;
    char input[MAX_KEY_SIZE];
    KeyValue *key_values = NULL;

    // Read in keys and values
    printf("Enter the number of keys: ");
    scanf("%d", &num_keys);

    if (num_keys > MAX_KEY_NUM) {
        printf("Error: Too many keys.\n");
        return 1;
    }

    key_values = malloc(num_keys * sizeof(KeyValue));

    for (i = 0; i < num_keys; i++) {
        printf("Enter key %d: ", i+1);
        scanf("%s", input);

        if (strlen(input) > MAX_KEY_SIZE) {
            printf("Error: Key too long.\n");
            return 1;
        }

        strcpy(key_values[i].key, input);
        key_values[i].value = i;
    }

    // Sort keys
    qsort(key_values, num_keys, sizeof(KeyValue), key_compare);

    // Print out sorted keys
    printf("Sorted keys:\n");
    for (i = 0; i < num_keys; i++) {
        printf("%s\n", key_values[i].key);
    }

    // Free memory
    free(key_values);

    return 0;
}