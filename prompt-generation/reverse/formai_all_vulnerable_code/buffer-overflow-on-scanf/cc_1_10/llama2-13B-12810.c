//LLAMA2-13B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

// Structure to store a single user input
typedef struct {
    int id;
    char name[50];
    int age;
} user_input_t;

// Function to read user input
user_input_t get_user_input(void) {
    int id, age;
    char name[50];

    printf("Enter your ID: ");
    scanf("%d", &id);
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);

    return (user_input_t) {id, name, age};
}

// Function to calculate the average age of a group of users
double calculate_average_age(user_input_t *users, int num_users) {
    int i;
    double sum = 0;

    for (i = 0; i < num_users; i++) {
        sum += users[i].age;
    }

    return sum / num_users;
}

int main(void) {
    srand(time(NULL));

    // Create an array of user inputs
    user_input_t users[10];
    int i;

    for (i = 0; i < 10; i++) {
        users[i] = get_user_input();
    }

    // Calculate the average age of the group
    double average_age = calculate_average_age(users, 10);

    printf("The average age of the group is: %f\n", average_age);

    return 0;
}