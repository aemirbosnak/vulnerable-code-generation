//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 4
#define MAX_VERTICES 10

struct edge
{
    int src, dest;
};

int color[MAX_VERTICES];
int adj_list[MAX_VERTICES][MAX_VERTICES];
struct edge edges[MAX_VERTICES];
int num_vertices = 0, num_edges = 0;

void add_edge(int src, int dest)
{
    edges[num_edges].src = src;
    edges[num_edges].dest = dest;
    adj_list[src][dest] = 1;
    adj_list[dest][src] = 1;
    num_edges++;
}

int is_valid_color(int vertex, int c)
{
    for (int i=0; i<num_vertices; i++)
    {
        if (adj_list[vertex][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graph_coloring(int vertex)
{
    if (vertex == num_vertices)
        return 1;
    
    for (int i=0; i<MAX_COLORS; i++)
    {
        if (is_valid_color(vertex, i))
        {
            color[vertex] = i;
            if (graph_coloring(vertex+1))
                return 1;
            color[vertex] = -1;
        }
    }
    return 0;
}

int main()
{
    int num_players;
    
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    
    if (num_players <= 0)
    {
        printf("Invalid number of players!\n");
        return 0;
    }
    
    printf("Enter number of vertices (minimum %d): ", num_players);
    scanf("%d", &num_vertices);
    
    if (num_vertices < num_players)
    {
        printf("Number of vertices must be greater than or equal to the number of players!\n");
        return 0;
    }
    
    printf("Enter edges in the format 'src dest' (negative values to stop):\n");
    int src, dest;
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src < 0 || dest < 0)
            break;
        if (src >= num_vertices || dest >= num_vertices)
        {
            printf("Invalid vertex! Please try again.\n");
            continue;
        }
        add_edge(src, dest);
    }
    
    memset(color, -1, sizeof(color));
    
    if (graph_coloring(0))
    {
        printf("Colors assigned to vertices:\n");
        for (int i=0; i<num_vertices; i++)
            printf("Vertex %d: Color %d\n", i, color[i]);
        
        int player_color[MAX_COLORS] = {0};
        for (int i=0; i<num_vertices; i++)
            player_color[color[i]]++;
        
        printf("Player Colors:\n");
        for (int i=1; i<=num_players; i++)
            printf("Player %d: Color %d\n", i, player_color[i-1]);
    }
    else
    {
        printf("Graph cannot be colored with %d colors!\n", MAX_COLORS);
    }
    
    return 0;
}