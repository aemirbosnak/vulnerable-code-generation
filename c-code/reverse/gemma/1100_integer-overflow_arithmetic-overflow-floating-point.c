#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, units_from, units_to;
    float distance;
    float conversion_factor[4] = {1, 1000, 1609.34, 1.613};

    while (1)
    {
        printf("Enter the number of units you want to convert (0 to quit): ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        printf("Enter the number of units you want to convert from: ");
        scanf("%d", &units_from);

        printf("Enter the number of units you want to convert to: ");
        scanf("%d", &units_to);

        distance = (float)units_from * conversion_factor[units_from] / conversion_factor[units_to];

        printf("The converted distance is: %.2f %s\n", distance, units_to);
    }

    return 0;
}
