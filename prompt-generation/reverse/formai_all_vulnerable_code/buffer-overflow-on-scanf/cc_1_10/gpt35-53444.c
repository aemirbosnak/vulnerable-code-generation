//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIST 1000.0
#define MAX_ALT 500.0

typedef struct Coordinate {
    double x;
    double y;
    double z;
} Coordinate;

double calc_distance(Coordinate p1, Coordinate p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    Coordinate drone_pos = {0, 0, 0};
    double drone_alt = 0.0;
    bool is_flying = false;
    bool is_connected = false;
    
    char command;
    while (true) {
        printf("Enter command (F)ly, (L)and, (C)onnect, (D)isconnect, (M)ove: ");
        scanf(" %c", &command);
        switch (command) {
            case 'F':
                if (is_flying) {
                    printf("Drone is already flying\n");
                } else if (!is_connected) {
                    printf("Cannot fly without connection\n");
                } else {
                    printf("Drone is flying\n");
                    is_flying = true;
                }
                break;
            case 'L':
                if (!is_flying) {
                    printf("Drone is not flying\n");
                } else {
                    printf("Drone is landing\n");
                    is_flying = false;
                    drone_alt = 0.0;
                }
                break;
            case 'C':
                if (is_connected) {
                    printf("Drone is already connected\n");
                } else {
                    printf("Drone is connected\n");
                    is_connected = true;
                }
                break;
            case 'D':
                if (!is_connected) {
                    printf("Drone is not connected\n");
                } else if (is_flying) {
                    printf("Cannot disconnect while flying\n");
                } else {
                    printf("Drone is disconnected\n");
                    is_connected = false;
                }
                break;
            case 'M': {
                if (!is_flying) {
                    printf("Drone is not flying\n");
                    break;
                }
                
                double x, y, z;
                printf("Enter movement vector (x y z): ");
                scanf("%lf %lf %lf", &x, &y, &z);
                Coordinate dest_pos = {drone_pos.x + x, drone_pos.y + y, drone_pos.z + z};
                double dist = calc_distance(drone_pos, dest_pos);
                if (dist > MAX_DIST) {
                    printf("Destination is too far away, cannot move\n");
                    break;
                }
                
                double dest_alt = drone_alt + z;
                if (dest_alt < 0.0 || dest_alt > MAX_ALT) {
                    printf("Destination altitude is out of range, cannot move\n");
                    break;
                }
                
                drone_pos = dest_pos;
                drone_alt = dest_alt;
                printf("Drone moved to (%.2f, %.2f, %.2f) altitude %.2f\n", 
                       drone_pos.x, drone_pos.y, drone_pos.z, drone_alt);
                break;
            }
            default:
                printf("Invalid command\n");
                break;
        }
        
        if (!is_connected) {
            is_flying = false;
        }
    }
    
    return 0;
}