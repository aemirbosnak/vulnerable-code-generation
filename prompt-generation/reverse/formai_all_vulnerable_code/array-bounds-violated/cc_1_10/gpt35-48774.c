//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_VERTICES 10000

#define PI 3.14159265358979323846

int n, m;   //number of nodes and edges
int nodes[MAX_NODES];
double resistances[MAX_VERTICES];
int a[MAX_VERTICES], b[MAX_VERTICES];
int g[MAX_NODES][MAX_NODES];
double g2[MAX_NODES][MAX_NODES];   //Matrix for conductance
double r[MAX_NODES][MAX_NODES];    //Matrix for resistances
double v1[MAX_NODES];  //Voltage at each node
double v2[MAX_NODES];  //New voltage at each node


//Function to read input
void read_input(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;++i){
        scanf("%d %d %lf", &a[i], &b[i], &resistances[i]);
        g[a[i]][b[i]] = 1;
        g[b[i]][a[i]] = 1;
        r[a[i]][b[i]] = resistances[i];
        r[b[i]][a[i]] = resistances[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%d", &nodes[i]);
    }
}

//Function to initialize conductance matrix
void initialize(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j){
                g2[i][j] = 1.0/nodes[i];
            }
            else if(g[i][j]){
                g2[i][j] = -1.0/r[i][j];
                g2[i][i] += 1.0/r[i][j];
            }
        }
    }
}

//Matrix multiplication function
void multiply(double a[][MAX_NODES], double b[][MAX_NODES], int size){
    double c[size+1][size+1];
    for(int i=1;i<=size;++i){
        for(int j=1;j<=size;++j){
            c[i][j] = 0.0;
            for(int k=1;k<=size;++k){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(int i=1;i<=size;++i){
        for(int j=1;j<=size;++j){
            a[i][j] = c[i][j];
        }
    }
}

//Gaussian elimination function to solve for voltage
void solve(){
    double eps = 1e-10;
    int max_iter = 100;

    for(int iter=1;iter<=max_iter;++iter){
        for(int i=1;i<=n;++i){
            v2[i] = 0;
            for(int j=1;j<=n;++j){
                v2[i] += g2[i][j]*v1[j];
            }
        }
        double delta = 0;
        for(int i=1;i<=n;++i){
            delta = fmax(delta, fabs(v2[i]-v1[i]));
            v1[i] = v2[i];
        }
        if(delta < eps){
            break;
        }
    }
}

//Function to print output
void print_output(){
    for(int i=1;i<=n;++i){
        printf("Node %d Voltage: %lf V\n", i, v1[i]);
    }
}

int main(){
    read_input();
    initialize();
    solve();
    print_output();

    return 0;
}