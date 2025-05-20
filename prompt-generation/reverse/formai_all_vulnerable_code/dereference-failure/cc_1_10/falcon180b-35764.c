//Falcon-180B DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = NULL;
    s->size = 0;
}

void append_string(String *s, char *str) {
    int new_size = s->size + strlen(str);
    if (new_size > MAX_SIZE) {
        printf("Error: string too long\n");
        return;
    }
    s->data = realloc(s->data, new_size + 1);
    if (s->data == NULL) {
        printf("Error: out of memory\n");
        return;
    }
    strcat(s->data, str);
    s->size = new_size;
}

void print_string(String *s) {
    printf("%s\n", s->data);
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, "hello");
    append_string(&s1, "world");
    print_string(&s1);

    append_string(&s2, "foo");
    append_string(&s2, "bar");
    print_string(&s2);

    free(s1.data);
    free(s2.data);

    return 0;
}