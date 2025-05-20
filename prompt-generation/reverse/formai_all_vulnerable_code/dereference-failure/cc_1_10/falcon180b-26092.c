//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char *str;
    int length;
} string_t;

void init_string(string_t *str) {
    str->str = NULL;
    str->length = 0;
}

void free_string(string_t *str) {
    if (str->str!= NULL) {
        free(str->str);
        str->str = NULL;
    }
    str->length = 0;
}

void append_string(string_t *str, char *add) {
    int add_length = strlen(add);
    str->length += add_length;
    str->str = realloc(str->str, str->length + 1);
    strcat(str->str, add);
}

void print_string(string_t *str) {
    printf("%s\n", str->str);
}

int main() {
    string_t str1, str2, str3;
    init_string(&str1);
    init_string(&str2);
    init_string(&str3);

    append_string(&str1, "Hello");
    append_string(&str2, "World");

    printf("Before concatenation:\n");
    print_string(&str1);
    print_string(&str2);

    strcat(str1.str, str2.str);

    printf("After concatenation:\n");
    print_string(&str1);

    free_string(&str1);
    free_string(&str2);

    return 0;
}