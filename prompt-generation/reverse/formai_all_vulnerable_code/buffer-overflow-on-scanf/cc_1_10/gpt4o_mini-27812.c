//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float height; // in centimeters
    float weight; // in kilograms
    float distance; // in kilometers
    float calories; // burned calories
} User;

typedef struct {
    User users[MAX_RECORDS];
    int count;
} FitnessTracker;

void init_fitness_tracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void add_user(FitnessTracker *tracker, char *name, int age, float height, float weight) {
    if (tracker->count < MAX_RECORDS) {
        User new_user;
        strncpy(new_user.name, name, NAME_LENGTH);
        new_user.age = age;
        new_user.height = height;
        new_user.weight = weight;
        new_user.distance = 0.0;
        new_user.calories = 0.0;
        
        tracker->users[tracker->count] = new_user;
        tracker->count++;
    } else {
        printf("User limit reached. Cannot add more users.\n");
    }
}

void record_activity(FitnessTracker *tracker, int user_index, float distance, float calories_burned) {
    if (user_index < 0 || user_index >= tracker->count) {
        printf("Invalid user index provided.\n");
        return;
    }
    
    tracker->users[user_index].distance += distance;
    tracker->users[user_index].calories += calories_burned;
}

void display_user_info(FitnessTracker *tracker, int user_index) {
    if (user_index < 0 || user_index >= tracker->count) {
        printf("Invalid user index provided.\n");
        return;
    }

    User user = tracker->users[user_index];
    printf("User Information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f cm\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Total Distance: %.2f km\n", user.distance);
    printf("Total Calories Burned: %.2f cal\n", user.calories);
}

void display_all_users(FitnessTracker *tracker) {
    printf("Fitness Tracker Users:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("[%d] %s\n", i, tracker->users[i].name);
    }
}

void save_data_to_file(FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }
    fwrite(tracker, sizeof(FitnessTracker), 1, file);
    fclose(file);
    printf("Data saved to %s\n", filename);
}

void load_data_from_file(FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }
    fread(tracker, sizeof(FitnessTracker), 1, file);
    fclose(file);
    printf("Data loaded from %s\n", filename);
}

int main() {
    FitnessTracker tracker;
    init_fitness_tracker(&tracker);

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Record Activity\n");
        printf("3. Display User Info\n");
        printf("4. Display All Users\n");
        printf("5. Save Data\n");
        printf("6. Load Data\n");
        printf("0. Exit\n");
        printf("Choose an option (0-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                int age;
                float height, weight;
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter height (cm): ");
                scanf("%f", &height);
                printf("Enter weight (kg): ");
                scanf("%f", &weight);
                add_user(&tracker, name, age, height, weight);
                break;
            }
            case 2: {
                int user_index;
                float distance, calories;
                printf("Enter user index: ");
                scanf("%d", &user_index);
                printf("Enter distance (km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%f", &calories);
                record_activity(&tracker, user_index, distance, calories);
                break;
            }
            case 3: {
                int user_index;
                printf("Enter user index: ");
                scanf("%d", &user_index);
                display_user_info(&tracker, user_index);
                break;
            }
            case 4:
                display_all_users(&tracker);
                break;
            case 5: {
                char filename[100];
                printf("Enter filename to save data: ");
                scanf("%s", filename);
                save_data_to_file(&tracker, filename);
                break;
            }
            case 6: {
                char filename[100];
                printf("Enter filename to load data: ");
                scanf("%s", filename);
                load_data_from_file(&tracker, filename);
                break;
            }
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}