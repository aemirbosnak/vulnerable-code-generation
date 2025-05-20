//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store details of Music
struct music{
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

//Function to display Menu
void menu(){
    printf("----------- MUSIC LIBRARY MANAGEMENT SYSTEM -----------\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music\n");
    printf("4. Edit Music\n");
    printf("5. Delete Music\n");
    printf("6. Exit\n");
}

//Function to add Music to Library
void add_music(struct music *m){
    printf("Enter Music Title: ");
    scanf("%s", m->title);
    printf("Enter Music Artist: ");
    scanf("%s", m->artist);
    printf("Enter Music Album: ");
    scanf("%s", m->album);
    printf("Enter Music Year: ");
    scanf("%d", &m->year);
    printf("Music Added Successfully!\n");
}

//Function to display Music Library
void display_music(struct music *m, int count){
    printf("----------- MUSIC LIBRARY -----------\n");
    printf("Title\t\tArtist\t\tAlbum\t\tYear\n");
    for(int i=0; i<count; i++){
        printf("%s\t\t%s\t\t%s\t\t%d\n", m[i].title, m[i].artist, m[i].album, m[i].year);
    }
    printf("_____________________________________\n\n");
}

//Function to search Music by Title
void search_music(struct music *m, int count){
    char search_title[50];
    int flag=0;
    printf("Enter Music Title to be searched: ");
    scanf("%s", search_title);
    for(int i=0; i<count; i++){
        if(strcmp(m[i].title, search_title) == 0){
            printf("Title\t\tArtist\t\tAlbum\t\tYear\n");
            printf("%s\t\t%s\t\t%s\t\t%d\n", m[i].title, m[i].artist, m[i].album, m[i].year);
            flag=1;
        }
    }
    if(flag == 0)
        printf("\nNo Music Found!\n");
}

//Function to edit Music by Title
void edit_music(struct music *m, int count){
    char edit_title[50];
    int flag=0;
    printf("Enter Music Title to be edited: ");
    scanf("%s", edit_title);
    for(int i=0; i<count; i++){
        if(strcmp(m[i].title, edit_title) == 0){
            printf("Enter New Music Title: ");
            scanf("%s", m[i].title);
            printf("Enter New Music Artist: ");
            scanf("%s", m[i].artist);
            printf("Enter New Music Album: ");
            scanf("%s", m[i].album);
            printf("Enter New Music Year: ");
            scanf("%d", &m[i].year);
            printf("Music Edited Successfully!\n");
            flag=1;
        }
    }
    if(flag == 0)
        printf("\nNo Music Found!\n");
}

//Function to delete Music by Title
void delete_music(struct music *m, int *count){
    char delete_title[50];
    int flag=0;
    printf("Enter Music Title to be deleted: ");
    scanf("%s", delete_title);
    for(int i=0; i<*count; i++){
        if(strcmp(m[i].title, delete_title) == 0){
            for(int j=i+1;j<*count;j++){
                m[j-1] = m[j];
            }
            (*count)--;
            printf("Music Deleted Successfully!\n");
            flag=1;
        }
    }
    if(flag == 0)
        printf("\nNo Music Found!\n");
}

//Main Function
int main(){
    int choice, count=0;
    struct music *m;
    m = (struct music*)malloc(100*sizeof(struct music));      //Creating Array of Structure
    do{
        menu();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_music(&m[count]); count++; break;
            case 2: display_music(m, count); break;
            case 3: search_music(m, count); break;
            case 4: edit_music(m, count); break;
            case 5: delete_music(m, &count); break;
            case 6: printf("Thank You for Using Music Library Management System!\n"); break;
            default:printf("Invalid Choice!\n");
        }
    }while(choice!=6);
    free(m);
    return 0;
}