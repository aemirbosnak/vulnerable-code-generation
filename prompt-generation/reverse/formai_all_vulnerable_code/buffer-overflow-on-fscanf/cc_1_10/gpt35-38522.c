//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_POINTS 1000

typedef struct {
  double x, y;
} Point;

typedef struct node_t {
  Point pt;
  int cluster_id;
  struct node_t *next;
} Node;

double euclidean_distance(Point a, Point b) {
  return sqrt(pow((b.x-a.x),2) + pow((b.y-a.y),2));
}

void add_node(Node **head, Point new_pt) {
  Node *new_node = malloc(sizeof(Node));
  new_node->pt = new_pt;
  new_node->cluster_id = -1;
  new_node->next = *head;
  *head = new_node;
}

void print_cluster(Node *head, int cluster_id) {
  printf("Cluster %d:\n", cluster_id);
  while (head != NULL) {
    if (head->cluster_id == cluster_id) {
      printf("(%f, %f)\n", head->pt.x, head->pt.y);
    }
    head = head->next;
  }
}

void merge_clusters(Node *head, int cluster_id_1, int cluster_id_2) {
  while (head != NULL) {
    if (head->cluster_id == cluster_id_2) {
      head->cluster_id = cluster_id_1;
    }
    head = head->next;
  }
}

int main() {
  Point points[MAX_NUM_POINTS];
  int num_points = 0;

  // Read points from file
  FILE *file = fopen("points.txt", "r");

  if (file != NULL) {
    while (fscanf(file, "%lf,%lf", &points[num_points].x, &points[num_points].y) == 2) {
      num_points++;
    }

    fclose(file);
  } else {
    printf("Error: Could not open file\n");
    return 1;
  }

  Node *head = NULL;

  // Populate linked list with points
  for (int i = 0; i < num_points; i++) {
    add_node(&head, points[i]);
  }

  // Set the cluster ID for each point to the point's index
  Node *curr_node = head;
  int cluster_id = 0;
  while (curr_node != NULL) {
    curr_node->cluster_id = cluster_id;
    curr_node = curr_node->next;
    cluster_id++;
  }

  // TODO: Implement clustering algorithm

  // Debugging output
  for (int i = 0; i < cluster_id; i++) {
    print_cluster(head, i);
  }

  return 0;
}