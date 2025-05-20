//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A love story of two lovers represented by sorting their names based on their beauty.
typedef struct {
    char name[30];
    float beautyScore;
} Lover;

// Function to compare lovers based on beauty score
int compareLovers(const void *a, const void *b) {
    Lover *loverA = (Lover *)a;
    Lover *loverB = (Lover *)b;
    // Compare by beautyScore
    return (loverA->beautyScore < loverB->beautyScore) - (loverA->beautyScore > loverB->beautyScore);
}

// Function to display the lovers and their beauty scores
void displayLovers(Lover *lovers, int count) {
    printf("\nIn the garden of love, we find our hearts...\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Lover's Name: %-20s | Beauty Score: %.2f\n", lovers[i].name, lovers[i].beautyScore);
    }
    printf("-------------------------------------------------\n");
}

// Romantic function to fill details about lovers
void fillLoverDetails(Lover *lovers, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of lover %d: ", i + 1);
        scanf(" %[^\n]", lovers[i].name);
        printf("Assign a beauty score (0.0 to 10.0) to %s: ", lovers[i].name);
        scanf("%f", &lovers[i].beautyScore);
    }
}

// A magical tale function to interact with our lovers
void heartwarmingTale(Lover *lovers, int count) {
    printf("\nAh, love is in the air...\n");
    printf("Let us witness the beauty contest among the lovers:\n");

    // Sorting lovers based on beauty score
    qsort(lovers, count, sizeof(Lover), compareLovers);
    
    displayLovers(lovers, count);
}

int main() {
    int count;

    printf("Welcome to the Love Sorting Garden!\n");
    printf("How many lovers shall we gather today in this romantic tale? ");
    scanf("%d", &count);

    Lover *lovers = malloc(count * sizeof(Lover));
    if (lovers == NULL) {
        fprintf(stderr, "Memory allocation failed! Love cannot blossom without space for our hearts.\n");
        return 1;
    }

    fillLoverDetails(lovers, count);
    heartwarmingTale(lovers, count);
    
    free(lovers);
    printf("Thank you for joining us in this heartfelt journey. Until we meet again...\n");
    
    return 0;
}