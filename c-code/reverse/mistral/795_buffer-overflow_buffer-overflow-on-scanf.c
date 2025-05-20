#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void moveVehicle(int x, int y, int rotation) {
    if (x < -100 || x > 100 || y < -100 || y > 100 || rotation < -180 || rotation > 180) {
        printf("Input values out of range. Please input values between -100 and 100 for x, y, and rotation.\n");
        return;
    }

    // Implement vehicle movement logic based on x, y, and rotation values
    // For example:
    if (rotation >= 0 && rotation <= 90) {
        printf("Vehicle is moving forward and turning right.\n");
    } else if (rotation >= 90 && rotation <= 180) {
        printf("Vehicle is turning right.\n");
    } else if (rotation >= -180 && rotation <= -90) {
        printf("Vehicle is turning left.\n");
    } else if (rotation >= -90 && rotation <= 0) {
        printf("Vehicle is moving backward and turning left.\n");
    } else {
        printf("Vehicle is stationary.\n");
    }
}

int main() {
    int x, y, rotation;

    printf("Enter x, y, and rotation values (separated by spaces): ");
    scanf("%d %d %d", &x, &y, &rotation);

    moveVehicle(x, y, rotation);

    return 0;
}
