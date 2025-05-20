//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of fairies in the meadow
#define MAX_FAIRIES 100

// Define the structure of a fairy
typedef struct {
    char name[20];     // The name of the fairy
    int age;          // The age of the fairy
    float height;     // The height of the fairy in inches
    float weight;     // The weight of the fairy in pounds
} Fairy;

// Create an array of fairies
Fairy fairies[MAX_FAIRIES];

// Get the number of fairies in the meadow
int num_fairies;

// Get the data for each fairy
void get_fairy_data() {
    for (int i = 0; i < num_fairies; i++) {
        printf("Enter the name of fairy %d: ", i + 1);
        scanf("%s", fairies[i].name);
        printf("Enter the age of fairy %d: ", i + 1);
        scanf("%d", &fairies[i].age);
        printf("Enter the height of fairy %d in inches: ", i + 1);
        scanf("%f", &fairies[i].height);
        printf("Enter the weight of fairy %d in pounds: ", i + 1);
        scanf("%f", &fairies[i].weight);
    }
}

// Print the data for each fairy
void print_fairy_data() {
    for (int i = 0; i < num_fairies; i++) {
        printf("Fairy %d:\n", i + 1);
        printf("Name: %s\n", fairies[i].name);
        printf("Age: %d\n", fairies[i].age);
        printf("Height: %.2f inches\n", fairies[i].height);
        printf("Weight: %.2f pounds\n", fairies[i].weight);
    }
}

// Calculate the average age of the fairies
float calculate_average_age() {
    float average_age = 0.0;
    for (int i = 0; i < num_fairies; i++) {
        average_age += fairies[i].age;
    }
    average_age /= num_fairies;
    return average_age;
}

// Calculate the average height of the fairies
float calculate_average_height() {
    float average_height = 0.0;
    for (int i = 0; i < num_fairies; i++) {
        average_height += fairies[i].height;
    }
    average_height /= num_fairies;
    return average_height;
}

// Calculate the average weight of the fairies
float calculate_average_weight() {
    float average_weight = 0.0;
    for (int i = 0; i < num_fairies; i++) {
        average_weight += fairies[i].weight;
    }
    average_weight /= num_fairies;
    return average_weight;
}

// Print the average age, height, and weight of the fairies
void print_average_data() {
    float average_age = calculate_average_age();
    float average_height = calculate_average_height();
    float average_weight = calculate_average_weight();
    printf("Average age: %.2f years\n", average_age);
    printf("Average height: %.2f inches\n", average_height);
    printf("Average weight: %.2f pounds\n", average_weight);
}

// Main function
int main() {
    // Get the number of fairies in the meadow
    printf("Enter the number of fairies in the meadow: ");
    scanf("%d", &num_fairies);

    // Get the data for each fairy
    get_fairy_data();

    // Print the data for each fairy
    print_fairy_data();

    // Print the average age, height, and weight of the fairies
    print_average_data();

    return 0;
}