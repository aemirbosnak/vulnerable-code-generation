//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char genome[1000], copy[1000];
    int i, j, k, l, m, n;
    printf("Enter Genome Sequence: ");
    scanf("%s", &genome);

    printf("Original Sequence: %s\n", genome);

    srand(time(NULL)); // Seed for random number generation

    /* Mutation */
    for(i = 0; i < strlen(genome); i++) {
        if((rand() % 100) < 10) { // 10% chance of mutation
            if(genome[i] == 'A') {
                genome[i] = 'C';
            } else if(genome[i] == 'C') {
                genome[i] = 'G';
            } else if(genome[i] == 'G') {
                genome[i] = 'T';
            } else {
                genome[i] = 'A';
            }
        }
    }

    printf("\nMutated Sequence: %s\n", genome);

    /* Inversion */
    for(i = 0; i < strlen(genome); i++) {
        if((rand() % 100) < 5) { // 5% chance of inversion
            j = rand() % strlen(genome);
            if(i < j) {
                for(k = i, l = j; k < l; k++, l--) {
                    copy[k] = genome[k];
                    genome[k] = genome[l];
                    genome[l] = copy[k];
                }
            } else if(j < i) {
                for(k = j, l = i; k < l; k++, l--) {
                    copy[k] = genome[k];
                    genome[k] = genome[l];
                    genome[l] = copy[k];
                }
            }
        }
    }

    printf("\nInverted Sequence: %s\n", genome);

    /* Duplication */
    for(i = 0; i < strlen(genome); i++) {
        if((rand() % 100) < 20) { // 20% chance of duplication
            j = rand() % strlen(genome);
            k = rand() % strlen(genome);
            if(j < k) {
                for(l = j, m = k; l <= m; l++, m++) {
                    copy[l] = genome[l];
                }
                for(n = i + (m - l); n >= i; n--) {
                    genome[n + (m - l) + 1] = genome[n];
                }
                for(n = i, l = j; l <= m; n++, l++) {
                    genome[n] = copy[l];
                }
                i += (m - j + 1);
            } else {
                for(l = k, m = j; l <= m; l++, m++) {
                    copy[l] = genome[l];
                }
                for(n = i + (m - l); n >= i; n--) {
                    genome[n + (m - l) + 1] = genome[n];
                }
                for(n = i, l = k; l <= j; n++, l++) {
                    genome[n] = copy[l];
                }
                i += (j - k + 1);
            }
        }
    }

    printf("\nDuplicated Sequence: %s\n", genome);

    return 0;
}