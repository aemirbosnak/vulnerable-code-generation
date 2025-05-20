//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a knight's information
typedef struct Knight {
    char name[50];
    int age;
    float weight;
    float height;
    int steps_today;
    float distance_travelled; // in miles
    int quests_completed;
} Knight;

// Function to initialize a Knight
void initialize_knight(Knight *knight, const char *name, int age, float weight, float height) {
    strcpy(knight->name, name);
    knight->age = age;
    knight->weight = weight;
    knight->height = height;
    knight->steps_today = 0;
    knight->distance_travelled = 0.0;
    knight->quests_completed = 0;
}

// Function to add steps for a knight
void add_steps(Knight *knight, int steps) {
    knight->steps_today += steps;
    knight->distance_travelled += (steps * 0.0005); // Each step is approximately 0.0005 miles
}

// Function to complete a quest
void complete_quest(Knight *knight) {
    knight->quests_completed += 1;
}

// Function to display the knight's stats
void display_knight_stats(Knight *knight) {
    printf("Knight's Name: %s\n", knight->name);
    printf("Age: %d\n", knight->age);
    printf("Weight: %.2f lbs\n", knight->weight);
    printf("Height: %.2f ft\n", knight->height);
    printf("Steps Taken Today: %d\n", knight->steps_today);
    printf("Distance Travelled: %.2f miles\n", knight->distance_travelled);
    printf("Quests Completed: %d\n", knight->quests_completed);
}

int main() {
    Knight arthur;
    
    // Initialize the knight
    initialize_knight(&arthur, "Sir Arthur", 30, 180.0, 6.0);
    
    int choice, steps, quests;
    
    // Welcome message
    printf("Welcome to the Medieval Fitness Tracker for Knights!\n");
    
    // Main loop
    do {
        printf("\nChoose thy action:\n");
        printf("1. Add Steps\n");
        printf("2. Complete a Quest\n");
        printf("3. Display Knight Stats\n");
        printf("4. Exit\n");
        printf("Enter thy choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of steps taken: ");
                scanf("%d", &steps);
                add_steps(&arthur, steps);
                printf("Steps added! Sir Arthur now has taken %d steps today!\n", arthur.steps_today);
                break;
                
            case 2:
                printf("How many quests hast thou completed? ");
                scanf("%d", &quests);
                for (int i = 0; i < quests; i++) {
                    complete_quest(&arthur);
                }
                printf("Thou hast completed %d quests! Huzzah!\n", quests);
                break;
                
            case 3:
                display_knight_stats(&arthur);
                break;
            
            case 4:
                printf("Farewell, brave knight!\n");
                break;
                
            default:
                printf("Thy choice is not valid, choose again!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}