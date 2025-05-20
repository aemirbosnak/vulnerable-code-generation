//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_KNIGHTS 100

// Structure to hold the knight's details
struct Knight {
    char name[50];
    int valor; // Valor represents the knight's bravery score
};

// Function to compare two knights based on their valor
int compareKnights(const void *a, const void *b) {
    struct Knight *knightA = (struct Knight *)a;
    struct Knight *knightB = (struct Knight *)b;
    return knightB->valor - knightA->valor; // Sort in descending order of valor
}

// Function to read knight details
void readKnights(struct Knight knights[], int *count) {
    printf("Enter the number of knights (max %d): ", MAX_KNIGHTS);
    scanf("%d", count);

    if (*count > MAX_KNIGHTS) {
        printf("Too many knights! Limiting to %d.\n", MAX_KNIGHTS);
        *count = MAX_KNIGHTS;
    }

    for (int i = 0; i < *count; i++) {
        printf("Enter the name of knight %d: ", i + 1);
        scanf("%s", knights[i].name);
        printf("Enter the valor of knight %d: ", i + 1);
        scanf("%d", &knights[i].valor);
    }
}

// Function to display the sorted knights
void displayKnights(const struct Knight knights[], int count) {
    printf("\nKnights sorted by valor in descending order:\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Knight Name: %s, Valor: %d\n", knights[i].name, knights[i].valor);
    }
    printf("-----------------------------------------------------\n");
}

// Main function - the grand hall of valor
int main() {
    struct Knight knights[MAX_KNIGHTS];
    int count;

    printf("Welcome to the Realm of Valor!\n");
    printf("Gathering the bravest knights...\n");

    readKnights(knights, &count);

    // The knights engage in a sorting battle for the glory
    printf("\nAssembling for the sorting battle...\n");
    qsort(knights, count, sizeof(struct Knight), compareKnights);

    // Display the mightiest knights
    displayKnights(knights, count);

    printf("The battle of valor concludes. May the finest knights lead our kingdom!\n");
    
    return 0;
}