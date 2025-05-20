//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[30];
    int age;
    float weight;
    float height;
    char gender[10];
    int steps;
    int heart_rate;
    time_t last_updated;
} user_data;

void create_user(user_data* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    printf("Enter your height in cm: ");
    scanf("%f", &user->height);
    printf("Enter your gender (male/female): ");
    scanf("%s", user->gender);
    printf("Enter your steps taken today: ");
    scanf("%d", &user->steps);
    printf("Enter your heart rate in bpm: ");
    scanf("%d", &user->heart_rate);
    time(&user->last_updated);
}

void print_user(user_data user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %0.2f kg\n", user.weight);
    printf("Height: %0.2f cm\n", user.height);
    printf("Gender: %s\n", user.gender);
    printf("Steps taken today: %d\n", user.steps);
    printf("Heart rate: %d bpm\n", user.heart_rate);
    printf("Last updated: %s\n", ctime(&user.last_updated));
}

void update_user(user_data* user) {
    printf("Enter your steps taken today: ");
    scanf("%d", &user->steps);
    printf("Enter your heart rate in bpm: ");
    scanf("%d", &user->heart_rate);
    time(&user->last_updated);
}

int main() {
    user_data user;
    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Create user\n");
        printf("2. Print user data\n");
        printf("3. Update user data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_user(&user);
                printf("User created successfully!\n");
                break;
            case 2:
                print_user(user);
                break;
            case 3:
                update_user(&user);
                printf("User data updated successfully!\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
    return 0;
}