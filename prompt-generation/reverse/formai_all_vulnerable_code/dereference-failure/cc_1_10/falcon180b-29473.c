//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    int count;
    struct node *next;
};

struct node *start;

void create(char str[], int n){
    int i;
    struct node *newnode, *temp;
    newnode = (struct node*) malloc(sizeof(struct node));
    strcpy(newnode->data, str);
    newnode->count = 1;
    newnode->next = NULL;
    if(start == NULL){
        start = newnode;
    }
    else{
        temp = start;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(char str[], int n){
    struct node *temp = start;
    while(temp!= NULL){
        printf("%s %d\n", temp->data, temp->count);
        temp = temp->next;
    }
}

void search(char str[], int n){
    struct node *temp = start;
    while(temp!= NULL){
        if(strcmp(temp->data, str) == 0){
            printf("The string %s has %d occurrences\n", str, temp->count);
            return;
        }
        temp = temp->next;
    }
    printf("The string %s does not exist\n", str);
}

int main(){
    int n, i, choice;
    char str[100];
    do{
        printf("Enter the number of strings: ");
        scanf("%d", &n);
    }while(n <= 0);

    for(i = 0; i < n; i++){
        printf("Enter string %d: ", i+1);
        scanf("%s", str);
        create(str, i+1);
    }

    do{
        printf("\n1. Display\n2. Search\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display(NULL, 0);
                break;
            case 2:
                printf("Enter the string to search: ");
                scanf("%s", str);
                search(str, strlen(str));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 3);

    return 0;
}