//FormAI DATASET v1.0 Category: Computer Biology ; Style: calm
#include <stdio.h>

int main() {
    // Welcome message for the user
    printf("Welcome to the Bioinformatics program!\n\n");

    // Prompt the user to input a DNA sequence
    printf("Please enter a DNA sequence: ");
    char dna_sequence[100];
    scanf("%s", dna_sequence);

    // Calculate the length of the DNA sequence
    int length = 0;
    for (int i = 0; dna_sequence[i] != '\0'; i++) {
        length++;
    }

    // Print the length of the DNA sequence
    printf("\nThe length of the DNA sequence is: %d\n\n", length);

    // Count the number of each nucleotide in the DNA sequence
    int a_count = 0, c_count = 0, g_count = 0, t_count = 0;
    for (int i = 0; i < length; i++) {
        if (dna_sequence[i] == 'A' || dna_sequence[i] == 'a') {
            a_count++;
        } else if (dna_sequence[i] == 'C' || dna_sequence[i] == 'c') {
            c_count++;
        } else if (dna_sequence[i] == 'G' || dna_sequence[i] == 'g') {
            g_count++;
        } else if (dna_sequence[i] == 'T' || dna_sequence[i] == 't') {
            t_count++;
        }
    }

    // Print the number of each nucleotide in the DNA sequence
    printf("Number of Adenine (A) nucleotides: %d\n", a_count);
    printf("Number of Cytosine (C) nucleotides: %d\n", c_count);
    printf("Number of Guanine (G) nucleotides: %d\n", g_count);
    printf("Number of Thymine (T) nucleotides: %d\n\n", t_count);

    // Calculate the GC content of the DNA sequence
    float gc_content = ((float)(c_count + g_count) / length) * 100;

    // Print the GC content of the DNA sequence
    printf("GC content of the DNA sequence: %.2f\n\n", gc_content);

    // Print a final message to the user
    printf("Thank you for using the Bioinformatics program!\n");

    return 0;
}