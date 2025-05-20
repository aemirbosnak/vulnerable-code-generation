//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance;
    float calories;
} FitnessRecord;

FitnessRecord records[MAX_RECORDS];
int record_count = 0;

// Function to add a new fitness record
void addRecord() {
    if (record_count >= MAX_RECORDS) {
        printf("Whoa! You've reached the maximum number of fitness records!\n");
        return;
    }
    FitnessRecord new_record;

    printf("Enter your name: ");
    scanf("%s", new_record.name);

    printf("Great! Now, how many steps did you walk today? ");
    scanf("%d", &new_record.steps);
    
    printf("Awesome! How far did you walk in kilometers? ");
    scanf("%f", &new_record.distance);
    
    printf("Fantastic! How many calories did you burn? ");
    scanf("%f", &new_record.calories);

    records[record_count++] = new_record;

    printf("Record added! Keep up the fantastic work, %s!\n", new_record.name);
}

// Function to display all fitness records
void displayRecords() {
    if (record_count == 0) {
        printf("Oh no! You have no fitness records yet. Let's add some!\n");
        return;
    }

    printf("\nYour Fitness Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("Record #%d:\n", i + 1);
        printf("Name: %s\n", records[i].name);
        printf("Steps: %d\n", records[i].steps);
        printf("Distance: %.2f km\n", records[i].distance);
        printf("Calories Burned: %.2f kcal\n", records[i].calories);
        printf("----------------------\n");
    }
}

// Function to calculate total statistics
void calculateTotalStats() {
    int total_steps = 0;
    float total_distance = 0.0;
    float total_calories = 0.0;

    for (int i = 0; i < record_count; i++) {
        total_steps += records[i].steps;
        total_distance += records[i].distance;
        total_calories += records[i].calories;
    }

    printf("Total Steps: %d\n", total_steps);
    printf("Total Distance: %.2f km\n", total_distance);
    printf("Total Calories Burned: %.2f kcal\n", total_calories);
}

// Function to display the menu
void displayMenu() {
    printf("\n~~~ Welcome to Your Fitness Tracker! ~~~\n");
    printf("1. Add a Fitness Record\n");
    printf("2. Display Fitness Records\n");
    printf("3. Calculate Total Statistics\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                calculateTotalStats();
                break;
            case 4:
                printf("Thank you for using the Fitness Tracker! Keep moving and stay healthy!\n");
                break;
            default:
                printf("Oops! That's not a valid option. Please try again!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}