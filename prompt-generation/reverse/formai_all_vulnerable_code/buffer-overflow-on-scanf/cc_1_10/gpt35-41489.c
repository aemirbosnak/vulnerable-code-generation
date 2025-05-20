//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Wacky Circuit Simulator!\n");

    int numComponents;
    printf("Enter the number of components in your circuit: ");
    scanf("%d", &numComponents);

    char** components = malloc(numComponents * sizeof(char*));

    for (int i = 0; i < numComponents; i++) {
        printf("Enter component %d: ", i+1);
        components[i] = malloc(20 * sizeof(char));
        scanf("%s", components[i]);
    }

    printf("\nYour circuit contains:\n");
    for (int i = 0; i < numComponents; i++) {
        printf("%d. %s\n", i+1, components[i]);
    }

    printf("\nNow let's simulate some current flowing through your circuit.\n");

    double voltage;
    printf("Enter the voltage across the circuit: ");
    scanf("%lf", &voltage);

    double totalResistance = 0.0;
    for (int i = 0; i < numComponents; i++) {
        double resistance;
        printf("Enter the resistance of %s: ", components[i]);
        scanf("%lf", &resistance);
        totalResistance += resistance;
    }

    double current = voltage / totalResistance;
    printf("\nThe current flowing through your circuit is %.2lf Amps.\n", current);

    printf("\nThanks for using the Wacky Circuit Simulator!\n");

    // Free allocated memory
    for (int i = 0; i < numComponents; i++) {
        free(components[i]);
    }
    free(components);

    return 0;
}