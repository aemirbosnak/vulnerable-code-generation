//Falcon-180B DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

void init(String* s) {
    s->size = 0;
    s->data[0] = '\0';
}

void append(String* s, char c) {
    if (s->size == MAX_SIZE - 1) {
        printf("Error: String is full.\n");
        return;
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print(String s) {
    printf("%s", s.data);
}

int main() {
    String* arr = (String*) malloc(10 * sizeof(String));
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        init(&arr[i]);
        printf("Enter string %d: ", i + 1);
        char c;
        while ((c = getchar())!= '\n') {
            append(&arr[i], c);
        }
    }

    printf("Sorted strings:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].data, arr[j].data) > 0) {
                String temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        print(arr[i]);
        printf("\n");
    }

    free(arr);
    return 0;
}