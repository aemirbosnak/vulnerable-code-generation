//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song{
    char name[50];
    char artist[50];
    char album[50];
    char year[10];
};

struct node{
    struct song s;
    struct node* next;
}*head=NULL;

void addSong(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter song name:\n");
    scanf("%[^\n]", temp->s.name);
    getchar();
    printf("Enter artist name:\n");
    scanf("%[^\n]", temp->s.artist);
    getchar();
    printf("Enter album name:\n");
    scanf("%[^\n]", temp->s.album);
    getchar();
    printf("Enter year of release:\n");
    scanf("%[^\n]", temp->s.year);
    getchar();
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void displaySongs(){
    struct node* temp=head;
    if(temp==NULL){
        printf("No songs found!\n");
        return ;
    }
    while(temp!=NULL){
        printf("Name: %s\n",temp->s.name);
        printf("Artist: %s\n",temp->s.artist);
        printf("Album: %s\n",temp->s.album);
        printf("Year: %s\n",temp->s.year);
        temp=temp->next;
    }
}

int searchSong(char* name){
    struct node* temp=head;
    while(temp!=NULL){
        if(strcmp(temp->s.name,name)==0){
            printf("\nName: %s\n",temp->s.name);
            printf("Artist: %s\n",temp->s.artist);
            printf("Album: %s\n",temp->s.album);
            printf("Year: %s\n",temp->s.year);
            return 1;
        }
        else{
            temp=temp->next;
        }
    }
    return 0;
}

void deleteSong(){
    if(head==NULL){
        printf("No songs found!\n");
        return ;
    }
    printf("Enter the name of song to be deleted:\n");
    char name[50];
    scanf("%[^\n]", name);
    getchar();
    if(strcmp(head->s.name,name)==0){
        struct node* temp=head;
        head=head->next;
        free(temp);
        return ;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        if(strcmp(temp->next->s.name,name)==0){
            struct node* temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
            return ;
        }
        else{
            temp=temp->next;
        }
    }
    printf("%s not found!\n",name);
}

int main(){
    printf("\nWelcome to C Music Library Management System!\n\n");
    while(1){
        printf("1. Add song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                printf("\nEnter the name of song to be searched:\n");
                char name[50];
                scanf("%[^\n]", name);
                getchar();
                if(searchSong(name)==0) printf("%s not found!\n",name);
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                printf("\nThank you for using C Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}