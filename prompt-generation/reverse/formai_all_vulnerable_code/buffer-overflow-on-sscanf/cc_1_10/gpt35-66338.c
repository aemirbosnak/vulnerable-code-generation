//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

void print_record(Record r) {
    printf("%d, %s, %d\n", r.id, r.name, r.age);
}

int compare_records(const void *a, const void *b) {
    Record *ra = (Record*)a;
    Record *rb = (Record*)b;
    if (ra->id < rb->id) return -1;
    else if (ra->id > rb->id) return 1;
    else return 0;
}

int main() {
    FILE *fp = fopen("data.txt", "r+");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    
    // Read the records from the file
    Record records[BUF_SIZE];
    int count = 0;
    char line[BUF_SIZE];
    while (fgets(line, BUF_SIZE, fp) != NULL) {
        sscanf(line, "%d %s %d", &(records[count].id), records[count].name, &(records[count].age));
        count++;
    }
    
    // Sort the records
    qsort(records, count, sizeof(Record), compare_records);
    
    // Rewrite the file with the sorted records
    rewind(fp);
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d\n", records[i].id, records[i].name, records[i].age);
    }
    
    fclose(fp);
    return 0;
}