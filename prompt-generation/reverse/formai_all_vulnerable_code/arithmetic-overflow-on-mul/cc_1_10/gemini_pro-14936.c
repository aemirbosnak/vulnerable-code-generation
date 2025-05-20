//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a cell in the maze.
typedef struct Cell
{
    int x;              // X-coordinate of the cell.
    int y;              // Y-coordinate of the cell.
    bool visited;       // Whether the cell has been visited.
    bool north;         // Whether the northern wall is present.
    bool east;          // Whether the eastern wall is present.
    bool south;         // Whether the southern wall is present.
    bool west;          // Whether the western wall is present.
} Cell;

// Structure to represent the maze.
typedef struct Maze
{
    int width;           // Width of the maze.
    int height;          // Height of the maze.
    Cell** cells;        // Array of cells representing the maze.
} Maze;

// Function to create a new maze.
Maze* createMaze(int width, int height)
{
    // Allocate memory for the maze.
    Maze* maze = malloc(sizeof(Maze));
    if (maze == NULL)
    {
        return NULL;
    }

    // Initialize the maze.
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(sizeof(Cell*) * height);
    if (maze->cells == NULL)
    {
        free(maze);
        return NULL;
    }

    for (int i = 0; i < height; i++)
    {
        maze->cells[i] = malloc(sizeof(Cell) * width);
        if (maze->cells[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(maze->cells[j]);
            }
            free(maze->cells);
            free(maze);
            return NULL;
        }
    }

    // Initialize the cells of the maze.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            maze->cells[i][j].x = j;
            maze->cells[i][j].y = i;
            maze->cells[i][j].visited = false;
            maze->cells[i][j].north = true;
            maze->cells[i][j].east = true;
            maze->cells[i][j].south = true;
            maze->cells[i][j].west = true;
        }
    }

    // Return the maze.
    return maze;
}

// Function to free the memory allocated for the maze.
void freeMaze(Maze* maze)
{
    // Free the cells of the maze.
    for (int i = 0; i < maze->height; i++)
    {
        free(maze->cells[i]);
    }

    // Free the array of cells.
    free(maze->cells);

    // Free the maze.
    free(maze);
}

// Function to print the maze.
void printMaze(Maze* maze)
{
    // Print the top border of the maze.
    for (int i = 0; i < maze->width * 2 + 1; i++)
    {
        printf("#");
    }
    printf("\n");

    // Print the maze.
    for (int i = 0; i < maze->height; i++)
    {
        // Print the western border of the cell.
        for (int j = 0; j < maze->width; j++)
        {
            if (maze->cells[i][j].west)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        // Print the northern border of the cell.
        for (int j = 0; j < maze->width; j++)
        {
            if (maze->cells[i][j].north)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");

        // Print the eastern border of the cell.
        for (int j = 0; j < maze->width; j++)
        {
            if (maze->cells[i][j].east)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        // Print the southern border of the cell.
        for (int j = 0; j < maze->width; j++)
        {
            if (maze->cells[i][j].south)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the bottom border of the maze.
    for (int i = 0; i < maze->width * 2 + 1; i++)
    {
        printf("#");
    }
    printf("\n");
}

// Function to find a path through the maze.
bool findPath(Maze* maze, int x, int y)
{
    // If the cell is out of bounds, return false.
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
    {
        return false;
    }

    // If the cell has been visited, return false.
    if (maze->cells[y][x].visited)
    {
        return false;
    }

    // If the cell is the goal, return true.
    if (x == maze->width - 1 && y == maze->height - 1)
    {
        return true;
    }

    // Mark the cell as visited.
    maze->cells[y][x].visited = true;

    // Recursively call findPath on the adjacent cells.
    bool foundPath = false;
    if (!maze->cells[y][x].north)
    {
        foundPath = findPath(maze, x, y - 1);
    }
    if (!foundPath && !maze->cells[y][x].east)
    {
        foundPath = findPath(maze, x + 1, y);
    }
    if (!foundPath && !maze->cells[y][x].south)
    {
        foundPath = findPath(maze, x, y + 1);
    }
    if (!foundPath && !maze->cells[y][x].west)
    {
        foundPath = findPath(maze, x - 1, y);
    }

    // If a path was found, return true.
    if (foundPath)
    {
        return true;
    }

    // Otherwise, unmark the cell as visited and return false.
    maze->cells[y][x].visited = false;
    return false;
}

// Main function.
int main()
{
    // Create a maze.
    Maze* maze = createMaze(10, 10);

    // Print the maze.
    printMaze(maze);

    // Find a path through the maze.
    bool foundPath = findPath(maze, 0, 0);

    // Print whether a path was found.
    if (foundPath)
    {
        printf("A path was found!\n");
    }
    else
    {
        printf("No path was found.\n");
    }

    // Free the memory allocated for the maze.
    freeMaze(maze);

    return 0;
}