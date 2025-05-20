//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct user {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight;
    float height;
    float bmi;
    float calories;
};

void welcome() {
    printf("Welcome to the C Fitness Tracker!\n\n");
}

void menu() {
    printf("Please select an option:\n");
    printf("1. Calculate BMI\n");
    printf("2. Calculate daily caloric intake\n");
    printf("3. Save user data\n");
    printf("4. Load user data\n");
    printf("5. Exit\n\n");
}

void calculate_bmi(struct user *u) {
    u->bmi = (u->weight * 703) / (u->height * u->height);
    printf("Your BMI is %.2f\n\n", u->bmi);
}

void calculate_calories(struct user *u) {
    float bmr;
    printf("Please select your gender:\n");
    printf("1. Male\n");
    printf("2. Female\n\n");
    int gender_choice;
    scanf("%d", &gender_choice);
    switch(gender_choice) {
        case 1:
            bmr = 66 + (6.2 * u->weight) + (12.7 * u->height) - (6.76 * u->age);
            break;
        case 2:
            bmr = 655.1 + (4.35 * u->weight) + (4.7 * u->height) - (4.7 * u->age);
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
    printf("Please select your activity level:\n");
    printf("1. Sedentary\n");
    printf("2. Lightly active (1-3 days/week)\n");
    printf("3. Moderately active (3-5 days/week)\n");
    printf("4. Very active (6-7 days/week)\n");
    printf("5. Super active (twice/day)\n\n");
    int activity_choice;
    scanf("%d", &activity_choice);
    switch(activity_choice) {
        case 1:
            u->calories = bmr * 1.2;
            break;
        case 2:
            u->calories = bmr * 1.375;
            break;
        case 3:
            u->calories = bmr * 1.55;
            break;
        case 4:
            u->calories = bmr * 1.725;
            break;
        case 5:
            u->calories = bmr * 1.9;
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
    printf("Your daily caloric intake is %.2f calories\n\n", u->calories);
}

void save_user(struct user *u) {
    FILE *fptr;
    char filename[MAX_NAME_LENGTH];
    printf("Please enter a file name to save your data: ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fptr, "%s\n%d\n%.2f\n%.2f\n%.2f\n%.2f", u->name, u->age, u->weight, u->height, u->bmi, u->calories);
    fclose(fptr);
    printf("Data saved successfully!\n\n");
}

void load_user(struct user *u) {
    FILE *fptr;
    char filename[MAX_NAME_LENGTH];
    printf("Please enter a file name to load your data: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fptr, "%s\n%d\n%f\n%f\n%f\n%f", u->name, &u->age, &u->weight, &u->height, &u->bmi, &u->calories);
    fclose(fptr);
    printf("Data loaded successfully!\n\n");
}

int main() {
    struct user u;
    welcome();
    while (1) {
        menu();
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Please enter your weight in pounds: ");
                scanf("%f", &u.weight);
                printf("Please enter your height in inches: ");
                scanf("%f", &u.height);
                calculate_bmi(&u);
                break;
            case 2:
                printf("Please enter your weight in pounds: ");
                scanf("%f", &u.weight);
                printf("Please enter your height in inches: ");
                scanf("%f", &u.height);
                printf("Please enter your age in years: ");
                scanf("%d", &u.age);
                calculate_calories(&u);
                break;
            case 3:
                printf("Please enter your name: ");
                scanf("%s", u.name);
                printf("Please enter your age in years: ");
                scanf("%d", &u.age);
                printf("Please enter your weight in pounds: ");
                scanf("%f", &u.weight);
                printf("Please enter your height in inches: ");
                scanf("%f", &u.height);
                save_user(&u);
                break;
            case 4:
                load_user(&u);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}