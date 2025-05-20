//Falcon-180B DATASET v1.0 Category: Memory management ; Style: cheerful
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

void destroy_string(String *s) {
    if (s->data!= NULL) {
        free(s->data);
        s->data = NULL;
    }
    s->size = 0;
}

int string_length(const String *s) {
    return s->size;
}

void string_append(String *s, const char *data) {
    int new_size = s->size + strlen(data);
    if (new_size > MAX_SIZE) {
        printf("Error: string too long!\n");
        return;
    }
    s->data = realloc(s->data, new_size + 1);
    if (s->data == NULL) {
        printf("Error: out of memory!\n");
        return;
    }
    strcat(s->data, data);
    s->size = new_size;
}

void string_clear(String *s) {
    s->size = 0;
    s->data[0] = '\0';
}

int main() {
    String s;
    init_string(&s);

    string_append(&s, "Hello");
    string_append(&s, " ");
    string_append(&s, "world!");

    printf("String length: %d\n", string_length(&s));
    printf("String data: %s\n", s.data);

    string_clear(&s);

    printf("String length: %d\n", string_length(&s));
    printf("String data: %s\n", s.data);

    destroy_string(&s);

    return 0;
}