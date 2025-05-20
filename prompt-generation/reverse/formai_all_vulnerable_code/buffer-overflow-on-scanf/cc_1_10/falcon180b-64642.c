//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 100
#define MAX_CATEGORIES 10
#define MAX_LABEL_LENGTH 20

typedef struct {
    char label[MAX_LABEL_LENGTH];
    int count;
} Category;

void generateRandomData(int data[], int numData) {
    srand(time(NULL));
    for (int i = 0; i < numData; i++) {
        data[i] = rand() % MAX_DATA;
    }
}

void countData(int data[], int numData, Category categories[], int numCategories) {
    for (int i = 0; i < numData; i++) {
        int category = data[i] / (MAX_DATA / numCategories);
        categories[category].count++;
    }
}

void printCategories(Category categories[], int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        printf("%s: %d\n", categories[i].label, categories[i].count);
    }
}

int main() {
    int data[MAX_DATA];
    Category categories[MAX_CATEGORIES];
    int numData, numCategories;

    printf("Enter the number of data points: ");
    scanf("%d", &numData);

    printf("Enter the number of categories: ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        printf("Enter the label for category %d: ", i + 1);
        scanf("%s", categories[i].label);
    }

    generateRandomData(data, numData);
    countData(data, numData, categories, numCategories);
    printCategories(categories, numCategories);

    return 0;
}