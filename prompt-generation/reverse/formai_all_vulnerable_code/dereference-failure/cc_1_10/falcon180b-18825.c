//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char *str;
    int length;
} String;

void init(String *s) {
    s->str = (char *)malloc(MAX_LENGTH * sizeof(char));
    s->length = 0;
    s->str[0] = '\0';
}

void append(String *s, char c) {
    char *temp = (char *)realloc(s->str, s->length + 2);
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    s->str = temp;
    s->str[s->length] = c;
    s->str[s->length + 1] = '\0';
    s->length++;
}

void print(String s) {
    printf("%s\n", s.str);
}

void reverse(String *s) {
    char *start = s->str;
    char *end = s->str + s->length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    String s1, s2;
    init(&s1);
    init(&s2);

    append(&s1, 'H');
    append(&s1, 'e');
    append(&s1, 'l');
    append(&s1, 'l');
    append(&s1, 'o');

    append(&s2, 'W');
    append(&s2, 'o');
    append(&s2, 'r');
    append(&s2, 'l');
    append(&s2, 'd');

    printf("Original strings:\n");
    print(s1);
    print(s2);

    reverse(&s1);
    reverse(&s2);

    printf("\nReversed strings:\n");
    print(s1);
    print(s2);

    free(s1.str);
    free(s2.str);

    return 0;
}