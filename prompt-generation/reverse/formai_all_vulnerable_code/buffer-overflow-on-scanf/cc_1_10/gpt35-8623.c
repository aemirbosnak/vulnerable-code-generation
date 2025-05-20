//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char key[10];
    int value;
} node;

node database[1000]; // assume we have a database of maximum 1000 entries

int databaseSize = 0; // initial size is zero

// function to add a new entry into the database
void addEntry(char *key, int value) {
    strcpy(database[databaseSize].key, key);
    database[databaseSize].value = value;
    databaseSize++;
}

// function to search a key in the database and return its index
int findIndex(char *key) {
    int i;
    for(i = 0; i < databaseSize; i++) {
        if(strcmp(database[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

// sorting algorithm
void quicksort(int left, int right) {
    int i, j, pivot, temp;
    char pivotKey[10];
    if (left < right) {
        i = left;
        j = right + 1;
        strcpy(pivotKey, database[left].key);
        pivot = database[left].value;
        do {
            do i++; while (strcmp(database[i].key, pivotKey) < 0);
            do j--; while (strcmp(database[j].key, pivotKey) > 0);
            if (i < j) {
                temp = database[i].value;
                database[i].value = database[j].value;
                database[j].value = temp;
                char tempKey[10];
                strcpy(tempKey, database[i].key);
                strcpy(database[i].key, database[j].key);
                strcpy(database[j].key, tempKey);
            }
        } while (i < j);
        temp = database[left].value;
        database[left].value = database[j].value;
        database[j].value = temp;
        char tempKey[10];
        strcpy(tempKey, database[left].key);
        strcpy(database[left].key, database[j].key);
        strcpy(database[j].key, tempKey);
        quicksort(left, j - 1);
        quicksort(j + 1, right);
    }
}

int main() {
    printf("Welcome to the Database Indexing System!\n");

    printf("Please enter the number of entries you wish to add to the database: ");
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter key for entry %d: ", i+1);
        char key[10];
        scanf("%s", key);
        printf("Enter value for entry %d: ", i+1);
        int value;
        scanf("%d", &value);
        addEntry(key, value);
    }

    // sort the database using quicksort algorithm
    quicksort(0, databaseSize-1);

    printf("\nDatabase after sorting:\n");
    for(int i = 0; i < databaseSize; i++) {
        printf("%s: %d\n", database[i].key, database[i].value);
    }

    printf("\nPlease enter the key you wish to search: ");
    char searchKey[10];
    scanf("%s", searchKey);
    int index = findIndex(searchKey);
    if(index != -1) {
        printf("Value for %s: %d\n", searchKey, database[index].value);
    } else {
        printf("Key not found in database!\n");
    }

    return 0;
}