//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int length;
    int start;
    int end;
} Gene;

void generateRandomGene(Gene *gene) {
    gene->name = (char *) malloc(10 * sizeof(char));
    for (int i = 0; i < 10; i++) {
        gene->name[i] = 'A' + rand() % 26;
    }
    gene->length = rand() % 1000 + 1;
    gene->start = rand() % 10000;
    gene->end = gene->start + gene->length - 1;
}

int compareGenes(const void *a, const void *b) {
    Gene *geneA = (Gene *) a;
    Gene *geneB = (Gene *) b;
    if (geneA->start < geneB->start) {
        return -1;
    } else if (geneA->start > geneB->start) {
        return 1;
    } else {
        return 0;
    }
}

void printGene(Gene *gene) {
    printf("Name: %s\n", gene->name);
    printf("Length: %d\n", gene->length);
    printf("Start: %d\n", gene->start);
    printf("End: %d\n", gene->end);
}

int main() {
    srand(time(NULL));

    int numGenes;
    printf("Enter the number of genes: ");
    scanf("%d", &numGenes);

    Gene *genes = (Gene *) malloc(numGenes * sizeof(Gene));

    for (int i = 0; i < numGenes; i++) {
        generateRandomGene(&genes[i]);
    }

    qsort(genes, numGenes, sizeof(Gene), compareGenes);

    for (int i = 0; i < numGenes; i++) {
        printGene(&genes[i]);
    }

    free(genes);

    return 0;
}