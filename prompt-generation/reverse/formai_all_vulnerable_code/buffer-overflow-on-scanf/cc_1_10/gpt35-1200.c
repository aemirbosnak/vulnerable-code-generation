//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100

struct node{
  int data;
  struct node* next;
};

struct node* graph[101] = {NULL}; // adjacency list of the graph
int visited[101] = {0}; // to track visited nodes
int dist[101] = {0}; // to store distance from starting node
int queue[MAX_QUEUE_SIZE];
int front = 0; // index of the first element of the queue
int rear = -1; // index of the last element of the queue

// function to add an edge to the graph
void add_edge(int u, int v){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = v;
  temp->next = graph[u];
  graph[u] = temp;
}

// function to perform Breadth-First Search
void bfs(int start, int end){
  visited[start] = 1;
  dist[start] = 0;
  queue[++rear] = start; // enqueue the starting node
  while(front <= rear){ // while queue is not empty
    int curr = queue[front++]; // dequeue the front node
    if(curr == end) return; // if the destination is reached
    struct node* temp = graph[curr];
    while(temp != NULL){ // loop through adjacent nodes
      int adj = temp->data;
      if(visited[adj] == 0){ // if the node is not visited
        visited[adj] = 1;
        dist[adj] = dist[curr] + 1;
        queue[++rear] = adj; // enqueue the adjacent node
      }
      temp = temp->next;
    }
  }
}

int main(){
  int n, e, u, v, start, end;
  printf("Enter the number of nodes and edges: ");
  scanf("%d %d", &n, &e);
  printf("Enter the edges:\n");
  for(int i=0; i<e; i++){
    scanf("%d %d", &u, &v);
    add_edge(u, v);
    add_edge(v, u); // for undirected graph
  }
  printf("Enter the starting and ending nodes: ");
  scanf("%d %d", &start, &end);
  bfs(start, end);
  if(visited[end] == 1){
    printf("Shortest path from %d to %d is %d\n", start, end, dist[end]);
  }
  else{
    printf("No path found from %d to %d\n", start, end);
  }
  return 0;
}