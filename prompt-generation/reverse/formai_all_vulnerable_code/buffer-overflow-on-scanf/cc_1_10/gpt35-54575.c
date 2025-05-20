//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100 // maximum size of the index array
#define MAX_NAME_LENGTH 25 // maximum length of a name

// structure for storing the names and their corresponding index
struct NameIndex {
    char name[MAX_NAME_LENGTH];
    int index;
};

// function for comparing two name-index structures based on their names
int compareByName(const void *a, const void *b) {
    return strcmp(((struct NameIndex *)a)->name, ((struct NameIndex *)b)->name);
}

// function for comparing two name-index structures based on their indices
int compareByIndex(const void *a, const void *b) {
    if (((struct NameIndex *)a)->index < ((struct NameIndex *)b)->index) {
        return -1;
    }
    else if (((struct NameIndex *)a)->index > ((struct NameIndex *)b)->index) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n, i, j;
    struct NameIndex names[MAX_INDEX_SIZE];

    // get the number of names to be indexed
    printf("Enter the number of names to be indexed: ");
    scanf("%d", &n);

    // get the names and their corresponding indices
    for (i = 0; i < n; i++) {
        printf("Enter the name and index of name %d: ", i + 1);
        scanf("%s %d", names[i].name, &names[i].index);
    }

    // sort the names and indices based on their names
    qsort(names, n, sizeof(struct NameIndex), compareByName);

    // display the sorted names and indices
    printf("Names in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d\n", names[i].name, names[i].index);
    }

    // sort the names and indices based on their indices
    qsort(names, n, sizeof(struct NameIndex), compareByIndex);

    // display the sorted names and indices
    printf("Names in index order:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d\n", names[i].name, names[i].index);
    }

    return 0;
}