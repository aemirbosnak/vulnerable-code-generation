//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_ACTIVITIES 20

typedef struct {
    char name[30];
    int age;
    float weight;
    float height;
} User;

typedef struct {
    char name[30];
    float calories_per_hour;
} Activity;

typedef struct {
    User user;
    Activity activity;
    float duration; // in hours
    int day;
    int month;
    int year;
} Exercise;

User users[MAX_USERS];
int num_users = 0;

Activity activities[MAX_ACTIVITIES];
int num_activities = 0;

Exercise exercises[MAX_ACTIVITIES];
int num_exercises = 0;

int get_user_index(char* name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_activity_index(char* name) {
    for (int i = 0; i < num_activities; i++) {
        if (strcmp(activities[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    
    User user;
    printf("Enter user name: ");
    scanf("%s", &user.name);
    printf("Enter user age: ");
    scanf("%d", &user.age);
    printf("Enter user weight: ");
    scanf("%f", &user.weight);
    printf("Enter user height: ");
    scanf("%f", &user.height);
    
    users[num_users] = user;
    num_users++;
}

void add_activity() {
    if (num_activities == MAX_ACTIVITIES) {
        printf("Maximum number of activities reached.\n");
        return;
    }
    
    Activity activity;
    printf("Enter activity name: ");
    scanf("%s", &activity.name);
    printf("Enter activity calories burned per hour: ");
    scanf("%f", &activity.calories_per_hour);
    
    activities[num_activities] = activity;
    num_activities++;
}

void add_exercise() {
    char user_name[30];
    printf("Enter user name: ");
    scanf("%s", &user_name);
    int user_index = get_user_index(user_name);
    if (user_index == -1) {
        printf("No user found.\n");
        return;
    }
    
    char activity_name[30];
    printf("Enter activity name: ");
    scanf("%s", &activity_name);
    int activity_index = get_activity_index(activity_name);
    if (activity_index == -1) {
        printf("No activity found.\n");
        return;
    }
    
    Exercise exercise;
    exercise.user = users[user_index];
    exercise.activity = activities[activity_index];
    printf("Enter exercise duration (in hours): ");
    scanf("%f", &exercise.duration);
    printf("Enter exercise date (day month year): ");
    scanf("%d %d %d", &exercise.day, &exercise.month, &exercise.year);
    
    exercises[num_exercises] = exercise;
    num_exercises++;
}

void show_user_info() {
    char user_name[30];
    printf("Enter user name: ");
    scanf("%s", &user_name);
    int user_index = get_user_index(user_name);
    if (user_index == -1) {
        printf("No user found.\n");
        return;
    }
    
    User user = users[user_index];
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f\n", user.weight);
    printf("Height: %.2f\n", user.height);
}

void show_activity_info() {
    char activity_name[30];
    printf("Enter activity name: ");
    scanf("%s", &activity_name);
    int activity_index = get_activity_index(activity_name);
    if (activity_index == -1) {
        printf("No activity found.\n");
        return;
    }
    
    Activity activity = activities[activity_index];
    printf("Name: %s\n", activity.name);
    printf("Calories burned per hour: %.2f\n", activity.calories_per_hour);
}

void show_exercise_info() {
    char user_name[30];
    printf("Enter user name: ");
    scanf("%s", &user_name);
    int user_index = get_user_index(user_name);
    if (user_index == -1) {
        printf("No user found.\n");
        return;
    }
    
    printf("Exercises for user %s:\n", user_name);
    for (int i = 0; i < num_exercises; i++) {
        if (strcmp(exercises[i].user.name, user_name) == 0) {
            Exercise exercise = exercises[i];
            printf("Activity: %s\n", exercise.activity.name);
            printf("Duration: %.2f hours\n", exercise.duration);
            printf("Calories burned: %.2f\n", exercise.activity.calories_per_hour * exercise.duration);
            printf("Date: %d/%d/%d\n", exercise.day, exercise.month, exercise.year);
        }
    }
}

void menu() {
    printf("\n");
    printf("1. Add user\n");
    printf("2. Add activity\n");
    printf("3. Add exercise\n");
    printf("4. Show user info\n");
    printf("5. Show activity info\n");
    printf("6. Show exercise info\n");
    printf("7. Exit\n");
    printf("Enter option: ");
}


int main() {
    int option;
    do {
        menu();
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                add_user();
                break;
            case 2:
                add_activity();
                break;
            case 3:
                add_exercise();
                break;
            case 4:
                show_user_info();
                break;
            case 5:
                show_activity_info();
                break;
            case 6:
                show_exercise_info();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 7);
    
    return 0;
}