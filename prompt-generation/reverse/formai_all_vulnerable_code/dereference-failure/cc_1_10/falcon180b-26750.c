//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAMPLES 100

typedef struct {
    char *name;
    size_t size;
} AllocInfo;

static AllocInfo samples[MAX_SAMPLES];
static int numSamples = 0;

void addSample(const char *name, size_t size) {
    if (numSamples >= MAX_SAMPLES) {
        fprintf(stderr, "Error: Maximum number of samples reached.\n");
        exit(1);
    }

    samples[numSamples].name = strdup(name);
    samples[numSamples].size = size;
    numSamples++;
}

void printSamples() {
    printf("Total RAM usage:\n");
    for (int i = 0; i < numSamples; i++) {
        printf("%s: %zu bytes\n", samples[i].name, samples[i].size);
    }
}

int main() {
    char *str1 = malloc(10);
    addSample("String 1", 10);

    char *str2 = malloc(20);
    addSample("String 2", 20);

    char *str3 = malloc(30);
    addSample("String 3", 30);

    free(str1);
    free(str2);
    free(str3);

    printSamples();

    return 0;
}