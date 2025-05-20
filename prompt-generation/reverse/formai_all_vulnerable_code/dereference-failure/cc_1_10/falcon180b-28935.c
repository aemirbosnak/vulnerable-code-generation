//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    char *data;
} String;

String *string_create(int size) {
    String *s = (String *)malloc(sizeof(String));
    s->size = size;
    s->data = (char *)malloc(size * sizeof(char));
    memset(s->data, 0, size);
    return s;
}

void string_destroy(String *s) {
    free(s->data);
    free(s);
}

void string_append(String *s, char *str) {
    int new_size = s->size + strlen(str) + 1;
    s->data = (char *)realloc(s->data, new_size * sizeof(char));
    strcat(s->data, str);
    s->size = new_size;
}

int string_compare(String *s1, String *s2) {
    return strcmp(s1->data, s2->data);
}

int main() {
    String *s1 = string_create(10);
    String *s2 = string_create(20);

    string_append(s1, "Hello");
    string_append(s2, "World");

    int result = string_compare(s1, s2);

    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("s1 is less than s2.\n");
    } else {
        printf("s1 is greater than s2.\n");
    }

    string_destroy(s1);
    string_destroy(s2);

    return 0;
}