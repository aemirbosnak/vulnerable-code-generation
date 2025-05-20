//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight; // in kg
    float height; // in meters
    int steps_today;
    int calories_burned_today;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user();
void display_users();
void update_steps(int user_index);
void record_calories(int user_index);
void calculate_bmi(int user_index);
void display_user_stats(int user_index);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update Steps\n");
        printf("4. Record Calories Burned\n");
        printf("5. Calculate BMI\n");
        printf("6. Display User Stats\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_user(); break;
            case 2: display_users(); break;
            case 3: {
                int user_index;
                printf("Enter user index (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    update_steps(user_index);
                } else {
                    printf("Invalid index. Please try again.\n");
                }
                break;
            }
            case 4: {
                int user_index;
                printf("Enter user index (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    record_calories(user_index);
                } else {
                    printf("Invalid index. Please try again.\n");
                }
                break;
            }
            case 5: {
                int user_index;
                printf("Enter user index (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    calculate_bmi(user_index);
                } else {
                    printf("Invalid index. Please try again.\n");
                }
                break;
            }
            case 6: {
                int user_index;
                printf("Enter user index (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    display_user_stats(user_index);
                } else {
                    printf("Invalid index. Please try again.\n");
                }
                break;
            }
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    User new_user;
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter age: ");
    scanf("%d", &new_user.age);
    printf("Enter weight (kg): ");
    scanf("%f", &new_user.weight);
    printf("Enter height (m): ");
    scanf("%f", &new_user.height);
    new_user.steps_today = 0;
    new_user.calories_burned_today = 0;
    
    users[user_count] = new_user;
    user_count++;
    printf("User added successfully.\n");
}

void display_users() {
    if (user_count == 0) {
        printf("No users to display.\n");
        return;
    }
    printf("\nList of Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("Index: %d, Name: %s, Age: %d\n", i, users[i].name, users[i].age);
    }
}

void update_steps(int user_index) {
    int steps;
    printf("Enter steps taken today: ");
    scanf("%d", &steps);
    users[user_index].steps_today += steps;
    printf("Steps updated successfully for user %s.\n", users[user_index].name);
}

void record_calories(int user_index) {
    int calories;
    printf("Enter calories burned today: ");
    scanf("%d", &calories);
    users[user_index].calories_burned_today += calories;
    printf("Calories updated successfully for user %s.\n", users[user_index].name);
}

void calculate_bmi(int user_index) {
    float bmi = users[user_index].weight / (users[user_index].height * users[user_index].height);
    printf("BMI for user %s: %.2f\n", users[user_index].name, bmi);
}

void display_user_stats(int user_index) {
    printf("\nUser Statistics for %s:\n", users[user_index].name);
    printf("Age: %d\n", users[user_index].age);
    printf("Weight: %.2f kg\n", users[user_index].weight);
    printf("Height: %.2f m\n", users[user_index].height);
    printf("Steps Today: %d\n", users[user_index].steps_today);
    printf("Calories Burned Today: %d\n", users[user_index].calories_burned_today);
}