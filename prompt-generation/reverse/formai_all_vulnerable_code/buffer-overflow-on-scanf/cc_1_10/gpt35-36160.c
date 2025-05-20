//FormAI DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int song_id;
    char song_name[50];
    char artist[50];
    int year;
    int duration;
} Song;

typedef struct node{
    Song data;
    struct node *next;
} Node;

Node *head = NULL;
int song_counter = 0;

void addSong(){
    Song song;
    int song_id, year, duration;
    char song_name[50], artist[50];
    printf("Enter Song ID: ");
    scanf("%d", &song_id);
    printf("Enter Song Name: ");
    getchar();
    fgets(song_name, 50, stdin);
    song_name[strcspn(song_name, "\n")] = 0;
    printf("Enter Song Artist: ");
    fgets(artist, 50, stdin);
    artist[strcspn(artist, "\n")] = 0;
    printf("Enter Song Year: ");
    scanf("%d", &year);
    printf("Enter Song Duration: ");
    scanf("%d", &duration);
    song.song_id = song_id;
    strcpy(song.song_name, song_name);
    strcpy(song.artist, artist);
    song.year = year;
    song.duration = duration;
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = song;
    new_node->next = head;
    head = new_node;
    song_counter++; 
    printf("\nSong added successfully!\n");
}

void deleteSong(){
    if(head == NULL){
        printf("\nNo song in the Music Library.\n");
        return;
    }
    int song_id;
    printf("\nEnter Song ID: ");
    scanf("%d", &song_id);
    Node *current_node = head;
    Node *prev_node = NULL;
    while(current_node != NULL){
        if(current_node->data.song_id == song_id){
            if(prev_node == NULL){
                head = current_node->next;
            }
            else{
                prev_node->next = current_node->next;
            }
            free(current_node);
            song_counter--;
            printf("\nSong deleted successfully!\n");
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    printf("\nSong Not Found!\n");
}

void displaySongDetails(){
    if(head == NULL){
        printf("\nNo song in the Music Library.\n");
        return;
    }
    Node *current_node = head;
    printf("\n%-10s%-50s%-50s%-10s%-10s\n","Song ID", "Song Name", "Artist", "Year", "Duration");
    while(current_node != NULL){
        printf("%-10d%-50s%-50s%-10d%-10d\n", current_node->data.song_id, current_node->data.song_name, current_node->data.artist, current_node->data.year, current_node->data.duration);
        current_node = current_node->next;
    }
}

int main(){
    int choice = 0;
    printf("Welcome to Music Library Management System!\n");
    do{
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Song Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                displaySongDetails();
                break;
            case 4:
                printf("\nExiting the Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }while(choice != 4);
    return 0;
}