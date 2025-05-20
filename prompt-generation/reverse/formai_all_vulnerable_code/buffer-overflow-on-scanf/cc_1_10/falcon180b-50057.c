//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct user {
    char name[50];
    int age;
    double weight;
    double height;
    double bmi;
    double heart_rate;
    double steps;
};

int main() {
    int n;
    struct user user[100];

    printf("Enter the number of users: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the name of user %d: ", i + 1);
        scanf("%s", user[i].name);

        printf("Enter the age of user %s: ", user[i].name);
        scanf("%d", &user[i].age);

        printf("Enter the weight (in kg) of user %s: ", user[i].name);
        scanf("%lf", &user[i].weight);

        printf("Enter the height (in cm) of user %s: ", user[i].name);
        scanf("%lf", &user[i].height);

        user[i].bmi = user[i].weight / (user[i].height * user[i].height);

        printf("The BMI of %s is %.2lf\n", user[i].name, user[i].bmi);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the heart rate (in bpm) of user %s: ", user[i].name);
        scanf("%lf", &user[i].heart_rate);

        user[i].steps = user[i].age * 2.0 + (user[i].weight * 0.1) + (user[i].heart_rate * 0.5);

        printf("The recommended number of steps for %s to take per day is %.0lf\n", user[i].name, user[i].steps);
    }

    return 0;
}