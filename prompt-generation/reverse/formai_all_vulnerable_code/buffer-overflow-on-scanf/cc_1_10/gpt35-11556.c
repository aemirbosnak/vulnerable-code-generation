//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    int value;
    char unit[10];

    printf("Welcome to the Medieval Unit Converter!\n");
    printf("=======================================\n\n");

    printf("Please enter a value and unit: ");
    scanf("%d %s", &value, unit);

    if (strcmp(unit, "knights") == 0) {
        int goblins = value * 10;
        int trolls = value * 4;
        int dragons = value / 10;

        printf("%d knights is equivalent to:\n", value);
        printf("%d goblins\n", goblins);
        printf("%d trolls\n", trolls);
        printf("%d dragons\n", dragons);
    } else if (strcmp(unit, "goblins") == 0) {
        int knights = value / 10;
        int trolls = value / 2;
        int dragons = value / 100;

        printf("%d goblins is equivalent to:\n", value);
        printf("%d knights\n", knights);
        printf("%d trolls\n", trolls);
        printf("%d dragons\n", dragons);
    } else if (strcmp(unit, "trolls") == 0) {
        int knights = value / 4;
        int goblins = value * 2;
        int dragons = value / 25;

        printf("%d trolls is equivalent to:\n", value);
        printf("%d knights\n", knights);
        printf("%d goblins\n", goblins);
        printf("%d dragons\n", dragons);
    } else if (strcmp(unit, "dragons") == 0) {
        int knights = value * 10;
        int goblins = value * 100;
        int trolls = value * 25;

        printf("%d dragons is equivalent to:\n", value);
        printf("%d knights\n", knights);
        printf("%d goblins\n", goblins);
        printf("%d trolls\n", trolls);
    } else {
        printf("Invalid unit entered.\n");
    }

    return 0;
}