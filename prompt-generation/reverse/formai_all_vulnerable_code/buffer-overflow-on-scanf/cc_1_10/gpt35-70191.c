//FormAI DATASET v1.0 Category: Computer Biology ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DNA {
    int length;
    char sequence[100];
};

int main() {
    struct DNA myDNA;   // create a struct object to store DNA sequence
    int count_A = 0, count_T = 0, count_C = 0, count_G = 0;   // variables to count each nucleotide

    printf("Enter the DNA sequence: ");
    scanf("%s", myDNA.sequence);
    myDNA.length = strlen(myDNA.sequence);

    // count each nucleotide in the sequence
    for (int i = 0; i < myDNA.length; i++) {
        if (myDNA.sequence[i] == 'A') {
            count_A++;
        }
        else if (myDNA.sequence[i] == 'T') {
            count_T++;
        }
        else if (myDNA.sequence[i] == 'C') {
            count_C++;
        }
        else if (myDNA.sequence[i] == 'G') {
            count_G++;
        }
        else {
            printf("Invalid character detected!\n");
            return 1;   // exit the program if an invalid character is detected
        }
    }

    // print the total count of each nucleotide
    printf("Total counts:\n");
    printf("A: %d\nT: %d\nC: %d\nG: %d\n", count_A, count_T, count_C, count_G);

    // calculate the GC content
    double gc_content = (double)(count_C + count_G) / myDNA.length * 100;
    printf("GC Content: %.2lf%%\n", gc_content);

    // check for any repeating sequences
    for (int i = 0; i < myDNA.length - 1; i++) {
        for (int j = i + 1; j < myDNA.length; j++) {
            if (strncmp(myDNA.sequence + i, myDNA.sequence + j, 3) == 0) {
                printf("Repeating sequence found: %.*s\n", 3, myDNA.sequence + i);
            }
        }
    }

    return 0;
}