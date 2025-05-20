//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    int x;
    int y;
} CoordDest;

typedef struct {
    int cost;
    int heuristic;
} Cost;

typedef struct {
    Coord source;
    CoordDest destination;
    Cost* cost;
} Path;

bool isPath(Path* path) {
    return path!= NULL;
}

Cost* getCost(int x1, int y1, int x2, int y2) {
    Cost* cost = (Cost*)malloc(sizeof(Cost));
    cost->cost = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cost->heuristic = abs(x2 - x1) + abs(y2 - y1);
    return cost;
}

Path* findPath(Coord source, CoordDest destination) {
    Path* path = (Path*)malloc(sizeof(Path));
    path->source = source;
    path->destination = destination;
    path->cost = (Cost*)malloc(sizeof(Cost));
    path->cost = getCost(source.x, source.y, destination.x, destination.y);
    return path;
}

void freePath(Path* path) {
    free(path->cost);
    free(path);
}

int main() {
    Coord source = {0, 0};
    CoordDest destination = {10, 10};

    Path* path = findPath(source, destination);

    if (isPath(path)) {
        printf("Path found: (%d, %d) -> (%d, %d)\n", source.x, source.y, destination.x, destination.y);
    } else {
        printf("No path found\n");
    }

    freePath(path);

    return 0;
}