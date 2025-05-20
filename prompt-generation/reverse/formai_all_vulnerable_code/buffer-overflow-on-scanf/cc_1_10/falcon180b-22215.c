//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>

#define MAX_USERS 10

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
} User;

void addUser(User *users, int numUsers) {
    printf("Enter name: ");
    scanf("%s", &users[numUsers].name);
    printf("Enter age: ");
    scanf("%d", &users[numUsers].age);
    printf("Enter weight (in kg): ");
    scanf("%f", &users[numUsers].weight);
    printf("Enter height (in cm): ");
    scanf("%f", &users[numUsers].height);
    users[numUsers].bmi = users[numUsers].weight / (users[numUsers].height * users[numUsers].height);
    printf("Enter number of steps taken today: ");
    scanf("%d", &users[numUsers].steps);
    numUsers++;
}

void displayUserInfo(User *users, int numUsers) {
    printf("User Information:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Weight: %f kg\n", users[i].weight);
        printf("Height: %f cm\n", users[i].height);
        printf("BMI: %f\n", users[i].bmi);
        printf("Steps taken today: %d\n\n", users[i].steps);
    }
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;

    while (numUsers < MAX_USERS) {
        printf("Enter 1 to add a user, 2 to display user information, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, numUsers);
                break;
            case 2:
                displayUserInfo(users, numUsers);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}