//Falcon-180B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} String;

void init_string(String *s) {
    s->size = 0;
    s->data = malloc(MAX_SIZE);
    if (!s->data) {
        printf("Failed to allocate memory for string\n");
        exit(1);
    }
    s->data[0] = '\0';
}

void append_string(String *s, char *str) {
    int len = strlen(str);
    if (s->size + len >= MAX_SIZE) {
        printf("String is too long\n");
        exit(1);
    }
    strcat(s->data, str);
    s->size += len;
}

void print_string(String s) {
    printf("%s\n", s.data);
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, "Hello");
    append_string(&s2, "World");

    print_string(s1);
    print_string(s2);

    free(s1.data);
    free(s2.data);

    return 0;
}