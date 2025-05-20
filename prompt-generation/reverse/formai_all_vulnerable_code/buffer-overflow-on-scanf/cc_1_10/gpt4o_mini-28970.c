//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLUES 100
#define CLUE_LENGTH 256

void displayClues(char clues[MAX_CLUES][CLUE_LENGTH], int count) {
    printf("\nThe collected clues are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, clues[i]);
    }
}

void swap(char* a, char* b) {
    char temp[CLUE_LENGTH];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void bubbleSort(char clues[MAX_CLUES][CLUE_LENGTH], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(clues[j], clues[j + 1]) > 0) {
                swap(clues[j], clues[j + 1]);
            }
        }
    }
}

int main() {
    char clues[MAX_CLUES][CLUE_LENGTH];
    int count = 0;
    char command[10];

    printf("Sherlock Holmes Detective Agency\n");
    printf("Enter the clues (type 'sort' to sort and display, up to %d clues):\n", MAX_CLUES);

    while (count < MAX_CLUES) {
        printf("Clue %d: ", count + 1);
        scanf(" %[^\n]", clues[count]);

        // Check if the user wants to sort the clues
        if (strcmp(clues[count], "sort") == 0) {
            break; // Exit loop on 'sort'
        }

        count++;
    }

    // Display the clues before sorting
    displayClues(clues, count);

    // Sort the clues
    bubbleSort(clues, count);

    // Display the clues after sorting
    printf("\nAfter sorting, the clues are revealed in order:\n");
    displayClues(clues, count);

    printf("\nWatson, let us reflect on these clues to unravel the mystery behind this case.\n");
    printf("An organized mind is essential to discern the truth from chaos!\n");

    return 0;
}