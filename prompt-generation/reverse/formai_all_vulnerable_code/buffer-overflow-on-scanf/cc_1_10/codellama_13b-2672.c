//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
// Periodic Table Quiz Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent an element
struct Element {
    char name[100];
    int number;
    char symbol[10];
    char group[10];
    char period[10];
    char phase[10];
    char atomic_mass[10];
};

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random element
struct Element generate_element() {
    struct Element element;
    int number = rand_num(1, 118);
    sprintf(element.name, "Element %d", number);
    sprintf(element.symbol, "E%d", number);
    sprintf(element.group, "Group %d", number % 18 + 1);
    sprintf(element.period, "Period %d", number % 7 + 1);
    sprintf(element.phase, "Phase %d", number % 4 + 1);
    sprintf(element.atomic_mass, "%d.00", number);
    return element;
}

// Function to print the element information
void print_element(struct Element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Group: %s\n", element.group);
    printf("Period: %s\n", element.period);
    printf("Phase: %s\n", element.phase);
    printf("Atomic Mass: %s\n", element.atomic_mass);
}

// Function to check the user's answer
int check_answer(struct Element element, char answer[100]) {
    if (strcmp(element.name, answer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate a random element
    struct Element element = generate_element();

    // Print the element information
    print_element(element);

    // Prompt the user for an answer
    char answer[100];
    printf("What is the name of this element? ");
    scanf("%s", answer);

    // Check the user's answer
    int correct = check_answer(element, answer);

    // Print the result
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", element.name);
    }

    return 0;
}