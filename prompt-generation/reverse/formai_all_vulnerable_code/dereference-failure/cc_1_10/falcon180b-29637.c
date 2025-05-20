//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char *str;
    int length;
} String;

void init_string(String *s) {
    s->str = (char *)malloc(MAX_LENGTH * sizeof(char));
    s->length = 0;
    s->str[0] = '\0';
}

void append_string(String *s, char *append) {
    int new_length = s->length + strlen(append);
    if (new_length >= MAX_LENGTH) {
        printf("Error: String is too long.\n");
        return;
    }
    strcat(s->str, append);
    s->length = new_length;
}

void reverse_string(String *s) {
    int i, j;
    char temp;
    for (i = 0, j = s->length - 1; i < j; i++, j--) {
        temp = s->str[i];
        s->str[i] = s->str[j];
        s->str[j] = temp;
    }
}

void capitalize_string(String *s) {
    int i;
    for (i = 0; i < s->length; i++) {
        if (isalpha(s->str[i])) {
            s->str[i] = toupper(s->str[i]);
        }
    }
}

void print_string(String *s) {
    printf("%s\n", s->str);
}

int main() {
    String s;
    init_string(&s);

    append_string(&s, "Hello, world!");
    print_string(&s);

    reverse_string(&s);
    print_string(&s);

    capitalize_string(&s);
    print_string(&s);

    free(s.str);
    return 0;
}