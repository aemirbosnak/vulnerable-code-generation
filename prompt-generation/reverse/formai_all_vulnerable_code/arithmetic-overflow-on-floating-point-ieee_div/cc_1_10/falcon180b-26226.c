//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} person;

person entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, maximum entries reached.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter age: ");
    scanf("%d", &entries[num_entries].age);
    printf("Enter weight (in kg): ");
    scanf("%f", &entries[num_entries].weight);
    printf("Enter height (in cm): ");
    scanf("%f", &entries[num_entries].height);
    entries[num_entries].bmi = entries[num_entries].weight / (entries[num_entries].height * entries[num_entries].height);
    num_entries++;
}

void display_entries() {
    printf("Name\tAge\tWeight (kg)\tHeight (cm)\tBMI\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%.2f\t%.2f\t%.2f\n", entries[i].name, entries[i].age, entries[i].weight, entries[i].height, entries[i].bmi);
    }
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");
    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}