//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    char value[50];
} element;

int compare(const void *a, const void *b) {
    return ((element*)a)->key - ((element*)b)->key;
}

void swap(element *a, element *b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(element list[], int left, int right) {
    int i, j, pivot;
    if (left < right) {
        i = left;
        j = right + 1;
        pivot = list[left].key;
        do {
            do i++; while (list[i].key < pivot);
            do j--; while (list[j].key > pivot);
            if (i < j) swap(&list[i], &list[j]);
        } while (i < j);
        swap(&list[left], &list[j]);
        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);
    }
}

int binary_search(element list[], int n, int key) {
    int left = 0, right = n - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (list[middle].key == key) return middle;
        else if (list[middle].key < key) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int main() {
    element *list = (element*)malloc(MAX_SIZE * sizeof(element));
    char line[50], *word;
    int n = 0;
    FILE *fp;
    fp = fopen("words.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        line[strlen(line) - 1] = '\0'; // remove newline character at the end
        word = strtok(line, " "); // split line into key and value using space as delimiter
        list[n].key = atoi(word);
        word = strtok(NULL, " ");
        strcpy(list[n].value, word);
        n++;
    }
    fclose(fp);

    quicksort(list, 0, n - 1);

    int key = 123456789;
    int index = binary_search(list, n, key);
    if (index == -1) printf("Key not found.\n");
    else printf("Value of key %d is %s.\n", key, list[index].value);

    free(list);

    return 0;
}