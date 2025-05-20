//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURES 100
#define MAX_TEMP_LENGTH 20

struct temperature {
    char name[MAX_TEMP_LENGTH];
    double value;
};

int main() {
    int numTemperatures = 0;
    struct temperature temperatures[MAX_TEMPERATURES];

    while (numTemperatures < MAX_TEMPERATURES) {
        printf("Enter a temperature name (up to %d characters): ", MAX_TEMP_LENGTH);
        scanf("%s", temperatures[numTemperatures].name);

        printf("Enter the temperature value: ");
        scanf("%lf", &temperatures[numTemperatures].value);

        numTemperatures++;
    }

    while (1) {
        printf("\n");
        for (int i = 0; i < numTemperatures; i++) {
            printf("%s: %.2lf\n", temperatures[i].name, temperatures[i].value);
        }

        printf("Press enter to update temperatures or type 'quit' to exit.\n");
        char input[MAX_TEMP_LENGTH];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        printf("\n");
        for (int i = 0; i < numTemperatures; i++) {
            printf("Update temperature %s? (y/n): ", temperatures[i].name);
            scanf(" %c", &input[0]);

            if (input[0] == 'y' || input[0] == 'Y') {
                printf("Enter the new temperature value: ");
                scanf("%lf", &temperatures[i].value);
            }
        }
    }

    return 0;
}