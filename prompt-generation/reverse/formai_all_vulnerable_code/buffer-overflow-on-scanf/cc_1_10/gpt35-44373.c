//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h> // Standard input and output header
#include <stdlib.h> // Standard library header
#include <string.h> // String header

// Function prototype(s)
void welcomeMessage();
void displayMenu();
void addExercise();
void viewProgress();
void exitProgram();

// Variable declaration(s)
typedef struct
{
    char name[50];
    int sets;
    int reps;
    float weight;
} ExerciseEntry;

ExerciseEntry entries[50];
int totalEntries = 0;

int main()
{
    int option;

    // Welcome message
    welcomeMessage();

    // Display menu
    displayMenu();

    // Get user option
    scanf("%d", &option);

    // Loop until user chooses to exit
    while (option != 4)
    {
        switch (option)
        {
            case 1:
                // Add exercise
                addExercise();
                break;

            case 2:
                // View progress
                viewProgress();
                break;

            case 3:
                // Display menu
                displayMenu();
                break;

            default:
                // Invalid option
                printf("\nInvalid option. Please try again.\n");
                break;
        }

        // Get next option
        scanf("%d", &option);
    }

    // Exit program
    exitProgram();

    return 0;
}

// Function to display welcome message
void welcomeMessage()
{
    printf("Welcome to the C Fitness Tracker!\n\n");
}

// Function to display the menu
void displayMenu()
{
    printf("Please choose an option:\n");
    printf("1. Add exercise\n");
    printf("2. View progress\n");
    printf("3. Display menu\n");
    printf("4. Exit program\n\n");
}

// Function to add an exercise entry
void addExercise()
{
    printf("\nAdding exercise entry:\n");

    ExerciseEntry entry;

    printf("\nExercise name: ");
    scanf("%s", entry.name);

    printf("Number of sets: ");
    scanf("%d", &entry.sets);

    printf("Number of reps: ");
    scanf("%d", &entry.reps);

    printf("Weight: ");
    scanf("%f", &entry.weight);

    entries[totalEntries] = entry;

    printf("\nSuccess! Exercise entry has been added.\n\n");

    totalEntries++;
}

// Function to view progress
void viewProgress()
{
    if (totalEntries == 0) // Check if there are any exercise entries
    {
        printf("\nThere are no exercise entries.\n\n");
    }
    else
    {
        printf("\nExercise progress:\n");

        // Table header
        printf("Exercise name\tSets\tReps\tWeight\n");

        // Table content
        for (int i = 0; i < totalEntries; i++)
        {
            printf("%s\t\t%d\t%d\t%.2f\n", entries[i].name, entries[i].sets, entries[i].reps, entries[i].weight);
        }

        printf("\n");
    }
}

// Function to exit the program
void exitProgram()
{
    printf("\nThank you for using the C Fitness Tracker!\n\n");
}