//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 150

char bases[] = {'A', 'C', 'G', 'T'};

int main() {
    srand(time(0)); // initialize random seed
    char genome[MAX_LENGTH];
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Enter the length of the genome you want to sequence: ");
    int length;
    scanf("%d", &length);
    if (length > MAX_LENGTH) {
        printf("Error: Maximum genome length exceeded.\n");
        return 1;
    }
    int i;
    for (i = 0; i < length; i++) {
        genome[i] = bases[rand() % 4];
    }
    printf("Your genome sequence is: %s\n", genome);
    printf("Would you like to perform any mutations on the genome sequence? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("How many mutations would you like to perform? (maximum %d): ", length/2);
        int num_mutations;
        scanf("%d", &num_mutations);
        if (num_mutations > length/2) {
            printf("Error: Maximum number of mutations exceeded.\n");
            return 1;
        }
        for (i = 0; i < num_mutations; i++) {
            int pos = rand() % length;
            char old_base = genome[pos];
            char new_base = bases[rand() % 4];
            while (new_base == old_base) {
                new_base = bases[rand() % 4];
            }
            genome[pos] = new_base;
            printf("Mutation %d: base %d changed from %c to %c.\n", i+1, pos+1, old_base, new_base);
        }
        printf("Your final genome sequence is: %s\n", genome);
    }
    printf("Thank you for using the Genome Sequencing Simulator!\n");
    return 0;
}