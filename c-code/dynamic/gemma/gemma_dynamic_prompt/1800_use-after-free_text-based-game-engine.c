#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *map = "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n"
                 "####################################################\n";

    char *player_position = "A";

    printf("%s", map);
    printf("\nYour position: %s", player_position);

    char input[20];
    printf("\nEnter a direction (N/S/E/W): ");
    scanf("%s", input);

    switch (input[0])
    {
        case 'N':
            player_position = "N";
            break;
        case 'S':
            player_position = "S";
            break;
        case 'E':
            player_position = "E";
            break;
        case 'W':
            player_position = "W";
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    printf("\nYour new position: %s", player_position);

    return 0;
}
