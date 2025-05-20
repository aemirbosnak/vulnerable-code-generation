//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int search(char *array[], int size, char *query);

int main() {
    char *array[MAX_SIZE];
    int size = 0;
    char query[MAX_SIZE];

    FILE *fp;
    fp = fopen("data.txt", "r");

    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while(fscanf(fp, "%s", array[size])!= EOF) {
        size++;
    }

    fclose(fp);

    printf("Enter query:\n");
    scanf("%s", query);

    int result = search(array, size, query);

    if(result == -1) {
        printf("Query not found\n");
    } else {
        printf("Found at position %d\n", result);
    }

    return 0;
}

int search(char *array[], int size, char *query) {
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(array[i], query) == 0) {
            return i;
        }
    }

    return -1;
}