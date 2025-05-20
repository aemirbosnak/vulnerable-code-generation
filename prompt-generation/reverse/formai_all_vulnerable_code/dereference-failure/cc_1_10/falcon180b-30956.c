//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = NULL;
    s->size = 0;
}

void free_string(String *s) {
    if (s->data!= NULL) {
        free(s->data);
        s->data = NULL;
    }
    s->size = 0;
}

void append_string(String *s, char *str) {
    int len = strlen(str);
    s->size += len;
    s->data = realloc(s->data, s->size);
    strcat(s->data, str);
}

void search_string(String *s, char *pattern) {
    char *pos = strstr(s->data, pattern);
    while (pos!= NULL) {
        printf("%s\n", pos);
        pos = strstr(pos + 1, pattern);
    }
}

int main() {
    String s;
    init_string(&s);

    char input[MAX_SIZE];
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        append_string(&s, input);
    }

    char pattern[MAX_SIZE];
    printf("Enter a pattern to search for: ");
    fgets(pattern, MAX_SIZE, stdin);

    search_string(&s, pattern);

    free_string(&s);

    return 0;
}