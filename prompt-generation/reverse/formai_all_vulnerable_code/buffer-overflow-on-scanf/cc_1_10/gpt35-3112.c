//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct User{
    char name[50];
    int age;
    char gender[10];
    double height;
    double weight;
    double bmi;
};

typedef struct User User;

void createUser(User *newUser){
    printf("Enter name: ");
    fgets(newUser->name, sizeof(newUser->name), stdin);

    printf("Enter age: ");
    scanf("%d", &newUser->age);
    getchar();

    printf("Enter gender (Male/Female): ");
    fgets(newUser->gender, sizeof(newUser->gender), stdin);

    printf("Enter height in meters: ");
    scanf("%lf", &newUser->height);
    getchar();

    printf("Enter weight in kg: ");
    scanf("%lf", &newUser->weight);
    getchar();

    double bmi = newUser->weight / (newUser->height * newUser->height);

    printf("\n------------------------------------------\n");
    printf("USER CREATED: \n");
    printf("Name: %s", newUser->name);
    printf("Age: %d\n", newUser->age);
    printf("Gender: %s", newUser->gender);
    printf("Height: %.2lf m\n", newUser->height);
    printf("Weight: %.2lf kg\n", newUser->weight);
    printf("BMI: %.2lf\n", bmi);
    printf("------------------------------------------\n");

    newUser->bmi = bmi;

    printf("Press enter to continue...");
    getchar();
}

void displayUser(User user){
    printf("\n------------------------------------------\n");
    printf("USER INFORMATION: \n");
    printf("Name: %s", user.name);
    printf("Age: %d\n", user.age);
    printf("Gender: %s", user.gender);
    printf("Height: %.2lf m\n", user.height);
    printf("Weight: %.2lf kg\n", user.weight);
    printf("BMI: %.2lf\n", user.bmi);
    printf("------------------------------------------\n");

    printf("Press enter to continue...");
    getchar();
}

int main(){
    User currentUser;
    int menuChoice;

    printf("FITNESS TRACKER\n");

    printf("------------------------------------------\n");
    printf("1 - Create New User\n");
    printf("2 - Display User Information\n");
    printf("3 - Calculate Calorie Intake\n");
    printf("4 - Record Workout\n");
    printf("5 - Exit\n");
    printf("------------------------------------------\n");

    printf("Enter choice: ");
    scanf("%d", &menuChoice);
    getchar();

    switch(menuChoice){
        case 1:
            createUser(&currentUser);
            break;
        case 2:
            displayUser(currentUser);
            break;
        case 3:
            //TODO: calculate calorie intake
            break;
        case 4:
            //TODO: record workout
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.");
            break;
    }

    return 0;
}