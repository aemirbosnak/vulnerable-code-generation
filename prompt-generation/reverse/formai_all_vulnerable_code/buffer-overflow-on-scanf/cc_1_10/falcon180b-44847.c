//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MIN_HEART_RATE 50
#define MAX_HEART_RATE 200
#define MIN_STEPS 1000
#define MAX_STEPS 10000
#define MIN_CALORIES 100
#define MAX_CALORIES 2000

struct user {
    char name[50];
    int age;
    int weight;
    int height;
    int steps;
    int heart_rate;
    int calories;
};

struct user create_user(void) {
    struct user user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight in kg: ");
    scanf("%d", &user.weight);
    printf("Enter your height in cm: ");
    scanf("%d", &user.height);
    user.steps = 0;
    user.heart_rate = 0;
    user.calories = 0;
    return user;
}

void get_steps(struct user *user) {
    printf("Enter the number of steps you took today: ");
    scanf("%d", &user->steps);
}

void get_heart_rate(struct user *user) {
    printf("Enter your heart rate: ");
    scanf("%d", &user->heart_rate);
}

void get_calories(struct user *user) {
    printf("Enter the number of calories you burned today: ");
    scanf("%d", &user->calories);
}

void display_user(struct user user) {
    printf("\nName: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %d kg\n", user.weight);
    printf("Height: %d cm\n", user.height);
    printf("Steps: %d\n", user.steps);
    printf("Heart rate: %d bpm\n", user.heart_rate);
    printf("Calories burned: %d\n", user.calories);
}

void main() {
    struct user user = create_user();
    get_steps(&user);
    get_heart_rate(&user);
    get_calories(&user);
    display_user(user);
}