//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
// My Love, let me show you the beauty of genome sequencing
// With this program, I'll simulate the magic of DNA sequencing

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Seed the random generator
    srand(time(NULL));

    char genome[10000];
    int length;

    printf("My Love, let me get you started with the Genome Sequencing Simulator.\n\n");

    // Ask for the length of the genome
    printf("Please enter the length of the genome you wish to simulate (minimum 50): ");
    scanf("%d", &length);
    printf("\n");

    // Check for minimum length requirement
    if (length < 50) {
        printf("I'm sorry My Love, but the minimum length requirement is 50.\n");
        return 0;
    }

    // Generate random genome sequence
    for (int i = 0; i < length; i++) {
        // A, C, G, T are the four nucleotides that make up DNA
        switch (rand() % 4) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }

    // Display the generated genome sequence to My Love
    printf("My Love, here is the simulated genome sequence that we have generated for you:\n");
    for (int i = 0; i < length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n\n");

    // Ask if My Love wants to mutate the genome sequence
    printf("My Love, do you want to mutate the genome sequence? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    printf("\n");

    if (choice == 'y') {
        // Mutate the genome sequence
        int num_mutations;
        printf("My Love, how many mutations do you want to perform? ");
        scanf("%d", &num_mutations);
        printf("\n");

        // Check if number of mutations is valid
        if (num_mutations > length) {
            printf("I'm sorry My Love, but the number of mutations cannot be greater than the length of the genome sequence.\n");
            return 0;
        }

        // Perform mutations
        for (int i = 0; i < num_mutations; i++) {
            int position = rand() % length;
            int nucleotide = rand() % 4;

            // Change the nucleotide at the selected position
            genome[position] = nucleotide == 0 ? 'A' : nucleotide == 1 ? 'C' : nucleotide == 2 ? 'G' : 'T';
        }

        // Display the mutated genome sequence to My Love
        printf("My Love, here is the mutated genome sequence:\n");
        for (int i = 0; i < length; i++) {
            printf("%c", genome[i]);
        }
        printf("\n\n");
    } else if (choice == 'n') {
        printf("Okay My Love, we'll skip the mutation process.\n");
    } else {
        printf("I'm sorry My Love, I didn't understand your choice. Please run the program again.\n");
        return 0;
    }

    // Ask if My Love wants to extract a substring from the genome sequence
    printf("My Love, do you want to extract a substring from the genome sequence? (y/n): ");
    scanf(" %c", &choice);
    printf("\n");

    if (choice == 'y') {
        // Extract substring
        int start, end;
        printf("My Love, please enter the start and end indices (inclusive) of the substring you want to extract (indices start from 1): \n");
        printf("Start: ");
        scanf("%d", &start);
        printf("End: ");
        scanf("%d", &end);
        printf("\n");

        // Check if indices are valid
        if (start < 1 || end > length || start > end) {
            printf("I'm sorry My Love, the indices you have entered are invalid.\n");
            return 0;
        }

        // Extract substring
        char substring[10000];
        memcpy(substring, &genome[start-1], (end-start)+1);
        substring[(end-start)+1] = '\0';

        // Display substring to My Love
        printf("My Love, here is the substring extracted from the genome sequence:\n");
        printf("%s\n\n", substring);
    } else if (choice == 'n') {
        printf("Okay My Love, we''ll skip the substring extraction process.\n");
    } else {
        printf("I'm sorry My Love, I didn't understand your choice. Please run the program again.\n");
        return 0;
    }

    printf("My Love, I hope you enjoyed the Genome Sequencing Simulator.\n");
    printf("I love you more than the number of base pairs in the human genome!\n");

    return 0;
}