//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
};

void calculateBmi(struct User *user) {
    user->bmi = user->weight / ((user->height / 100) * (user->height / 100));
}

void getRecommendations(struct User *user) {
    if (user->bmi < 18.5) {
        printf("You are underweight. You should consume more calories than you burn.\n");
        printf("Recommended calorie intake: %d\n", (int) (user->bmi * 22 * user->height * user->height / 10000));
    } else if (user->bmi >= 18.5 && user->bmi <= 24.9) {
        printf("You are normal weight. You should aim to maintain your weight.\n");
    } else if (user->bmi >= 25 && user->bmi <= 29.9) {
        printf("You are overweight. You should consume fewer calories than you burn.\n");
        printf("Recommended calorie intake: %d\n", (int) (user->bmi * 22 * user->height * user->height / 10000));
    } else if (user->bmi >= 30) {
        printf("You are obese. You should consume significantly fewer calories than you burn.\n");
        printf("Recommended calorie intake: %d\n", (int) (user->bmi * 22 * user->height * user->height / 10000));
    }
}

int main() {
    struct User user;
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your height in centimeters: ");
    scanf("%f", &user.height);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &user.weight);

    calculateBmi(&user);
    printf("\n\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f cm\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);
    printf("BMI: %.2f\n", user.bmi);

    printf("\n\nRecommendations:\n");
    getRecommendations(&user);

    return 0;
}