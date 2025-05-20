//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if a given vertex can be assigned a color
int check_color(int color, int* colors, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (colors[i] == color)
            return 0;
    }
    return 1;
}

// Function to assign colors to the vertices of the graph
void assign_colors(int* colors, int n) {
    int i, color;
    for (i = 0; i < n; i++)
        colors[i] = i+1;

    while (1) {
        color = 1;
        for (i = 0; i < n; i++) {
            if (check_color(color, colors, n)) {
                colors[i] = color;
                color++;
            } else {
                color = 1;
            }
        }
        if (color == n)
            break;
    }
}

// Function to print the colored graph
void print_graph(int* colors, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", colors[i]);
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int* colors = (int*)malloc(sizeof(int) * n);
    assign_colors(colors, n);
    print_graph(colors, n);
    return 0;
}