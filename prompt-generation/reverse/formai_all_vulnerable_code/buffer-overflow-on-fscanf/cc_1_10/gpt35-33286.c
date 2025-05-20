//FormAI DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char email[50];
    struct node* next;
};

typedef struct node Node;

Node* head=NULL;
char filename[50];

//function to create a new node
Node* create_node(char email[]){
    Node* new_node=(Node*)malloc(sizeof(Node));
    if(new_node==NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(new_node->email,email);
    new_node->next=NULL;
    return new_node;
}

//function to insert new email into linked list
void add_email(char email[]){
    Node* new_node=create_node(email);
    if(head==NULL){
        head=new_node;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

//function to delete an email from the linked list
void delete_email(char email[]){
    if(head==NULL){
        printf("Email list is empty\n");
        return;
    }
    if(strcmp(head->email,email)==0){
        Node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(strcmp(temp->next->email,email)==0){
            Node* temp2=temp->next;
            temp->next=temp->next->next;
            free(temp2);
            return;
        }
        temp=temp->next;
    }
    printf("Email not found\n");
}

//function to print all emails in the linked list
void view_emails(){
    if(head==NULL){
        printf("Email list is empty\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%s\n",temp->email);
        temp=temp->next;
    }
}

//function to save emails to a file
void save_emails(){
    FILE* file=fopen(filename,"w");
    if(file==NULL){
        printf("File could not be created\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        fprintf(file,"%s\n",temp->email);
        temp=temp->next;
    }
    fclose(file);
    printf("Emails saved to file successfully\n");
}

//function to load emails from a file
void load_emails(){
    FILE* file=fopen(filename,"r");
    if(file==NULL){
        printf("File could not be opened\n");
        return;
    }
    char email[50];
    while(fscanf(file,"%s",email)!=EOF){
        add_email(email);
    }
    fclose(file);
    printf("Emails loaded from file successfully\n");
}

//main function
int main(){
    int choice;
    printf("Enter the name of the file to save/load emails:\n");
    scanf("%s",filename);
    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. View all emails\n");
        printf("4. Save emails to file\n");
        printf("5. Load emails from file\n");
        printf("6. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter email to add:\n");
                char new_email[50];
                scanf("%s",new_email);
                add_email(new_email);
                printf("Email added successfully\n");
                break;
            case 2:
                printf("Enter email to delete:\n");
                char del_email[50];
                scanf("%s",del_email);
                delete_email(del_email);
                break;
            case 3:
                printf("List of all emails:\n");
                view_emails();
                break;
            case 4:
                save_emails();
                break;
            case 5:
                load_emails();
                break;
            case 6:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}