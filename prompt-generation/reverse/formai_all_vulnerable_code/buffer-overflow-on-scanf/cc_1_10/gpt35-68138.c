//FormAI DATASET v1.0 Category: Mailing list manager ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 50
#define MAX_EMAIL 50

struct node{
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    struct node *next;
};

void addToList(struct node **head, char *name, char *email){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = *head;
    *head = new_node;
}

int findInList(struct node *head, char *name){
    struct node *current = head;
    int count = 0;
    while(current != NULL){
        if(strcmp(current->name, name) == 0){
            count++;
            printf("%s : %s\n", current->name, current->email);
        }
        current = current->next;
    }
    return count;
}

void printList(struct node *head){
    struct node *current = head;
    while(current != NULL){
        printf("%s : %s\n", current->name, current->email);
        current = current->next;
    }
}

int main(){

    struct node *head = NULL;
    char name[MAX_NAME], email[MAX_EMAIL];
    int choice = 1, flag;

    while(choice){
        printf("\n\n1. Add to list\n2. Find in list\n3. Print list\n4. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1 : 
                printf("Enter name : ");
                scanf("%s", name);
                printf("Enter email : ");
                scanf("%s", email);
                addToList(&head, name, email);
                break;
            case 2 :
                printf("Enter name : ");
                scanf("%s", name);
                flag = findInList(head, name);
                if(flag == 0){
                    printf("Name not found in list!\n");
                }
                break;
            case 3 :
                printList(head);
                break;
            case 4 : 
                printf("Exiting program!\n");
                choice = 0;
                break;
            default :
                printf("Invalid choice!\n");
        }
    }

    return 0;
}