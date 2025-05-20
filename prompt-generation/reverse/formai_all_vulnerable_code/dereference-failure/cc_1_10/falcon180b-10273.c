//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODEWORDS 1000
#define MAX_DATA_MODULES 1000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int count;
} Polygon;

void addPoint(Polygon* polygon, int x, int y) {
    if (polygon->count >= MAX_DATA_MODULES) {
        printf("Error: Too many points in polygon\n");
        exit(1);
    }
    polygon->points[polygon->count] = (Point) {x, y};
    polygon->count++;
}

void drawPolygon(Polygon polygon) {
    for (int i = 0; i < polygon.count; i++) {
        printf("(%d,%d) ", polygon.points[i].x, polygon.points[i].y);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    Polygon polygon = {0};
    char line[1000];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char* token = strtok(line, " ");
        while (token!= NULL) {
            if (isdigit(token[0])) {
                int x = atoi(token);
                int y = atoi(strtok(NULL, " "));
                addPoint(&polygon, x, y);
            } else {
                printf("Error: Invalid data in input file\n");
                exit(1);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    if (polygon.count < 3) {
        printf("Error: Polygon must have at least 3 points\n");
        exit(1);
    }

    drawPolygon(polygon);

    return 0;
}