//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_INPUT_SIZE 100

struct Element {
    char value[MAX_INPUT_SIZE];
    bool is_searched;
};

void print_element(struct Element* element) {
    printf("%s\n", element->value);
}

void print_search_result(struct Element* element) {
    if (element->is_searched) {
        printf("Found: %s\n", element->value);
    } else {
        printf("Not found\n");
    }
}

void binary_search(struct Element* elements, int num_elements, char* search_value) {
    int left = 0;
    int right = num_elements - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(elements[mid].value, search_value) == 0) {
            elements[mid].is_searched = true;
            print_search_result(&elements[mid]);
            return;
        } else if (strcmp(elements[mid].value, search_value) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    print_search_result(NULL);
}

int main() {
    struct Element elements[] = {
        { "Alice", false },
        { "Bob", false },
        { "Charlie", false },
        { "David", false },
        { "Eve", false },
        { "Frank", false },
        { "Grace", false },
        { "Helen", false },
        { "Irene", false },
        { "Jane", false },
    };
    int num_elements = sizeof(elements) / sizeof(struct Element);
    char search_value[MAX_INPUT_SIZE];
    printf("Enter search value: ");
    scanf("%s", search_value);
    binary_search(elements, num_elements, search_value);
    for (int i = 0; i < num_elements; i++) {
        print_element(&elements[i]);
    }
    return 0;
}