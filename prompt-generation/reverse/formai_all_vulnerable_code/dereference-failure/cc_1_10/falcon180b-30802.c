//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_FORTUNES 100
#define MAX_LENGHT 100

// function prototypes
void generateFortune(char *fortune);
int compareFortune(const void *a, const void *b);

int main() {
    char *fortunes[MAX_FORTUNES];
    int numFortunes = 0;
    FILE *file;
    char line[MAX_LENGHT];

    // read fortunes from file
    file = fopen("fortunes.txt", "r");
    if (file == NULL) {
        printf("Error: could not open fortunes file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGHT, file)!= NULL) {
        fortunes[numFortunes] = malloc(strlen(line) + 1);
        strcpy(fortunes[numFortunes], line);
        numFortunes++;
    }

    fclose(file);

    // sort fortunes alphabetically
    qsort(fortunes, numFortunes, sizeof(char *), compareFortune);

    // generate random fortune
    srand(time(NULL));
    int index = rand() % numFortunes;
    printf("Your fortune: %s\n", fortunes[index]);

    for (int i = 0; i < numFortunes; i++) {
        free(fortunes[i]);
    }

    return 0;
}

void generateFortune(char *fortune) {
    // TODO: generate a random fortune and store it in the given string
}

int compareFortune(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}