//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.141592653

struct user {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    float heart_rate;
};

void get_user_info(struct user *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);

    printf("Enter your height in cm: ");
    scanf("%f", &user->height);

    user->bmi = user->weight / (user->height * user->height) * 10000;

    printf("Your BMI is %.2f\n", user->bmi);
}

void get_heart_rate(struct user *user) {
    int count = 0;
    float sum = 0.0;

    printf("Enter your heart rate in beats per minute: ");
    scanf("%f", &user->heart_rate);

    while (count < 10) {
        sum += user->heart_rate;
        count++;
    }

    user->heart_rate = sum / 10.0;
}

void display_user_info(struct user user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f kg\n", user.weight);
    printf("Height: %f cm\n", user.height);
    printf("BMI: %.2f\n", user.bmi);
    printf("Heart rate: %.2f bpm\n", user.heart_rate);
}

int main() {
    struct user user;

    get_user_info(&user);
    get_heart_rate(&user);

    display_user_info(user);

    return 0;
}