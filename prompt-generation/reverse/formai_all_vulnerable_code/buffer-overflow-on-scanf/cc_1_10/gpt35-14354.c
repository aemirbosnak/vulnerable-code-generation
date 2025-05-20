//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// A structure to store the details of a person
struct Person {
    char name[50];
    int age;
    float weight;
};

// A structure to store the details of an exercise
struct Exercise {
    char name[50];
    float calories;
};

// A function to calculate the calories burnt
float calculateCaloriesBurnt(float weight, float time, float MET) {
    return (weight * MET * time) / 60;
}

int main() {
    struct Person person;
    printf("Enter your name: ");
    scanf("%s", person.name);
    printf("Enter your age: ");
    scanf("%d", &person.age);
    printf("Enter your weight in kgs: ");
    scanf("%f", &person.weight);

    int exerciseCount;
    printf("Enter the number of exercises you want to track: ");
    scanf("%d", &exerciseCount);

    struct Exercise exercises[exerciseCount];

    for(int i=0; i<exerciseCount; i++) {
        printf("Enter the name of the exercise #%d: ", i+1);
        scanf("%s", exercises[i].name);
        printf("Enter the MET value of %s: ", exercises[i].name);
        scanf("%f", &exercises[i].calories);
    }

    float totalTime = 0; // in minutes
    float totalCaloriesBurnt = 0;

    while(1) {
        int choice;
        printf("\n1. Add exercise\n2. View summary\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nSelect the exercise you want to add:\n");
                for(int i=0; i<exerciseCount; i++) {
                    printf("%d. %s\n", i+1, exercises[i].name);
                }

                int selectedExercise;
                printf("\nEnter your choice: ");
                scanf("%d", &selectedExercise);

                if(selectedExercise > 0 && selectedExercise <= exerciseCount) {
                    float time;
                    printf("Enter the time in minutes: ");
                    scanf("%f", &time);

                    totalCaloriesBurnt += calculateCaloriesBurnt(person.weight, time, exercises[selectedExercise-1].calories);
                    totalTime += time;

                    printf("\nExercise added successfully!\n");
                }
                else {
                    printf("\nInvalid choice!\n");
                }
                break;

            case 2:
                printf("\nName: %s\nAge: %d\nWeight: %.2f kgs\n", person.name, person.age, person.weight);
                printf("Total time: %.2f minutes\nTotal calories burnt: %.2f calories\n", totalTime, totalCaloriesBurnt);
                break;

            case 3:
                printf("\nExiting the program...\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}