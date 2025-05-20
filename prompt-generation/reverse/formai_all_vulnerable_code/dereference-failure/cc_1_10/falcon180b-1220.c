//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Node structure definition
struct Node{
    char songName[50];
    char artistName[50];
    int songLength;
    struct Node* next;
};

//Function to add a song to the playlist
void addSong(struct Node** head, char* songName, char* artistName, int songLength){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->songName, songName);
    strcpy(newNode->artistName, artistName);
    newNode->songLength = songLength;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to display the playlist
void displayPlaylist(struct Node* head){
    if(head == NULL){
        printf("Playlist is empty\n");
        return;
    }

    struct Node* temp = head;
    while(temp!= NULL){
        printf("Song Name: %s\nArtist Name: %s\nSong Length: %d seconds\n", temp->songName, temp->artistName, temp->songLength);
        temp = temp->next;
    }
}

//Function to search for a song in the playlist
struct Node* searchSong(struct Node* head, char* songName){
    struct Node* temp = head;
    while(temp!= NULL){
        if(strcmp(temp->songName, songName) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Function to delete a song from the playlist
void deleteSong(struct Node** head, char* songName){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(strcmp(temp->songName, songName) == 0){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && strcmp(temp->songName, songName)!= 0){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Song not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

//Main function
int main(){
    struct Node* head = NULL;

    //Adding songs to the playlist
    addSong(&head, "Shape of You", "Ed Sheeran", 240);
    addSong(&head, "Despacito", "Luis Fonsi", 220);
    addSong(&head, "Closer", "The Chainsmokers", 180);

    //Displaying the playlist
    printf("Playlist:\n");
    displayPlaylist(head);

    //Searching for a song
    struct Node* foundSong = searchSong(head, "Despacito");
    if(foundSong!= NULL){
        printf("Found song: %s\n", foundSong->songName);
    }else{
        printf("Song not found\n");
    }

    //Deleting a song
    deleteSong(&head, "Closer");

    //Displaying the updated playlist
    printf("\nPlaylist after deleting a song:\n");
    displayPlaylist(head);

    return 0;
}