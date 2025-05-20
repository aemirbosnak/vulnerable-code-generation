//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_DATA_LEN 1024
#define MAX_RECORDS 100

typedef struct record_t {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} record_t;

typedef struct index_node_t {
    char key[MAX_KEY_LEN];
    int position;
} index_node_t;

typedef struct index_t {
    index_node_t nodes[MAX_RECORDS];
    int length;
} index_t;

void quicksort(index_node_t *nodes, int left, int right) {
    int i = left, j = right;
    index_node_t pivot = nodes[(left + right) / 2];
    while (i <= j) {
        while (strcmp(nodes[i].key, pivot.key) < 0) i++;
        while (strcmp(nodes[j].key, pivot.key) > 0) j--;
        if (i <= j) {
            index_node_t tmp = nodes[i];
            nodes[i] = nodes[j];
            nodes[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) quicksort(nodes, left, j);
    if (i < right) quicksort(nodes, i, right);
}

int main() {
    FILE *fp;
    index_t index;
    record_t records[MAX_RECORDS];
    char key[MAX_KEY_LEN], data[MAX_DATA_LEN];
    int num_records = 0;

    // read in records from file
    printf("Reading in records from file...\n");
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening data file\n");
        return -1;
    }
    while (fscanf(fp, "%s %s", key, data) != EOF) {
        if (num_records < MAX_RECORDS) {
            strcpy(records[num_records].key, key);
            strcpy(records[num_records].data, data);
            num_records++;
        } else {
            printf("Maximum number of records exceeded\n");
            break;
        }
    }
    fclose(fp);

    // create index
    printf("Creating index...\n");
    index.length = num_records;
    for (int i = 0; i < num_records; i++) {
        strcpy(index.nodes[i].key, records[i].key);
        index.nodes[i].position = i;
    }
    quicksort(index.nodes, 0, index.length - 1);

    // print index
    printf("Index created. Printing index...\n");
    for (int i = 0; i < index.length; i++) {
        printf("%s %d\n", index.nodes[i].key, index.nodes[i].position);
    }

    return 0;
}