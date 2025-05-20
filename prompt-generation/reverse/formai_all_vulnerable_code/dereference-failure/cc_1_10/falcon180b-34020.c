//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

typedef struct {
    char *str;
    size_t len;
} string_t;

string_t *string_new(const char *str) {
    string_t *s = malloc(sizeof(string_t));
    s->str = strdup(str);
    s->len = strlen(str);
    return s;
}

void string_free(string_t *s) {
    free(s->str);
    free(s);
}

int string_cmp(const string_t *a, const string_t *b) {
    return strcmp(a->str, b->str);
}

void string_concat(string_t *dest, const string_t *src) {
    dest->len += src->len;
    dest->str = realloc(dest->str, dest->len + 1);
    memcpy(dest->str + dest->len - src->len, src->str, src->len);
    dest->str[dest->len] = '\0';
}

void string_reverse(string_t *s) {
    char *start = s->str;
    char *end = start + s->len - 1;
    while (start < end) {
        char tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
}

int main() {
    string_t *s1 = string_new("Hello");
    string_t *s2 = string_new("World");

    string_concat(s1, s2);
    printf("s1 = %s\n", s1->str);

    string_reverse(s1);
    printf("s1 reversed = %s\n", s1->str);

    string_free(s1);
    string_free(s2);

    return 0;
}