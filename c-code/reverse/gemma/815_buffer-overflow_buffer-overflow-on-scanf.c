#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char input[10];
    int device_selection;

    printf("Select a device:\n");
    printf("1. Light\n");
    printf("2. Fan\n");
    printf("3. AC\n");

    scanf("%s", input);

    device_selection = atoi(input);

    switch (device_selection)
    {
        case 1:
            printf("Light is toggled.\n");
            break;
        case 2:
            printf("Fan is toggled.\n");
            break;
        case 3:
            printf("AC is toggled.\n");
            break;
        default:
            printf("Invalid selection.\n");
    }

    return 0;
}
