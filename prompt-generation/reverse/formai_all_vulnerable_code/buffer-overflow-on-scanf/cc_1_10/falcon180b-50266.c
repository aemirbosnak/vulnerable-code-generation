//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct User {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
};

int main() {
    int choice;
    struct User user;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Create User\n2. View User\n3. Edit User\n4. Delete User\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", user.name);
            printf("Enter age: ");
            scanf("%d", &user.age);
            printf("Enter weight (in kg): ");
            scanf("%f", &user.weight);
            printf("Enter height (in cm): ");
            scanf("%f", &user.height);
            user.bmi = user.weight / (user.height * user.height);
            printf("\nUser %s created!\n", user.name);
            break;
        case 2:
            printf("User name: %s\n", user.name);
            printf("User age: %d\n", user.age);
            printf("User weight: %f kg\n", user.weight);
            printf("User height: %f cm\n", user.height);
            printf("User BMI: %f\n", user.bmi);
            break;
        case 3:
            printf("Enter name: ");
            scanf("%s", user.name);
            printf("Enter age: ");
            scanf("%d", &user.age);
            printf("Enter weight (in kg): ");
            scanf("%f", &user.weight);
            printf("Enter height (in cm): ");
            scanf("%f", &user.height);
            user.bmi = user.weight / (user.height * user.height);
            printf("\nUser %s edited!\n", user.name);
            break;
        case 4:
            printf("\nUser %s deleted!\n", user.name);
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}