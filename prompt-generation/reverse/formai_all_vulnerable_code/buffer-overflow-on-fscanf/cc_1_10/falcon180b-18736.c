//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CITIES 50
#define MAX_ROADS 100
#define MAX_DEMAND 100

typedef struct {
    int id;
    int demand;
    int x, y;
    int connected;
} City;

typedef struct {
    int id;
    int demand;
    int from;
    int to;
    int cost;
} Road;

int num_cities;
City *cities;
int num_roads;
Road *roads;

void read_cities(FILE *fp) {
    num_cities = 0;
    while (fscanf(fp, "%d %d %d %d", &cities[num_cities].id, &cities[num_cities].x, &cities[num_cities].y, &cities[num_cities].demand) == 4) {
        num_cities++;
    }
}

void read_roads(FILE *fp) {
    num_roads = 0;
    while (fscanf(fp, "%d %d %d %d", &roads[num_roads].id, &roads[num_roads].from, &roads[num_roads].to, &roads[num_roads].cost) == 4) {
        num_roads++;
    }
}

void kruskal() {
    int i, j, u, v, parent[MAX_CITIES];
    int min_cost = 0;
    int num_components = 0;

    for (i = 0; i < num_cities; i++) {
        parent[i] = i;
    }

    for (i = 0; i < num_roads; i++) {
        u = find_parent(parent, roads[i].from);
        v = find_parent(parent, roads[i].to);

        if (u!= v) {
            parent[v] = u;
            min_cost += roads[i].cost;
            num_components--;
        }
    }

    printf("Minimum spanning tree cost: %d\n", min_cost);
    printf("Number of components: %d\n", num_components);
}

int find_parent(int parent[], int i) {
    if (parent[i]!= i) {
        parent[i] = find_parent(parent, parent[i]);
    }
    return parent[i];
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");

    read_cities(fp);
    read_roads(fp);

    kruskal();

    fclose(fp);
    return 0;
}