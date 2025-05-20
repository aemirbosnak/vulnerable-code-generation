//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct {
    char *str;
    int len;
} string_t;

static char buffer[MAX_LENGTH];

static void string_init(string_t *s) {
    s->str = buffer;
    s->len = 0;
}

static void string_append(string_t *s, const char *str) {
    if (s->len + strlen(str) >= MAX_LENGTH) {
        printf("Error: String too long.\n");
        exit(1);
    }
    strcat(s->str, str);
    s->len += strlen(str);
}

static void string_clear(string_t *s) {
    s->len = 0;
    s->str[0] = '\0';
}

static void string_destroy(string_t *s) {
    free(s->str);
    s->str = NULL;
    s->len = 0;
}

static int string_compare(const string_t *a, const string_t *b) {
    return strcmp(a->str, b->str);
}

int main() {
    string_t s1, s2;
    string_init(&s1);
    string_init(&s2);

    string_append(&s1, "Hello, world!");
    string_append(&s2, "Hello, world!");

    if (string_compare(&s1, &s2) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    string_clear(&s1);
    string_clear(&s2);

    string_append(&s1, "Hello");
    string_append(&s2, "world");

    if (string_compare(&s1, &s2) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    string_destroy(&s1);
    string_destroy(&s2);

    return 0;
}