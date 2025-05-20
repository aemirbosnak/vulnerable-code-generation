//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50
#define MAX_ID_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char id[MAX_ID_LENGTH];
} Record;

void writeToFile(Record records[], int size) {
    FILE *file = fopen("records.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s|%s|%s\n", records[i].name, records[i].address, records[i].id);
    }
    fclose(file);
    printf("Records written to file.\n");
}

void readFromFile(Record records[], int *size) {
    FILE *file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + MAX_ID_LENGTH + 2];
    while (fgets(line, sizeof line, file) != NULL) {
        sscanf(line, "%[^|]|%[^|]|%s", records[*size].name, records[*size].address, records[*size].id);
        (*size)++;
    }
    fclose(file);
    printf("Records read from file.\n");
}

int main() {
    Record records[3] = {
        {"John Doe", "123 Main Street", "12345"},
        {"Jane Smith", "456 Oak Avenue", "67890"},
        {"Bob Johnson", "789 Maple Drive", "24680"}
    };
    int size = 3;

    writeToFile(records, size);

    Record loadedRecords[10];
    int loadedSize = 0;
    readFromFile(loadedRecords, &loadedSize);

    printf("Loaded Records:\n");
    for (int i = 0; i < loadedSize; i++) {
        printf("%s|%s|%s\n", loadedRecords[i].name, loadedRecords[i].address, loadedRecords[i].id);
    }

    return 0;
}