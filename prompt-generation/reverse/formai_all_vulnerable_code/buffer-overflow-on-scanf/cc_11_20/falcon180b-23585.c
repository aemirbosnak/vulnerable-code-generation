//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char name[30];
    int age;
    int height;
    int weight;
} Person;

int main() {
    int choice;
    Person *people = (Person *) malloc(MAX_SIZE * sizeof(Person));
    int count = 0;

    do {
        printf("\nFitness Tracker\n");
        printf("1. Add a person\n2. Display all people\n3. Display average height\n4. Display average weight\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= MAX_SIZE) {
                    printf("Maximum capacity reached. Cannot add more people.\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", people[count].name);
                printf("Enter age: ");
                scanf("%d", &people[count].age);
                printf("Enter height in cm: ");
                scanf("%d", &people[count].height);
                printf("Enter weight in kg: ");
                scanf("%d", &people[count].weight);
                count++;
                break;

            case 2:
                printf("\nAll people:\n");
                for(int i=0; i<count; i++) {
                    printf("%s, %d years old, %d cm tall, %d kg\n", people[i].name, people[i].age, people[i].height, people[i].weight);
                }
                break;

            case 3:
                if(count == 0) {
                    printf("No people added yet.\n");
                    break;
                }
                int total_height = 0;
                for(int i=0; i<count; i++) {
                    total_height += people[i].height;
                }
                float avg_height = (float) total_height / count;
                printf("Average height: %.2f cm\n", avg_height);
                break;

            case 4:
                if(count == 0) {
                    printf("No people added yet.\n");
                    break;
                }
                int total_weight = 0;
                for(int i=0; i<count; i++) {
                    total_weight += people[i].weight;
                }
                float avg_weight = (float) total_weight / count;
                printf("Average weight: %.2f kg\n", avg_weight);
                break;

            case 5:
                printf("Exiting...\n");
                free(people);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}