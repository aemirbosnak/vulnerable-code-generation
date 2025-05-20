#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define DB_SIZE 100
#define FIELD_SIZE 100

typedef struct {
    char name[FIELD_SIZE];
    char email[FIELD_SIZE];
    char phone[FIELD_SIZE];
} Record;

Record database[DB_SIZE];
int count = 0;

void readData() {
    FILE *file = fopen("data.txt", "r");
    char line[200];

    while (fgets(line, 200, file)) {
        sscanf(line, "%s %s %s", database[count].name, database[count].email, database[count].phone);
        count++;
    }

    fclose(file);
}

void writeData() {
    FILE *file = fopen("output.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%s\n", database[i].name, database[i].email, database[i].phone);
    }

    fclose(file);
}

void processData(int index) {
    if (index >= DB_SIZE) {
        printf("Index out of bounds.\n");
        return;
    }

    // Perform complex database migration operations on 'database[index]' here.
    printf("Processing record %s\n", database[index].name);
}

int main() {
    readData();

    for (int i = 0; i < DB_SIZE * 2; i++) { // Process more records than we have to trigger an out of bounds error.
        processData(i);
    }

    writeData();

    return 0;
}
