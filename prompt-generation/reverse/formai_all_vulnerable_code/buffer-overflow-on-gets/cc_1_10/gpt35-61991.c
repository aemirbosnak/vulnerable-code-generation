//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
 
//define a struct to store information about music record
struct Music{
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};
//define a function to display menu
void displayMenu(){
    printf("\n\n---------------WELCOME TO MUSIC LIBRARY MANAGEMENT SYSTEM---------------\n\n");
    printf("1. Add a new record\n");
    printf("2. Search by artist name\n");
    printf("3. Search by record title\n");
    printf("4. Display all records in the library\n");
    printf("5. Exit the program\n\n");
}
 
//define a function to add new record
void addRecord(struct Music library[], int *count){
    printf("\n\n Enter the record details (Press Enter Key after each entry):\n");
    printf("Title : ");
    fflush(stdin);  //clears buffer to prevent errors while taking input
    gets(library[*count].title);
    printf("Artist : ");
    fflush(stdin);
    gets(library[*count].artist);
    printf("Genre : ");
    fflush(stdin);
    gets(library[*count].genre);
    printf("Year : ");
    scanf("%d",&library[*count].year);
    (*count)++;
    printf("\n Record added Successfully...\n");
}
 
//define a function to search record by artist name
void searchByArtistName(struct Music library[], int count){
    char artist_name[50];
    int flag=0;
    printf("\n\nEnter the artist name :");
    fflush(stdin);
    gets(artist_name);
    printf("\n\n|%-50s | %-50s | %-20s | %-4s|\n","Title","Artist","Genre","Year");
    for(int i=0; i<count; i++){
        if(strcmp(artist_name,library[i].artist)==0){
            printf("|%-50s | %-50s | %-20s | %-4d|\n",library[i].title,library[i].artist,library[i].genre,library[i].year);
            flag=1;
        }
    }
    if(flag==0){
        printf("\nRecord not found.\n");
    }
}
 
//define a function to search record by record title
void searchByRecordTitle(struct Music library[], int count){
    char record_title[50];
    int flag=0;
    printf("\n\nEnter the record title :");
    fflush(stdin);
    gets(record_title);
    printf("\n\n|%-50s | %-50s | %-20s | %-4s|\n","Title","Artist","Genre","Year");
    for(int i=0; i<count; i++){
        if(strcmp(record_title,library[i].title)==0){
            printf("|%-50s | %-50s | %-20s | %-4d|\n",library[i].title,library[i].artist,library[i].genre,library[i].year);
            flag=1;
        }
    }
    if(flag==0){
        printf("\nRecord not found.\n");
    }
}
 
//define a function to display all records in the library
void displayAllRecords(struct Music library[], int count){
    printf("\n\n|%-50s | %-50s | %-20s | %-4s|\n","Title","Artist","Genre","Year");
    for(int i=0; i<count; i++){
        printf("|%-50s | %-50s | %-20s | %-4d|\n",library[i].title,library[i].artist,library[i].genre,library[i].year);
    }
}
 
 
int main(){
    struct Music library[MAX_SIZE];
    int choice;
    int count=0;
    while(1){
        displayMenu();
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addRecord(library,&count);
                break;
            case 2:
                searchByArtistName(library,count);
                break;
            case 3:
                searchByRecordTitle(library,count);
                break;
            case 4:
                displayAllRecords(library,count);
                break;
            case 5:
                printf("\n\nTHANK YOU FOR USING THE SYSTEM !!!\n\n");
                return 0;
            default:
                printf("\n\nPlease enter a valid choice !!!\n\n");
        }
    }
    return 0;
}