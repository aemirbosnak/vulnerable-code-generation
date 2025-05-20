//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    size_t length;
} String;

void create_string(String *s, const char *input) {
    s->length = strlen(input);
    s->string = (char *) malloc((s->length + 1) * sizeof(char));
    strcpy(s->string, input);
}

void destroy_string(String *s) {
    free(s->string);
}

void print_string(const String *s) {
    printf("%s\n", s->string);
}

void reverse_string(String *s) {
    char *start = s->string;
    char *end = s->string + s->length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    String input_string;
    create_string(&input_string, "Hello, World!");

    printf("Original string: ");
    print_string(&input_string);

    reverse_string(&input_string);

    printf("Reversed string: ");
    print_string(&input_string);

    destroy_string(&input_string);

    return 0;
}