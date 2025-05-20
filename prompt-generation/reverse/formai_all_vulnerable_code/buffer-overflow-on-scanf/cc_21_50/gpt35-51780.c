//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int main(){
    int i, j, k, n, m, p, q, r, t;
    int speed, position, length;
    int road[MAX][MAX];
    char direction;

    printf("Enter the simulation time: ");
    scanf("%d", &t); //simulation time
    printf("Enter the number of cars: ");
    scanf("%d", &n); //number of cars
    
    /*Initializing the road*/
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            road[i][j]=0;
        }
    }

    /*Generating the cars randomly*/
    srand(time(NULL));
    for(i=0;i<n;i++){
        speed=rand()%5+1;
        position=rand()%MAX;
        length=rand()%3+2;
        direction=rand()%2==0?'E':'W';
        for(j=position;j<position+length;j++){
            if(j<MAX){
                road[j][i]=speed;
                road[j][n+i]=length;
                road[j][2*n+i]=direction;
            }
        }
    }

    /*Simulating the traffic flow*/
    printf("Simulating the traffic flow...\n");
    for(k=0;k<t;k++){
        for(i=0;i<MAX;i++){
            for(j=0;j<n;j++){
                if(road[i][j]>0){
                    speed=road[i][j];
                    length=road[i][n+j];
                    direction=road[i][2*n+j];
                    road[i][j]=0;
                    road[i][n+j]=0;
                    road[i][2*n+j]=0;
                    if(direction=='E'){
                        if(i+speed<MAX){
                            p=i+speed;
                            q=i+length;
                            for(m=i+1;m<p;m++){
                                if(road[m][n+j]>0){
                                    speed=0;
                                    break;
                                }
                            }
                            if(speed>0){
                                for(m=p;m<q;m++){
                                    road[m][j]=speed;
                                    road[m][n+j]=length;
                                    road[m][2*n+j]=direction;
                                }
                                road[q][j]=speed;
                                road[q][n+j]=length;
                                road[q][2*n+j]=direction;
                            }
                            else{
                                for(m=i;m<q;m++){
                                    road[m][j]=0;
                                    road[m][n+j]=0;
                                    road[m][2*n+j]=0;
                                }
                                road[i][j]=speed;
                                road[i][n+j]=length;
                                road[i][2*n+j]=direction;
                            }
                        }
                        else{
                            road[i][j]=speed;
                            road[i][n+j]=length;
                            road[i][2*n+j]=direction;
                        }
                    }
                    else{
                        if(i-speed>=0){
                            p=i-speed;
                            q=i-length;
                            for(m=p+1;m<i;m++){
                                if(road[m][n+j]>0){
                                    speed=0;
                                    break;
                                }
                            }
                            if(speed>0){
                                for(m=q;m<p;m++){
                                    road[m][j]=speed;
                                    road[m][n+j]=length;
                                    road[m][2*n+j]=direction;
                                }
                                road[q][j]=speed;
                                road[q][n+j]=length;
                                road[q][2*n+j]=direction;
                            }
                            else{
                                for(m=q;m<i;m++){
                                    road[m][j]=0;
                                    road[m][n+j]=0;
                                    road[m][2*n+j]=0;
                                }
                                road[i][j]=speed;
                                road[i][n+j]=length;
                                road[i][2*n+j]=direction;
                            }
                        }
                        else{
                            road[i][j]=speed;
                            road[i][n+j]=length;
                            road[i][2*n+j]=direction;
                        }
                    }
                }
            }
        }
    }

    /*Printing the final state of the road*/
    printf("Final state of the road:\n");
    for(i=0;i<MAX;i++){
        printf("|");
        for(j=0;j<n;j++){
            if(road[i][j]>0){
                printf("%d", road[i][j]);
            }
            else{
                printf(" ");
            }
        }
        printf("|\n");
    }

    return 0;
}