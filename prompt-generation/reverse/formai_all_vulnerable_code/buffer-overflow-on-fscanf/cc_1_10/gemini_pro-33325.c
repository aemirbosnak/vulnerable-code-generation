//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Dataset;

typedef struct {
    int *data;
    int size;
} Pattern;

typedef struct {
    Pattern *patterns;
    int size;
} Patterns;

Dataset *read_dataset(char *filename) {
    Dataset *dataset = malloc(sizeof(Dataset));
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }
    fscanf(file, "%d", &dataset->size);
    dataset->data = malloc(sizeof(int) * dataset->size);
    for (int i = 0; i < dataset->size; i++) {
        fscanf(file, "%d", &dataset->data[i]);
    }
    fclose(file);
    return dataset;
}

void print_dataset(Dataset *dataset) {
    printf("Dataset size: %d\n", dataset->size);
    for (int i = 0; i < dataset->size; i++) {
        printf("%d ", dataset->data[i]);
    }
    printf("\n");
}

Pattern *generate_pattern(int size) {
    Pattern *pattern = malloc(sizeof(Pattern));
    pattern->size = size;
    pattern->data = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        pattern->data[i] = rand() % 10;
    }
    return pattern;
}

void print_pattern(Pattern *pattern) {
    printf("Pattern size: %d\n", pattern->size);
    for (int i = 0; i < pattern->size; i++) {
        printf("%d ", pattern->data[i]);
    }
    printf("\n");
}

Patterns *generate_patterns(int size, int num_patterns) {
    Patterns *patterns = malloc(sizeof(Patterns));
    patterns->size = num_patterns;
    patterns->patterns = malloc(sizeof(Pattern) * num_patterns);
    for (int i = 0; i < num_patterns; i++) {
        patterns->patterns[i] = *generate_pattern(size);
    }
    return patterns;
}

void print_patterns(Patterns *patterns) {
    printf("Patterns size: %d\n", patterns->size);
    for (int i = 0; i < patterns->size; i++) {
        print_pattern(&patterns->patterns[i]);
    }
}

bool match_pattern(Pattern *pattern, Dataset *dataset) {
    for (int i = 0; i < pattern->size; i++) {
        if (pattern->data[i] != dataset->data[i]) {
            return false;
        }
    }
    return true;
}

Patterns *mine_patterns(Dataset *dataset, int pattern_size, int num_patterns) {
    Patterns *patterns = generate_patterns(pattern_size, num_patterns);
    for (int i = 0; i < patterns->size; i++) {
        for (int j = 0; j < dataset->size; j++) {
            if (match_pattern(&patterns->patterns[i], &dataset->data[j])) {
                patterns->patterns[i].data[patterns->patterns[i].size++] = dataset->data[j];
            }
        }
    }
    return patterns;
}

void print_mined_patterns(Patterns *patterns) {
    printf("Mined patterns:\n");
    for (int i = 0; i < patterns->size; i++) {
        print_pattern(&patterns->patterns[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <dataset file> <pattern size> <num patterns>\n", argv[0]);
        exit(1);
    }
    Dataset *dataset = read_dataset(argv[1]);
    int pattern_size = atoi(argv[2]);
    int num_patterns = atoi(argv[3]);
    Patterns *patterns = mine_patterns(dataset, pattern_size, num_patterns);
    print_mined_patterns(patterns);
    return 0;
}