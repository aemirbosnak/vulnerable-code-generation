#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define RECORD_SIZE 100
#define FIELD_NAME_LENGTH 50

typedef struct {
    char name[FIELD_NAME_LENGTH];
    char value[RECORD_SIZE];
} Record;

Record table[TABLE_SIZE];

void print_table() {
    int i;
    for (i = 0; i < TABLE_SIZE; ++i) {
        printf("Record %d:\n", i);
        printf("Name: %s\n", table[i].name);
        printf("Value: %s\n", table[i].value);
        printf("\n");
    }
}

void insert_record(int index, char* name, char* value) {
    if (index >= TABLE_SIZE) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    strcpy(table[index].name, name);
    strcpy(table[index].value, value);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <index> <name> <value>\n", argv[0]);
        return 1;
    }

    int index = atoi(argv[1]);
    char* name = argv[2];
    char* value = argv[3];

    insert_record(index, name, value);
    print_table();

    return 0;
}
