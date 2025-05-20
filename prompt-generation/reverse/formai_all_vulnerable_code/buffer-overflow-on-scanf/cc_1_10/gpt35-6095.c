//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    float weight;
    float height;
    int age;
    char gender[6];
} UserInfo;

struct ExerciseRecord {
    Date date;
    char activity[20];
    int minutes;
    float caloriesBurned;
};

typedef struct ExerciseRecord ExerciseRecord;

void printMenu() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("1. Enter User Information\n");
    printf("2. Log Exercise\n");
    printf("3. View Exercise Log\n");
    printf("4. Quit\n");
    printf("Choice: ");
}

int getDaysInMonth(int month, int year) {
    int days;
    if(month == 2) {
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            days = 29;
        else
            days = 28;
    } else if(month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else
        days = 31;
    return days;
}

bool isDateValid(int day, int month, int year) {
    if(month < 1 || month > 12)
        return false;

    int daysInMonth = getDaysInMonth(month, year);

    if(day < 1 || day > daysInMonth)
        return false;

    return true;    
}

bool isUserInfoValid(UserInfo userInfo) {
    if(userInfo.weight <= 0)
        return false;

    if(userInfo.height <= 0)
        return false;

    if(userInfo.age < 0 || userInfo.age > 120)
        return false;

    if(strcmp(userInfo.gender, "Male") != 0 && strcmp(userInfo.gender, "Female") != 0)
        return false;

    return true;    
}

ExerciseRecord* logExercise(UserInfo userInfo, ExerciseRecord* exerciseLog, int* count, int* size) {
    Date date;
    int day, month, year;
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    date.day = day;
    date.month = month;
    date.year = year;
    if(!isDateValid(day, month, year)) {
        printf("Invalid date.\n");
        return exerciseLog;
    }

    char activity[20];
    printf("Enter Activity: ");
    scanf("%s", activity);

    int minutes;
    printf("Enter Minutes: ");
    scanf("%d", &minutes);

    float met;
    if(strcmp(activity, "Walking") == 0)
        met = 3.5;
    else if(strcmp(activity, "Running") == 0)
        met = 7.0;
    else if(strcmp(activity, "Swimming") == 0)
        met = 8.0;
    else if(strcmp(activity, "Strength Training") == 0)
        met = 6.0;
    else {
        printf("Invalid activity.\n");
        return exerciseLog;
    }

    float caloriesBurned;
    if(strcmp(userInfo.gender, "Male") == 0)
        caloriesBurned = ((met * 3.5 * userInfo.weight) / 200) * minutes;
    else
       caloriesBurned = ((met * 3.5 * userInfo.weight) / 140) * minutes;

    if(*count == *size) {
        *size *= 2;
        exerciseLog = (ExerciseRecord*)realloc(exerciseLog, (*size) * sizeof(ExerciseRecord));
    }
    exerciseLog[*count].date = date;
    strcpy(exerciseLog[*count].activity, activity);
    exerciseLog[*count].minutes = minutes;
    exerciseLog[*count].caloriesBurned = caloriesBurned;
    (*count)++;

    printf("Exercise successfully logged!\n");
    return exerciseLog;   
}

void displayExerciseLog(ExerciseRecord* exerciseLog, int count) {
    printf("Date\t\tActivity\tMinutes\tCalories Burned\n");
    for(int i = 0; i < count; i++) {
        printf("%d/%d/%d\t%s\t\t%d\t%.2f\n", exerciseLog[i].date.day, 
            exerciseLog[i].date.month, exerciseLog[i].date.year, 
            exerciseLog[i].activity, exerciseLog[i].minutes,
            exerciseLog[i].caloriesBurned);
    }
}

int main() {
    UserInfo userInfo;
    bool userInfoEntered = false;

    ExerciseRecord* exerciseLog = (ExerciseRecord*)malloc(5 * sizeof(ExerciseRecord));
    int count = 0, size = 5;

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Weight (kg): ");
                scanf("%f", &userInfo.weight);
                printf("Enter Height (cm): ");
                scanf("%f", &userInfo.height);
                printf("Enter Age: ");
                scanf("%d", &userInfo.age);
                printf("Enter Gender (Male/Female): ");
                scanf("%s", userInfo.gender);
                if(!isUserInfoValid(userInfo)) {
                    printf("Invalid user information.\n");
                    continue;
                }
                printf("User information successfully entered!\n");
                userInfoEntered = true;
                break;
            case 2:
                if(!userInfoEntered) {
                    printf("User information not entered.\n");
                    continue;
                }
                exerciseLog = logExercise(userInfo, exerciseLog, &count, &size);
                break;
            case 3:
                if(count == 0)
                    printf("No exercise logged.\n");
                else
                    displayExerciseLog(exerciseLog, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while(choice != 4);

    free(exerciseLog);

    return 0;
}