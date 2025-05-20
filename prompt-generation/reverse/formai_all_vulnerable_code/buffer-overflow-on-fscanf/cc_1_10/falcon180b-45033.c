//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 1000

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
char words[MAX_WORDS];

void init() {
    FILE *file = fopen("conspiracies.txt", "r");
    if (file == NULL) {
        printf("Error: could not open conspiracies file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_CONSPIRACIES && fscanf(file, "%s %s\n", words, words) == 2) {
        conspiracies[count].name = strdup(words);
        conspiracies[count].description = strdup(words);
        count++;
    }

    fclose(file);
}

void generate_conspiracy() {
    srand(time(NULL));
    int index = rand() % MAX_CONSPIRACIES;

    printf("The %s conspiracy:\n", conspiracies[index].name);
    printf("%s\n", conspiracies[index].description);
}

int main() {
    init();

    int choice;
    do {
        printf("\nEnter 1 to generate a random conspiracy theory or 0 to exit:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            generate_conspiracy();
        }
    } while (choice == 1);

    return 0;
}