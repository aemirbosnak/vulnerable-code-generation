//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//define the structure of the node
struct node{
    int data;
    struct node *next;
};

//define the structure of the linked list
struct linked_list{
    struct node *head;
};

//function to create a new node
struct node *create_node(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//function to create a new linked list
struct linked_list *create_linked_list(){
    struct linked_list *temp = (struct linked_list *)malloc(sizeof(struct linked_list));
    temp->head = NULL;
    return temp;
}

//function to add a node to the linked list
void add_node(struct linked_list *list, int data){
    struct node *temp = create_node(data);
    temp->next = list->head;
    list->head = temp;
}

//function to print the linked list
void print_list(struct linked_list *list){
    struct node *temp = list->head;
    printf("List: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//function to create a new network topology
struct linked_list *create_network(int num_nodes){
    struct linked_list *network = create_linked_list();
    int i;
    for(i=1; i<=num_nodes; i++){
        add_node(network, i);
    }
    return network;
}

//function to add a link between two nodes
void add_link(struct linked_list *network, int node1, int node2){
    struct node *temp1 = network->head;
    struct node *temp2 = network->head;
    while(temp1!= NULL && temp1->data!= node1){
        temp1 = temp1->next;
    }
    while(temp2!= NULL && temp2->data!= node2){
        temp2 = temp2->next;
    }
    temp1->next = temp2;
    temp2->next = temp1;
}

//function to print the network topology
void print_network(struct linked_list *network){
    struct node *temp = network->head;
    printf("Network Topology:\n");
    while(temp!= NULL){
        printf("%d ", temp->data);
        struct node *next = temp->next;
        while(next!= temp){
            printf(" -> %d", next->data);
            next = next->next;
        }
        printf("\n");
        temp = temp->next;
    }
}

//main function
int main(){
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    struct linked_list *network = create_network(num_nodes);
    int i, choice, node1, node2;
    while(1){
        printf("\n");
        printf("1. Add link\n");
        printf("2. Print network topology\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the nodes to add a link between: ");
                scanf("%d %d", &node1, &node2);
                add_link(network, node1, node2);
                break;
            case 2:
                print_network(network);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}