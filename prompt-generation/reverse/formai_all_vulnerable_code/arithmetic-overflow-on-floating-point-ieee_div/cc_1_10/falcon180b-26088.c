//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int choice;
    double weight, height, bmi, calories_burned;
    char name[50];
    time_t start_time, end_time;
    
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Enter weight\n");
        printf("2. Enter height\n");
        printf("3. Calculate BMI\n");
        printf("4. Calculate calories burned\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter your weight in kg: ");
                scanf("%lf", &weight);
                printf("%s, your weight is %.2lf kg.\n", name, weight);
                break;
            case 2:
                printf("Enter your height in cm: ");
                scanf("%lf", &height);
                printf("%s, your height is %.2lf cm.\n", name, height);
                break;
            case 3:
                printf("Calculating BMI...\n");
                bmi = weight / (height * height);
                printf("%s, your BMI is %.2lf.\n", name, bmi);
                break;
            case 4:
                printf("Enter the duration of your workout in seconds: ");
                scanf("%ld", &calories_burned);
                printf("%s, you burned %.2lf calories in your workout.\n", name, calories_burned);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}