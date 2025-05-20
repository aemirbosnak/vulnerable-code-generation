//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#define x(y) ((y[0]>='0'&&y[0]<='9')||y[0]=='-'?atoi(y):0)  
int mx(int a,int b){return a>b?a:b;}
int mn(int a,int b){return a<b?a:b;}
int d[1010][1010],c[1010][1010],h[1010],v[1010],gn[1010][1010];  
int cmp1(const void *a,const void *b){return *(int*)a-*(int*)b;}
int cmp2(const void *a,const void *b){return *(int*)b-*(int*)a;}
int que1[2010],f1=0,r1=-1,que2[2010],f2=0,r2=-1,vis[1010]; 
int n,m,cnt=0,maxh=0,minv=1e9,nowh;  
int check(int x,int y){ return x<=n&&x>=1&&y<=m&&y>=1&&(d[x][y]==0?1:0); }  
int change(int i){return (i&1)?i+1:i-1;}  
void init(){  
    scanf("%d%d",&n,&m);  
    int i,j,xx,yy,tt;  
    for(i=1;i<=n;i++)  
        for(j=1;j<=m;j++){  
            scanf("%d",&d[i][j]);  
            c[i][j]=d[i][j];  
        }  

    for(i=1;i<=n;i++){  
        for(j=1;j<=m;j++)  
            if(d[i][j])  
                h[i]++,v[j]++;  
    }
    for(i=1;i<=n;i++)
        maxh+=h[i];
    for(j=1;j<=m;j++)
        minv=mn(minv,v[j]);  
} 

int dh(int i)
{
    int j,res=0;  
    for(j=1;j<=m;j++)  
        res+=gn[i][j]*c[i][j];  
    return res;  
}  

int dv(int j)
{
    int i,res=0;  
    for(i=1;i<=n;i++)  
        res+=gn[i][j]*c[i][j];  
    return res;  
}  

int ch(int i,int change)
{
    int j,res=0;  
    for(j=1;j<=m;j++)  
        res+=gn[i][j]*c[i][j+change];  
    return res;  
}  

int cv(int j,int change)
{
    int i,res=0;  
    for(i=1;i<=n;i++)  
        res+=gn[i][j]*c[i+change][j];  
    return res;  
} 

void flip1(int i)
{
    nowh-=(mx(c[i][1],0)-mx(c[i][m]-1,0))*h[i];
    if(dh(i)<=dv(1)+nowh){
        int j;
        nowh=dh(i)-dv(1);
        for(j=1;j<=m;j++)
            gn[i][j]=change(gn[i][j]);
    }
}  

void flip2(int j)
{
    nowh-=(mx(c[1][j],0)-mx(c[n][j]-1,0))*v[j];
    if(dv(j)<=dh(1)+nowh){
        int i;
        nowh=dv(j)-dh(1);
        for(i=1;i<=n;i++)
            gn[i][j]=change(gn[i][j]);
    }
}  

void exchange(int x1,int y1,int x2,int y2)
{
    gn[x1][y1]=change(gn[x1][y1]);  
    gn[x2][y2]=change(gn[x2][y2]);  
    int tt=c[x1][y1];c[x1][y1]=c[x2][y2];c[x2][y2]=tt;  
}  

void bfs(int sx,int sy,int tx,int ty)
{
    int i,x,y;
    memset(vis,0,sizeof(vis));  
    vis[sx]=1;que1[++r1]=sx; que2[++r2]=sy;  
    while(f1<=r1){  
        x=que1[f1]; y=que2[f1++];  
        if(x==tx&&y==ty)  
            return;  
        for(i=0;i<4;i++){
            int nx=x+"2011"[i]-'1';
            int ny=y+"1120"[i]-'1';
            if(check(nx,ny)&&!vis[nx]){
                vis[nx]=1;  
                que1[++r1]=nx; que2[++r2]=ny;  
            }  
        }  
    }  
}  

int A_star(int sx,int sy,int tx,int ty)
{
    bfs(sx,sy,tx,ty);  
    int i,j,mx;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(vis[i*m+j]){
                mx=abs(i-tx)+abs(j-ty);
                gn[i][j]=0;
                gn[tx][ty]=0;
            }  
    int x=sx,y=sy,tx1,ty1,dis=0,re;
    while(!(x==tx&&y==ty)){
        if(x>tx)
            tx1=m+1,ty1=n+1;
        else if(x<tx)
            tx1=0,ty1=0;
        else tx1=1;  
        if(y>ty)
            ty1=m+1,tx1=n+1;
        else if(y<ty)
            ty1=0,tx1=0;
        else ty1=1;
        if(gn[x+tx1-ty1][y+ty1-tx1]){  
            exchange(x,y,x+tx1-ty1,y+ty1-tx1);  
            dis++;  
        }  
        if(x<tx) 
            x++;
        else if(x>tx)
            x--;  
        else if(y<ty) 
            y++;  
        else if(y>ty) 
            y--;  
    }
    return dis;
}

void solve()
{
    int lst=-1;  
    nowh=maxh-minv;
    while(nowh>=0&&lst!=cnt){
        lst=cnt;
        int nx,ny,x,y,k=1;  
        for(x=1;x<=n;x++)  
            if(h[x]>h[k])
                k=x;  
        if(k!=1)  
            cnt++,flip1(k);  
        else if(nowh>=dv(1)){  
            cnt++;flip2(1);  
        }  
        else break;  
    }  
}  

int main()  
{  
    int i,j,t; 
    init();  
    solve();  
    printf("%d\n",cnt);  

    for(i=1;i<=n;i++){  
        for(j=1;j<=m;j++){
            if(gn[i][j]&&d[i][j])
                printf("1 ");
            else printf("0 ");
        }  
        printf("\n");  
    }  
    return 0;  
}