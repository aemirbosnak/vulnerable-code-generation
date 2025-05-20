//Falcon-180B DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 10

typedef struct {
    char *data;
    size_t len;
    size_t capacity;
} String;

String *string_create() {
    String *s = (String *)malloc(sizeof(String));
    s->data = (char *)malloc(INIT_SIZE * sizeof(char));
    s->len = 0;
    s->capacity = INIT_SIZE;
    return s;
}

void string_destroy(String *s) {
    free(s->data);
    free(s);
}

void string_append(String *s, const char *str) {
    size_t len = strlen(str);
    if (s->len + len > s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    }
    strcat(s->data, str);
    s->len += len;
}

char *string_data(String *s) {
    return s->data;
}

size_t string_length(String *s) {
    return s->len;
}

int main() {
    String *s = string_create();
    string_append(s, "Hello, ");
    string_append(s, "world!");
    printf("%s\n", string_data(s));
    string_destroy(s);
    return 0;
}