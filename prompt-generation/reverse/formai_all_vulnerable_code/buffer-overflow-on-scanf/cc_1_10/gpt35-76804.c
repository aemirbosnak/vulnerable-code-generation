//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 100

typedef struct Record {
    int id;
    char name[50];
    char address[100];
} Record;

typedef struct Index {
    int key;
    int record_index;
} Index;

int main() {
    // initialize records
    Record records[MAX_INDEX] = {
        {1, "John Doe", "123 Main St."},
        {2, "Jane Smith", "456 Oak Ave."},
        {3, "Bob Johnson", "789 Maple Dr."},
        {4, "Sally West", "101 Pine St."},
        {5, "Tom Green", "222 Elm St."},
        {6, "Mary Brown", "333 Cedar Ave."},
        {7, "Alex Lee", "444 Walnut Blvd."},
        {8, "Karen Kim", "555 Spruce Dr."},
        {9, "Mike Chen", "666 Birch St."},
        {10, "Susan Chang", "777 Oak Ave."}
    };

    // initialize index
    Index index[MAX_INDEX] = {
        {1, 0},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 4},
        {6, 5},
        {7, 6},
        {8, 7},
        {9, 8},
        {10, 9}
    };

    // prompt user for search key
    int key;
    printf("Enter search key: ");
    scanf("%d", &key);

    // search index for key
    int index_size = sizeof(index) / sizeof(Index);
    int record_index = -1;
    for (int i = 0; i < index_size; i++) {
        if (index[i].key == key) {
            record_index = index[i].record_index;
            break;
        }
    }

    // print result
    if (record_index != -1) {
        Record record = records[record_index];
        printf("Record found:\n");
        printf("ID: %d\n", record.id);
        printf("Name: %s\n", record.name);
        printf("Address: %s\n", record.address);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}