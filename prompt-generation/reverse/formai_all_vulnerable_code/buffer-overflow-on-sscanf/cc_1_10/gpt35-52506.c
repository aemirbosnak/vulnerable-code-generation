//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COORDINATES 10   // Maximum number of coordinates that can be entered
#define MAX_LINE_LENGTH 80   // Maximum length of a line of input

typedef struct Coordinate {
    float x;
    float y;
} Coordinate;

float calculateDistance(Coordinate a, Coordinate b) {
    float distance = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
    return distance;
}

float calculatePerimeter(Coordinate coordinates[], int count) {
    float perimeter = 0;
    for(int i = 0; i < count-1; i++) {
        perimeter += calculateDistance(coordinates[i], coordinates[i+1]);
    }
    perimeter += calculateDistance(coordinates[count-1], coordinates[0]);
    return perimeter;
}

int checkCollinear(Coordinate a, Coordinate b, Coordinate c) {
    float area = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y))/2;
    if(area == 0) return 1;
    return 0;
}

int checkConvex(Coordinate coordinates[], int count) {
    int sign = 0;
    for(int i = 0; i < count-2; i++) {
        int tempSign = checkCollinear(coordinates[i], coordinates[i+1], coordinates[i+2]) ? 0 : (coordinates[i+1].y - coordinates[i].y) * (coordinates[i+2].x - coordinates[i+1].x) - (coordinates[i+1].x - coordinates[i].x) * (coordinates[i+2].y - coordinates[i+1].y) > 0 ? 1 : -1;
        if(i == 0) sign = tempSign;
        else if(sign != tempSign) return 0;
    }
    int tempSign = checkCollinear(coordinates[count-2], coordinates[count-1], coordinates[0]) ? 0 : (coordinates[count-1].y - coordinates[count-2].y) * (coordinates[0].x - coordinates[count-1].x) - (coordinates[count-1].x - coordinates[count-2].x) * (coordinates[0].y - coordinates[count-1].y) > 0 ? 1 : -1;
    if(sign != tempSign) return 0;
    tempSign = checkCollinear(coordinates[count-1], coordinates[0], coordinates[1]) ? 0 : (coordinates[0].y - coordinates[count-1].y) * (coordinates[1].x - coordinates[0].x) - (coordinates[0].x - coordinates[count-1].x) * (coordinates[1].y - coordinates[0].y) > 0 ? 1 : -1;
    if(sign != tempSign) return 0;
    return 1;
}

int main(void) {
    int count = 0;
    Coordinate coordinates[MAX_COORDINATES];
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, stdin)) {
        if(line[0] == '\n') break;
        sscanf(line, "%f %f", &coordinates[count].x, &coordinates[count].y);
        count++;
    }
    if(count < 3) {
        printf("Polygon must have at least 3 points.\n");
        return 0;
    }
    printf("Perimeter: %.2f\n", calculatePerimeter(coordinates, count));
    if(checkConvex(coordinates, count)) {
        printf("Shape is convex.\n");
    } else {
        printf("Shape is not convex.\n");
    }
    return 0;
}