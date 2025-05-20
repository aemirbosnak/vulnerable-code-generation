//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100

int main()
{
    int genome[MAX_SIZE];
    int size, i, j; 
    srand(time(0)); 

    printf("Enter the size of the genome(Max 100): ");
    scanf("%d", &size);

    if(size>MAX_SIZE || size<=0){
        printf("Invalid Size!");
        return 0;
    }

    printf("\n Genome Sequence: ");

    for(i=0; i<size; i++){
        genome[i] = rand()%4;
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("T");
                break;
            case 3:
                printf("G");
                break;
        }
    }

    // Comparing Genome Sequences
    int match_count = 0;
    int mismatch_count = 0;

    int match_array[size]; 
    int mismatch_array[size];

    printf("\n\nEnter the genome sequence to compare: ");
    int compare_genome[size];
    for(i=0; i<size; i++){
        char base;
        scanf(" %c", &base);

        // converting base characters into numbers
        switch(base) {
            case 'A':
                compare_genome[i] = 0;
                break;
            case 'C':
                compare_genome[i] = 1;
                break;
            case 'T':
                compare_genome[i] = 2;
                break;
            case 'G':
                compare_genome[i] = 3;
                break;
            default:
                printf("Invalid Character!");
                return 0;
        }
    }

    printf("\n Match or Mismatch?: ");
    for(i=0; i<size; i++){
        if(genome[i] == compare_genome[i]){
            printf("M ");
            match_array[match_count] = i;
            match_count++;
        }
        else {
            printf("NM ");
            mismatch_array[mismatch_count] = i;
            mismatch_count++;
        }
    }

    // Printing Summary Report
    printf("\n\n Match Count: %d", match_count);
    printf("\n Mismatach Count: %d", mismatch_count);

    // Printing positions of matches
    printf("\n Position of Matches: ");
    for(j=0; j<match_count; j++) {
        printf("%d ", match_array[j]);
    }

    // Printing positions of mismatches
    printf("\n Position of Mismatches: ");
    for(j=0; j<mismatch_count; j++) {
        printf("%d ", mismatch_array[j]);
    }

    return 0;
}