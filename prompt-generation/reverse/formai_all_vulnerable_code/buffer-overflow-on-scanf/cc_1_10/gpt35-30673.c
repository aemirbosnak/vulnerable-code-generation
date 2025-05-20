//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Structures
typedef struct exercise
{
    char name[50];
    int reps;
    int sets;
    int weight;
    struct exercise *next;
} Exercise;

typedef struct day
{
    char date[15];
    Exercise *first_exercise;
    struct day *next;
} Day;

// Declare Functions
void display_menu();
int get_menu_choice();
void add_day(Day **head, char date[]);
int add_exercise(Exercise **head, char name[], int reps, int sets, int weight);
void display_history(Day *head);
void free_days(Day *head);
void free_exercises(Exercise *head);

// Main Function
int main(void)
{
    // Declare Variables
    int loop = 1;
    char date[15];
    int exercise_choice, reps, sets, weight;
    char name[50];
    Day *day_history = NULL;

    // Loop until user chooses to exit
    while (loop)
    {
        // Display Menu
        display_menu();

        // Get User Menu Choice
        int menu_choice = get_menu_choice();

        // Perform action based on menu choice
        switch (menu_choice)
        {
            // Add Day
            case 1:
                printf("Enter Date (MM/DD/YYYY): ");
                scanf("%s", date);
                add_day(&day_history, date);
                break;

            // Add Exercise
            case 2:
                // Get Date
                printf("Enter Date (MM/DD/YYYY): ");
                scanf("%s", date);

                // Find Date in History
                Day *day = day_history;
                while (day != NULL && strcmp(day->date, date) != 0)
                    day = day->next;

                // If Date Found, Add Exercise
                if (day != NULL)
                {
                    // Get Exercise Details
                    printf("Enter Exercise Name: ");
                    scanf("%s", name);
                    printf("Enter Reps: ");
                    scanf("%d", &reps);
                    printf("Enter Sets: ");
                    scanf("%d", &sets);
                    printf("Enter Weight (lbs): ");
                    scanf("%d", &weight);

                    // Add Exercise to Date
                    int success = add_exercise(&(day->first_exercise), name, reps, sets, weight);
                    if (success)
                        printf("Exercise Added Successfully.\n");
                    else
                        printf("Exercise Add Failed.\n");
                }
                // If Date Not Found, Output Error
                else
                {
                    printf("Date Not Found.\n");
                }
                break;

            // Display History
            case 3:
                display_history(day_history);
                break;

            // Exit Program
            case 4:
                free_days(day_history);
                printf("Exiting Fitness Tracker...\n");
                loop = 0;
                break;

            // Invalid Menu Choice
            default:
                printf("Invalid Menu Choice.\n");
        }

    }

    return 0;
}

// Display Menu Function
void display_menu()
{
    printf("===== Fitness Tracker =====\n");
    printf("1. Add Day\n");
    printf("2. Add Exercise\n");
    printf("3. Display History\n");
    printf("4. Exit Program\n");
}

// Get Menu Choice Function
int get_menu_choice()
{
    int menu_choice;
    printf("Enter Menu Choice: ");
    scanf("%d", &menu_choice);

    return menu_choice;
}

// Add Day Function
void add_day(Day **head, char date[])
{
    // Create New Day Node
    Day *new_day = (Day*) malloc(sizeof(Day));
    strcpy(new_day->date, date);
    new_day->first_exercise = NULL;
    new_day->next = NULL;

    // Insert Day Node at Beginning of List
    new_day->next = *head;
    *head = new_day;

    printf("Day Added Successfully.\n");
}

// Add Exercise Function
int add_exercise(Exercise **head, char name[], int reps, int sets, int weight)
{
    // Create New Exercise Node
    Exercise *new_exercise = (Exercise*) malloc(sizeof(Exercise));
    strcpy(new_exercise->name, name);
    new_exercise->reps = reps;
    new_exercise->sets = sets;
    new_exercise->weight = weight;
    new_exercise->next = NULL;

    // Insert Exercise Node at Beginning of List
    new_exercise->next = *head;
    *head = new_exercise;

    return 1;
}

// Display History Function
void display_history(Day *head)
{
    // Loop Through Days
    Day *day = head;
    while (day != NULL)
    {
        printf("%s\n", day->date);

        // Loop Through Exercises
        Exercise *exercise = day->first_exercise;
        while (exercise != NULL)
        {
            printf("- %s: %d sets of %d reps @ %d lbs\n", exercise->name, exercise->sets, exercise->reps, exercise->weight);
            exercise = exercise->next;
        }

        day = day->next;
    }
}

// Free All Days and Exercises Function
void free_days(Day *head)
{
    // Loop Through Days
    while (head != NULL)
    {
        // Loop Through Exercises and Free Nodes
        Exercise *exercise = head->first_exercise;
        while (exercise != NULL)
        {
            Exercise *temp = exercise;
            exercise = exercise->next;
            free(temp);
        }

        // Free Day Node
        Day *temp = head;
        head = head->next;
        free(temp);
    }
}