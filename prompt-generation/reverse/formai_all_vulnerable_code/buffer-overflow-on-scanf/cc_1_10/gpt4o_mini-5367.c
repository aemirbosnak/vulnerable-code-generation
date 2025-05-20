//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS 10
#define POINT_NAME_LENGTH 30

typedef struct {
    char name[POINT_NAME_LENGTH];
    float latitude;
    float longitude;
} Point;

void displayMenu() {
    printf("==== GPS Navigation Simulation ====\n");
    printf("1. Add a point\n");
    printf("2. List all points\n");
    printf("3. Navigate to a point\n");
    printf("4. Exit\n");
    printf("==================================\n");
    printf("Choose an option (1-4): ");
}

void addPoint(Point* points, int* count) {
    if (*count >= MAX_POINTS) {
        printf("Maximum number of points reached.\n");
        return;
    }
    
    printf("Enter point name: ");
    scanf("%s", points[*count].name);
    printf("Enter latitude: ");
    scanf("%f", &points[*count].latitude);
    printf("Enter longitude: ");
    scanf("%f", &points[*count].longitude);
    
    (*count)++;
    printf("Point '%s' added successfully!\n", points[*count - 1].name);
}

void listPoints(Point* points, int count) {
    if (count == 0) {
        printf("No points available.\n");
        return;
    }
    
    printf("Listing all points:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Lat: %.2f, Lon: %.2f)\n", i + 1, points[i].name, points[i].latitude, points[i].longitude);
    }
}

void navigateToPoint(Point* points, int count) {
    if (count == 0) {
        printf("No points available to navigate to.\n");
        return;
    }
    
    int choice;
    printf("Select a point to navigate to (1-%d): ", count);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > count) {
        printf("Invalid choice! Please select a valid point.\n");
        return;
    }
    
    Point selectedPoint = points[choice - 1];
    printf("Navigating to %s...\n", selectedPoint.name);
    printf("Coordinates: (Lat: %.2f, Lon: %.2f)\n", selectedPoint.latitude, selectedPoint.longitude);
    printf("You have arrived at %s!\n", selectedPoint.name);
}

int main() {
    Point points[MAX_POINTS];
    int pointCount = 0;
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addPoint(points, &pointCount);
                break;
            case 2:
                listPoints(points, pointCount);
                break;
            case 3:
                navigateToPoint(points, pointCount);
                break;
            case 4:
                printf("Exiting the GPS Navigation Simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose a number between 1 and 4.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}