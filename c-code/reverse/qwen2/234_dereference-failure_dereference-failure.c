#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int atomicNumber;
} Element;

int main() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    Element element;
    while (fscanf(file, "%s %d", element.name, &element.atomicNumber) != EOF) {
        printf("%s: %d\n", element.name, element.atomicNumber);
    }

    fclose(file);
    return 0;
}
