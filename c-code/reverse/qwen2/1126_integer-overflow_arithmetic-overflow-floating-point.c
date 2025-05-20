#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int dt = 1;
    int gravity = -9.8;
    int simulation_count;
    
    printf("Enter the number of simulations: ");
    scanf("%d", &simulation_count);
    
    for (int i = 0; i <= simulation_count; i++) {
        int position = i * (i + 1) / 2 * dt + gravity * i * dt / 2;
        printf("Time: %d, Position: %d\n", i * dt, position);
    }
    
    return 0;
}
