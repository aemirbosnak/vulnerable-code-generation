//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: random
#include <stdio.h>
#define ROW 10
#define COL 10

struct node{
  int x, y, f, g, h;
  struct node *parent;
};

struct node *openList[ROW * COL], *closedList[ROW * COL];

int nOpen = 0, nClosed = 0;
struct node start, goal;
int graph[ROW][COL];
int dirX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void insert(struct node *n);
struct node *pop();

int isValid(int x, int y){
  return x >= 0 && x < ROW && y >= 0 && y < COL;
}

int distance(int x1, int y1, int x2, int y2){
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
  int i, j;
  for(i = 0; i < ROW; i++){
    for(j = 0; j < COL; j++){
      scanf("%d", &graph[i][j]);
    }
  }
  scanf("%d %d %d %d", &start.x, &start.y, &goal.x, &goal.y);

  start.parent = NULL;
  start.f = 0; start.g = 0; start.h = distance(start.x, start.y, goal.x, goal.y);
  insert(&start);

  struct node *q;
  while(nOpen > 0){
    q = pop();
    openList[q->y*ROW+q->x] = NULL;
    closedList[nClosed] = q;
    nClosed++;

    if(q->x == goal.x && q->y == goal.y){
      // Goal Found!!
      printf("Path Found!\n");
      while(q != NULL){
        printf("(%d, %d) -> ", q->x, q->y);
        q = q->parent;
      }
      break;
    }

    for(i = 0; i < 8; i++){
      int x2 = q->x + dirX[i];
      int y2 = q->y + dirY[i];

      if(isValid(x2, y2) && graph[y2][x2] != 0){
        int g2 = q->g + graph[y2][x2];
        int h2 = distance(x2, y2, goal.x, goal.y);
        int f2 = g2 + h2;

        int index = y2*ROW+x2;
        struct node *n2 = openList[index];
        if(n2 == NULL){
          n2 = closedList[index];
        }

        if(n2 == NULL || n2->f > f2){
          if(n2 != NULL){
            // Remove it from Closed List
            for(j = 0; j < nClosed; j++){
              if(n2 == closedList[j]){
                closedList[j] = closedList[nClosed-1];
                nClosed--;
                break;
              }
            }
          }
          // Insert it to Open List
          n2 = (struct node *)malloc(sizeof(struct node));
          n2->x = x2; n2->y = y2;
          n2->f = f2; n2->g = g2; n2->h = h2;
          n2->parent = q;
          insert(n2);
          openList[index] = n2;
        }
      }
    }
  }

  for(i = 0; i < nOpen; i++){
    free(openList[i]);
  }
  for(i = 0; i < nClosed; i++){
    free(closedList[i]);
  }

  return 0;
}

void insert(struct node *n){
  int i;
  if(nOpen == 0){
    openList[0] = n;
    nOpen++;
    return;
  }
  for(i = 0; i < nOpen; i++){
    if(n->f <= openList[i]->f){
      break;
    }
  }
  for(int j = nOpen; j > i; j--){
    openList[j] = openList[j-1];
  }
  openList[i] = n;
  nOpen++;
}

struct node *pop(){
  nOpen--;
  struct node *n = openList[0];
  for(int i = 1; i < nOpen; i++){
    openList[i-1] = openList[i];
  }
  openList[nOpen] = NULL;
  return n;
}