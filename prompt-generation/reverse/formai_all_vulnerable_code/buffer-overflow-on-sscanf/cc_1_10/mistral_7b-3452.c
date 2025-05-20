//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define FILE_NAME "data.txt"

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

void readFile(Item items[], int* numItems);
void writeFile(Item items[], int numItems);

int main() {
    int numItems = 0;
    Item items[MAX_SIZE];

    readFile(items, &numItems);

    // Perform some operations on the items here

    writeFile(items, numItems);

    return 0;
}

void readFile(Item items[], int* numItems) {
    FILE *fp;
    char line[MAX_SIZE];

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d %s %f", &items[*numItems].id, items[*numItems].name, &items[*numItems].price);
        (*numItems)++;
    }

    fclose(fp);
}

void writeFile(Item items[], int numItems) {
    FILE *fp;
    int i;

    fp = fopen(FILE_NAME, "w");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (i = 0; i < numItems; i++) {
        fprintf(fp, "%d %s %.2f\n", items[i].id, items[i].name, items[i].price);
    }

    fclose(fp);
}