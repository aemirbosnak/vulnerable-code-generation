//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct MUSIC_NODE{
    char song_name[50];
    char artist[50];
    float duration;
    struct MUSIC_NODE *next;
};

struct MUSIC_NODE *head;

void add_song(){
    struct MUSIC_NODE *new_node, *temp;
    new_node = (struct MUSIC_NODE*)malloc(sizeof(struct MUSIC_NODE));

    printf("Enter song name: ");
    scanf("%s", new_node->song_name);

    printf("Enter artist name: ");
    scanf("%s", new_node->artist);

    printf("Enter duration: ");
    scanf("%f", &new_node->duration);

    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display(){
    struct MUSIC_NODE *temp;
    temp = head;

    printf("Song name\t Artist name\t Duration\n\n");
    while(temp != NULL){
        printf("%s\t\t %s\t\t %.2f\n", temp->song_name, temp->artist, temp->duration);
        temp = temp->next;
    }
}

void search_song(){
    char search_query[50];
    struct MUSIC_NODE *temp;
    temp = head;

    printf("Enter the song name/artist name to search: ");
    scanf("%s", search_query);

    printf("Search results:\n\n");
    while(temp != NULL){
        if(strstr(temp->song_name, search_query) || strstr(temp->artist, search_query)){
            printf("%s\t\t %s\t\t %.2f\n", temp->song_name, temp->artist, temp->duration);
        }
        temp = temp->next;
    }
}

void delete_song(){
    char song_name[50];
    struct MUSIC_NODE *temp, *prev;
    temp = head;

    printf("Enter the song name to delete: ");
    scanf("%s", song_name);

    while(temp != NULL){
        if(strcmp(temp->song_name, song_name) == 0){
            if(temp == head){
                head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            free(temp);
            printf("Song %s deleted successfully!\n", song_name);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Song %s not found.\n", song_name);
}

int main(){
    int choice;
    printf("=====================\n");
    printf(" MUSIC LIBRARY MANAGER\n");
    printf("=====================\n");
    while(1){
        printf("\n1. Add song\n2. Display library\n3. Search for song\n4. Delete song\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                display();
                break;
            case 3:
                search_song();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}