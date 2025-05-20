//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    int id;
    char name[20];
    int age;
    float gpa;
} Record;

typedef struct index_node {
    int key;
    int offset;
} IndexNode;

typedef struct index {
    char filename[20];
    IndexNode* nodes;
    int node_count;
    int max_nodes;
} Index;

int insert_record(FILE* fp, Record record, Index* index) {
    int offset = ftell(fp);
    fwrite(&record, sizeof(Record), 1, fp);

    if (index->node_count >= index->max_nodes) {
        index->max_nodes *= 2;
        index->nodes = realloc(index->nodes, sizeof(IndexNode)*index->max_nodes);
    }

    IndexNode node = {record.id, offset};
    index->nodes[index->node_count++] = node;

    return offset;
}

int search_index(Index* index, int key) {
    int low = 0, high = index->node_count-1;

    while (low <= high) {
        int mid = (low+high)/2;
        if (index->nodes[mid].key == key) {
            return index->nodes[mid].offset;
        }
        else if (index->nodes[mid].key > key) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return -1;
}

void print_record(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("GPA: %.2f\n", record.gpa);
}

int main() {
    FILE* fp = fopen("students.bin", "wb");
    Index index = {"students.idx", NULL, 0, 10};
    index.nodes = malloc(sizeof(IndexNode)*index.max_nodes);

    int input;
    while (1) {
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &input);

        if (input == 1) {
            Record record;
            printf("Enter ID: ");
            scanf("%d", &record.id);
            printf("Enter name: ");
            scanf("%s", record.name);
            printf("Enter age: ");
            scanf("%d", &record.age);
            printf("Enter GPA: ");
            scanf("%f", &record.gpa);

            int offset = insert_record(fp, record, &index);
            printf("Record added at offset %d.\n", offset);
        }
        else if (input == 2) {
            int id;
            printf("Enter ID to search: ");
            scanf("%d", &id);

            int offset = search_index(&index, id);
            if (offset == -1) {
                printf("Record not found.\n");
                continue;
            }

            Record record;
            fseek(fp, offset, SEEK_SET);
            fread(&record, sizeof(Record), 1, fp);
            print_record(record);
        }
        else if (input == 3) {
            break;
        }
        else {
            printf("Invalid input.\n");
        }
    }

    fclose(fp);
    free(index.nodes);
    return 0;
}