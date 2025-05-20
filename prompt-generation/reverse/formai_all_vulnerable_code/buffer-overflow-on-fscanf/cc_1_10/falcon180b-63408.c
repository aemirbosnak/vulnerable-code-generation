//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 3
#define MAX_SYMBOL_LEN 2

typedef struct {
    char name[MAX_NAME_LEN + 1];
    char symbol[MAX_SYMBOL_LEN + 1];
    int atomicNumber;
} Element;

int main() {
    Element elements[MAX_ELEMENTS];
    int numElements = 0;
    FILE *fp;

    // Read elements data from file
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %d", elements[numElements].name, elements[numElements].symbol, &elements[numElements].atomicNumber)!= EOF) {
        numElements++;
    }
    fclose(fp);

    // Sort elements by atomic number
    for (int i = 0; i < numElements - 1; i++) {
        for (int j = i + 1; j < numElements; j++) {
            if (elements[i].atomicNumber > elements[j].atomicNumber) {
                Element temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }

    // Print elements table
    printf("Periodic Table of Elements\n");
    printf("---------------------------\n");
    printf("No.  Name           Symbol\n");
    printf("---------------------------\n");

    for (int i = 0; i < numElements; i++) {
        printf("%-3d %-9s %-2s\n", elements[i].atomicNumber, elements[i].name, elements[i].symbol);
    }

    return 0;
}