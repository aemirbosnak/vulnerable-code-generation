//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

typedef struct {
    char name[20];
    int id;
    struct Node *next;
} Node;

typedef struct {
    int src_id;
    int dest_id;
    int weight;
    struct Link *next;
} Link;

Node *head = NULL;
Link *link_head = NULL;

void add_node(int id, char *name) {
    Node *temp = (Node *) malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->id = id;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    } else {
        Node *ptr = head;
        while(ptr->next!= NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void add_link(int src_id, int dest_id, int weight) {
    Link *temp = (Link *) malloc(sizeof(Link));
    temp->src_id = src_id;
    temp->dest_id = dest_id;
    temp->weight = weight;
    temp->next = NULL;
    if(link_head == NULL) {
        link_head = temp;
    } else {
        Link *ptr = link_head;
        while(ptr->next!= NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void print_nodes() {
    Node *ptr = head;
    printf("ID\tName\n");
    while(ptr!= NULL) {
        printf("%d\t%s\n", ptr->id, ptr->name);
        ptr = ptr->next;
    }
}

void print_links() {
    Link *ptr = link_head;
    printf("Source ID\tDestination ID\tWeight\n");
    while(ptr!= NULL) {
        printf("%d\t%d\t%d\n", ptr->src_id, ptr->dest_id, ptr->weight);
        ptr = ptr->next;
    }
}

int main() {
    int choice, id, src_id, dest_id, weight;
    char name[20];

    printf("Enter the number of nodes: ");
    scanf("%d", &id);

    for(int i = 0; i < id; i++) {
        printf("Enter the ID and name of node %d: ", i+1);
        scanf("%d%s", &id, name);
        add_node(id, name);
    }

    printf("Enter the number of links: ");
    scanf("%d", &id);

    for(int i = 0; i < id; i++) {
        printf("Enter the source ID, destination ID and weight of link %d: ", i+1);
        scanf("%d%d%d", &src_id, &dest_id, &weight);
        add_link(src_id, dest_id, weight);
    }

    do {
        printf("\nSelect an option:\n");
        printf("1. Print nodes\n");
        printf("2. Print links\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_nodes();
                break;
            case 2:
                print_links();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    } while(1);

    return 0;
}