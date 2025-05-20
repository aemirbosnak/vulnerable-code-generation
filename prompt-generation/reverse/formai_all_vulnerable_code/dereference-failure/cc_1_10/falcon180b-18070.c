//Falcon-180B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

void init() {
    printf("Initializing memory manager...\n");
}

void *my_malloc(int size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

String *my_strdup(const char *str) {
    String *s = (String *) my_malloc(sizeof(String));
    s->data = (char *) my_malloc(strlen(str) + 1);
    strcpy(s->data, str);
    s->size = strlen(str);
    return s;
}

int main() {
    init();

    String *s1 = my_strdup("Hello world!");
    printf("s1 = %s, size = %d\n", s1->data, s1->size);

    String *s2 = my_strdup("This is a test.");
    printf("s2 = %s, size = %d\n", s2->data, s2->size);

    my_free(s1->data);
    my_free(s1);
    my_free(s2->data);
    my_free(s2);

    return 0;
}