//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR 10
#define MAX_VERTEX 100

int color[MAX_VERTEX];
int color_count[MAX_COLOR];
int num_colors;

int find_min_color() {
    int min = MAX_COLOR;
    for (int i = 0; i < num_colors; i++) {
        if (color_count[i] < min) {
            min = color_count[i];
        }
    }
    return min;
}

void assign_color(int vertex) {
    if (color[vertex]!= -1) {
        printf("Vertex %d already has a color assigned\n", vertex);
        return;
    }

    int min_color = find_min_color();

    while (min_color == color[vertex]) {
        min_color++;
        if (min_color == MAX_COLOR) {
            printf("No available colors for vertex %d\n", vertex);
            exit(1);
        }
    }

    color[vertex] = min_color;
    color_count[min_color]++;

    if (color_count[min_color] == num_colors - 1) {
        printf("All vertices have been colored!\n");
        exit(0);
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < MAX_VERTEX; i++) {
        color[i] = -1;
        color_count[i] = 0;
    }

    num_colors = rand() % (MAX_COLOR + 1);

    for (int i = 0; i < MAX_VERTEX; i++) {
        assign_color(i);
    }

    return 0;
}