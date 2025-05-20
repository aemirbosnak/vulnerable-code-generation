//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    int capacity;
    char *data;
} string;

string *str_create() {
    string *s = (string *)malloc(sizeof(string));
    s->size = 0;
    s->capacity = MAX_SIZE;
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    return s;
}

void str_destroy(string *s) {
    free(s->data);
    free(s);
}

void str_append(string *s, char c) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void str_print(const string *s) {
    printf("%s", s->data);
}

int main() {
    string *s1 = str_create();
    string *s2 = str_create();
    string *s3 = str_create();

    str_append(s1, 'a');
    str_append(s2, 'b');
    str_append(s3, 'c');

    str_print(s1);
    str_print(s2);
    str_print(s3);

    str_destroy(s1);
    str_destroy(s2);
    str_destroy(s3);

    return 0;
}