//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

typedef struct {
    String *strings;
    int count;
    int capacity;
} StringArray;

void string_array_init(StringArray *array) {
    array->strings = (String *)malloc(sizeof(String) * 10);
    array->count = 0;
    array->capacity = 10;
}

void string_array_destroy(StringArray *array) {
    for (int i = 0; i < array->count; i++) {
        free(array->strings[i].data);
    }
    free(array->strings);
}

void string_array_add(StringArray *array, char *str) {
    if (array->count == array->capacity) {
        array->capacity *= 2;
        array->strings = (String *)realloc(array->strings, sizeof(String) * array->capacity);
    }
    array->strings[array->count].size = strlen(str);
    strcpy(array->strings[array->count].data, str);
    array->count++;
}

int string_array_search(StringArray *array, char *target) {
    for (int i = 0; i < array->count; i++) {
        if (strcmp(array->strings[i].data, target) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    StringArray array;
    string_array_init(&array);

    char *strings[] = {"apple", "banana", "orange", "pear", "grape"};

    for (int i = 0; i < sizeof(strings)/sizeof(char *); i++) {
        string_array_add(&array, strings[i]);
    }

    int index = string_array_search(&array, "orange");
    if (index!= -1) {
        printf("Found \"%s\" at index %d\n", array.strings[index].data, index);
    } else {
        printf("\"%s\" not found\n", "orange");
    }

    string_array_destroy(&array);

    return 0;
}