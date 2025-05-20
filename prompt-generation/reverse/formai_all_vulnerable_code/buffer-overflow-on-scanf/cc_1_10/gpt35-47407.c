//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

void readInput(char input[][MAX], int *n) {
    printf("Enter the number of nodes in the network: ");
    scanf("%d", n);
    printf("Enter the mapping details (e.g. A:B,C,D): \n");
    for(int i = 0; i < *n; i++) {
        printf("Node%d: ",i+1);
        scanf("%s",input[i]);
    }
}

void parseMapping(char input[][MAX], int n, char map[][MAX], int *m) {
    *m = 0;
    for(int i = 0; i < n; i++) {
        char *tok = strtok(input[i],":");
        strcpy(map[*m],tok);
        (*m)++;
        while(tok != NULL) {
            tok = strtok(NULL,",");
            if(tok != NULL) {
                strcpy(map[*m],tok);
                (*m)++;
            }
        }
    }
}

void printMapping(char map[][MAX], int m) {
    printf("Node\tConnections\n");
    for(int i = 0; i < m; i++) {
        printf("%s",map[i]);
        if(i%2 == 0) {
            printf("\t");
        } else {
            printf("\n");
        }
    }
    printf("\n");
}

void generateGraph(char map[][MAX], int m, int graph[][MAX], int *n) {
    *n = 0;
    for(int i = 0; i < m; i++) {
        if(isalpha(map[i][0])) {
            int j = i+1;
            while(j < m && !isalpha(map[j][0])) {
                int conn = atoi(map[j]);
                graph[*n][conn-1] = 1;
                j++;
            }
            (*n)++;
        }
    }
}

void printGraph(int graph[][MAX], int n) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX][MAX], map[MAX][MAX];
    int n,m;
    int graph[MAX][MAX] = {0};

    readInput(input,&n);
    parseMapping(input,n,map,&m);
    printMapping(map,m);
    generateGraph(map,m,graph,&n);
    printGraph(graph,n);

    return 0;
}