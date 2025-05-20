//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Define a struct to hold each entry in the fitness tracker
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} Entry;

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}

// Function to compare two entries by name
int compare_entries(const void* a, const void* b) {
    const Entry* entry1 = (const Entry*)a;
    const Entry* entry2 = (const Entry*)b;
    return strcmp(entry1->name, entry2->name);
}

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    // Initialize the fitness tracker
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name and age:\n");
    scanf("%s %d", entries[num_entries].name, &entries[num_entries].age);
    num_entries++;

    // Loop until the user is done adding entries
    while (num_entries < MAX_ENTRIES) {
        printf("Would you like to add another entry? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Please enter your name and age:\n");
            scanf("%s %d", entries[num_entries].name, &entries[num_entries].age);
            printf("Please enter your weight in pounds:\n");
            scanf("%f", &entries[num_entries].weight);
            printf("Please enter your height in inches:\n");
            scanf("%f", &entries[num_entries].height);
            entries[num_entries].bmi = calculate_bmi(entries[num_entries].weight, entries[num_entries].height);
            num_entries++;
        } else {
            break;
        }
    }

    // Sort the entries by name
    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    // Print the fitness tracker
    printf("\nFitness Tracker:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nAge: %d\nWeight: %.2f\nHeight: %.2f\nBMI: %.2f\n\n", entries[i].name, entries[i].age, entries[i].weight, entries[i].height, entries[i].bmi);
    }

    return 0;
}