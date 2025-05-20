//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
int n,m;
int adj[100][100],color[100];
void input_graph(){
   int i,j,s,d;
   printf("\nEnter number of Vertices: ");
   scanf("%d",&n);
   printf("Enter number of edges: ");
   scanf("%d",&m);
   printf("\nEnter source and destination vertices of edges: \n");
   for(i=1;i<=m;i++){
      printf("Edge %d : ",i);
      scanf("%d %d",&s,&d);
      adj[s][d]=1;
      adj[d][s]=1;
   }
}
void print_graph(){
   int i,j;
   printf("\nAdjacency matrix of Graph:\n");
   for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
         printf("%d ",adj[i][j]);
      printf("\n");
   }
}
int isSafe(int v,int c){
   int i;
   for(i=1;i<=n;i++){
      if(adj[v][i] && color[i]==c)
         return 0;
   }
   return 1;
}
int graph_coloring(int v){
   int i,c;
   if(v>n)
      return 1;
   for(c=1;c<=n;c++){
      if(isSafe(v,c)){
         color[v]=c;
         if(graph_coloring(v+1))
            return 1;
         color[v]=0;
      }
   }
   return 0;
}
int main(){
   int i,chromatic_num;
   input_graph();
   print_graph();
   for(i=1;i<=n;i++)
      color[i]=0;
   if(graph_coloring(1))
      printf("\nGraph can be colored using %d colors.\n",chromatic_num);
   else
      printf("\nGraph cannot be colored using %d colors.\n",chromatic_num);
   return 0;
}