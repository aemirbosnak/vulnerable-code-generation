//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    int value;
} Item;

typedef struct {
    Item data[MAX_SIZE];
    int size;
} MyList;

void swap(Item *a, Item *b) {
    Item temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(MyList *list) {
    int i, j, min_idx;

    for (i = 0; i < list->size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < list->size; j++) {
            if (list->data[j].key < list->data[min_idx].key) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&list->data[i], &list->data[min_idx]);
        }
    }
}

void printList(MyList list) {
    int i;

    printf("List: \n");
    for (i = 0; i < list.size; i++) {
        printf("(%d, %d)\n", list.data[i].key, list.data[i].value);
    }
}

void printErrorAndExit(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void parseInputFile(FILE *file, MyList *list) {
    Item new_item;
    char line[100];
    int index = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %d", &new_item.key, &new_item.value);
        if (list->size >= MAX_SIZE) {
            printErrorAndExit("Error: Input file too large.\n");
        }
        list->data[index++] = new_item;
        list->size++;
    }
}

int main(int argc, char *argv[]) {
    MyList list;
    FILE *input_file;

    if (argc != 2) {
        printErrorAndExit("Usage: ./program input_file\n");
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printErrorAndExit("Error: Could not open input file.\n");
    }

    list.size = 0;
    parseInputFile(input_file, &list);
    fclose(input_file);

    selectionSort(&list);
    printList(list);

    return 0;
}