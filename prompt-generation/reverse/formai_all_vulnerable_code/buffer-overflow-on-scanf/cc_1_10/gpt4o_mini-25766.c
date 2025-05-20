//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 20 // Maximum number of nodes

typedef struct {
    int num_players;
    int graph[MAX_NODES][MAX_NODES];
    int colors[MAX_NODES];
} GameState;

void init_game(GameState *state, int num_players, int edges[][2], int num_edges) {
    state->num_players = num_players;

    // Initialize graph
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            state->graph[i][j] = 0;
        }
        state->colors[i] = -1; // -1 indicates no color assigned
    }

    // Build graph from edges
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        state->graph[u][v] = 1;
        state->graph[v][u] = 1;
    }
}

bool is_color_valid(GameState *state, int node, int color) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (state->graph[node][i] && state->colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(GameState *state, int node) {
    if (node == MAX_NODES) {
        return true; // All nodes are colored successfully
    }

    for (int color = 0; color < state->num_players; color++) {
        if (is_color_valid(state, node, color)) {
            state->colors[node] = color;
            if (graph_coloring_util(state, node + 1)) {
                return true;
            }
            state->colors[node] = -1; // Reset color
        }
    }
    return false;
}

void print_solution(GameState *state) {
    printf("Graph Coloring Solution:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        if (state->colors[i] != -1) {
            printf("Node %d -> Color %d\n", i, state->colors[i]);
        }
    }
}

int main() {
    GameState game;
    int num_players;
    int num_edges;
    int edges[MAX_NODES][2];

    printf("Enter number of players: ");
    scanf("%d", &num_players);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges:\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    init_game(&game, num_players, edges, num_edges);

    if (graph_coloring_util(&game, 0)) {
        print_solution(&game);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}