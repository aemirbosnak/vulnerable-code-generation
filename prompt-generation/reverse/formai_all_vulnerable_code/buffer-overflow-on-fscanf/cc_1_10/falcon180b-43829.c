//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

// Structure for holding fortunes
typedef struct {
    char text[80];
    int length;
} Fortune;

// Function prototypes
void loadFortunes(Fortune fortunes[]);
Fortune getRandomFortune(Fortune fortunes[], int numFortunes);

int main() {
    Fortune fortunes[MAX_FORTUNES];
    int numFortunes = 0;

    // Load fortunes from file
    loadFortunes(fortunes);
    numFortunes = sizeof(fortunes) / sizeof(Fortune);

    srand(time(NULL));
    int choice = rand() % numFortunes;

    Fortune randomFortune = getRandomFortune(fortunes, numFortunes);

    printf("Your fortune: %s\n", randomFortune.text);

    return 0;
}

// Loads fortunes from file into array
void loadFortunes(Fortune fortunes[]) {
    FILE *file = fopen("fortunes.txt", "r");

    if (file == NULL) {
        printf("Error loading fortunes.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", fortunes[i].text)!= EOF) {
        fortunes[i].length = strlen(fortunes[i].text);
        i++;
    }

    fclose(file);
}

// Returns a random fortune from the array
Fortune getRandomFortune(Fortune fortunes[], int numFortunes) {
    int index = rand() % numFortunes;
    return fortunes[index];
}