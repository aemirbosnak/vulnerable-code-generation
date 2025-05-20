//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_SIZE 100

    typedef struct {
        int key;
        char value[MAX_SIZE];
    } Data;

    void bubbleSort(Data* array, int size) {
        int i, j, temp;
        for (i = 0; i < size - 1; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (array[j].key > array[j + 1].key) {
                    temp = array[j].key;
                    array[j].key = array[j + 1].key;
                    array[j + 1].key = temp;
                }
            }
        }
    }

    int search(Data* array, int size, int key) {
        int i;
        for (i = 0; i < size; i++) {
            if (array[i].key == key) {
                return i;
            }
        }
        return -1;
    }

    int main() {
        Data array[MAX_SIZE];
        int size, i, key;

        printf("Enter the size of the array: ");
        scanf("%d", &size);

        for (i = 0; i < size; i++) {
            printf("Enter the key and value for element %d: ", i);
            scanf("%d %s", &array[i].key, array[i].value);
        }

        bubbleSort(array, size);

        printf("Enter the key to search for: ");
        scanf("%d", &key);

        i = search(array, size, key);

        if (i != -1) {
            printf("The key was found at index %d.\n", i);
        } else {
            printf("The key was not found.\n");
        }

        return 0;
    }