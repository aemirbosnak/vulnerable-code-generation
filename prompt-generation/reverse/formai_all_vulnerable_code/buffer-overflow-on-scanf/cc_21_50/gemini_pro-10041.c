//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#define DIM 100
#define POW(A) ((A)*(A))
#define ABS(A) ((A)>0?(A):-(A))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define MAX(A,B) ((A)>(B)?(A):(B))
#define P 5
#define log2(x) (31 - __builtin_clz(x))
#define UNUSED(x) (void)(x)

int m[DIM][DIM],d[DIM][DIM],q[DIM*DIM][3],s[DIM*DIM][2],ok[DIM*DIM],idx=3;

void dijkstra(){
  int x,y,i,j,k;
  for(i=0;i<DIM;i++)for(j=0;j<DIM;j++)d[i][j]=1<<30,ok[idx*DIM+i*DIM+j]=0;
  d[0][0]=0;ok[0]=1;
  while(idx--){
    x=-1;y=-1;
    for(i=0;i<DIM*DIM;i++)if(!ok[i]&&((x==-1)||(d[i/DIM][i%DIM]<d[x][y]))){x=i/DIM;y=i%DIM;}
    if(x==-1)break;
    for(i=MAX(x-1,0);i<=MIN(x+1,DIM-1);i++)for(j=MAX(y-1,0);j<=MIN(y+1,DIM-1);j++)if(m[x][y]!=m[i][j]&&d[x][y]+1<d[i][j]){
      d[i][j]=d[x][y]+1;
      q[idx][0]=i;q[idx][1]=j;q[idx][2]=d[i][j];
    }
    ok[idx*DIM+x*DIM+y]=1;
  }
}

int main(){
  int i,j,n,x,y,k,l,z,e,o,p;
  srand(728);
  scanf("%d",&n);
  m[0][0]=rand()%P;
  for(x=0;x<DIM;x++)for(y=0;y<DIM;y++)if(x>0||y>0){i=rand()%(POW(P)-1)+1;j=rand()%(POW(P)-1)+1;m[x][y]=(j*m[x-1][y]+i*m[x][y-1])%P;}
  for(x=0;x<DIM;x++)for(y=0;y<DIM;y++){z=0;k=x-1;l=y-1;if(k>=0&&l>=0){z|=1<<0;}k=x+1;l=y+1;if(k<DIM&&l<DIM){z|=1<<1;}k=x-1;if(k>=0){z|=1<<2;}k=x+1;if(k<DIM){z|=1<<3;}k=y+1;if(k<DIM){z|=1<<4;}k=y-1;if(k>=0){z|=1<<5;}m[x][y]=z;}
  dijkstra();
  for(i=1;i<DIM*DIM;i++){s[i][0]=q[i][0];s[i][1]=q[i][1];}
  for(i=1;i<DIM*DIM;i++){
    x=s[i][0];y=s[i][1];k=q[i][2]-q[i-1][2];
    if((m[x][y]&1<<0)){e=x-1;o=y;}
    if((m[x][y]&1<<1)){e=x+1;o=y;}
    if((m[x][y]&1<<2)){e=x;o=y-1;}
    if((m[x][y]&1<<3)){e=x;o=y+1;}
    if((m[x][y]&1<<4)){e=x;o=y+1;}
    if((m[x][y]&1<<5)){e=x;o=y-1;}
    p=m[e][o];m[e][o]=m[x][y];m[x][y]=p;
    if(m[e][o]<m[x][y]){
      for(j=i-1;j>0&&s[j][0]>s[j+1][0];j--){
        x=s[j][0];y=s[j][1];p=m[x][y];m[x][y]=m[e][o];m[e][o]=p;e=x;o=y;
      }
    }else for(j=i-1;j>0&&s[j][0]<s[j+1][0];j--){
      x=s[j][0];y=s[j][1];p=m[x][y];m[x][y]=m[e][o];m[e][o]=p;e=x;o=y;
    }
  }
  for(x=0;x<DIM;x++)for(y=0;y<DIM;y++)printf("%d ",m[x][y]);
  return 0;
}