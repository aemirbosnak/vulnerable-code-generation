//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct User {
    char username[20];
    char password[20];
    float weight;
    float height;
};

struct FitnessTracker {
    float weight;
    float height;
    float BMI;
    float daily_calories;
    int daily_water_intake;
};

void newUser() {
    struct User user;
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);
    printf("Enter weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Enter height (in meters): ");
    scanf("%f", &user.height);
    FILE *f = fopen("users.txt", "a");
    fprintf(f, "%s %s %.2f %.2f\n", user.username, user.password, user.weight, user.height);
    fclose(f);
}

bool login(char username[], char password[], struct User users[], int num_users) {
    for(int i=0; i<num_users; i++) {
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return true;
        }
    }
    return false;
}

float calculateBMI(float height, float weight) {
    return weight / (height * height);
}

float calculateDailyCalories(float height, float weight) {
    float BMR;
    // Calculate BMR using Harris-Benedict equation
    BMR = 655 + (9.6 * weight) + (1.8 * height * 100) - (4.7 * 25);
    return BMR * 1.2; // Multiply by activity factor
}

void trackFitness(struct FitnessTracker *tracker) {
    int choice;
    printf("\n1. Track weight\n2. Track height\n3. Track water intake\n4. Exit tracker\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter weight (in kg): ");
            scanf("%f", &tracker->weight);
            tracker->BMI = calculateBMI(tracker->height, tracker->weight);
            tracker->daily_calories = calculateDailyCalories(tracker->height, tracker->weight);
            break;
        case 2:
            printf("Enter height (in meters): ");
            scanf("%f", &tracker->height);
            tracker->BMI = calculateBMI(tracker->height, tracker->weight);
            tracker->daily_calories = calculateDailyCalories(tracker->height, tracker->weight);
            break;
        case 3:
            printf("Enter amount of water drank (in ml): ");
            scanf("%d", &tracker->daily_water_intake);
            break;
        case 4:
            printf("Exiting tracker...\n");
            break;
        default:
            printf("Invalid choice. Try again\n");
    }
}

int main() {
    char username[20], password[20];
    int num_users = 0, i = 0;
    float BMR;
    struct User users[100];
    struct FitnessTracker tracker;
    FILE *f = fopen("users.txt", "r");
    while(!feof(f)) {
        fscanf(f, "%s %s %f %f", users[i].username, users[i].password, &users[i].weight, &users[i].height);
        i++;
        num_users++;
    }
    fclose(f);
    int option;
    printf("1. New User\n2. Existing User\nEnter your choice: ");
    scanf("%d", &option);
    if(option == 1) {
        newUser();
    }
    else if(option == 2) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        if(login(username, password, users, num_users)) {
            printf("Login successful\n");
            tracker.weight = users[i-1].weight;
            tracker.height = users[i-1].height;
            printf("Welcome back %s!\n", username);
            while(true) {
                trackFitness(&tracker);
                printf("\nWeight: %.2f kg\n", tracker.weight);
                printf("Height: %.2f meters\n", tracker.height);
                printf("BMI: %.2f\n", tracker.BMI);
                printf("Daily calorie requirement: %.2f cal\n", tracker.daily_calories);
                printf("Daily water intake: %d ml\n", tracker.daily_water_intake);
                printf("\nPress enter to continue...\n");
                while(getchar() != '\n');
                getchar();
                system("clear");
                if(tracker.daily_calories < 1200 || tracker.daily_water_intake < 2000) {
                    printf("Warning: You might be under-eating or dehydrated. Make sure you are getting enough nutrition and hydration\n");
                }
            }
        }
        else {
            printf("Invalid username/password\n");
        }
    }
    else {
        printf("Invalid choice\n");
    }
    return 0;
}