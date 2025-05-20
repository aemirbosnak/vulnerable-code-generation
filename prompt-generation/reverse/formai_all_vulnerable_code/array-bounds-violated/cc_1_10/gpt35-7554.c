//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LEN 1000000
#define MAX_READ_LEN 10000
#define MIN_READ_LEN 50

char genome[MAX_GENOME_LEN];

void generate_random_genome(int length) {
    int i;
    for(i=0; i<length; i++) {
        switch(rand() % 4) {
            case 0: genome[i] = 'A'; break;
            case 1: genome[i] = 'C'; break;
            case 2: genome[i] = 'G'; break;
            case 3: genome[i] = 'T'; break;
        }
    }
    genome[length] = '\0';
}

void generate_random_read(char* read, int length) {
    int i;
    for(i=0; i<length; i++) {
        switch(rand() % 4) {
            case 0: read[i] = 'A'; break;
            case 1: read[i] = 'C'; break;
            case 2: read[i] = 'G'; break;
            case 3: read[i] = 'T'; break;
        }
    }
    read[length] = '\0';
}

int main() {
    srand(time(NULL));
    int genome_len, num_reads, read_len, i, j;
    printf("Enter genome length in base pairs: ");
    scanf("%d", &genome_len);
    if(genome_len > MAX_GENOME_LEN) {
        printf("Error: genome length exceeds maximum limit of %d base pairs.\n", MAX_GENOME_LEN);
        exit(1);
    }
    generate_random_genome(genome_len);
    printf("Genome sequence generated successfully.\n");
    printf("Enter number of reads to be generated: ");
    scanf("%d", &num_reads);
    printf("Enter minimum length of each read in base pairs: ");
    scanf("%d", &read_len);
    if(read_len < MIN_READ_LEN) {
        printf("Error: read length is less than minimum limit of %d base pairs.\n", MIN_READ_LEN);
        exit(1);
    }
    char read[MAX_READ_LEN];
    for(i=0; i<num_reads; i++) {
        generate_random_read(read, read_len);
        printf("Read %d: %s\n", i+1, read);
        for(j=0; j<genome_len-read_len+1; j++) {
            if(strncmp(genome+j, read, read_len) == 0) {
                printf("Match found at position %d in genome for read %d.\n", j+1, i+1);
                break;
            }
        }
        if(j == genome_len-read_len+1) {
            printf("No match found in genome for read %d.\n", i+1);
        }
    }
    return 0;
}