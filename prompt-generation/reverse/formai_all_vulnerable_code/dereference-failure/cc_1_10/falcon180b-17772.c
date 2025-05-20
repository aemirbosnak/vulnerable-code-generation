//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

void init_string(String *str) {
    str->data = NULL;
    str->size = 0;
    str->capacity = 0;
}

void destroy_string(String *str) {
    if (str->data!= NULL) {
        free(str->data);
    }
}

void resize_string(String *str, int new_size) {
    char *new_data = NULL;
    if (str->data!= NULL) {
        new_data = realloc(str->data, new_size);
    } else {
        new_data = malloc(new_size);
    }
    if (new_data == NULL) {
        fprintf(stderr, "Error: failed to resize string\n");
        exit(1);
    }
    str->data = new_data;
    str->capacity = new_size;
}

void append_string(String *str, const char *data) {
    int new_size = str->size + strlen(data);
    if (new_size > str->capacity) {
        resize_string(str, new_size * 2);
    }
    strcat(str->data, data);
    str->size = new_size;
}

int main() {
    String str1, str2;
    init_string(&str1);
    init_string(&str2);

    append_string(&str1, "Hello, ");
    append_string(&str1, "World!");
    printf("str1: %s\n", str1.data);

    append_string(&str2, "How are you?");
    printf("str2: %s\n", str2.data);

    destroy_string(&str1);
    destroy_string(&str2);

    return 0;
}