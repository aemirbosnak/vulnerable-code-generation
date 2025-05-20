//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOVERS 100
#define TIME_POINTS 5

typedef struct {
    char name[50];
    int year;
    char romantic_message[256];
} Lover;

void travel_to_year(int year, Lover lovers[], int lover_count);
void create_love_story(Lover lover1, Lover lover2);
void display_time_travel_options();

int main() {
    Lover lovers[MAX_LOVERS];
    int lover_count = 0;

    FILE *file = fopen("lovers.txt", "r");
    if (file == NULL) {
        printf("Could not open lovers.txt. Creating a new one...\n");
        file = fopen("lovers.txt", "w");
        if (file == NULL) {
            perror("Failed to create lovers.txt");
            return EXIT_FAILURE;
        }
        fprintf(file, "Alice 1880 To love is to find your soulmate in every lifetime.\n");
        fprintf(file, "Bob 1900 A love that transcends time knows no bounds.\n");
        fprintf(file, "Clara 1920 In dreams and whispers, we shall always meet.\n");
        fprintf(file, "David 1980 The stars aligned for our hearts to connect.\n");
        fprintf(file, "Ella 2020 Together, we will rewrite history with our love.\n");
        fclose(file);
        printf("lovers.txt created successfully. Please run the program again.\n");
        return EXIT_SUCCESS;
    } else {
        while (fscanf(file, "%s %d %[^\n]", lovers[lover_count].name, &lovers[lover_count].year, lovers[lover_count].romantic_message) != EOF) {
            lover_count++;
        }
        fclose(file);
    }

    int choice;
    printf("Welcome to the Romantic Time Travel Simulator!\n");
    printf("We have the following lovers from history:\n");

    for (int i = 0; i < lover_count; i++) {
        printf("%d: %s (%d) - %s\n", i + 1, lovers[i].name, lovers[i].year, lovers[i].romantic_message);
    }

    display_time_travel_options();
    printf("Choose a year to travel to (input a year to search, or press 0 to quit): ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("Thank you for playing. May love find you across all time!\n");
        return EXIT_SUCCESS;
    }

    travel_to_year(choice, lovers, lover_count);
    
    return EXIT_SUCCESS;
}

void travel_to_year(int year, Lover lovers[], int lover_count) {
    int found = 0;
    
    printf("\n--- Time Traveling to %d ---\n", year);
    for (int i = 0; i < lover_count; i++) {
        if (lovers[i].year == year) {
            printf("You have found: %s! \n", lovers[i].name);
            printf("Romantic Message: %s\n", lovers[i].romantic_message);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No lovers found from the year %d. Maybe their romance is hidden in time...\n", year);
    }
}

void create_love_story(Lover lover1, Lover lover2) {
    printf("In a time long past, %s met %s in the enchanting year of %d.\n", lover1.name, lover2.name, lover1.year);
    printf("Their hearts danced like stars across a midnight sky, and they whispered to each other:\n");
    printf("\"%s\"\n", lover1.romantic_message);
    printf("\"%s\"\n", lover2.romantic_message);
    printf("As time faded into eternity, their love became a story told among the ages.\n");
}

void display_time_travel_options() {
    printf("Possible time travel points:\n");
    printf("1: 1880\n");
    printf("2: 1900\n");
    printf("3: 1920\n");
    printf("4: 1980\n");
    printf("5: 2020\n");
}