//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fitness_tracker {
    char name[20];
    int age;
    float height;
    float weight;
    char gender[10];
    int steps;
    int heart_rate;
};

void print_data(struct fitness_tracker tracker)
{
    printf("Name: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Height: %.2f\n", tracker.height);
    printf("Weight: %.2f\n", tracker.weight);
    printf("Gender: %s\n", tracker.gender);
    printf("Steps: %d\n", tracker.steps);
    printf("Heart Rate: %d\n", tracker.heart_rate);
}

void update_data(struct fitness_tracker *tracker, int steps, int heart_rate)
{
    tracker->steps = steps;
    tracker->heart_rate = heart_rate;
}

int main()
{
    struct fitness_tracker tracker;
    strcpy(tracker.name, "CyberPunk");
    tracker.age = 25;
    tracker.height = 5.8;
    tracker.weight = 70.5;
    strcpy(tracker.gender, "Male");
    tracker.steps = 0;
    tracker.heart_rate = 0;
    
    printf("Welcome to CyberPunk Fitness Tracker\n\n");
    print_data(tracker);
    
    int option = 0;
    do {
        printf("\nSelect an option:\n");
        printf("1. Update Steps and Heart Rate\n");
        printf("2. Print Data\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                int steps = 0;
                int heart_rate = 0;
                printf("\nEnter Steps: ");
                scanf("%d", &steps);
                printf("Enter Heart Rate: ");
                scanf("%d", &heart_rate);
                
                update_data(&tracker, steps, heart_rate);
                
                printf("\nData Updated!\n");
                break;
            }
            case 2: {
                printf("\nCurrent Data:\n");
                print_data(tracker);
                break;
            }
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid Option!\n");
        }
        
    } while(option != 3);
    
    return 0;
}