//FormAI DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// Linked List Node Structure
struct node{
    char email[50];
    struct node *next;
};

typedef struct node NODE;

NODE* create_node(char mail[]){
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    strcpy(newnode->email,mail);
    newnode->next=NULL;
    return newnode;
}

NODE* insert_begin(NODE *head,char mail[]){
    NODE *newnode=create_node(mail);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}

int is_valid_email(char mail[]){
    int i=0;
    int len=strlen(mail);
    int atflag=0,dotflag=0;
    while(mail[i]!='\0'){
        if(isalnum(mail[i])){
            i++;
            continue;
        }
        else if(mail[i]=='@'){
            atflag++;
            i++;
            continue;
        }
        else if(mail[i]=='.'){
            dotflag++;
            i++;
            continue;
        }
        else{
            return 0;
        }
    }
    if(atflag==1 && dotflag>0 && (dotflag+1)<len && i==len){
        return 1;
    }
    else{
        return 0;
    }
}

void display_list(NODE *head){
    if(head==NULL){
        printf("\nMailing List is Empty!!\n");
        return;
    }
    while(head!=NULL){
        printf("%s\n",head->email);
        head=head->next;
    }
}

int main(){
    NODE *head=NULL;
    char choice,email[50];
    printf("\n\t\tMY HEART'S MAILING LIST MANAGER\n\n");
    do{
        printf("\n\n# MENU #\n");
        printf("1. Add new email\n");
        printf("2. Display mailing list\n");
        printf("3. Exit Mailing List Manager\n");
        printf("    Enter your choice (1/2/3): ");
        scanf(" %c",&choice);
        switch(choice){
            case '1':{
                printf("\nEnter Email to Add in Mailing List: ");
                scanf("%s",email);
                if(is_valid_email(email)){
                    head=insert_begin(head,email);
                    printf("\nNew Email Added Successfully to Mailing List!\n");
                }
                else{
                    printf("\nInvalid Email! Please Try Again...\n");
                }
                break;
            }
            case '2':{
                printf("\nList of Emails in Mailing List: \n\n");
                display_list(head);
                break;
            }
            case '3':{
                printf("\nThank You for Using MY HEART'S Mailing List Manager! Love You <3\n\n");
                break;
            }
            default:{
                printf("\nInvalid Choice! Please Try Again...\n");
            }
        }

    }while(choice!='3');

    return 0;
}