//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void boot_up()
{
    printf("Initializing genome sequencing simulator...\n");
    printf("Enter the genome sequence:\n");
}

void read_genome_sequence(char** sequence)
{
    size_t size = 1000;
    *sequence = (char*)malloc(size * sizeof(char));
    getline(sequence, &size, stdin);
}

void generate_random_sequence(char** sequence)
{
    int length = rand() % 100 + 50;
    *sequence = (char*)malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        int num = rand() % 4;
        switch(num) {
            case 0:
                (*sequence)[i] = 'A';
                break;
            case 1:
                (*sequence)[i] = 'C';
                break;
            case 2:
                (*sequence)[i] = 'G';
                break;
            case 3:
                (*sequence)[i] = 'T';
                break;
        }
    }
}

void print_sequence(char* sequence)
{
    printf("The genome sequence is:\n%s", sequence);
}

void analyze_sequence(char* sequence)
{
    printf("Analyzing genome sequence...\n");
    int count_a = 0, count_c = 0, count_g = 0, count_t = 0;
    for (int i = 0; sequence[i] != '\0'; i++) {
        switch(sequence[i]) {
            case 'A':
                count_a++;
                break;
            case 'C':
                count_c++;
                break;
            case 'G':
                count_g++;
                break;
            case 'T':
                count_t++;
                break;
        }
    }

    printf("Adenine (A) count: %d\n", count_a);
    printf("Cytosine (C) count: %d\n", count_c);
    printf("Guanine (G) count: %d\n", count_g);
    printf("Thymine (T) count: %d\n", count_t);
}

int main()
{
    char* sequence;
    int option;
    srand(time(NULL));

    boot_up();

    printf("1. Read genome sequence\n");
    printf("2. Generate random genome sequence\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            read_genome_sequence(&sequence);
            break;
        case 2:
            generate_random_sequence(&sequence);
            break;
        default:
            printf("Invalid option.");
            return 0;
    }

    print_sequence(sequence);
    analyze_sequence(sequence);

    free(sequence);

    return 0;
}