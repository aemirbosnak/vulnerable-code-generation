//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int size;
    char **data;
} CSV;

CSV *readCSV(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->size = 0;
    csv->data = NULL;
    char line[1024];
    while(fgets(line, 1024, fp)!= NULL) {
        int len = strlen(line);
        if(len == 0 || line[len - 1] == '\r') {
            line[--len] = '\0';
        }
        int i = 0;
        char *token = strtok(line, ",");
        while(token!= NULL) {
            if(i == csv->size) {
                csv->data = (char **)realloc(csv->data, sizeof(char *) * (csv->size + 1));
            }
            csv->data[i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }
        csv->size = i;
    }
    return csv;
}

void printCSV(CSV *csv) {
    int i;
    for(i = 0; i < csv->size; i++) {
        printf("%s\t", csv->data[i]);
    }
    printf("\n");
}

void freeCSV(CSV *csv) {
    int i;
    for(i = 0; i < csv->size; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = readCSV(fp);
    printCSV(csv);
    freeCSV(csv);
    fclose(fp);
    return 0;
}