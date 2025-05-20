//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 50
#define MAX_LOGS 100

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
} User;

typedef struct {
    int user_id;
    int day;
    int month;
    int year;
    int steps;
    float distance;
    float calories;
} Log;

int main() {
    User users[MAX_USERS];
    Log logs[MAX_LOGS];

    int user_count = 0;
    int log_count = 0;

    int menu_choice = -1;

    while(menu_choice != 0) {
        printf("========== Fitness Tracker ==========\n");
        printf("1. Add User\n");
        printf("2. Add Log\n");
        printf("3. View User\n");
        printf("4. View Logs\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &menu_choice);

        if(menu_choice == 1) {
            if(user_count >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
            } else {
                User user;
                printf("Enter user name: ");
                scanf("%s", user.name);
                printf("Enter user age: ");
                scanf("%d", &user.age);
                printf("Enter user height (in meters): ");
                scanf("%f", &user.height);
                printf("Enter user weight (in kg): ");
                scanf("%f", &user.weight);

                users[user_count] = user;
                printf("User created successfully.\n");
                user_count++;
            }
        } else if(menu_choice == 2) {
            if(log_count >= MAX_LOGS) {
                printf("Maximum number of logs reached.\n");
            } else {
                Log log;
                printf("Enter user id: ");
                scanf("%d", &log.user_id);

                if(log.user_id < 0 || log.user_id >= user_count) {
                    printf("Invalid user id.\n");
                    continue;
                }

                printf("Enter day: ");
                scanf("%d", &log.day);
                printf("Enter month: ");
                scanf("%d", &log.month);
                printf("Enter year: ");
                scanf("%d", &log.year);
                printf("Enter number of steps: ");
                scanf("%d", &log.steps);
                printf("Enter distance (in km): ");
                scanf("%f", &log.distance);
                printf("Enter calories burned: ");
                scanf("%f", &log.calories);

                logs[log_count] = log;
                printf("Log added successfully.\n");
                log_count++;
            }
        } else if(menu_choice == 3) {
            printf("Enter user id: ");
            int user_id;
            scanf("%d", &user_id);

            if(user_id < 0 || user_id >= user_count) {
                printf("Invalid user id.\n");
            } else {
                User user = users[user_id];
                printf("================ USER ================\n");
                printf("Name: %s\n", user.name);
                printf("Age: %d\n", user.age);
                printf("Height: %.2f meters\n", user.height);
                printf("Weight: %.2f kg\n", user.weight);
            }
        } else if(menu_choice == 4) {
            printf("Enter user id: ");
            int user_id;
            scanf("%d", &user_id);

            if(user_id < 0 || user_id >= user_count) {
                printf("Invalid user id.\n");
            } else {
                printf("================ LOGS ================\n");
                printf("%10s %12s %12s %12s %12s %12s %12s\n", "Date", "Steps", "Distance", "Calories");
                printf("--------------------------------------\n");

                for(int i = 0; i < log_count; i++) {
                    if(logs[i].user_id == user_id) {
                        printf("%02d/%02d/%04d %12d %12.2f %12.2f\n", logs[i].day, logs[i].month, logs[i].year, logs[i].steps, logs[i].distance, logs[i].calories);
                    }
                }
            }
        } else if(menu_choice == 0) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}