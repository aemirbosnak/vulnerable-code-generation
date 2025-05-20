//FormAI DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing the indexed data
typedef struct {
    char name[50];
    int index;
} Record;

// Function for comparing two Records based on name
int compare_name(const void* a, const void* b) {
    Record* r1 = (Record*) a;
    Record* r2 = (Record*) b;
    return strcmp(r1->name, r2->name);
}

// Function for comparing two Records based on index
int compare_index(const void* a, const void* b) {
    Record* r1 = (Record*) a;
    Record* r2 = (Record*) b;
    return (r1->index - r2->index);
}

int main() {
    int n; // Number of records
    printf("Enter the number of records: ");
    scanf("%d", &n);

    // Allocate memory for records
    Record* records = (Record*) malloc(n * sizeof(Record));

    // Read records from user
    printf("Enter the records:\n");
    for (int i=0; i<n; i++) {
        printf("Record %d:\n", i+1);
        scanf("%s", records[i].name);
        records[i].index = i;
    }

    // Sort records by name
    qsort(records, n, sizeof(Record), compare_name);

    // Print records sorted by name
    printf("Records sorted by name:\n");
    for (int i=0; i<n; i++) {
        printf("%s\n", records[i].name);
    }

    // Sort records by index
    qsort(records, n, sizeof(Record), compare_index);

    // Print records sorted by index
    printf("Records sorted by index:\n");
    for (int i=0; i<n; i++) {
        printf("%s\n", records[i].name);
    }

    // Free memory allocated for records
    free(records);

    return 0;
}