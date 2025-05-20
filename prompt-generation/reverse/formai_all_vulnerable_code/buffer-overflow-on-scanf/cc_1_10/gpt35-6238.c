//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct node{ //defining a structure for each node in the network
    int vertex; //vertex number of the node
    struct node* link; //link to the next node
};

int main(){
    int n, i, j, adj_matrix[100][100]; //declaring variables
    struct node* head[100], *temp;
    
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &n);

    /*Getting the adjacency matrix from the user*/
    printf("Enter the adjacency matrix of the network:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    /*Creating a linked list for each node based on the adjacency matrix*/
    for(i=0;i<n;i++){
        head[i] = (struct node*)malloc(sizeof(struct node));
        head[i]->link = NULL;
        for(j=0;j<n;j++){
            if(adj_matrix[i][j] == 1){
                temp = (struct node*)malloc(sizeof(struct node));
                temp->vertex = j;
                temp->link = head[i]->link;
                head[i]->link = temp;
            }
        }
    }

    /*Printing the linked list for each node in the network*/
    printf("\nThe network topology:\n");
    for(i=0;i<n;i++){
        printf("%d -> ", i);
        temp = head[i]->link;
        while(temp != NULL){
            printf("%d -> ", temp->vertex);
            temp = temp->link;
        }
        printf("NULL\n");
    }
    return 0;
}