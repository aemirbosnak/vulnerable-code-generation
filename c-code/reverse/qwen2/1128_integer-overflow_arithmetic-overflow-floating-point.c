#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num_simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);

    for (int i = 0; i <= num_simulations; i++) {
        // Simulate drone flight logic here
        printf("Simulation %d\n", i);
    }

    return 0;
}
