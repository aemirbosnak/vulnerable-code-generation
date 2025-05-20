//Falcon-180B DATASET v1.0 Category: Data mining ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
    int data;
    int count;
    struct node* next;
};

struct node* create(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->count=1;
    new_node->next=NULL;
    return new_node;
}

void insert(struct node** head_ref,int data){
    struct node* new_node=create(data);
    struct node* last=*head_ref;

    if(*head_ref==NULL){
        new_node->next=NULL;
        *head_ref=new_node;
        return;
    }

    while(last->next!=NULL){
        last=last->next;
    }

    last->next=new_node;
    return;
}

void printList(struct node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
}

int search(struct node* head,int x){
    struct node* current=head;
    while(current!=NULL){
        if(current->data==x){
            return 1;
        }
        current=current->next;
    }
    return 0;
}

void deleteNode(struct node **head_ref, int key){
    struct node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main(){
    struct node* head=NULL;
    int choice,data;

    do{
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                insert(&head,data);
                break;

            case 2:
                printf("\nEnter the data to be deleted:");
                scanf("%d",&data);
                deleteNode(&head,data);
                break;

            case 3:
                printf("\nEnter the data to be searched:");
                scanf("%d",&data);
                if(search(head,data)){
                    printf("\n%d is present in the list",data);
                }
                else{
                    printf("\n%d is not present in the list",data);
                }
                break;

            case 4:
                printf("\nThe list is:");
                printList(head);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }while(1);

    return 0;
}