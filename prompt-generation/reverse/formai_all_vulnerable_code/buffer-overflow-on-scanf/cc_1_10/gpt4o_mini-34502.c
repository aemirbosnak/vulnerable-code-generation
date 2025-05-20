//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate the percentage of survivors based on current supplies
double calculateSurvivorPercentage(int foodSupply, int waterSupply, int medicineSupply) {
    double foodFactor = foodSupply > 0 ? 0.5 : 0;  // Each unit of food increases survival odds
    double waterFactor = waterSupply > 0 ? 0.3 : 0; // Each unit of water increases survival odds
    double medicineFactor = medicineSupply > 0 ? 0.2 : 0; // Each unit of medicine increases survival odds

    double percentage = (foodFactor + waterFactor + medicineFactor) * 100;
    return percentage > 100 ? 100 : percentage; // Cap at 100%
}

// Function to generate materials for the survivors
void generateSupplies(int *food, int *water, int *medicine) {
    *food = rand() % 100;       // Random food supply between 0 to 99
    *water = rand() % 100;      // Random water supply between 0 to 99
    *medicine = rand() % 100;   // Random medicine supply between 0 to 99
}

// Function to print supply status
void printStatus(int food, int water, int medicine, double survivorPercentage) {
    printf("\nSupplies Status:\n");
    printf("Food Supply: %d units\n", food);
    printf("Water Supply: %d units\n", water);
    printf("Medicine Supply: %d units\n", medicine);
    printf("Estimated Survivor Percentage: %.2f%%\n", survivorPercentage);
}

// Function to check if survivors can scavenge more supplies
void scavengeSupplies(int *food, int *water, int *medicine) {
    printf("\nScavenging the deserted wasteland...\n");
    *food += rand() % 50; // Finds 0 to 49 more food
    *water += rand() % 50; // Finds 0 to 49 more water
    *medicine += rand() % 20; // Finds 0 to 19 more medicine

    printf("Scavenging complete!\n");
}

// Function to simulate time passage and potential depletion of supplies
void timePassage(int *food, int *water, int *medicine) {
    int consumptionRate = 1; // Generic consumption rate for all supplies
    *food -= consumptionRate;
    *water -= consumptionRate;
    *medicine -= consumptionRate;

    // Ensure supplies do not go negative
    if (*food < 0) *food = 0;
    if (*water < 0) *water = 0;
    if (*medicine < 0) *medicine = 0;
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int foodSupply = 0; // Initial supplies
    int waterSupply = 0;
    int medicineSupply = 0;

    // Generate initial supplies
    generateSupplies(&foodSupply, &waterSupply, &medicineSupply);

    double survivorPercentage = calculateSurvivorPercentage(foodSupply, waterSupply, medicineSupply);
    printStatus(foodSupply, waterSupply, medicineSupply, survivorPercentage);

    // Survivor decides to scavenge for more supplies
    char choice;
    do {
        printf("\nDo you want to scavenge for more supplies? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            scavengeSupplies(&foodSupply, &waterSupply, &medicineSupply);
        }
        
        // Simulate the passage of time
        timePassage(&foodSupply, &waterSupply, &medicineSupply);
        survivorPercentage = calculateSurvivorPercentage(foodSupply, waterSupply, medicineSupply);
        printStatus(foodSupply, waterSupply, medicineSupply, survivorPercentage);

    } while (choice != 'n' && foodSupply > 0);

    // Final thoughts on survival
    printf("\nFinal Status:\n");
    printStatus(foodSupply, waterSupply, medicineSupply, survivorPercentage);
    printf("\nIn this harsh world, survival is never guaranteed...\n");

    return 0;
}