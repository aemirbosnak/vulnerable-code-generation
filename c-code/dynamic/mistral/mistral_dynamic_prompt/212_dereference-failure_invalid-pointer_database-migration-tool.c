#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct Record {
    char name[100];
    char data[1024];
};

int main(int argc, char *argv[]) {
    struct Record *records = malloc(MAX_RECORDS * sizeof(struct Record));
    int record_count = 0;

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), inputFile)) {
        record_count++;
        if (record_count > MAX_RECORDS) {
            printf("Error: Exceeded maximum number of records.\n");
            break;
        }

        strcpy(records[record_count - 1].name, strtok(line, ": ")[1]);
        strcpy(records[record_count - 1].data, strtok(NULL, "\n"));
    }

    fclose(inputFile);

    // Dereference failure (invalid pointer) vulnerability
    for (int i = 0; i < record_count; i++) {
        printf("Name: %s\nData: %s\n", records[i].name, records[i].data);
        printf("Name: %s\nData: %s\n", records[i + 1].name, records[i].data); // Access out-of-bound memory
    }

    free(records);
    return 0;
}
