//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>

// Define struct for user data
struct user_data {
    char name[50];
    int age;
    float height;
    float weight;
};

// Function to get user input for name, age, height, and weight
void get_user_data(struct user_data *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your height in meters: ");
    scanf("%f", &user->height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &user->weight);
}

// Function to calculate BMI and print fitness level
void calculate_bmi(struct user_data *user) {
    float bmi = user->weight / (user->height * user->height);
    printf("Your BMI is %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are at a healthy weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }
}

// Function to print user data
void print_user_data(struct user_data *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %f meters\n", user->height);
    printf("Weight: %f kilograms\n", user->weight);
}

int main() {
    struct user_data user;
    get_user_data(&user);
    calculate_bmi(&user);
    print_user_data(&user);

    return 0;
}