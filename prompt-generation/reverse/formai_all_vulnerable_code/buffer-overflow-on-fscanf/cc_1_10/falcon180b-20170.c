//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

int main() {
    FILE *indexFile;
    FILE *dataFile;
    Record record;
    char input[MAX_VALUE_LEN];
    int count = 0;

    // Open the index file for reading
    indexFile = fopen("index.txt", "r");
    if (indexFile == NULL) {
        printf("Error opening index file.\n");
        return 1;
    }

    // Open the data file for reading
    dataFile = fopen("data.txt", "r");
    if (dataFile == NULL) {
        printf("Error opening data file.\n");
        return 1;
    }

    // Read the index file
    while (fscanf(indexFile, "%s %d", record.name, &record.value)!= EOF) {
        // Seek to the corresponding record in the data file
        fseek(dataFile, record.value, SEEK_SET);

        // Read the record from the data file
        if (fgets(input, MAX_VALUE_LEN, dataFile) == NULL) {
            printf("Error reading record.\n");
            return 1;
        }

        // Print the record
        printf("%s = %s\n", record.name, input);

        count++;
    }

    fclose(indexFile);
    fclose(dataFile);

    printf("%d records retrieved.\n", count);
    return 0;
}