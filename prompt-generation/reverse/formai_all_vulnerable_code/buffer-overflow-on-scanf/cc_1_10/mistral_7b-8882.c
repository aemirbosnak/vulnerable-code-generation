//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int length;
} Element;

void print_element(Element e) {
    for (int i = 0; i < e.length; i++) {
        printf("%c", e.data[i]);
    }
    printf("\n");
}

int c_search(Element arr[], int size, char key) {
    for (int i = 0; i < size; i++) {
        if (arr[i].length > 0 && arr[i].data[arr[i].length - 1] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    Element elements[10];
    int size = 0;

    // Filling elements with strings
    elements[size++] = (Element){.data = "Hello", .length = 5};
    elements[size++] = (Element){.data = "World", .length = 5};
    elements[size++] = (Element){.data = "Coding", .length = 6};
    elements[size++] = (Element){.data = "is", .length = 2};
    elements[size++] = (Element){.data = "fun", .length = 3};
    elements[size++] = (Element){.data = "!", .length = 1};

    char key;
    printf("Enter the character to search: ");
    scanf("%c", &key);

    int index = c_search(elements, size, key);

    if (index != -1) {
        printf("Character '%c' found at index %d\n", key, index);
        print_element(elements[index]);
    } else {
        printf("Character '%c' not found\n", key);
    }

    return 0;
}