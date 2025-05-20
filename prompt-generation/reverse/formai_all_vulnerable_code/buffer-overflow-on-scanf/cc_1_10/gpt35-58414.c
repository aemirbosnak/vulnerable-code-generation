//FormAI DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createList(struct node *head){ // Function to create a Linked List
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d",&num);
    struct node *t,*prev;
    for(int i=1;i<=num;i++){
        t=(struct node*)malloc(sizeof(struct node));
        printf("Enter node %d data: ",i);
        scanf("%d",&t->data);
        t->next=NULL;
        if(head==NULL){
            head=t;
            prev=t;
        }
        else{
            prev->next=t;
            prev=t;
        }
    }
    return head;
}

void displayList(struct node *head){ // Function to display the Linked List
    printf("\nLinked List: ");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

struct node *insertElement(struct node *head){ // Function to insert an element in the Linked List
    struct node *t,*prev,*cur;
    int pos,num,flag=0;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d",&t->data);
    t->next=NULL;
    printf("Enter the position to insert the node: ");
    scanf("%d",&pos);
    cur=head;
    if(pos==1){
        t->next=head;
        head=t;
        flag=1;
    }
    else{
        for(int i=1;i<pos;i++){
            prev=cur;
            cur=cur->next;
        }
        prev->next=t;
        t->next=cur;
        flag=1;
    }
    if(flag==0){
        printf("Insertion not possible at given positon\n");
    }
    return head;
}

struct node *deleteElement(struct node *head){ // Function to delete an element from the Linked List
    int pos,flag=0;
    struct node *prev,*cur;
    printf("Enter the node position to delete: ");
    scanf("%d",&pos);
    cur=head;
    if(pos==1){
        head=cur->next;
        free(cur);
        flag=1;
    }
    else{
        for(int i=1;i<pos;i++){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        free(cur);
        flag=1;
    }
    if(flag==0){
        printf("Deletion not possible at given positon\n");
    }
    return head;
}

int main(){
    struct node *head=NULL;
    int choice;
    printf("\n--------------Welcome to Mind-Bending Magic with Linked Lists-------------\n\n");
    printf("1. Create Linked List\n");
    printf("2. Display Linked List\n");
    printf("3. Insert an Element\n");
    printf("4. Delete an Element\n");
    printf("5. Exit\n\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: head=createList(head);
                    break;
            case 2: displayList(head);
                    break;
            case 3: head=insertElement(head);
                    break;
            case 4: head=deleteElement(head);
                    break;
            case 5: printf("\nThanks for witnessing the Mind-Bending Magic!\n\n");
                    exit(0);
                    break;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}