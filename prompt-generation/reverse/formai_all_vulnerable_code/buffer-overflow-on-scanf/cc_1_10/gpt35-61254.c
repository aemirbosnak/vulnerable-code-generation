//FormAI DATASET v1.0 Category: Password management ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 30

struct Node{
    char name[MAX], password[MAX];
    struct Node* next;
};

struct Node *head = NULL;

void insert(char name[], char password[]){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    strcpy(new_node->password, password);
    new_node->next = head;
    head = new_node;
}

void display(){
    struct Node* ptr = head;
    printf("\n");
    while(ptr != NULL){
        printf("Name: %s, Password: %s\n", ptr->name, ptr->password);
        ptr = ptr->next;
    }
}

int count(){
    int c=0;
    struct Node* ptr = head;
    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    }
    return c;
}

int check(char name[]){
    struct Node* ptr = head;
    while(ptr != NULL){
        if(strcmp(ptr->name, name) == 0)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

void modify(char name[]){
    int flag=0;
    char new_password[MAX];
    struct Node* ptr = head;
    while(ptr != NULL){
        if(strcmp(ptr->name, name) == 0){
            printf("Enter new password for %s: ",ptr->name);
            scanf("%s",new_password);
            strcpy(ptr->password,new_password);
            flag=1;
            break;
        }
        ptr = ptr->next;
    }
    if(flag==0)
        printf("No such name exists!\n");
}

void del(char name[]){
    struct Node *temp = head, *prev;
    if(temp != NULL && strcmp(temp->name, name) == 0){
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("There is no record of %s\n", name);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void menu(){
    printf("1. Add Password\n");
    printf("2. List Passwords\n");
    printf("3. Modify Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
}

int main(){
    int choice;
    char name[MAX], password[MAX];
    while(1){
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf("%s",name);
                if(check(name)==1){
                    printf("%s already exists!\n",name);
                    break;
                }
                printf("Enter password: ");
                scanf("%s",password);
                insert(name,password);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s",name);
                modify(name);
                break;
            case 4:
                printf("Enter name: ");
                scanf("%s",name);
                del(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}