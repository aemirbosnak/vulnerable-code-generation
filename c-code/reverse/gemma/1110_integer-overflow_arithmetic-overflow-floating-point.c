#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, temp, converted_temp;
    printf("Enter 1 for Celsius to Galactic or 2 for Galactic to Celsius:\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temp);
            converted_temp = (temp * 2) + 100000000000000;
            printf("The temperature in Galactic is: %d\n", converted_temp);
            break;
        case 2:
            printf("Enter the temperature in Galactic:");
            scanf("%d", &temp);
            converted_temp = (temp - 100000000000000) / 2;
            printf("The temperature in Celsius is: %d\n", converted_temp);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
