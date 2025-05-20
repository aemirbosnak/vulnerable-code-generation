//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

String *createString() {
    String *s = (String *) malloc(sizeof(String));
    s->data = (char *) malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    return s;
}

void appendChar(String *s, char c) {
    if (s->size >= MAX_SIZE) {
        fprintf(stderr, "Error: String is full.\n");
        exit(1);
    }
    s->data[s->size++] = c;
}

void appendString(String *dest, String *src) {
    int i;
    for (i = 0; i < src->size; i++) {
        appendChar(dest, src->data[i]);
    }
}

int compareStrings(String *s1, String *s2) {
    int i;
    for (i = 0; i < s1->size && i < s2->size; i++) {
        if (s1->data[i]!= s2->data[i]) {
            return s1->data[i] - s2->data[i];
        }
    }
    if (s1->size < s2->size) {
        return -1;
    } else if (s1->size > s2->size) {
        return 1;
    } else {
        return 0;
    }
}

void freeString(String *s) {
    free(s->data);
    free(s);
}

int main() {
    String *s1 = createString();
    String *s2 = createString();

    appendString(s1, s2);
    appendChar(s1, 'a');

    int cmp = compareStrings(s1, s2);
    if (cmp < 0) {
        printf("s1 is less than s2\n");
    } else if (cmp > 0) {
        printf("s1 is greater than s2\n");
    } else {
        printf("s1 is equal to s2\n");
    }

    freeString(s1);
    freeString(s2);

    return 0;
}