//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct person {
    int height;
    int weight;
    int age;
    float bmi;
};

struct person person_data[] = {
    {180, 75, 25, 23.0},
    {165, 60, 30, 22.0},
    {175, 70, 20, 21.0},
    {155, 50, 40, 24.0},
    {185, 90, 35, 26.0}
};

struct person *get_person(int index) {
    if (index < 0 || index >= sizeof(person_data) / sizeof(person_data[0])) {
        return NULL;
    }
    return &person_data[index];
}

float calculate_bmi(struct person *person) {
    return person->weight / (person->height * person->height);
}

int main() {
    struct person *person;
    int choice;
    int index;

    printf("Welcome to the Fitness Tracker!\n");
    printf("1. Calculate BMI\n");
    printf("2. Find the oldest person\n");
    printf("3. Find the youngest person\n");
    printf("4. Find the heaviest person\n");
    printf("5. Find the lightest person\n");
    printf("6. Find a person by age\n");
    printf("7. Find a person by weight\n");
    printf("8. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 8) {
        switch (choice) {
            case 1:
                printf("Enter person's height in cm: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("BMI: %.2f\n", calculate_bmi(person));
                break;
            case 2:
                printf("Enter person's age: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("Oldest person: %.2f, %.2f, %.2f, %.2f\n", person->height, person->weight, person->age, person->bmi);
                break;
            case 3:
                printf("Enter person's age: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("Youngest person: %.2f, %.2f, %.2f, %.2f\n", person->height, person->weight, person->age, person->bmi);
                break;
            case 4:
                printf("Enter person's weight: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("Heaviest person: %.2f, %.2f, %.2f, %.2f\n", person->height, person->weight, person->age, person->bmi);
                break;
            case 5:
                printf("Enter person's weight: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("Lightest person: %.2f, %.2f, %.2f, %.2f\n", person->height, person->weight, person->age, person->bmi);
                break;
            case 6:
                printf("Enter person's age: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("Person found: %.2f, %.2f, %.2f, %.2f\n", person->height, person->weight, person->age, person->bmi);
                break;
            case 7:
                printf("Enter person's weight: ");
                scanf("%d", &index);
                person = get_person(index);
                if (person == NULL) {
                    printf("Invalid index. Try again.\n");
                    continue;
                }
                printf("Person found: %.2f, %.2f, %.2f, %.2f\n", person->height, person->weight, person->age, person->bmi);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("Do you want to continue? (y/n): ");
        char c;
        scanf("%c", &c);
        if (c == 'n') {
            break;
        }
    }
    return 0;
}