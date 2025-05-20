//Code Llama-13B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100000

void print_help(char *program_name) {
  printf("Usage: %s <sequence_file> <kmer_size> <error_rate>\n", program_name);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    print_help(argv[0]);
    return 1;
  }

  char *sequence_file = argv[1];
  int kmer_size = atoi(argv[2]);
  double error_rate = atof(argv[3]);

  FILE *fp = fopen(sequence_file, "r");
  if (!fp) {
    printf("Error: cannot open file %s\n", sequence_file);
    return 1;
  }

  char *sequence = malloc(MAX_LEN);
  fgets(sequence, MAX_LEN, fp);
  fclose(fp);

  int len = strlen(sequence);
  int num_kmers = len - kmer_size + 1;
  int num_errors = (int)(error_rate * num_kmers);

  printf("Sequence length: %d\n", len);
  printf("Number of kmers: %d\n", num_kmers);
  printf("Number of errors: %d\n", num_errors);

  srand(time(NULL));

  for (int i = 0; i < num_errors; i++) {
    int pos = rand() % num_kmers;
    char base = sequence[pos];
    sequence[pos] = (base == 'A' ? 'T' : (base == 'T' ? 'A' : (base == 'G' ? 'C' : 'G')));
  }

  printf("Simulated genome sequence:\n");
  printf("%s\n", sequence);

  free(sequence);
  return 0;
}