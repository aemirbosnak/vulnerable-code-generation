//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int x, y;
}Point;

Point start, end;
int map[101][101], visited[101][101];

void init_map(int n, int m){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d", &map[i][j]);
      visited[i][j] = 0;
    }
  }
}

void print_map(int n, int m){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
}

int is_safe(int n, int m, int x, int y){
  return (x>=1 && x<=n && y>=1 && y<=m && map[x][y]==1 && !visited[x][y]);
}

int find_path(int n, int m, Point p){
  if(p.x == end.x && p.y == end.y) return 1;
  visited[p.x][p.y] = 1;
  
  if(is_safe(n, m, p.x+1, p.y)){
    if(find_path(n, m, (Point){p.x+1, p.y})) return 1;
  }
  if(is_safe(n, m, p.x, p.y+1)){
    if(find_path(n, m, (Point){p.x, p.y+1})) return 1;
  }
  if(is_safe(n, m, p.x-1, p.y)){
    if(find_path(n, m, (Point){p.x-1, p.y})) return 1;
  }
  if(is_safe(n, m, p.x, p.y-1)){
    if(find_path(n, m, (Point){p.x, p.y-1})) return 1;
  }
  
  visited[p.x][p.y] = 0;
  return 0;
}

int main(){
  int n, m;
  printf("Enter maze size (n x m): ");
  scanf("%d %d", &n, &m);
  printf("Enter maze:\n");
  init_map(n, m);
  
  printf("Enter start location (x, y): ");
  scanf("%d %d", &start.x, &start.y);
  printf("Enter end location (x, y): ");
  scanf("%d %d", &end.x, &end.y);
  
  printf("Maze:\n");
  print_map(n, m);
  
  if(find_path(n, m, start)){
    printf("Path found!\n");
  }
  else{
    printf("Path not found!\n");
  }
  
  return 0;
}