//FormAI DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <string.h>

int main() {
    char command[100], unit[20], unit1[20], unit2[20];
    double value, result;
    int num_players;

    printf("Welcome to Unit Converter Multiplayer Game!\n");
    printf("How many players are there? ");
    scanf("%d", &num_players);

    while (1) {
        printf("\nNext player, enter a command (or 'quit' to end the game): ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) break;

        printf("Enter the unit to convert from: ");
        scanf("%s", unit);

        printf("Enter the unit to convert to: ");
        scanf("%s", unit2);

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        // do the conversion
        if (strcmp(unit, "cm") == 0 && strcmp(unit2, "in") == 0) {
            result = value / 2.54;
        } else if (strcmp(unit, "in") == 0 && strcmp(unit2, "cm") == 0) {
            result = value * 2.54;
        } else if (strcmp(unit, "km") == 0 && strcmp(unit2, "mi") == 0) {
            result = value / 1.60934;
        } else if (strcmp(unit, "mi") == 0 && strcmp(unit2, "km") == 0) {
            result = value * 1.60934;
        } else if (strcmp(unit, "kg") == 0 && strcmp(unit2, "lb") == 0) {
            result = value * 2.20462;
        } else if (strcmp(unit, "lb") == 0 && strcmp(unit2, "kg") == 0) {
            result = value / 2.20462;
        } else {
            printf("Invalid units!\n");
            continue;
        }

        // print the result
        printf("%lf %s = %lf %s\n", value, unit, result, unit2);
    }

    printf("\nThanks for playing Multiplayer Unit Converter!\n");

    return 0;
}