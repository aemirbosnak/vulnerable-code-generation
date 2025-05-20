//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STR_LEN 100

/* Struct to hold user information */
typedef struct {
    char name[MAX_STR_LEN];
    int age;
    int weight;
    int height;
    double bmi;
} User;

/* Function to calculate BMI */
double calculate_bmi(int weight, int height) {
    double bmi = (double)weight / (height * height);
    return bmi;
}

/* Function to compare two users based on their BMI */
int compare_users(const void *a, const void *b) {
    const User *user_a = (const User *)a;
    const User *user_b = (const User *)b;

    if (user_a->bmi > user_b->bmi) {
        return -1;
    } else if (user_a->bmi < user_b->bmi) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to display user information */
void display_user(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %d\n", user.weight);
    printf("Height: %d\n", user.height);
    printf("BMI: %.2f\n\n", user.bmi);
}

int main(void) {
    int num_users;
    User users[MAX_STR_LEN];

    printf("Enter the number of users: ");
    scanf("%d", &num_users);

    /* Get user information */
    for (int i = 0; i < num_users; i++) {
        printf("Enter information for user %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]", users[i].name);
        users[i].age = rand() % 100;
        users[i].weight = rand() % 200;
        users[i].height = rand() % 100;
        users[i].bmi = calculate_bmi(users[i].weight, users[i].height);
    }

    /* Sort users by BMI */
    qsort(users, num_users, sizeof(User), compare_users);

    /* Display user information */
    printf("User information sorted by BMI:\n");
    for (int i = 0; i < num_users; i++) {
        display_user(users[i]);
    }

    return 0;
}