//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#define N 10
char g[N][N],s[N][N],t[N][N],f[N][N],p[N][N],d[N][N],dp[N][N],*o="\v",*h=" ",*b="~",*w="m";
void u(int x,int y,int*c){
  if(x<0||x>=N||y<0||y>=N||g[x][y]==b||f[x][y])return;
  if(d[x][y]<*c){
    *c=d[x][y];
    d[x][y]=-1;
    u(x-1,y,c);
    u(x+1,y,c);
    u(x,y-1,c);
    u(x,y+1,c);
  }
}
int main(){
  int x=0,y=0,z=0,v=0,e=0,i=0,j=0,q,c=0,l=0;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%c ",&g[i][j]);
      if(g[i][j]==w){x=i;y=j;z=1;}
      if(g[i][j]==o){v=i;e=j;}
    }
  }
  for(;z;z=0){
    for(i=0;i<N;i++)for(j=0;j<N;j++){
      s[i][j]=g[i][j];
      f[i][j]=0;
      t[i][j]=0;
      p[i][j]=0;
      d[i][j]=l++;
      dp[i][j]=l++;
    }
    s[x][y]=h;
    u(x,y,&c);
    q=c;
    e=0;
    for(i=0;i<N;i++)for(j=0;j<N;j++){if(s[i][j]==h){p[i][j]=1;t[i][j]=q;}}
    j=e=0;
    while(e){
      z=0;
      for(i=0;i<N;i++){
        for(j=0;j<N;j++){
          if(s[i][j]==h){
            if(i>0&&s[i-1][j]==o){e=0;q=t[i-1][j];x=i-1;y=j;z=1;}
            if(j>0&&s[i][j-1]==o){e=0;q=t[i][j-1];x=i;y=j-1;z=1;}
            if(i<N-1&&s[i+1][j]==o){e=0;q=t[i+1][j];x=i+1;y=j;z=1;}
            if(j<N-1&&s[i][j+1]==o){e=0;q=t[i][j+1];x=i;y=j+1;z=1;}
          }
        }
      }
      if(z){
        for(i=0;i<N;i++)for(j=0;j<N;j++){if(s[i][j]==w||s[i][j]==o){p[i][j]=1;t[i][j]=q;}}
        e=1;
        for(i=x,j=y;i!=v||j!=e;i=v,j=e){x=v;y=e;c=1<<30;u(i-1,j,&c);v=i-1;e=j;
          c=1<<30;u(i,j-1,&c);v=i;e=j-1;
          c=1<<30;u(i+1,j,&c);v=i+1;e=j;
          c=1<<30;u(i,j+1,&c);v=i;e=j+1;
        }
      }
    }
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if(p[i][j]){
          if(g[i][j]==w)g[i][j]=h;
          if(g[i][j]==h)g[i][j]=w;
          if(g[i][j]==b)g[i][j]=h;
        }
      }
    }
  }
  for(i=0;i<N;i++){for(j=0;j<N;j++){printf("%c",g[i][j]);}printf("\n");}
  return 0;
}