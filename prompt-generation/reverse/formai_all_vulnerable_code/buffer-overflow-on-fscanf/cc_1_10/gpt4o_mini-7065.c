//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float calories;
    float distance;
    int steps;
    time_t date;
} Activity;

Activity activities[MAX_ENTRIES];
int activity_count = 0;

void add_activity();
void view_activities();
void search_activity();
void delete_activity();
void display_menu();
void save_to_file();
void load_from_file();

int main() {
    load_from_file();
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_activity();
                break;
            case 2:
                view_activities();
                break;
            case 3:
                search_activity();
                break;
            case 4:
                delete_activity();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void display_menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Activity\n");
    printf("2. View Activities\n");
    printf("3. Search Activity\n");
    printf("4. Delete Activity\n");
    printf("5. Save Activities\n");
    printf("6. Exit\n");
}

void add_activity() {
    if (activity_count >= MAX_ENTRIES) {
        printf("Activity log is full!\n");
        return;
    }

    Activity new_activity;
    printf("Enter activity name: ");
    getchar(); // consume newline
    fgets(new_activity.name, NAME_LEN, stdin);
    new_activity.name[strcspn(new_activity.name, "\n")] = 0; // remove newline

    printf("Enter calories burned: ");
    scanf("%f", &new_activity.calories);

    printf("Enter distance walked (in km): ");
    scanf("%f", &new_activity.distance);

    printf("Enter number of steps: ");
    scanf("%d", &new_activity.steps);

    new_activity.date = time(NULL);
    activities[activity_count++] = new_activity;

    printf("Activity added successfully!\n");
}

void view_activities() {
    if (activity_count == 0) {
        printf("No activities logged.\n");
        return;
    }

    printf("\nActivity Log:\n");
    for (int i = 0; i < activity_count; i++) {
        printf("Activity %d: %s\n", i + 1, activities[i].name);
        printf("Calories: %.2f, Distance: %.2f km, Steps: %d, Date: %s", 
            activities[i].calories, 
            activities[i].distance, 
            activities[i].steps, 
            ctime(&activities[i].date));
    }
}

void search_activity() {
    if (activity_count == 0) {
        printf("No activities logged.\n");
        return;
    }

    char search_name[NAME_LEN];
    printf("Enter activity name to search: ");
    getchar(); // consume newline
    fgets(search_name, NAME_LEN, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // remove newline

    for (int i = 0; i < activity_count; i++) {
        if (strcasecmp(activities[i].name, search_name) == 0) {
            printf("Found Activity: %s\n", activities[i].name);
            printf("Calories: %.2f, Distance: %.2f km, Steps: %d, Date: %s", 
                activities[i].calories, 
                activities[i].distance, 
                activities[i].steps, 
                ctime(&activities[i].date));
            return;
        }
    }
    printf("Activity not found.\n");
}

void delete_activity() {
    if (activity_count == 0) {
        printf("No activities logged.\n");
        return;
    }

    int index;
    printf("Enter the index of the activity to delete (1 to %d): ", activity_count);
    scanf("%d", &index);

    if (index < 1 || index > activity_count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index - 1; i < activity_count - 1; i++) {
        activities[i] = activities[i + 1];
    }
    activity_count--;
    printf("Activity deleted successfully.\n");
}

void save_to_file() {
    FILE *file = fopen("activity_log.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < activity_count; i++) {
        fprintf(file, "%s,%f,%f,%d,%ld\n", 
            activities[i].name, 
            activities[i].calories, 
            activities[i].distance, 
            activities[i].steps, 
            activities[i].date);
    }
    fclose(file);
    printf("Activities saved to file successfully.\n");
}

void load_from_file() {
    FILE *file = fopen("activity_log.txt", "r");
    if (file == NULL) {
        printf("No previous activity log found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%49[^,],%f,%f,%d,%ld\n", 
            activities[activity_count].name, 
            &activities[activity_count].calories, 
            &activities[activity_count].distance, 
            &activities[activity_count].steps, 
            &activities[activity_count].date) != EOF) {
        activity_count++;
    }
    fclose(file);
    printf("Activities loaded from file successfully.\n");
}