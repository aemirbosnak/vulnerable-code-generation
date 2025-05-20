//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

//Function prototypes
void addSong();
void deleteSong();
void searchSong();
void display();

//Global variable declaration
struct Song{
    char title[20];
    char artist[20];
    char album[20];
    int year;
    float duration;
};

struct Song myMusic[MAX];
int count=0;

//Main function
int main(){
    int choice;
    do{
        //Displaying menu
        printf("\nC MUSIC LIBRARY MANAGEMENT SYSTEM");
        printf("\n--------------------------------");
        printf("\n1. Add a song");
        printf("\n2. Delete a song");
        printf("\n3. Search for a song");
        printf("\n4. Display all songs");
        printf("\n5. Exit");
        printf("\n--------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        //Switch case to perform required operation
        switch(choice){
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: searchSong(); break;
            case 4: display(); break;
            case 5: exit(0); break;
            default: printf("\nInvalid choice! Try again.");
        }
    }while(choice!=5);
    return 0;
}

//Function to add song details
void addSong(){
    if(count==MAX){
        printf("\nMusic library is full!");
    }
    else{
        printf("\nEnter details for song %d:",count+1);
        printf("\nTitle: ");
        scanf("%s",&myMusic[count].title);
        printf("Artist: ");
        scanf("%s",&myMusic[count].artist);
        printf("Album: ");
        scanf("%s",&myMusic[count].album);
        printf("Year: ");
        scanf("%d",&myMusic[count].year);
        printf("Duration (in mins): ");
        scanf("%f",&myMusic[count].duration);
        count++;
        printf("\nSong added successfully!");
    }
}

//Function to delete song details
void deleteSong(){
    char key[20];
    int i,index=-1;
    printf("\nEnter the title of the song to be deleted: ");
    scanf("%s",&key);
    for(i=0;i<count;i++){
        if(strcmp(myMusic[i].title,key)==0){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("\nSong not found!");
    }
    else{
        for(i=index;i<count-1;i++){
            myMusic[i]=myMusic[i+1];
        }
        count--;
        printf("\nSong deleted successfully!");
    }
}

//Function to search song details
void searchSong(){
    char key[20];
    int i,index=-1;
    printf("\nEnter the title of the song to be searched: ");
    scanf("%s",&key);
    for(i=0;i<count;i++){
        if(strcmp(myMusic[i].title,key)==0){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("\nSong not found!");
    }
    else{
        printf("\nSong details:");
        printf("\nTitle: %s",myMusic[index].title);
        printf("\nArtist: %s",myMusic[index].artist);
        printf("\nAlbum: %s",myMusic[index].album);
        printf("\nYear: %d",myMusic[index].year);
        printf("\nDuration: %.2f mins",myMusic[index].duration);
    }
}

//Function to display all song details
void display(){
    int i;
    if(count==0){
        printf("\nMusic library is empty!");
    }
    else{
        printf("\nNumber of songs in library: %d",count);
        printf("\nSong details:");
        for(i=0;i<count;i++){
            printf("\nTitle: %s",myMusic[i].title);
            printf("\nArtist: %s",myMusic[i].artist);
            printf("\nAlbum: %s",myMusic[i].album);
            printf("\nYear: %d",myMusic[i].year);
            printf("\nDuration: %.2f mins",myMusic[i].duration);
            printf("\n---------------------------");
        }
    }
}