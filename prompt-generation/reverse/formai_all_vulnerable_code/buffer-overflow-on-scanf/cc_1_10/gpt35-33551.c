//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char title[50];
    char artist[50];
    int ratings;
} song;

void add_song();
void display_all_songs();
void search_song_by_title();
void delete_song_by_title();
void edit_song_ratings();

int main(){
    int choice;
    do{
        printf("\n\n~~~~ Welcome to your Funny C Music Library Management System ~~~~");
        printf("\n1. Add a Song\n2. Display all Songs\n3. Search Song by Title\n4. Delete Song by Title\n5. Edit Song Ratings\n6. Quit\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_song(); break;
            case 2: display_all_songs(); break;
            case 3: search_song_by_title(); break;
            case 4: delete_song_by_title(); break;
            case 5: edit_song_ratings(); break;
            case 6: printf("\nThank you for using our Funny C Music Library Management System!"); break;
            default: printf("\nInvalid Choice, try again!"); break;
        }
    }while(choice!=6);
    return 0;
}

void add_song(){
    system("cls");
    printf("\n~~~~ Add a Song ~~~~\n");
    FILE* fp = fopen("songs.txt","a");
    song s;
    printf("\nEnter Song title: ");
    scanf(" %[^\n]s",s.title);
    printf("\nEnter Artist name: ");
    scanf(" %[^\n]s",s.artist);
    printf("\nEnter Song Ratings (out of 10): ");
    scanf("%d",&s.ratings);
    if(fprintf(fp,"%s;%s;%d\n",s.title,s.artist,s.ratings)>0){
        printf("\nSong added successfully!");
    }
    fclose(fp);
}

void display_all_songs(){
    system("cls");
    printf("\n~~~~ Display all Songs ~~~~\n");
    FILE* fp = fopen("songs.txt","r");
    song s;
    printf("\n%-20s%-20s%-20s","Song Title", "Artist Name", "Ratings");
    printf("\n------------------------------------------------------------------------\n");
    while((fscanf(fp,"%[^;];%[^;];%d\n",s.title,s.artist,&s.ratings))!=EOF){
        printf("%-20s%-20s%-20d\n",s.title,s.artist,s.ratings);
    }
    fclose(fp);
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void search_song_by_title(){
    system("cls");
    printf("\n~~~~ Search Song by Title ~~~~\n");
    FILE* fp = fopen("songs.txt","r");
    song s;
    char query[50];
    int found = 0;
    printf("\nEnter the Song Title to be searched: ");
    scanf(" %[^\n]s",query);
    while((fscanf(fp,"%[^;];%[^;];%d\n",s.title,s.artist,&s.ratings))!=EOF){
        if(strcmp(query,s.title)==0){
            printf("\n%-20s%-20s%-20s","Song Title", "Artist Name", "Ratings");
            printf("\n------------------------------------------------------------------------\n");
            printf("%-20s%-20s%-20d\n",s.title,s.artist,s.ratings);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(!found)
        printf("\nSong not found in database!");
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void delete_song_by_title(){
    system("cls");
    printf("\n~~~~ Delete Song by Title ~~~~\n");
    FILE* fp1 = fopen("songs.txt","r");
    FILE* fp2 = fopen("temp.txt","w");
    song s;
    char query[50];
    int found = 0;
    printf("\nEnter Song Title to be deleted: ");
    scanf(" %[^\n]s",query);
    while((fscanf(fp1,"%[^;];%[^;];%d\n",s.title,s.artist,&s.ratings))!=EOF){
        if(strcmp(query,s.title)!=0){
            fprintf(fp2,"%s;%s;%d\n",s.title,s.artist,s.ratings);
        }
        else{
            found = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("songs.txt");
    rename("temp.txt","songs.txt");
    if(found)
        printf("\nSong deleted successfully!");
    else
        printf("\nSong not found in database! Deletion failed!");
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void edit_song_ratings(){
    system("cls");
    printf("\n~~~~ Edit Song Ratings ~~~~\n");
    FILE* fp1 = fopen("songs.txt","r");
    FILE* fp2 = fopen("temp.txt","w");
    song s;
    char query[50];
    int found = 0;
    printf("\nEnter Song Title to edit Ratings: ");
    scanf(" %[^\n]s",query);
    while((fscanf(fp1,"%[^;];%[^;];%d\n",s.title,s.artist,&s.ratings))!=EOF){
        if(strcmp(query,s.title)==0){
            printf("\nEnter new Ratings for %s by %s: ",s.title,s.artist);
            scanf("%d",&s.ratings);
            fprintf(fp2,"%s;%s;%d\n",s.title,s.artist,s.ratings);
            found = 1;
        }
        else{
            fprintf(fp2,"%s;%s;%d\n",s.title,s.artist,s.ratings);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("songs.txt");
    rename("temp.txt","songs.txt");
    if(found)
        printf("\nRatings edited successfully!");
    else
        printf("\nSong not found in the database! RAtings edition failed!");
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}