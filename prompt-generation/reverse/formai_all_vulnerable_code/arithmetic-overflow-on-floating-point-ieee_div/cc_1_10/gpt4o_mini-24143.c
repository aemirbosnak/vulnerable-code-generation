//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float height; // in meters
    float weight; // in kilograms
} User;

typedef struct {
    float steps;
    float distance; // in kilometers
    float calories; // calories burned
    float heartRate; // current heart rate
} DayRecord;

User user;
DayRecord records[MAX_RECORDS];
int recordCount = 0;

void displayHealthInfo() {
    printf("\n--- Health Information ---\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f m\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);
}

void addDailyRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Maximum records reached. Cannot add more records.\n");
        return;
    }
    
    printf("Enter steps taken today: ");
    scanf("%f", &records[recordCount].steps);
    
    printf("Enter distance traveled (km): ");
    scanf("%f", &records[recordCount].distance);
    
    printf("Enter calories burned: ");
    scanf("%f", &records[recordCount].calories);
    
    printf("Enter current heart rate: ");
    scanf("%f", &records[recordCount].heartRate);
    
    recordCount++;
    printf("Daily record added successfully!\n");
}

void displayAllRecords() {
    if (recordCount == 0) {
        printf("No records available.\n");
        return;
    }
    
    printf("\n--- Daily Records ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Record %d:\n", i + 1);
        printf("Steps: %.2f\n", records[i].steps);
        printf("Distance: %.2f km\n", records[i].distance);
        printf("Calories burned: %.2f\n", records[i].calories);
        printf("Heart Rate: %.2f bpm\n", records[i].heartRate);
        printf("-------------------\n");
    }
}

void calculateBMI() {
    float bmi = user.weight / (user.height * user.height);
    printf("\n--- BMI Calculation ---\n");
    printf("BMI: %.2f\n", bmi);
    if (bmi < 18.5) {
        printf("Category: Underweight\n");
    } else if (bmi < 24.9) {
        printf("Category: Normal weight\n");
    } else if (bmi < 29.9) {
        printf("Category: Overweight\n");
    } else {
        printf("Category: Obesity\n");
    }
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Display Health Info\n");
    printf("2. Add Daily Record\n");
    printf("3. Display All Records\n");
    printf("4. Calculate BMI\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

void initializeUser() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your height (in meters): ");
    scanf("%f", &user.height);
    printf("Please enter your weight (in kilograms): ");
    scanf("%f", &user.weight);
}

int main() {
    initializeUser();
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayHealthInfo();
                break;
            case 2:
                addDailyRecord();
                break;
            case 3:
                displayAllRecords();
                break;
            case 4:
                calculateBMI();
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}