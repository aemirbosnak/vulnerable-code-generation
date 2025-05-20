//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node{
    int id;
    char artist[50], album[50], year[10];
    struct node *next;
};
typedef struct node node;
node *head = NULL;

void add_music(){
    node *temp = (node*)malloc(sizeof(node));
    printf("\nPlease Enter Music ID: ");
    scanf("%d", &temp->id);
    printf("\nPlease Enter Music Artist: ");
    getchar();
    fgets(temp->artist, 50, stdin);
    printf("\nPlease Enter Music Album: ");
    fgets(temp->album, 50, stdin);
    printf("\nPlease Enter Music Year: ");
    fgets(temp->year, 10, stdin);
    if(head == NULL){
        head = temp;
        temp->next = NULL;
    }
    else{
        node *current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = temp;
        temp->next = NULL;
    }
}

void display_music(){
    if(head == NULL){
        printf("\nNo Musics in Library\n");
        return;
    }
    node *current = head;
    printf("\nID\tARTIST\t\tALBUM\t\tYEAR\n");
    while(current != NULL){
        printf("%d\t%s\t%s\t%s", current->id, current->artist, current->album, current->year);
        current = current->next;
    }
}

void search_music(){
    if(head == NULL){
        printf("\nNo Musics in Library\n");
        return;
    }
    int id;
    printf("\nPlease Enter Music ID: ");
    scanf("%d", &id);
    node *current = head;
    while(current != NULL && current->id != id)
        current = current->next;
    if(current == NULL)
        printf("\nMusic with ID %d not found\n", id);
    else
        printf("\nMusic ID: %d\nArtist: %s\nAlbum: %s\nYear: %s", current->id, current->artist, current->album, current->year);
}

void delete_music(){
    if(head == NULL){
        printf("\nNo Musics in Library\n");
        return;
    }
    int id;
    printf("\nPlease Enter Music ID: ");
    scanf("%d", &id);
    node *current = head, *prev = NULL;
    if(current->id == id){
        head = current->next;
        free(current);
    }
    else{
        while(current != NULL && current->id != id){
            prev = current;
            current = current->next;
        }
        if(current == NULL){
            printf("\nMusic with ID %d not found\n", id);
            return;
        }
        prev->next = current->next;
        free(current);
    }
    printf("\nMusic with ID %d Deleted Successfully!\n", id);
}

void menu(){
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n2. Display Music\n3. Search Music\n4. Delete Music\n5. Exit\n");
}

int main(){
    int choice;
    char ch;
    do{
        menu();
        printf("Please Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            add_music();
            break;
            case 2:
            display_music();
            break;
            case 3:
            search_music();
            break;
            case 4:
            delete_music();
            break;
            case 5:
            printf("\nThank You for Using Music Library Management System!\n");
            exit(0);
            break;
            default:
            printf("\nInvalid Input! Please Try Again.\n");
            break;
        }
        printf("\nDo You Want to Continue? (Y/N)\n");
        getchar();
        scanf("%c", &ch);
    }while(toupper(ch) == 'Y');
    return 0;
}