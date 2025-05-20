//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MAP_SIZE 100
#define MAX_NAME_LENGTH 256

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  char *name;
  int num_vertices;
  Point *vertices;
} Polygon;

typedef struct {
  int num_polygons;
  Polygon *polygons;
} Map;

typedef struct {
  Point start;
  Point goal;
  Map *map;
} PathfindingProblem;

typedef struct {
  Point point;
  float g;
  float h;
  float f;
  struct Node *parent;
} Node;

typedef struct {
  int num_nodes;
  Node *nodes;
} PriorityQueue;

bool point_in_polygon(Point point, Polygon *polygon) {
  int i, j;
  bool inside = false;
  for (i = 0, j = polygon->num_vertices - 1; i < polygon->num_vertices; j = i++) {
    if ((polygon->vertices[i].y > point.y) != (polygon->vertices[j].y > point.y) &&
        (point.x < (polygon->vertices[j].x - polygon->vertices[i].x) * (point.y - polygon->vertices[i].y) / (polygon->vertices[j].y - polygon->vertices[i].y) + polygon->vertices[i].x)) {
      inside = !inside;
    }
  }
  return inside;
}

bool is_blocked(Point point, Map *map) {
  int i;
  for (i = 0; i < map->num_polygons; i++) {
    if (point_in_polygon(point, &map->polygons[i])) {
      return true;
    }
  }
  return false;
}

float calculate_h(Point point, Point goal) {
  return sqrtf(powf(point.x - goal.x, 2) + powf(point.y - goal.y, 2));
}

Node *create_node(Point point, float g, Node *parent) {
  Node *node = malloc(sizeof(Node));
  node->point = point;
  node->g = g;
  node->h = calculate_h(point, parent->point);
  node->f = node->g + node->h;
  node->parent = parent;
  return node;
}

void insert_node(PriorityQueue *queue, Node *node) {
  int i;
  for (i = 0; i < queue->num_nodes; i++) {
    if (node->f < queue->nodes[i].f) {
      break;
    }
  }
  for (int j = queue->num_nodes; j > i; j--) {
    queue->nodes[j] = queue->nodes[j - 1];
  }
  queue->nodes[i] = *node;
  queue->num_nodes++;
}

Node *remove_node(PriorityQueue *queue) {
  queue->num_nodes--;
  return &queue->nodes[queue->num_nodes];
}

PathfindingProblem *create_problem(char *map_file, Point start, Point goal) {
  PathfindingProblem *problem = malloc(sizeof(PathfindingProblem));
  problem->start = start;
  problem->goal = goal;
  problem->map = malloc(sizeof(Map));
  FILE *file = fopen(map_file, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening map file: %s\n", map_file);
    exit(1);
  }
  fscanf(file, "%d", &problem->map->num_polygons);
  problem->map->polygons = malloc(sizeof(Polygon) * problem->map->num_polygons);
  for (int i = 0; i < problem->map->num_polygons; i++) {
    problem->map->polygons[i].name = malloc(sizeof(char) * MAX_NAME_LENGTH);
    fscanf(file, "%s", problem->map->polygons[i].name);
    fscanf(file, "%d", &problem->map->polygons[i].num_vertices);
    problem->map->polygons[i].vertices = malloc(sizeof(Point) * problem->map->polygons[i].num_vertices);
    for (int j = 0; j < problem->map->polygons[i].num_vertices; j++) {
      fscanf(file, "%d %d", &problem->map->polygons[i].vertices[j].x, &problem->map->polygons[i].vertices[j].y);
    }
  }
  fclose(file);
  return problem;
}

void free_problem(PathfindingProblem *problem) {
  for (int i = 0; i < problem->map->num_polygons; i++) {
    free(problem->map->polygons[i].name);
    free(problem->map->polygons[i].vertices);
  }
  free(problem->map->polygons);
  free(problem->map);
  free(problem);
}

Node *a_star(PathfindingProblem *problem) {
  PriorityQueue open_set;
  open_set.num_nodes = 0;
  open_set.nodes = malloc(sizeof(Node) * MAX_MAP_SIZE * MAX_MAP_SIZE);
  insert_node(&open_set, create_node(problem->start, 0.0f, NULL));
  while (open_set.num_nodes > 0) {
    Node *current = remove_node(&open_set);
    if (current->point.x == problem->goal.x && current->point.y == problem->goal.y) {
      return current;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        Point neighbor = {current->point.x + i, current->point.y + j};
        if (!is_blocked(neighbor, problem->map)) {
          float g = current->g + 1.0f;
          Node *neighbor_node = create_node(neighbor, g, current);
          insert_node(&open_set, neighbor_node);
        }
      }
    }
  }
  return NULL;
}

void print_path(Node *node) {
  if (node->parent != NULL) {
    print_path(node->parent);
  }
  printf("(%d, %d)\n", node->point.x, node->point.y);
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <map_file> <start_x> <start_y> <goal_x> <goal_y>\n", argv[0]);
    exit(1);
  }
  Point start = {atoi(argv[2]), atoi(argv[3])};
  Point goal = {atoi(argv[4]), atoi(argv[5])};
  PathfindingProblem *problem = create_problem(argv[1], start, goal);
  Node *path = a_star(problem);
  if (path != NULL) {
    print_path(path);
  } else {
    printf("No path found.\n");
  }
  free_problem(problem);
  return 0;
}