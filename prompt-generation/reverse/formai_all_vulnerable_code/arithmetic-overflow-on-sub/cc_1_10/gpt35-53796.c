//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node s_node;

s_node* create_node(int data){
    s_node *temp = malloc(sizeof(s_node));
    if(temp == NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert_begin(s_node **head, int data){
    s_node *new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void insert_end(s_node **head, int data){
    s_node *new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    s_node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_pos(s_node **head, int data, int pos){
    s_node *new_node = create_node(data);
    s_node *temp = *head;
    for(int i=1;i<pos-1;i++){
        if(temp->next == NULL){
            printf("The list is smaller than the position you are entered!\n");
            return;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_begin(s_node **head){
    if(*head == NULL){
        printf("The list is already empty!\n");
        return;
    }
    s_node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_end(s_node **head){
    if(*head == NULL){
        printf("The list is already empty!\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    s_node *temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_pos(s_node **head, int pos){
    if(*head == NULL){
        printf("The list is already empty!\n");
        return;
    }
    s_node *temp = *head;
    for(int i=1;i<pos-1;i++){
        if(temp->next == NULL){
            printf("The list is smaller than the position you are entered!\n");
            return;
        }
        temp = temp->next;
    }
    s_node *temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

void display(s_node *head){
    s_node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    s_node *head = NULL;
    int ch, data, pos;
    printf("1.Insert at the beginning\n2.Insert at the end\n3.Insert at any position\n");
    printf("4.Delete from beginning\n5.Delete from end\n6.Delete from any position\n7.Display the list\n8.Exit\n");
    
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_begin(&head, data);
                break;
            case 2: 
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_pos(&head, data, pos);
                break;
            case 4:
                delete_begin(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                delete_pos(&head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}