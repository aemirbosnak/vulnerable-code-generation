#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    printf("Welcome to the Smart Home System!\n");
    printf("Please select an option:\n");
    printf("1. Toggle Lights\n");
    printf("2. Control Fan\n");
    printf("3. Adjust AC Unit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            // Logic to toggle lights
            printf("Lights toggled.\n");
            break;
        case 2:
            // Logic to control fan
            printf("Fan controlled.\n");
            break;
        case 3:
            // Logic to adjust AC unit
            printf("AC unit adjusted.\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}
