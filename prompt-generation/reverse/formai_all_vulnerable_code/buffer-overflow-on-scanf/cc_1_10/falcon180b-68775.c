//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
    int steps;
    int calories;
} User;

void add_user(User *users, int size) {
    printf("Enter name: ");
    scanf("%s", users[size].name);
    printf("Enter age: ");
    scanf("%d", &users[size].age);
    printf("Enter weight (kg): ");
    scanf("%d", &users[size].weight);
    printf("Enter height (cm): ");
    scanf("%d", &users[size].height);
    printf("Enter steps taken: ");
    scanf("%d", &users[size].steps);
    printf("Enter calories burned: ");
    scanf("%d", &users[size].calories);
    size++;
}

void display_user(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight (kg): %d\n", user.weight);
    printf("Height (cm): %d\n", user.height);
    printf("Steps taken: %d\n", user.steps);
    printf("Calories burned: %d\n", user.calories);
}

int main() {
    User users[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("\n1. Add user\n2. Display user\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX_SIZE) {
                    printf("Maximum users reached.\n");
                } else {
                    add_user(users, size);
                    size++;
                }
                break;
            case 2:
                printf("\nEnter user ID: ");
                int id;
                scanf("%d", &id);
                if (id >= 0 && id < size) {
                    display_user(users[id]);
                } else {
                    printf("Invalid user ID.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}