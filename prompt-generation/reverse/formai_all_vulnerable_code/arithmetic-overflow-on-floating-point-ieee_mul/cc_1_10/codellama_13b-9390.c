//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

struct user {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    float target_weight;
    float target_height;
};

void print_user(struct user *u) {
    printf("Name: %s\n", u->name);
    printf("Age: %d\n", u->age);
    printf("Weight: %f kg\n", u->weight);
    printf("Height: %f cm\n", u->height);
    printf("BMI: %f\n", u->bmi);
    printf("Target Weight: %f kg\n", u->target_weight);
    printf("Target Height: %f cm\n", u->target_height);
}

int main() {
    struct user users[MAX_USERS];
    int num_users = 0;
    int i, j;

    while (1) {
        printf("Enter user name: ");
        scanf("%s", &users[num_users].name);
        printf("Enter user age: ");
        scanf("%d", &users[num_users].age);
        printf("Enter user weight (kg): ");
        scanf("%f", &users[num_users].weight);
        printf("Enter user height (cm): ");
        scanf("%f", &users[num_users].height);
        users[num_users].bmi = users[num_users].weight / (users[num_users].height * users[num_users].height);
        printf("Enter target weight (kg): ");
        scanf("%f", &users[num_users].target_weight);
        printf("Enter target height (cm): ");
        scanf("%f", &users[num_users].target_height);

        num_users++;

        if (num_users == MAX_USERS) {
            break;
        }
    }

    for (i = 0; i < num_users; i++) {
        printf("\nUser %d:\n", i + 1);
        print_user(&users[i]);
    }

    return 0;
}