//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ENTRIES 100
#define MAX_STEPS 5000
#define MAX_CALORIES 5000

typedef struct {
    char name[50];
    int steps;
    int calories;
} Entry;

void addEntry(Entry entries[], int numEntries) {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);
    printf("Enter steps: ");
    scanf("%d", &entries[numEntries].steps);
    printf("Enter calories: ");
    scanf("%d", &entries[numEntries].calories);
    numEntries++;
}

void displayEntries(Entry entries[], int numEntries) {
    printf("Name\tSteps\tCalories\n");
    for(int i=0; i<numEntries; i++) {
        printf("%s\t%d\t%d\n", entries[i].name, entries[i].steps, entries[i].calories);
    }
}

void sortEntries(Entry entries[], int numEntries) {
    for(int i=0; i<numEntries-1; i++) {
        for(int j=i+1; j<numEntries; j++) {
            if(entries[i].steps < entries[j].steps) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    while(numEntries < MAX_ENTRIES) {
        addEntry(entries, numEntries);
    }

    sortEntries(entries, numEntries);

    displayEntries(entries, numEntries);

    return 0;
}