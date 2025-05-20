//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 20    // Maximum number of floors
#define MAX_PEOPLE 50    // Maximum number of people

void insertSort(int arr[], int n) {
    int i, j, temp;
    
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = temp;
    }
}

int main() {
    int i, j, k, n, m, p, q, r, s, x = 1, y;
    int floor[MAX_PEOPLE], dest[MAX_PEOPLE], priority[MAX_PEOPLE];
    int elevator[MAX_PEOPLE], status[MAX_FLOORS] = {0};
    int minDestFloor = 0, maxDestFloor = 0, currFloor = 1, prevFloor = 1, nextFloor = 2;
    
    printf("Enter the number of people waiting: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the floor of person %d: ", i + 1);
        scanf("%d", &floor[i]);
        
        printf("Enter the destination floor of person %d: ", i + 1);
        scanf("%d", &dest[i]);
        
        priority[i] = rand() % 3;
    }
    
    printf("\nEnter the number of floors in the building: ");
    scanf("%d", &m);
    
    printf("\nElevator is currently at floor 1.\n");
    
    while (x) {
        y = 0;
        
        for (i = 0; i < n; i++) {
            if (floor[i] == currFloor && priority[i] == 0) {
                elevator[y] = i + 1;
                y++;
            }
        }
        
        for (i = 0; i < n; i++) {
            if (floor[i] == currFloor && priority[i] == 1) {
                elevator[y] = i + 1;
                y++;
            }
        }
        
        for (i = 0; i < n; i++) {
            if (floor[i] == currFloor && priority[i] == 2) {
                elevator[y] = i + 1;
                y++;
            }
        }
        
        insertSort(elevator, y);
        
        printf("\nAt floor %d:\n", currFloor);
        
        for (i = 0; i < y; i++) {
            printf("Person %d enters elevator.\n", elevator[i]);
        }
        
        for (i = 0; i < y; i++) {
            printf("Elevator goes from floor %d to floor %d.\n", currFloor, dest[elevator[i] - 1]);
            status[currFloor - 1] = 0;
            currFloor = dest[elevator[i] - 1];
            status[currFloor - 1] = 1;
        }
        
        if (x == 1) {
            for (i = 0; i < n; i++) {
                if (floor[i] > currFloor && floor[i] < nextFloor) {
                    nextFloor = floor[i];
                }
            }
        }
        
        if (currFloor == m) {
            printf("\nAll passengers have reached their destination. Elevator is now idle.\n");
            x = 0;
        }
        else if (currFloor == minDestFloor) {
            printf("\nElevator is at minimum destination floor %d. Going to next floor %d.\n", currFloor, nextFloor);
            prevFloor = currFloor;
            currFloor = nextFloor;
            minDestFloor = 0;
            maxDestFloor = 0;
            nextFloor = m;
            status[currFloor - 1] = 1;
        }
        else if (currFloor == maxDestFloor) {
            printf("\nElevator is at maximum destination floor %d. Going to next floor %d.\n", currFloor, nextFloor);
            prevFloor = currFloor;
            currFloor = nextFloor;
            minDestFloor = 0;
            maxDestFloor = 0;
            nextFloor = 1;
            status[currFloor - 1] = 1;
        }
        else if (currFloor > prevFloor) {
            for (i = currFloor - 1; i < m; i++) {
                if (status[i] == 1) {
                    maxDestFloor = i + 1;
                }
            }
            
            printf("\nElevator is going up. Next destination floor is %d.\n", maxDestFloor);
            prevFloor = currFloor;
            currFloor = maxDestFloor;
            minDestFloor = 0;
            status[currFloor - 1] = 1;
        }
        else if (currFloor < prevFloor) {
            for (i = currFloor - 1; i >= 0; i--) {
                if (status[i] == 1) {
                    minDestFloor = i + 1;
                }
            }
            
            printf("\nElevator is going down. Next destination floor is %d.\n", minDestFloor);
            prevFloor = currFloor;
            currFloor = minDestFloor;
            maxDestFloor = 0;
            status[currFloor - 1] = 1;
        }
    }
    
    return 0;
}