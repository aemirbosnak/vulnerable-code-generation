//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email_t{
    char from[30];
    char to[30];
    char subject[50];
    char body[250]; 
};

struct node_t{
    struct email_t email;
    struct node_t *next;
};

typedef struct node_t Node;

char encrypt(char c){
    return c + 5;
}

Node* create_node(struct email_t email){
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (!new_node){
        printf("Error: Memory allocation failed\n");
        exit(1); 
    }
    new_node->email = email; 
    new_node->next = NULL;
    return new_node;
}

Node* insert_at_head(Node *head, struct email_t email){
    Node *new_node = create_node(email);
    new_node->next = head;
    head = new_node;
    return head;
}

Node* delete_from_head(Node *head){
    if (!head){
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void display_list(Node *head){
    if (!head){
        printf("List is empty\n");
        return;
    } 
    printf("From\t\tTo\t\tSubject\t\tBody\n");
    Node *curr = head;
    while(curr){
        printf("%s\t", curr->email.from);
        printf("%s\t", curr->email.to);
        printf("%s\t", curr->email.subject);
        printf("%s\n", curr->email.body);
        curr = curr->next;
    }
}

void encrypt_data(struct email_t *email){
    for (int i = 0; i < strlen(email->from); i++){
        email->from[i] = encrypt(email->from[i]);
    }
    for (int i = 0; i < strlen(email->to); i++){
        email->to[i] = encrypt(email->to[i]);
    }
    for (int i = 0; i < strlen(email->subject); i++){
        email->subject[i] = encrypt(email->subject[i]);
    }
    for (int i = 0; i < strlen(email->body); i++){
        email->body[i] = encrypt(email->body[i]);
    }
}

int main(){
    Node *head = NULL;
    struct email_t email;
    char choice;
    do{
        printf("Enter email details\n");
        printf("From: ");
        scanf("%s", email.from);
        printf("To: ");
        scanf("%s", email.to);
        printf("Subject: ");
        scanf("%s", email.subject);
        printf("Body: ");
        scanf("%s", email.body);
        encrypt_data(&email); //encrypt data
        head = insert_at_head(head, email); //add email to list
        printf("Email added to list successfully.\n");
        printf("Do you want to add another email? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');

    display_list(head); //display all emails in the list

    //delete first email from list
    head = delete_from_head(head);
    printf("First email deleted successfully.\n");

    display_list(head); //display remaining emails in the list

    //free all nodes in the list
    Node *temp;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}