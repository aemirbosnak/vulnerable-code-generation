//Falcon-180B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    char *data;
} String;

void init(String *s) {
    s->size = 0;
    s->data = (char *)malloc(MAX_SIZE);
}

void append(String *s, char c) {
    if (s->size >= MAX_SIZE) {
        s->data = (char *)realloc(s->data, s->size + MAX_SIZE);
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print(String s) {
    printf("%s\n", s.data);
}

int main() {
    String s1, s2;
    init(&s1);
    init(&s2);

    append(&s1, 'h');
    append(&s1, 'e');
    append(&s1, 'l');
    append(&s1, 'l');
    append(&s1, 'o');

    append(&s2, 'w');
    append(&s2, 'o');
    append(&s2, 'r');
    append(&s2, 'l');
    append(&s2, 'd');

    print(s1);
    print(s2);

    return 0;
}