//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10

void move_elevator(int floors[], int dest) {
    int i, j, k;
    int random_dir;
    
    for (i = 0; i < MAX_FLOORS; i++) {
        floors[i] = i;
    }
    
    while (floors[dest]!= 0) {
        random_dir = rand() % 2;
        
        if (random_dir == 0) {
            for (j = 0; j < MAX_FLOORS; j++) {
                if (floors[j]!= 0) {
                    for (k = 0; k < MAX_FLOORS; k++) {
                        if (floors[k] == j) {
                            floors[k]--;
                            break;
                        }
                    }
                }
            }
        } else {
            for (j = 0; j < MAX_FLOORS; j++) {
                if (floors[j]!= 0) {
                    for (k = 0; k < MAX_FLOORS; k++) {
                        if (floors[k] == j) {
                            floors[k]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    printf("Destination reached. Elevator stopped.\n");
}

int main() {
    int floors[MAX_FLOORS];
    int dest;
    
    printf("Enter the number of floors: ");
    scanf("%d", &dest);
    
    for (int i = 0; i < dest; i++) {
        floors[i] = i;
    }
    
    srand(time(NULL));
    
    printf("Enter the destination floor: ");
    scanf("%d", &dest);
    
    move_elevator(floors, dest);
    
    return 0;
}