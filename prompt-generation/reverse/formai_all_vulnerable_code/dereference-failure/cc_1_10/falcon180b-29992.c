//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->data[0] = '\0';
}

void append_string(String *s, const char *str) {
    int len = strlen(str);
    if (s->size + len >= MAX_SIZE) {
        printf("Error: String is too long\n");
        return;
    }
    strcat(s->data, str);
    s->size += len;
}

void print_string(const String *s) {
    printf("%s", s->data);
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, "Hello, ");
    append_string(&s1, "world!");
    printf("\ns1 = ");
    print_string(&s1);

    append_string(&s2, "Linus ");
    append_string(&s2, "Torvalds");
    printf("\ns2 = ");
    print_string(&s2);

    free(s1.data);
    free(s2.data);

    return 0;
}