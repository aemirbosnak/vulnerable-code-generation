//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// define the structure of the index
typedef struct Index {
    int key;
    long offset;
} Index;

int main() {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    // allocate memory for the database
    FILE* database = fopen("database.bin", "wb");
    int* data = (int*) malloc(n * sizeof(int));
    fwrite(data, sizeof(int), n, database);
    fclose(database);

    // allocate memory for the index
    Index* index = (Index*) malloc(n * sizeof(Index));

    // fill the database and index with random data
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100;
        index[i].key = data[i];
        index[i].offset = i;
    }

    // sort the index by key
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (index[i].key > index[j].key) {
                Index temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    // write the index to a separate file
    FILE* index_file = fopen("index.bin", "wb");
    fwrite(index, sizeof(Index), n, index_file);
    fclose(index_file);

    // search for records by key
    int key;
    printf("Enter a key to search for: ");
    scanf("%d", &key);

    // read the index file
    index_file = fopen("index.bin", "rb");
    fread(index, sizeof(Index), n, index_file);
    fclose(index_file);
    
    // binary search the index by key
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (index[mid].key == key) {
            // read the corresponding record from the database
            database = fopen("database.bin", "rb");
            fseek(database, index[mid].offset * sizeof(int), SEEK_SET);
            int record;
            fread(&record, sizeof(int), 1, database);
            fclose(database);
            printf("Record found: %d\n", record);
            return 0;
        } else if (index[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Record not found.\n");

    // free memory
    free(data);
    free(index);

    return 0;
}