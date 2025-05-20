//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* Define a structure for a node */
struct node{
    int data;
    struct node *next;
};

/* Function to display all the nodes in linked list */
void display_list(struct node *head){
    if(head != NULL){
        printf("%d -> ", head->data);
        display_list(head->next);
    }
}

/* Function to add a node in the beginning of list */
struct node *add_at_beginning(struct node *head, int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

/* Function to add a node at any position in the list */
struct node *add_at_position(struct node *head, int x, int pos){
    if(pos == 1){
        head = add_at_beginning(head, x);
        return head;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node *p = head;
    int i = 1;
    while(i < (pos - 1)){
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next = temp;
    return head;
}

/* Function to delete a node at any position in the list */
struct node *delete_at_position(struct node *head, int pos){
    if(pos == 1){
        struct node *temp = head->next;
        free(head);
        head = temp;
        return head;
    }
    struct node *p = head, *q;
    int i = 1;
    while(i < (pos - 1)){
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

/* Main function */
int main(){
    struct node *head = NULL;
    int i = 0, x = 0, pos = 0;
    while(i < MAX){
        printf("Enter number to be added in the list: ");
        scanf("%d", &x);
        head = add_at_beginning(head, x);
        i++;
    }
    printf("Initial Linked List: ");
    display_list(head);
    printf("Done\n");
    printf("Enter number to be added at specific position: ");
    scanf("%d", &x);
    printf("Enter the position where to add the number: ");
    scanf("%d", &pos);
    head = add_at_position(head, x, pos);
    printf("Updated Linked List: ");
    display_list(head);
    printf("Done\n");
    printf("Enter the position of the node you want to delete: ");
    scanf("%d", &pos);
    head = delete_at_position(head, pos);
    printf("Updated Linked List: ");
    display_list(head);
    printf("Done\n");
    return 0;
}