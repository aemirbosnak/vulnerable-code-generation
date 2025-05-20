#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TABLE_COUNT 100000
#define COLUMN_COUNT 5

typedef struct {
    char name[BUFFER_SIZE];
    int age;
    char address[BUFFER_SIZE];
    float salary;
    char phone[BUFFER_SIZE];
} Record;

Record *records;

void init_database() {
    records = (Record *) malloc(TABLE_COUNT * sizeof(Record));
}

void load_data() {
    int i;
    for (i = 0; i < TABLE_COUNT; ++i) {
        sprintf(records[i].name, "John Doe %d", i);
        records[i].age = i * 3;
        strcpy(records[i].address, "123 Main St, City, ST 12345");
        records[i].salary = 50000.0 * i;
        strcpy(records[i].phone, "(123) 456-7890");
    }
}

void save_data() {
    int i;
    FILE *fp = fopen("data.bin", "wb");
    if (!fp) return;

    for (i = 0; i < TABLE_COUNT; ++i) {
        fwrite(&records[i], sizeof(Record), 1, fp);
    }
    fclose(fp);
}

int main() {
    init_database();
    load_data();
    save_data();
    free(records);

    // Dereference uninitialized pointer to trigger a segmentation fault
    printf("%s\n", records[TABLE_COUNT].name);

    return 0;
}
