//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int dna_seq_len = 0;
    char *dna_seq = NULL;
    FILE *fp;

    fp = fopen("dna_sequence.txt", "r");
    if(fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    // Read the first line that contains the DNA sequence length
    fscanf(fp, "%d\n", &dna_seq_len);

    // Allocate memory for the DNA sequence string
    dna_seq = (char *) malloc((dna_seq_len + 1) * sizeof(char));

    // Read the DNA sequence string from the file
    fgets(dna_seq, dna_seq_len+1, fp);

    // Remove the newline character at the end of the string
    dna_seq[strcspn(dna_seq, "\n")] = '\0';

    // Print the DNA sequence
    printf("The DNA sequence is: %s\n", dna_seq);

    // Calculate and print the counts of A, T, G and C bases
    int a_count = 0;
    int t_count = 0;
    int g_count = 0;
    int c_count = 0;

    for(int i=0; i<dna_seq_len; i++) {
        switch(dna_seq[i]) {
            case 'A':
            case 'a':
                a_count++;
                break;
            case 'T':
            case 't':
                t_count++;
                break;
            case 'G':
            case 'g':
                g_count++;
                break;
            case 'C':
            case 'c':
                c_count++;
                break;
            default:
                break;
        }
    }

    printf("A count: %d\n", a_count);
    printf("T count: %d\n", t_count);
    printf("G count: %d\n", g_count);
    printf("C count: %d\n", c_count);

    // Calculate and print the GC content percentage
    int gc_count = g_count + c_count;
    float gc_content = ((float) gc_count / dna_seq_len) * 100;
    printf("GC content: %.2f%\n", gc_content);

    // Free the memory allocated for the DNA sequence string
    free(dna_seq);

    // Close the file
    fclose(fp);

    return 0;
}