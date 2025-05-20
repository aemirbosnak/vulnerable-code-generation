//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->data[0] = '\0';
}

void append_char(String *s, char c) {
    if (s->size >= MAX_SIZE) {
        printf("Error: String overflow\n");
        exit(1);
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void append_string(String *s, String *t) {
    int i = 0;
    while (i < t->size) {
        append_char(s, t->data[i]);
        i++;
    }
}

void print_string(String *s) {
    printf("%s", s->data);
}

int main() {
    srand(time(NULL));
    String str1, str2;
    init_string(&str1);
    init_string(&str2);
    int i;
    for (i = 0; i < 10; i++) {
        char c = rand() % 26 + 'a';
        append_char(&str1, c);
    }
    printf("Random string 1: ");
    print_string(&str1);
    printf("\n");
    for (i = 0; i < 20; i++) {
        char c = rand() % 26 + 'a';
        append_char(&str2, c);
    }
    printf("Random string 2: ");
    print_string(&str2);
    printf("\n");
    append_string(&str1, &str2);
    printf("Concatenated string: ");
    print_string(&str1);
    printf("\n");
    free(str1.data);
    free(str2.data);
    return 0;
}