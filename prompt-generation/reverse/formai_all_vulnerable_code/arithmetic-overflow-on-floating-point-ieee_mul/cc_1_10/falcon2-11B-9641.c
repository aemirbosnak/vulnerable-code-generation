//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    float progress;
} User;

void add_user(User *users, int max_users, int new_user) {
    if (new_user >= 0 && new_user < max_users) {
        users[new_user].name[0] = '\0';
        printf("Enter name: ");
        fgets(users[new_user].name, sizeof(users[new_user].name), stdin);
        printf("Enter age: ");
        scanf("%d", &users[new_user].age);
        printf("Enter height: ");
        scanf("%f", &users[new_user].height);
        printf("Enter weight: ");
        scanf("%f", &users[new_user].weight);
        users[new_user].bmi = (users[new_user].weight / (users[new_user].height * users[new_user].height)) * 703;
        users[new_user].progress = 0.0;
    }
}

void print_users(User *users, int num_users) {
    for (int i = 0; i < num_users; i++) {
        printf("%s - %d years old, %.2f cm tall, %.2f kg, BMI: %.2f, Progress: %.2f\n", users[i].name, users[i].age, users[i].height, users[i].weight, users[i].bmi, users[i].progress);
    }
}

void update_progress(User *users, int num_users) {
    for (int i = 0; i < num_users; i++) {
        printf("Enter progress for %s: ", users[i].name);
        scanf("%f", &users[i].progress);
    }
}

void compare_users(User *users, int num_users) {
    for (int i = 0; i < num_users; i++) {
        printf("%s - Progress: %.2f\n", users[i].name, users[i].progress);
    }
}

int main() {
    srand(time(NULL));
    int max_users = 3;
    User users[max_users];
    int new_user;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter the number of users to add:\n");
    scanf("%d", &new_user);

    while (new_user >= 0 && new_user < max_users) {
        add_user(users, max_users, new_user);
        printf("Do you want to add another user? (y/n): ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'n') {
            break;
        }
        new_user++;
    }

    print_users(users, new_user);
    update_progress(users, new_user);
    compare_users(users, new_user);

    return 0;
}