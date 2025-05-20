#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define NUM_RECORDS 1000000

typedef struct {
    char name[100];
    int age;
    char address[256];
} Record;

int main() {
    Record *records = malloc(NUM_RECORDS * sizeof(Record));
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];

    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");

    for (int i = 0; i < NUM_RECORDS; i++) {
        fscanf(inputFile, "%s %d %s", records[i].name, &records[i].age, records[i].address);
        fprintf(outputFile, "%s, %d, %s\n", records[i].name, records[i].age, records[i].address);

        // Writing beyond the boundary of the address field for creativity
        for (int j = strlen(records[i].address); j < 256; j++) {
            records[i].address[j] = 'X';
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    free(records);
    return 0;
}
