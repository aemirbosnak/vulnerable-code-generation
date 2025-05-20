//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    int row;
    int col;
}Point;

int main(){
    int rows,cols,i,j,k,m,n,p,q,count=0;
    char maze[100][100];
    Point start,end;

    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    printf("Enter the number of columns: ");
    scanf("%d",&cols);

    //Generating a random maze
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            maze[i][j]='#';
        }
    }
    start.row=0;
    start.col=0;
    end.row=rows-1;
    end.col=cols-1;
    maze[start.row][start.col]='S';
    maze[end.row][end.col]='E';

    int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    srand(time(NULL));
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(maze[i][j]=='#'){
                k=rand()%4;
                while(k==0 || k==2){
                    k=rand()%4;
                }
                if(k==1){
                    n=rand()%2;
                    if(n==0){
                        p=i-1;
                        q=j;
                    }
                    else{
                        p=i+1;
                        q=j;
                    }
                }
                else if(k==3){
                    n=rand()%2;
                    if(n==0){
                        p=i;
                        q=j-1;
                    }
                    else{
                        p=i;
                        q=j+1;
                    }
                }
                maze[p][q]=' ';
            }
        }
    }

    //Displaying the maze
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }

    //Solving the maze
    count=0;
    while(1){
        if(maze[start.row][start.col]=='E'){
            printf("Path found with %d steps",count);
            break;
        }
        int flag=0;
        for(i=0;i<4;i++){
            p=start.row+directions[i][0];
            q=start.col+directions[i][1];
            if(p>=0 && p<rows && q>=0 && q<cols && maze[p][q]==' '){
                start.row=p;
                start.col=q;
                maze[p][q]='#';
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("No path found");
            break;
        }
        count++;
    }

    return 0;
}