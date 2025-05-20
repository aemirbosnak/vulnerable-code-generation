//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define a 2D array to represent the maze
int maze[5][5] = {{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0}};

// Define the direction constants
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Define the DFS algorithm
void dfs(int x, int y)
{
	// If the cell is out of bounds or the cell is blocked, return
	if (x < 0 || x >= 5 || y < 0 || y >= 5 || maze[x][y] == 1)
		return;

	// Mark the cell as visited
	maze[x][y] = 2;

	// Iterate over the four directions
	for (int i = 0; i < 4; i++)
	{
		// Check if the direction is valid
		int nx = x + dx[i];
		int ny = y + dy[i];

		// If the cell is not visited and the direction is valid, call dfs recursively
		if (maze[nx][ny] == 0)
			dfs(nx, ny);
	}
}

int main()
{
	// Initialize the maze
	maze[0][0] = 2;

	// Perform DFS
	dfs(0, 0);

	// Print the maze
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			printf("%d ", maze[x][y]);
		}
		printf("\n");
	}

	return 0;
}