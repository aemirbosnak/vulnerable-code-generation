//Falcon-180B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

String *create_string(char *str) {
    String *s = (String *) malloc(sizeof(String));
    if (!s) {
        printf("Memory error\n");
        exit(1);
    }
    s->data = strdup(str);
    s->size = strlen(str);
    return s;
}

void delete_string(String *s) {
    free(s->data);
    free(s);
}

void print_string(String *s) {
    printf("%s\n", s->data);
}

void concatenate_strings(String *s1, String *s2) {
    char *new_data = (char *) malloc(s1->size + s2->size + 1);
    if (!new_data) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(new_data, s1->data);
    strcat(new_data, s2->data);
    delete_string(s1);
    delete_string(s2);
    s1 = create_string(new_data);
}

int main() {
    String *s1 = create_string("Hello");
    String *s2 = create_string("World");
    print_string(s1);
    print_string(s2);
    concatenate_strings(s1, s2);
    print_string(s1);
    delete_string(s1);
    delete_string(s2);
    return 0;
}