//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_LOG_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
    float weight;
    float bmi;
    float target_weight;
} User;

typedef struct {
    User user;
    float calories_burned_today;
    float steps_today;
} DailyLogEntry;

typedef struct {
    DailyLogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries;
} WeeklyLog;

float calculate_bmi(float height, float weight) {
    return weight / (height * height);
}

void create_user(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    
    printf("Enter your age: ");
    scanf("%d", &user->age);
    
    printf("Enter your height (in meters): ");
    scanf("%f", &user->height);
    
    printf("Enter your weight (in kg): ");
    scanf("%f", &user->weight);
    
    user->bmi = calculate_bmi(user->height, user->weight);
    
    printf("Enter your target weight (in kg): ");
    scanf("%f", &user->target_weight);
}

void log_today(DailyLogEntry* log_entry) {
    printf("Enter calories burned today: ");
    scanf("%f", &log_entry->calories_burned_today);
    
    printf("Enter steps taken today: ");
    scanf("%f", &log_entry->steps_today);
}

void display_user_info(User user) {
    printf("\nName: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height (m): %.2f\n", user.height);
    printf("Weight (kg): %.2f\n", user.weight);
    printf("BMI: %.2f\n", user.bmi);
    printf("Target Weight (kg): %.2f\n\n", user.target_weight);
}

void display_weekly_log(WeeklyLog log) {
    if (log.num_entries == 0) {
        printf("No entries yet\n");
        return;
    }
    
    for (int i = 0; i < log.num_entries; i++) {
        printf("Day %d:\n", i+1);
        printf("Calories Burned Today: %.2f\n", log.log_entries[i].calories_burned_today);
        printf("Steps Taken Today: %.2f\n", log.log_entries[i].steps_today);
        printf("-----------------------------------\n");
    }
}

int main() {
    User user;
    create_user(&user);
    
    WeeklyLog weekly_log;
    weekly_log.num_entries = 0;
    
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Log today's data\n");
        printf("2. Display user info\n");
        printf("3. Display weekly log\n");
        printf("4. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                time_t t = time(NULL);
                struct tm* current_time = localtime(&t);
                
                DailyLogEntry log_entry;
                log_today(&log_entry);
                weekly_log.log_entries[ weekly_log.num_entries ] = log_entry;
                weekly_log.num_entries++;

                printf("Data for Day %d logged!\n", weekly_log.num_entries);
                break;
            }
            case 2: {
                display_user_info(user);
                break;
            }
            case 3: {
                display_weekly_log(weekly_log);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }
}