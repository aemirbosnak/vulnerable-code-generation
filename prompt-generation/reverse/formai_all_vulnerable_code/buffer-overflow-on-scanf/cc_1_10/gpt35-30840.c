//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* Function Declarations */
void print_instructions();
bool is_valid_input(char);

int main()
{
    int light = 0;
    bool is_on = false;
    char input;

    /* Print initial instructions */
    print_instructions();

    while (true)
    {
        /* Get user input */
        printf("\nEnter command: ");
        scanf(" %c", &input);

        /* Check if input is valid */
        if (!is_valid_input(input))
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        /* Execute user command */
        switch (input)
        {
            case '1':
                is_on = true;
                light = 100;
                printf("Turning on lights...\n");
                break;
            case '2':
                is_on = true;
                light = 50;
                printf("Dimming lights to 50%%...\n");
                break;
            case '3':
                is_on = true;
                light = 25;
                printf("Dimming lights to 25%%...\n");
                break;
            case '4':
                is_on = false;
                light = 0;
                printf("Turning off lights...\n");
                break;
            case '5':
                printf("Exiting program...\n");
                exit(0);
        }

        /* Display current light status */
        if (is_on)
            printf("Lights are on at %d%%\n", light);
        else
            printf("Lights are off\n");
    }

    return 0;
}

/**
 * Function that prints the initial instructions for the user
 */
void print_instructions()
{
    printf("Welcome to Smart Home Light Control!\n");
    printf("Use the following commands to control your lights:\n");
    printf("1. Turn on lights at 100%%\n");
    printf("2. Dim lights to 50%%\n");
    printf("3. Dim lights to 25%%\n");
    printf("4. Turn off lights\n");
    printf("5. Exit program\n");
}

/**
 * Function that checks if user input is valid
 *
 * @param input User input to be checked
 * @return True if input is valid, false otherwise
 */
bool is_valid_input(char input)
{
    return (input == '1' || input == '2' || input == '3' || input == '4' || input == '5');
}