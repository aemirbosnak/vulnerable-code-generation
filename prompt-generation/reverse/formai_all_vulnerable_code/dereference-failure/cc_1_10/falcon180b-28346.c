//Falcon-180B DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

char **generate_array(int size);
void print_array(char **array, int size);
void sort_array(char **array, int size);

int main() {
    int size;
    char **array;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;

    array = generate_array(size);
    printf("Original array:\n");
    print_array(array, size);

    sort_array(array, size);
    printf("Sorted array:\n");
    print_array(array, size);

    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

char **generate_array(int size) {
    char **array = (char **)malloc(sizeof(char *) * size);

    for (int i = 0; i < size; i++) {
        int word_size = rand() % 10 + 1;
        char *word = (char *)malloc(sizeof(char) * (word_size + 1));

        for (int j = 0; j < word_size; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[word_size] = '\0';

        array[i] = word;
    }

    return array;
}

void print_array(char **array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

void sort_array(char **array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                char *temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}