//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct {
	int x, y;
} pos_t;

typedef struct {
	pos_t pos;
	int g, h, f;
} node_t;

int compare(const void *a, const void *b) {
	node_t *na = (node_t *)a;
	node_t *nb = (node_t *)b;
	return na->f - nb->f;
}

int heuristic(pos_t a, pos_t b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	int w, h;
	scanf("%d %d", &w, &h);

	char grid[h][w];
	int map[h][w];
	for (int i = 0; i < h; i++) {
		scanf("%s", grid[i]);
		for (int j = 0; j < w; j++) {
			map[i][j] = grid[i][j] == '#' ? -1 : 0;
		}
	}

	pos_t start, end;
	scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);

	node_t open[w * h];
	int open_size = 0;

	node_t closed[w * h];
	int closed_size = 0;

	open[open_size++] = (node_t){start, 0, heuristic(start, end), heuristic(start, end)};

	while (open_size > 0) {
		qsort(open, open_size, sizeof(node_t), compare);
		node_t current = open[0];
		open_size--;

		if (current.pos.x == end.x && current.pos.y == end.y) {
			printf("Reached the goal!\n");
			break;
		}

		closed[closed_size++] = current;

		pos_t neighbors[4] = {
			{current.pos.x - 1, current.pos.y},
			{current.pos.x + 1, current.pos.y},
			{current.pos.x, current.pos.y - 1},
			{current.pos.x, current.pos.y + 1}
		};

		for (int i = 0; i < 4; i++) {
			pos_t neighbor = neighbors[i];
			if (neighbor.x < 0 || neighbor.x >= w || neighbor.y < 0 || neighbor.y >= h || map[neighbor.y][neighbor.x] == -1) {
				continue;
			}

			int g = current.g + 1;
			int h = heuristic(neighbor, end);
			int f = g + h;

			int found = 0;
			for (int j = 0; j < open_size; j++) {
				if (open[j].pos.x == neighbor.x && open[j].pos.y == neighbor.y) {
					found = 1;
					if (open[j].f > f) {
						open[j].f = f;
						open[j].g = g;
					}
				}
			}

			if (!found) {
				open[open_size++] = (node_t){neighbor, g, h, f};
			}
		}
	}

	if (open_size == 0) {
		printf("No path found.\n");
	}

	return 0;
}