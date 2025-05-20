//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

//function to generate random numbers 
void randomize(int arr[],int n){
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
        arr[i]=rand()%2;
}
// function to check for percolation 
int percolation(int arr[],int n,int row,int col){
    int visited[row*n+col];
    int top=n*n, bottom=n*n+1, i;
    for(i=0;i<row*n+col;i++)
        visited[i]=0;
    //checking if the cell is open or not
    if(arr[row*n+col]==1){
        visited[row*n+col]=1;
        //check for top row
        if(row==0){
            if(visited[top]==0){
                visited[top]=1;
                return percolation(arr,n,row+1,col);
            }else{
                return 1;
            }  
        }else if(row==n-1){ //check for bottom row
            if(visited[bottom]==0){
                visited[bottom]=1;
                return percolation(arr,n,row-1,col);
            }else{
                return 1;
            }   
        }else{ //check for middle rows
            if(visited[(row-1)*n+col]==0 && arr[(row-1)*n+col]==1){
                visited[(row-1)*n+col]=1;
                if(percolation(arr,n,row-1,col)==1) return 1;
            }
            if(col-1>=0 && visited[row*n+(col-1)]==0 && arr[row*n+(col-1)]==1){
                visited[row*n+(col-1)]=1;
                if(percolation(arr,n,row,col-1)==1) return 1;
            }
            if(col+1<n && visited[row*n+(col+1)]==0 && arr[row*n+(col+1)]==1){
                visited[row*n+(col+1)]=1;
                if(percolation(arr,n,row,col+1)==1) return 1;
            }
            if(visited[(row+1)*n+col]==0 && arr[(row+1)*n+col]==1){
                visited[(row+1)*n+col]=1;
                if(percolation(arr,n,row+1,col)==1) return 1;
            }
        }    
    }
    return 0;
}
//main function
int main(){
    int i,n,row,col,*arr,flag=0;
    printf("Enter the size of the grid: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*n*sizeof(int));
    randomize(arr,n*n);
    printf("Generated Grid:\n");
    for(i=0;i<n*n;i++){
        printf("%d ",arr[i]);
        if((i+1)%n==0) printf("\n");
    }
    for(i=0;i<n;i++){
        if(percolation(arr,n,0,i)==1){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("\nPercolation Occurs\n");
    }else{
        printf("\nPercolation does not occur\n");
    }
    return 0;
}