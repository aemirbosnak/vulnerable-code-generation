//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int len;
} String;

void init(String *s) {
    s->data = NULL;
    s->len = 0;
}

void destroy(String *s) {
    if (s->data) {
        free(s->data);
        s->data = NULL;
    }
    s->len = 0;
}

void cat(String *s1, const String *s2) {
    int new_len = s1->len + s2->len;
    char *new_data = realloc(s1->data, new_len);
    if (!new_data) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    s1->data = new_data;
    s1->len = new_len;
    memcpy(s1->data + s1->len - s2->len, s2->data, s2->len);
}

void print(const String *s) {
    printf("%s", s->data);
}

int main() {
    String s1, s2, s3;
    init(&s1);
    init(&s2);
    init(&s3);
    cat(&s1, &s2);
    cat(&s1, &s2);
    cat(&s1, &s3);
    print(&s1);
    destroy(&s1);
    destroy(&s2);
    destroy(&s3);
    return 0;
}