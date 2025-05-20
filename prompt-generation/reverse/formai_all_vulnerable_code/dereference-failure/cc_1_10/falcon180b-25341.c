//Falcon-180B DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

void init_string(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->capacity = MAX_SIZE;
}

void free_string(String *s) {
    free(s->data);
    s->size = 0;
    s->capacity = MAX_SIZE;
}

void string_append(String *s, char c) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void string_append_string(String *s, String *t) {
    int i = 0;
    while (i < t->size) {
        string_append(s, t->data[i]);
        i++;
    }
}

void string_print(String *s) {
    printf("%s\n", s->data);
}

int main() {
    String s1, s2, s3;

    init_string(&s1);
    init_string(&s2);
    init_string(&s3);

    string_append(&s1, 'H');
    string_append(&s1, 'e');
    string_append(&s1, 'l');
    string_append(&s1, 'l');
    string_append(&s1, 'o');
    string_append(&s1, '\0');

    string_append(&s2, 'W');
    string_append(&s2, 'o');
    string_append(&s2, 'r');
    string_append(&s2, 'l');
    string_append(&s2, 'd');
    string_append(&s2, '\0');

    string_append_string(&s3, &s1);
    string_append_string(&s3, &s2);

    string_print(&s1);
    string_print(&s2);
    string_print(&s3);

    free_string(&s1);
    free_string(&s2);
    free_string(&s3);

    return 0;
}