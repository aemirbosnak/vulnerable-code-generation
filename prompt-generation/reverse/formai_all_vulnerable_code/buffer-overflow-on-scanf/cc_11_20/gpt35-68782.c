//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 20

/* Structure for Graph */
typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int degree[MAX_VERTICES];
    int n_vertices;
} Graph;

int main()
{
    int i, j, color, max_color = 0;
    Graph g;

    /* Initializing the Graph */
    printf("Enter the number of vertices: ");
    scanf("%d", &g.n_vertices);

    for (i = 0; i < g.n_vertices; i++)
    {
        g.degree[i] = 0;

        for (j = 0; j < g.n_vertices; j++)
            g.edges[i][j] = 0;
    }

    /* Adding edges to the Graph */
    for (i = 0; i < g.n_vertices; i++)
    {
        int n, vertex;
        printf("Enter the number of edges for vertex %d: ", i+1);
        scanf("%d", &n);

        printf("Enter the vertices: ");
        for (j = 0; j < n; j++)
        {
            scanf("%d", &vertex);
            g.edges[i][vertex-1] = 1;
            g.degree[i]++;
        }
    }

    /* Assigning colors to the vertices */
    int vertex_colors[MAX_VERTICES];
    for (i = 0; i < g.n_vertices; i++)
    {
        int used_colors[MAX_COLORS] = {0};

        /* Checking colors of neighbors */
        for (j = 0; j < g.n_vertices; j++)
        {
            if (g.edges[i][j] && vertex_colors[j])
            {
                used_colors[vertex_colors[j]-1] = 1;
            }
        }

        /* Assigning the minimum possible unused color */
        for (color = 0; color < MAX_COLORS; color++)
        {
            if (!used_colors[color])
            {
                vertex_colors[i] = color+1;

                if (max_color < color+1)
                    max_color = color+1;

                break;
            }
        }
    }

    /* Printing the colored Graph */
    printf("\nColored Graph:\n");
    for (i = 0; i < g.n_vertices; i++)
    {
        printf("Vertex %d: Color %d\n", i+1, vertex_colors[i]);
    }

    printf("\nTotal number of colors required: %d\n", max_color);

    return 0;
}