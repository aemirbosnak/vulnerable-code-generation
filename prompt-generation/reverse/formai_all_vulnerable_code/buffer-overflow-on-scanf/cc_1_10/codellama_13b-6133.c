//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_ELEMENTS 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_KEY_SIZE];
} Element;

int compare(const void* a, const void* b) {
    const Element* element1 = (const Element*)a;
    const Element* element2 = (const Element*)b;
    return strcmp(element1->key, element2->key);
}

void search(Element* elements, int n, char* key) {
    qsort(elements, n, sizeof(Element), compare);
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int result = strcmp(elements[mid].key, key);
        if (result == 0) {
            printf("Found: %s\n", elements[mid].value);
            return;
        } else if (result < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Not found.\n");
}

int main() {
    Element elements[] = {
        {"apple", "A red fruit"},
        {"banana", "A yellow fruit"},
        {"cherry", "A red fruit"},
        {"date", "A sweet fruit"},
        {"eggplant", "A purple vegetable"},
        {"fig", "A green fruit"},
        {"grape", "A purple fruit"},
        {"guava", "A yellow fruit"},
        {"kiwi", "A green fruit"},
        {"lemon", "A yellow citrus fruit"},
        {"lychee", "A small, round fruit"},
        {"mango", "A yellow fruit"},
        {"orange", "A orange citrus fruit"},
        {"pear", "A green fruit"},
        {"pineapple", "A yellow fruit"},
        {"plum", "A purple fruit"},
        {"strawberry", "A red fruit"},
        {"tangerine", "A yellow citrus fruit"},
        {"watermelon", "A sweet fruit"},
    };

    int n = sizeof(elements) / sizeof(elements[0]);

    char key[MAX_KEY_SIZE];
    printf("Enter a key: ");
    scanf("%s", key);

    search(elements, n, key);

    return 0;
}