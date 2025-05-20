//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Exercise {
    char name[50];
    int calories;
    float duration;
} Exercise;

typedef struct Node {
    Exercise exercise;
    struct Node* next;
} Node;

Node* head = NULL;

void addExercise(char* name, int calories, float duration) {
    Node* newExercise = (Node*)malloc(sizeof(Node));
    strcpy(newExercise->exercise.name, name);
    newExercise->exercise.calories = calories;
    newExercise->exercise.duration = duration;
    newExercise->next = head;
    head = newExercise;
}

void displayExercises() {
    Node* current = head;
    while(current != NULL) {
        printf("%s\n", current->exercise.name);
        printf("Calories burned: %d\n", current->exercise.calories);
        printf("Duration: %.2f\n", current->exercise.duration);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50];
    int calories;
    float duration;
    bool exitProgram = false;
    while(!exitProgram) {
        printf("\nMenu:\n1. Add exercise\n2. Display exercises\n3. Exit program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter exercise name: ");
                scanf("%s", name);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                printf("Enter duration (in hours): ");
                scanf("%f", &duration);
                addExercise(name, calories, duration);
                printf("Exercise added!\n");
                break;
            case 2:
                displayExercises();
                break;
            case 3:
                exitProgram = true;
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}