//Falcon-180B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

void String_init(String *str) {
    str->data = (char*) malloc(MAX_SIZE * sizeof(char));
    str->size = 0;
}

void String_append(String *str, char *data) {
    int new_size = str->size + strlen(data);
    if (new_size > MAX_SIZE) {
        printf("Error: String too long.\n");
        exit(1);
    }
    str->data = (char*) realloc(str->data, new_size * sizeof(char));
    strcat(str->data, data);
    str->size = new_size;
}

void String_free(String *str) {
    free(str->data);
    str->data = NULL;
    str->size = 0;
}

void IntArray_init(IntArray *arr) {
    arr->data = (int*) malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
    arr->capacity = MAX_SIZE;
}

void IntArray_append(IntArray *arr, int data) {
    if (arr->size >= arr->capacity) {
        printf("Error: IntArray full.\n");
        exit(1);
    }
    arr->data[arr->size++] = data;
}

void IntArray_free(IntArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    String str;
    String_init(&str);
    String_append(&str, "Hello, world!");
    printf("%s\n", str.data);
    String_free(&str);

    IntArray arr;
    IntArray_init(&arr);
    IntArray_append(&arr, 1);
    IntArray_append(&arr, 2);
    IntArray_append(&arr, 3);
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
    IntArray_free(&arr);

    return 0;
}