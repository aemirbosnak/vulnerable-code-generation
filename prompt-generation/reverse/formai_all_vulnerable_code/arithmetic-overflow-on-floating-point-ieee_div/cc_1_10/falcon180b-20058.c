//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
    int calories;
    time_t timestamp;
} user_t;

void create_user(user_t* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your height in cm: ");
    scanf("%f", &user->height);
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    user->bmi = user->weight / (user->height * user->height);
    printf("Your BMI is %.2f\n", user->bmi);
    user->steps = 0;
    user->calories = 0;
    time(&user->timestamp);
}

void update_steps(user_t* user) {
    printf("Enter the number of steps you took today: ");
    scanf("%d", &user->steps);
}

void update_calories(user_t* user) {
    printf("Enter the number of calories you burned today: ");
    scanf("%d", &user->calories);
}

void view_user(user_t* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %.2f cm\n", user->height);
    printf("Weight: %.2f kg\n", user->weight);
    printf("BMI: %.2f\n", user->bmi);
    printf("Steps: %d\n", user->steps);
    printf("Calories: %d\n", user->calories);
    printf("Last updated on: %s\n", ctime(&user->timestamp));
}

int main() {
    user_t user;
    char choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Create user\n");
        printf("2. Update steps\n");
        printf("3. Update calories\n");
        printf("4. View user\n");
        printf("5. Exit\n");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                create_user(&user);
                break;
            case '2':
                update_steps(&user);
                break;
            case '3':
                update_calories(&user);
                break;
            case '4':
                view_user(&user);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= '5');
    return 0;
}