//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOVERS 100

typedef struct Lover {
    char name[50];
    int affectionLevel;
} Lover;

void sortLovers(Lover lovers[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(lovers[j].affectionLevel < lovers[j + 1].affectionLevel) {
                Lover temp = lovers[j];
                lovers[j] = lovers[j + 1];
                lovers[j + 1] = temp;
            }
        }
    }
}

void displayLovers(Lover lovers[], int n) {
    printf("\nThe Lovers and their Affection Levels:\n");
    for(int i = 0; i < n; i++) {
        printf("%s: %d\n", lovers[i].name, lovers[i].affectionLevel);
    }
}

void chooseLovers(Lover lovers[], int n) {
    int totalChosen = 0;
    printf("\nChoosing the top lovers based on their affection levels...\n");

    for(int i = 0; i < n; i++) {
        if(lovers[i].affectionLevel > 0) {
            printf("%s has been chosen with affection level %d!\n", lovers[i].name, lovers[i].affectionLevel);
            totalChosen++;
        } 
        if (totalChosen >= 5) break; // Only choose top 5
    }

    if (totalChosen == 0) {
        printf("Alas! No lover has been chosen.\n");
    }
}

int main() {
    Lover lovers[MAX_LOVERS];
    int numberOfLovers;

    printf("Enter the number of lovers in Verona: ");
    scanf("%d", &numberOfLovers);

    if (numberOfLovers > MAX_LOVERS) {
        printf("We cannot accept more than %d lovers in this tale.\n", MAX_LOVERS);
        return 1;
    }

    for(int i = 0; i < numberOfLovers; i++) {
        printf("Enter the name of lover %d: ", i + 1);
        scanf("%s", lovers[i].name);
        printf("Enter the affection level for %s (0-100): ", lovers[i].name);
        scanf("%d", &lovers[i].affectionLevel);
    }

    printf("\nThe gathering of Lovers has commenced...\n");
    displayLovers(lovers, numberOfLovers);

    sortLovers(lovers, numberOfLovers);
    printf("The Lovers have been sorted based on affection level:\n");
    displayLovers(lovers, numberOfLovers);

    chooseLovers(lovers, numberOfLovers);

    printf("\nThus, the tale of love unfolds...\n");
    printf("Let it be known in Verona, that Love conquers all!\n");

    return 0;
}