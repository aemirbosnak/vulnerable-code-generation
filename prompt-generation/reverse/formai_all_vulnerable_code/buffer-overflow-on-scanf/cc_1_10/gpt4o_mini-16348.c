//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold user data
typedef struct {
    char name[50];
    int age;
    float weight; // in kg
    int steps;
    float distance; // in km
    int calories;   // calories burned
} Survivor;

// Function prototypes
void initializeSurvivor(Survivor *survivor);
void recordActivity(Survivor *survivor);
void displayStats(Survivor *survivor);
void saveData(Survivor *survivor);
void loadData(Survivor *survivor);

int main() {
    Survivor mySurvivor;
    int choice;

    // Load previous survivor data if exists
    loadData(&mySurvivor);

    do {
        printf("\n--- Post-Apocalyptic Fitness Tracker ---\n");
        printf("1. Initialize Survivor\n");
        printf("2. Record Activity\n");
        printf("3. Display Stats\n");
        printf("4. Save Data\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeSurvivor(&mySurvivor);
                break;
            case 2:
                recordActivity(&mySurvivor);
                break;
            case 3:
                displayStats(&mySurvivor);
                break;
            case 4:
                saveData(&mySurvivor);
                break;
            case 5:
                printf("Survivor's journey ends here. Stay strong!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void initializeSurvivor(Survivor *survivor) {
    printf("Enter your name: ");
    scanf("%s", survivor->name);
    printf("Enter your age: ");
    scanf("%d", &survivor->age);
    printf("Enter your weight (kg): ");
    scanf("%f", &survivor->weight);
    
    // Initialize other fields
    survivor->steps = 0;
    survivor->distance = 0.0f;
    survivor->calories = 0;

    printf("Welcome %s, you are now ready to survive!\n", survivor->name);
}

void recordActivity(Survivor *survivor) {
    int steps;
    float distance;
    printf("Enter steps taken today: ");
    scanf("%d", &steps);
    printf("Enter distance covered today (km): ");
    scanf("%f", &distance);

    // Update survivor statistics
    survivor->steps += steps;
    survivor->distance += distance;
    // Rough estimate of calories burned
    survivor->calories += (int)(steps * 0.05) + (int)(distance * 100);

    printf("Activity recorded! Keep fighting the good fight, %s!\n", survivor->name);
}

void displayStats(Survivor *survivor) {
    printf("\n--- Survivor Stats ---\n");
    printf("Name: %s\n", survivor->name);
    printf("Age: %d\n", survivor->age);
    printf("Weight: %.2f kg\n", survivor->weight);
    printf("Total Steps: %d\n", survivor->steps);
    printf("Total Distance: %.2f km\n", survivor->distance);
    printf("Total Calories Burned: %d\n", survivor->calories);
}

void saveData(Survivor *survivor) {
    FILE *file = fopen("survivor_data.txt", "w");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }

    fprintf(file, "%s\n%d\n%.2f\n%d\n%.2f\n%d\n", 
            survivor->name, survivor->age, survivor->weight, 
            survivor->steps, survivor->distance, survivor->calories);
    
    fclose(file);
    printf("Survivor data saved successfully!\n");
}

void loadData(Survivor *survivor) {
    FILE *file = fopen("survivor_data.txt", "r");
    if (file != NULL) {
        fscanf(file, "%s\n%d\n%f\n%d\n%f\n%d\n",
               survivor->name, &survivor->age, &survivor->weight,
               &survivor->steps, &survivor->distance, &survivor->calories);
        fclose(file);
        printf("Previous survivor data loaded successfully!\n");
    } else {
        printf("No previous data found. Prepare for your journey!\n");
        survivor->steps = 0;
        survivor->distance = 0.0f;
        survivor->calories = 0;
    }
}