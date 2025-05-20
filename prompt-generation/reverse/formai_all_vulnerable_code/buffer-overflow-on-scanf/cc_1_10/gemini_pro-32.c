//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph {
	int n;
	int **adj;
} graph;

typedef struct node {
	int color;
	struct node *next;
} node;

typedef struct queue {
	node *head;
	node *tail;
} queue;

graph *create_graph(int n)
{
	graph *g = malloc(sizeof(graph));
	g->n = n;
	g->adj = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		g->adj[i] = malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			g->adj[i][j] = 0;
		}
	}
	return g;
}

void add_edge(graph *g, int u, int v)
{
	g->adj[u][v] = 1;
	g->adj[v][u] = 1;
}

void print_graph(graph *g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%d ", g->adj[i][j]);
		}
		printf("\n");
	}
}

queue *create_queue()
{
	queue *q = malloc(sizeof(queue));
	q->head = NULL;
	q->tail = NULL;
	return q;
}

void enqueue(queue *q, int color)
{
	node *new_node = malloc(sizeof(node));
	new_node->color = color;
	new_node->next = NULL;
	if (q->tail == NULL) {
		q->head = new_node;
		q->tail = new_node;
	} else {
		q->tail->next = new_node;
		q->tail = new_node;
	}
}

int dequeue(queue *q)
{
	if (q->head == NULL) {
		return -1;
	} else {
		int color = q->head->color;
		node *old_head = q->head;
		q->head = q->head->next;
		if (q->head == NULL) {
			q->tail = NULL;
		}
		free(old_head);
		return color;
	}
}

int is_empty(queue *q)
{
	return q->head == NULL;
}

int *graph_coloring(graph *g)
{
	int *colors = malloc(g->n * sizeof(int));
	for (int i = 0; i < g->n; i++) {
		colors[i] = -1;
	}

	queue *q = create_queue();
	enqueue(q, 0);
	while (!is_empty(q)) {
		int color = dequeue(q);
		for (int i = 0; i < g->n; i++) {
			if (g->adj[color][i] == 1 && colors[i] == -1) {
				enqueue(q, i);
				colors[i] = (color + 1) % g->n;
			}
		}
	}

	free(q);
	return colors;
}

int main()
{
	int n;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);

	graph *g = create_graph(n);
	printf("Enter the edges (u, v):\n");
	int u, v;
	while (scanf("%d %d", &u, &v) != EOF) {
		add_edge(g, u, v);
	}

	int *colors = graph_coloring(g);
	printf("The colors of the vertices are:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", colors[i]);
	}
	printf("\n");

	free(colors);
	free(g);

	return 0;
}