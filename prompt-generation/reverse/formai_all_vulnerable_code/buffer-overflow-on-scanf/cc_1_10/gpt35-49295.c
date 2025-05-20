//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include<stdio.h>
#include<string.h>

void random_dna(char *s, int len){
    char bases[] = "ATGC";
    int i;	
    for(i=0;i<len;i++){
        s[i] = bases[rand()%4];
    }
    s[i] = '\0';
}

int main(){
    int num_sequences, seq_length, i, j;
    char **sequences;

    srand(time(NULL));
	
    printf("Enter number of sequences: ");
    scanf("%d", &num_sequences);
	
    printf("Enter sequence length: ");
    scanf("%d", &seq_length);

    sequences = (char **) malloc(num_sequences * sizeof(char *));
    for(i=0;i<num_sequences;i++){
        sequences[i] = (char *) malloc((seq_length+1) * sizeof(char));
        random_dna(sequences[i],seq_length);
    }

    printf("\nSequences Generated:\n");
    for(i=0;i<num_sequences;i++){
        printf("Sequence %d: %s\n", i+1, sequences[i]);
    }

    printf("\nGenome Assembly:\n");

    for(i=0;i<num_sequences-1;i++){
        int overlap = rand() % seq_length;
        printf("\nMerging Sequence %d and Sequence %d at position %d...\n", i+1, i+2, overlap);
        for(j=overlap;j<seq_length;j++){
            sequences[i][j] = sequences[i+1][j];
        }
    }

    printf("\nAssembled Genome: %s\n", sequences[0]);

    for(i=0;i<num_sequences;i++){
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}