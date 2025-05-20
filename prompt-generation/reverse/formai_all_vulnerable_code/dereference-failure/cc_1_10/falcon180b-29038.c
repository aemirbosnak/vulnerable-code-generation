//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int length;
} Gene;

int main() {
    int num_genes;
    Gene *genes;
    char *genome_str;
    int i;

    // Prompt user for number of genes
    printf("Enter the number of genes: ");
    scanf("%d", &num_genes);

    // Allocate memory for genes
    genes = (Gene *) malloc(num_genes * sizeof(Gene));

    // Prompt user for gene names and lengths
    for (i = 0; i < num_genes; i++) {
        printf("Enter gene name %d: ", i + 1);
        scanf("%s", genes[i].name);
        printf("Enter gene length %d: ", i + 1);
        scanf("%d", &genes[i].length);
    }

    // Generate random genome string
    srand(time(NULL));
    genome_str = (char *) malloc(1000000 * sizeof(char)); // Allocate 1MB for genome string
    for (i = 0; i < 1000000; i++) {
        genome_str[i] = 'A' + rand() % 4; // Randomly choose A, C, G or T
    }
    genome_str[999999] = '\0'; // Null terminate the string

    // Print genome information
    printf("\nGenome Information:\n");
    printf("---------------------\n");
    printf("Number of Genes: %d\n", num_genes);
    printf("Genome Length: %d\n", strlen(genome_str));

    // Analyze genes in genome
    int total_genes_found = 0;
    int total_bp_analyzed = 0;
    for (i = 0; i < strlen(genome_str); i++) {
        total_bp_analyzed++;
        if (total_bp_analyzed >= genes[0].length) {
            total_bp_analyzed -= genes[0].length;
            total_genes_found++;
        }
        if (strncmp(genome_str + i, genes[total_genes_found - 1].name, genes[total_genes_found - 1].length) == 0) {
            // Found a gene
            printf("Found gene '%s' at position %d\n", genes[total_genes_found - 1].name, i);
        }
    }

    // Free memory
    for (i = 0; i < num_genes; i++) {
        free(genes[i].name);
    }
    free(genes);
    free(genome_str);

    return 0;
}