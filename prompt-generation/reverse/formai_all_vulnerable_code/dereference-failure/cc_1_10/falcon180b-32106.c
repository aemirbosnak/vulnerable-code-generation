//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

//Node structure for creating a linked list
struct Node{
    int data;
    struct Node* next;
};

//Function for creating a new node with given data
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function for adding a node at the end of the list
void enqueue(struct Node** front, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *front;

    if(*front == NULL){
        *front = newNode;
        return;
    }

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

//Function for removing a node from the front of the list
int dequeue(struct Node** front){
    struct Node* temp = *front;
    int data;

    if(*front == NULL){
        return -1;
    }

    data = temp->data;
    *front = temp->next;
    free(temp);

    return data;
}

//Function for displaying the contents of the list
void display(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

//Main function for testing the implementation
int main(){
    struct Node* front = NULL;

    enqueue(&front, 10);
    enqueue(&front, 20);
    enqueue(&front, 30);

    display(front);

    int removedData = dequeue(&front);
    printf("\nRemoved data: %d\n", removedData);

    display(front);

    return 0;
}