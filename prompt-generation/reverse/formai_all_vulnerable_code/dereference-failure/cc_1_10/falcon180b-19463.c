//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char *entry;
    int length;
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void generateRandomEntry(int length) {
    char *entry = malloc(length + 1);
    if (entry == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        entry[i] = (char) (rand() % 26 + 'a');
    }

    entry[length] = '\0';

    entries[entryCount++] = (Entry) {.entry = entry,.length = length };
}

void generateRandomTheory() {
    int numEntries = rand() % (MAX_ENTRIES - 1) + 2;
    int totalLength = 0;

    for (int i = 0; i < numEntries; i++) {
        int length = rand() % (MAX_ENTRY_LENGTH - 1) + 1;
        generateRandomEntry(length);
        totalLength += length;
    }

    char *theory = malloc(totalLength + 1);
    if (theory == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    int currentIndex = 0;
    for (int i = 0; i < entryCount; i++) {
        memcpy(theory + currentIndex, entries[i].entry, entries[i].length);
        currentIndex += entries[i].length;
    }

    theory[currentIndex] = '\0';

    printf("Random Conspiracy Theory:\n%s\n", theory);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        generateRandomTheory();
    }

    return 0;
}