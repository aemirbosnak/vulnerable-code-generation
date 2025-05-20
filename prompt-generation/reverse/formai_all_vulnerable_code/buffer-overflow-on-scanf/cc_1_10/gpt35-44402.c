//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50 // Maximum length for the member's name
#define MAX_MEMBERS 100 // Maximum number of members that can be added to the database

typedef struct {
    char name[MAX_NAME_LENGTH]; // Name of the member
    int age; // Age of the member
    float height; // Height of the member
} member;

int main() {

    // Create an array to store the members
    member members[MAX_MEMBERS];
    int num_members = 0;

    // Greet the user and prompt them to add a new member
    printf("Welcome to the Peaceful Database Simulation Program!\n\n");
    printf("You can add a new member to the database by entering their information below:\n");

    // Keep prompting the user to add new members until they choose to stop
    while (1) {
        // Read in the member's information
        printf("\nName: ");
        fgets(members[num_members].name, MAX_NAME_LENGTH, stdin);
        members[num_members].name[strcspn(members[num_members].name, "\n")] = '\0'; // Remove trailing newline

        printf("Age: ");
        scanf("%d", &members[num_members].age);

        printf("Height (in meters): ");
        scanf("%f", &members[num_members].height);

        // Increment the number of members and prompt the user to add another member or quit
        num_members++;

        printf("\nDo you want to add another member? (y/n): ");
        char response[2];
        scanf("%s", response);

        // If the user chooses to quit, break out of the loop
        if (strcmp(response, "n") == 0) {
            break;
        }

        // Clear the input buffer to prevent errors
        while ((getchar()) != '\n');
    }

    // Print out all the members in the database
    printf("\nHere are the members in the database:\n");
    for (int i = 0; i < num_members; i++) {
        printf("\nMember %d:\n", i+1);
        printf("Name: %s\n", members[i].name);
        printf("Age: %d\n", members[i].age);
        printf("Height: %.2f meters\n", members[i].height);
    }

    // Exit the program
    printf("\nThank you for using the Peaceful Database Simulation Program!\n");

    return 0;
}