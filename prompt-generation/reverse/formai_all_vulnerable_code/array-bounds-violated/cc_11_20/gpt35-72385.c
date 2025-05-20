//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include<stdio.h>
int G[50][50], nodes, color[50];
void GraphColor(int k){
  int available[50], i, j, m=0;
  for (i=1; i<=nodes; i++){
    available[i]=1;
  }
  while (m<k){
    int max_n=-1;
    for (i=1; i<=nodes; i++){
      int degree=0;
      for (j=1; j<=nodes; j++){
        if (G[i][j] && color[j]!=-1){
          degree++;
        }
      }
      if (color[i]==-1 && degree > max_n){
        max_n=i;
      }
    }
    for (i=1; i<=nodes; i++){
      if (G[max_n][i] && color[i]!=-1){
        available[color[i]]=0;
      }
    }
    for (i=1; i<=nodes; i++){
      if (available[i]){
        color[max_n]=i;
        break;
      }
    }
    m++;
    for(i=1;i<=nodes;i++) {
      if(G[max_n][i] && color[i]==-1){
        color[i]=0;
      }
    }
    printf("Coloring node %d with %d\n", max_n, color[max_n]); 
  }
}
void main(){
  int i,j,k;
  printf("\nEnter no. of nodes: ");
  scanf("%d",&nodes);
  printf("\nEnter adjacency matrix:\n");
  for(i=1;i<=nodes;i++) {
    for(j=1;j<=nodes;j++){
      scanf("%d",&G[i][j]);
    }
  }
  printf("\nMaximum no of colors available: ");
  scanf("%d", &k);
  for(i=1;i<=nodes;i++){
    color[i]=-1;
  }
  GraphColor(k);
  printf("\nColoring Resutls:\n");
  for(i=1; i<=nodes; i++){
    printf("Color Node %d with color %d\n",i,color[i]);
  }
}