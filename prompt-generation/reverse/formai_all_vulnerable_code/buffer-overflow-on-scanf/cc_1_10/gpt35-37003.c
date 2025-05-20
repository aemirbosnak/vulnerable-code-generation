//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Please enter your name: ");
    char name[30];
    scanf("%s", name);

    printf("Hello, %s! You will be embarking on a journey through space,\n", name);
    printf("exploring procedurally generated planets, and discovering new worlds.\n");

    int planets_explored = 0;
    while (1)
    {
        printf("\nYou have explored %d planets so far.\n", planets_explored);
        printf("Would you like to explore a new planet or return home?\n");
        printf("Enter 1 to explore a new planet, 2 to return home: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            // Generate a new planet
            printf("\nGenerating new planet...\n");
            int planet_type = rand() % 3; // 0, 1, or 2
            char* planet_name;
            switch (planet_type)
            {
                case 0:
                    planet_name = "Barren";
                    break;
                case 1:
                    planet_name = "Lush";
                    break;
                case 2:
                    planet_name = "Desolate";
                    break;
            }
            float temperature = -150.0 + ((float)rand()/(float)(RAND_MAX)) * 300.0;
            float gravity = 0.5 + ((float)rand()/(float)(RAND_MAX)) * 1.5;

            // Display planet information
            printf("\nYou have arrived on a %s planet.\n", planet_name);
            printf("The temperature is %.1f degrees Celsius.\n", temperature);
            printf("The gravity is %.1f m/s^2.\n", gravity);

            // Update planets explored count
            planets_explored++;
        }
        else if (choice == 2)
        {
            printf("\nYou have decided to return home.\n");
            printf("Thanks for playing Procedural Space Adventure!\n");
            break;
        }
        else
        {
            printf("\nInvalid choice. Please enter 1 or 2.\n");
        }
    }

    return 0;
}