//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

void init(String* str) {
    str->size = 0;
    str->data[0] = '\0';
}

void append(String* str, char c) {
    if (str->size >= MAX_SIZE - 1) {
        printf("Error: String is full.\n");
        return;
    }
    str->data[str->size++] = c;
    str->data[str->size] = '\0';
}

void print(String str) {
    printf("%s", str.data);
}

int search(String haystack, String needle) {
    int i, j;
    for (i = 0; i <= haystack.size - needle.size; i++) {
        for (j = 0; j < needle.size; j++) {
            if (haystack.data[i + j]!= needle.data[j]) {
                break;
            }
        }
        if (j == needle.size) {
            return i;
        }
    }
    return -1;
}

int main() {
    String haystack, needle;
    init(&haystack);
    init(&needle);

    printf("Enter the string to search for: ");
    scanf("%s", needle.data);

    printf("Enter the string to search in: ");
    fgets(haystack.data, MAX_SIZE, stdin);

    int index = search(haystack, needle);

    if (index == -1) {
        printf("The string was not found.\n");
    } else {
        printf("The string was found at index %d.\n", index);
    }

    return 0;
}