//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_EXERCISE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int weight;
    int height;
    char exercises[MAX_EXERCISE_LENGTH];
} user_t;

int main() {
    user_t users[MAX_ENTRIES];
    int num_users = 0;
    char input[MAX_EXERCISE_LENGTH];

    printf("Enter your name: ");
    scanf("%s", users[num_users].name);
    printf("Enter your age: ");
    scanf("%d", &users[num_users].age);
    printf("Enter your weight: ");
    scanf("%d", &users[num_users].weight);
    printf("Enter your height: ");
    scanf("%d", &users[num_users].height);
    printf("Enter your favorite exercises separated by commas: ");
    scanf("%s", input);

    char* exercise = strtok(input, ",");
    while (exercise!= NULL) {
        strcat(users[num_users].exercises, exercise);
        strcat(users[num_users].exercises, ", ");
        exercise = strtok(NULL, ",");
    }

    printf("Welcome, %s! Your favorite exercises are: %s\n", users[num_users].name, users[num_users].exercises);
    num_users++;

    while (1) {
        printf("\nWhat would you like to do?\n1. Add a new user\n2. View user information\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_users >= MAX_ENTRIES) {
                    printf("Sorry, you have reached the maximum number of users allowed.\n");
                } else {
                    printf("Enter the name of the new user: ");
                    scanf("%s", users[num_users].name);
                    printf("Enter the age of the new user: ");
                    scanf("%d", &users[num_users].age);
                    printf("Enter the weight of the new user: ");
                    scanf("%d", &users[num_users].weight);
                    printf("Enter the height of the new user: ");
                    scanf("%d", &users[num_users].height);
                    printf("Enter the favorite exercises of the new user separated by commas: ");
                    scanf("%s", users[num_users].exercises);
                    printf("Welcome, %s! Your favorite exercises are: %s\n", users[num_users].name, users[num_users].exercises);
                    num_users++;
                }
                break;
            case 2:
                printf("Enter the name of the user you want to view information for: ");
                scanf("%s", input);
                int i;
                for (i = 0; i < num_users; i++) {
                    if (strcmp(users[i].name, input) == 0) {
                        printf("\nName: %s\nAge: %d\nWeight: %d\nHeight: %d\nFavorite Exercises: %s\n", users[i].name, users[i].age, users[i].weight, users[i].height, users[i].exercises);
                    }
                }
                break;
            case 3:
                printf("Thank you for using the fitness tracker!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}