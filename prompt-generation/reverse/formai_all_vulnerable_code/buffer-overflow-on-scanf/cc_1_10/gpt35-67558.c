//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for each color
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define PURPLE 5

// Define constants for vertices
#define VERTICES 10
#define EDGES 15

int graph[VERTICES][VERTICES]; // The graph
int colors[VERTICES]; // An array to store the colors
int players; // Number of players
int turns; // Number of turns
int currentPlayer; // The current player
int winner; // The winning player

// Function to color a vertex with a specific color
void colorVertex(int vertex, int color)
{
    colors[vertex] = color;
}

// Function to check if a vertex has a specific color
int hasColor(int vertex, int color)
{
    return colors[vertex] == color;
}

// Function to check if a graph is properly colored
int isProperlyColored()
{
    int i, j;
    for (i = 0; i < VERTICES; i++)
    {
        for (j = 0; j < VERTICES; j++)
        {
            if (graph[i][j] == 1 && hasColor(i, colors[j]))
            {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get the color of a vertex
char* getColorName(int color)
{
    switch (color)
    {
        case RED:
            return "Red";
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case YELLOW:
            return "Yellow";
        case PURPLE:
            return "Purple";
    }
}

// Function to print the graph and colors
void printGraph()
{
    int i, j;
    for (i = 0; i < VERTICES; i++)
    {
        printf("%d - ", i+1);
        for (j = 0; j < VERTICES; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("   Color: %s\n", getColorName(colors[i]));
    }
}

// Function to select a random vertex
int getRandomVertex()
{
    return rand() % VERTICES;
}

// Function to select a random color
int getRandomColor()
{
    return rand() % 5 + 1; // There are 5 colors
}

// Function to get the next player
int getNextPlayer()
{
    return (currentPlayer + 1) % players;
}

// Function to play one turn
void playTurn()
{
    int vertex, color;
    do
    {
        printf("Player %d, select a vertex to color (1-%d): ", currentPlayer+1, VERTICES);
        scanf("%d", &vertex);
        vertex--; // Subtract one, since vertices are numbered from 1 to VERTICES
    } while (vertex < 0 || vertex >= VERTICES);

    do
    {
        printf("Player %d, select a color to use (1: Red, 2: Green, 3: Blue, 4: Yellow, 5: Purple): ", currentPlayer+1);
        scanf("%d", &color);
    } while (color < 1 || color > 5);

    colorVertex(vertex, color);
    printf("Player %d has colored vertex %d with color %s\n", currentPlayer+1, vertex+1, getColorName(color));

    if (isProperlyColored())
    {
        winner = currentPlayer+1;
    }
    currentPlayer = getNextPlayer();
    turns++;
}

// Function to play the game
void playGame()
{
    // Initialize the graph
    int i, j;
    for (i = 0; i < VERTICES; i++)
    {
        for (j = 0; j < VERTICES; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Create random edges
    srand(time(NULL)); // Seed the random number generator
    int edgeCount = 0;
    while (edgeCount < EDGES)
    {
        int u = getRandomVertex();
        int v = getRandomVertex();
        if (u != v && graph[u][v] != 1)
        {
            graph[u][v] = 1;
            graph[v][u] = 1;
            edgeCount++;
        }
    }

    // Initialize the colors
    for (i = 0; i < VERTICES; i++)
    {
        colors[i] = 0;
    }

    // Initialize the game state
    currentPlayer = 0;
    turns = 0;
    winner = 0;

    // Play the game
    while (winner == 0)
    {
        printf("\n");
        printf("Turn %d:\n", turns+1);
        printf("-------\n");
        printGraph();
        playTurn();
    }

    // Print the results
    printf("\n");
    printf("Game over! Player %d wins!\n", winner);
}

int main() 
{
    // Welcome message and player count input
    printf("Welcome to Multiplayer Graph Coloring Sim!\n");
    printf("Enter the number of players: ");
    scanf("%d", &players);
    printf("Starting game with %d players...\n", players);

    // Play the game
    playGame();

    return 0;
}