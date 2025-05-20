//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LEN 1000000
#define MAX_READ_LEN 100

typedef struct {
    char *seq;
    int len;
} Seq;

Seq *genome;
Seq *reads[1000];
int num_reads;

void init_genome() {
    genome = (Seq *)malloc(sizeof(Seq));
    genome->seq = (char *)malloc(MAX_SEQ_LEN * sizeof(char));
    genome->len = MAX_SEQ_LEN;
    for (int i = 0; i < MAX_SEQ_LEN; i++) {
        genome->seq[i] = 'A' + rand() % 4;
    }
}

void init_reads() {
    srand(time(NULL));
    num_reads = rand() % 1000 + 1;
    for (int i = 0; i < num_reads; i++) {
        reads[i] = (Seq *)malloc(sizeof(Seq));
        reads[i]->seq = (char *)malloc(MAX_READ_LEN * sizeof(char));
        reads[i]->len = MAX_READ_LEN;
        for (int j = 0; j < MAX_READ_LEN; j++) {
            reads[i]->seq[j] = 'A' + rand() % 4;
        }
    }
}

int main() {
    init_genome();
    init_reads();

    printf("Genome:\n%s\n", genome->seq);

    for (int i = 0; i < num_reads; i++) {
        printf("Read %d:\n%s\n", i + 1, reads[i]->seq);
    }

    return 0;
}