//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000

typedef struct Vertex {
    int vertex_num;
    struct Vertex* next;
} Vertex;

Vertex* graph[MAX_VERTICES];
int total_vertices = 0;

Vertex* create_vertex(int vertex_num) {
    Vertex* vertex = (Vertex*) malloc(sizeof(Vertex));
    vertex->vertex_num = vertex_num;
    vertex->next = NULL;
    return vertex;
}

void add_edge(int from_vertex, int to_vertex) {
    Vertex* vertex = create_vertex(to_vertex);
    vertex->next = graph[from_vertex];
    graph[from_vertex] = vertex;
}

void print_graph() {
    for (int i = 0; i < total_vertices; ++i) {
        Vertex* vertex = graph[i];
        printf("Vertex %d : ", i);
        while (vertex) {
            printf("%d -> ", vertex->vertex_num);
            vertex = vertex->next;
        }
        printf("NULL\n");
    }
}

void paranoid_check() {
    // Compare number of vertices with number of edges
    int edges = 0;
    for (int i = 0; i < total_vertices; ++i) {
        Vertex* vertex = graph[i];
        while (vertex) {
            ++edges;
            vertex = vertex->next;
        }
    }
    if (total_vertices <= edges) {
        printf("Possible edge duplication or missing vertices!\n");
        exit(1);
    }

    // Detect loops using BFS
    int visited[MAX_VERTICES] = {0};
    for (int i = 0; i < total_vertices; ++i) {
        Vertex* vertex = graph[i];
        if (!visited[i]) {
            visited[i] = 1;
            int queue[MAX_VERTICES] = {0};
            int front = 0;
            int rear = 0;
            queue[rear++] = i;

            while (front != rear) {
                int current = queue[front++];
                Vertex* current_vertex = graph[current];
                while (current_vertex) {
                    if (!visited[current_vertex->vertex_num]) {
                        visited[current_vertex->vertex_num] = 1;
                        queue[rear++] = current_vertex->vertex_num;
                    }
                    else if (current_vertex->vertex_num == i) {
                        // Loop detected
                        printf("Loop detected in graph!\n");
                        exit(1);
                    }
                    current_vertex = current_vertex->next;
                }
            }
        }
    }
}

int main() {
    // Create graph
    int choice = 0;
    while (choice != -1) {
        printf("1. Add vertex\n");
        printf("2. Add edge\n");
        printf("3. Print graph\n");
        printf("4. Paranoid Check\n");
        printf("-1. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (total_vertices >= MAX_VERTICES) {
                printf("Maximum number of vertices reached!\n");
                continue;
            }
            graph[total_vertices++] = NULL;
        }
        else if (choice == 2) {
            int from_vertex, to_vertex;
            printf("Enter from_vertex : ");
            scanf("%d", &from_vertex);
            printf("Enter to_vertex : ");
            scanf("%d", &to_vertex);
            if (from_vertex < 0 || from_vertex >= total_vertices || to_vertex < 0 || to_vertex >= total_vertices) {
                printf("Invalid vertex number!\n");
                continue;
            }
            add_edge(from_vertex, to_vertex);
        }
        else if (choice == 3) {
            print_graph();
        }
        else if (choice == 4) {
            paranoid_check();
            printf("Graph is paranoidly correct!\n");
        }
    }

    return 0;
}