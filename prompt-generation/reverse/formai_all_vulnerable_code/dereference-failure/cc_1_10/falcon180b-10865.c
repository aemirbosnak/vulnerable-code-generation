//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int length;
    int start;
    int end;
} Gene;

Gene *createGene(char *name, int length, int start, int end) {
    Gene *gene = (Gene *) malloc(sizeof(Gene));
    gene->name = name;
    gene->length = length;
    gene->start = start;
    gene->end = end;
    return gene;
}

void printGene(Gene *gene) {
    printf("Name: %s\n", gene->name);
    printf("Length: %d\n", gene->length);
    printf("Start: %d\n", gene->start);
    printf("End: %d\n", gene->end);
}

int main() {
    srand(time(NULL));

    int numGenes = rand() % 10 + 1;
    Gene **genes = (Gene **) malloc(sizeof(Gene *) * numGenes);

    for (int i = 0; i < numGenes; i++) {
        char name[10] = {0};
        sprintf(name, "Gene%d", i + 1);
        int length = rand() % 1000 + 1;
        int start = rand() % 10000;
        int end = start + length - 1;

        genes[i] = createGene(name, length, start, end);
    }

    for (int i = 0; i < numGenes; i++) {
        printGene(genes[i]);
    }

    for (int i = 0; i < numGenes; i++) {
        free(genes[i]->name);
        free(genes[i]);
    }
    free(genes);

    return 0;
}