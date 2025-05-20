//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

// Struct for a fitness tracker
struct FitnessTracker {
    char name[MAX_NAME_LENGTH];
    int age;
    double weight;
    double height;
    double bmi;
};

// Function to calculate BMI
void calculate_bmi(struct FitnessTracker *ft) {
    ft->bmi = ft->weight / (ft->height * ft->height);
}

int main() {
    int num_of_users;
    printf("Enter the number of users: ");
    scanf("%d", &num_of_users);

    // Array of fitness trackers
    struct FitnessTracker *ft_array = (struct FitnessTracker *) malloc(sizeof(struct FitnessTracker) * num_of_users);

    // Get user information for each fitness tracker
    for (int i = 0; i < num_of_users; i++) {
        printf("Enter user %d's name: ", i+1);
        scanf("%s", ft_array[i].name);

        printf("Enter user %d's age: ", i+1);
        scanf("%d", &ft_array[i].age);

        printf("Enter user %d's weight in kg: ", i+1);
        scanf("%lf", &ft_array[i].weight);

        printf("Enter user %d's height in m: ", i+1);
        scanf("%lf", &ft_array[i].height);

        calculate_bmi(&ft_array[i]);
        printf("User %d's BMI is: %0.2lf\n", i+1, ft_array[i].bmi);
    }

    // Find the user with the highest BMI
    int max_bmi_index = 0;
    for (int i = 1; i < num_of_users; i++) {
        if (ft_array[i].bmi > ft_array[max_bmi_index].bmi) {
            max_bmi_index = i;
        }
    }

    printf("%s has the highest BMI of %0.2lf\n", ft_array[max_bmi_index].name, ft_array[max_bmi_index].bmi);

    free(ft_array);
    return 0;
}