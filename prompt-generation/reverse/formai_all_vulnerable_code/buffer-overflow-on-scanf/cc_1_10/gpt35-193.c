//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct album{
    char album_name[100];
    char artist_name[100];
    int year_of_release;
    int rating;
};

int count=0;

void add_album(struct album* lib){
    printf("Enter album name: ");
    scanf("%s",lib[count].album_name);
    printf("Enter artist name: ");
    scanf("%s",lib[count].artist_name);
    printf("Enter year of release: ");
    scanf("%d",&lib[count].year_of_release);
    printf("Enter rating out of 10: ");
    scanf("%d",&lib[count].rating);
    count++;
    printf("\nAlbum added successfully!\n");
}

void display(struct album* lib){
    if(count==0){
        printf("\nLibrary is empty!\n");
    }
    else{
        printf("\nAlbums in the library:\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("|%-25s|%-25s|%-20s|%-15s|\n","Album Name","Artist Name","Year of Release","Rating");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i=0;i<count;i++){
            printf("|%-25s|%-25s|%-20d|%-15d|\n",lib[i].album_name,lib[i].artist_name,lib[i].year_of_release,lib[i].rating);
        }
        printf("------------------------------------------------------------------------------------------\n");
    }
}

void search_by_artist(struct album* lib){
    char artist[100];
    int found=0;
    printf("Enter artist name: ");
    scanf("%s",artist);
    printf("\nResults for artist: %s\n",artist);
    printf("------------------------------------------------------------------------------------------\n");
    printf("|%-25s|%-25s|%-20s|%-15s|\n","Album Name","Artist Name","Year of Release","Rating");
    printf("------------------------------------------------------------------------------------------\n");
    for(int i=0;i<count;i++){
        if(strcmp(lib[i].artist_name,artist)==0){
            printf("|%-25s|%-25s|%-20d|%-15d|\n",lib[i].album_name,lib[i].artist_name,lib[i].year_of_release,lib[i].rating);
            found=1;
        }
    }
    if(found==0){
        printf("\nNo albums found with the artist name %s\n",artist);
    }
    printf("------------------------------------------------------------------------------------------\n");
}

void search_by_album(struct album* lib){
    char album[100];
    int found=0;
    printf("Enter album name: ");
    scanf("%s",album);
    printf("\nResults for album: %s\n",album);
    printf("------------------------------------------------------------------------------------------\n");
    printf("|%-25s|%-25s|%-20s|%-15s|\n","Album Name","Artist Name","Year of Release","Rating");
    printf("------------------------------------------------------------------------------------------\n");
    for(int i=0;i<count;i++){
        if(strcmp(lib[i].album_name,album)==0){
            printf("|%-25s|%-25s|%-20d|%-15d|\n",lib[i].album_name,lib[i].artist_name,lib[i].year_of_release,lib[i].rating);
            found=1;
        }
    }
    if(found==0){
        printf("\nNo albums found with the name %s\n",album);
    }
    printf("------------------------------------------------------------------------------------------\n");
}

void delete_album(struct album* lib){
    char album[100];
    int found=0;
    printf("Enter album name to be deleted: ");
    scanf("%s",album);
    for(int i=0;i<count;i++){
        if(strcmp(lib[i].album_name,album)==0){
            found=1;
            printf("\nAlbum %s by %s deleted successfully!\n",album,lib[i].artist_name);
            for(int j=i;j<count-1;j++){
                strcpy(lib[j].album_name,lib[j+1].album_name);
                strcpy(lib[j].artist_name,lib[j+1].artist_name);
                lib[j].year_of_release=lib[j+1].year_of_release;
                lib[j].rating=lib[j+1].rating;
            }
            count--;
            break;
        }
    }
    if(found==0){
        printf("\nNo albums found with the name %s\n",album);
    }
}

void update_rating(struct album* lib){
    char album[100];
    int found=0;
    printf("Enter album name whose rating is to be updated: ");
    scanf("%s",album);
    for(int i=0;i<count;i++){
        if(strcmp(lib[i].album_name,album)==0){
            found=1;
            printf("\nEnter new rating out of 10 for %s by %s: ",album,lib[i].artist_name);
            scanf("%d",&lib[i].rating);
            printf("\nRating updated successfully!\n");
            break;
        }
    }
    if(found==0){
        printf("\nNo albums found with the name %s\n",album);
    }
}

int main(){
    printf("********** Welcome to C Music Library Management System **********\n\n");
    struct album lib[100];
    while(1){
        printf("Select an operation:\n");
        printf("1. Add a new album\n");
        printf("2. Display all albums\n");
        printf("3. Search an album by artist name\n");
        printf("4. Search an album by album name\n");
        printf("5. Delete an album from the library\n");
        printf("6. Update the rating of an album\n");
        printf("7. Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: add_album(lib); break;
            case 2: display(lib); break;
            case 3: search_by_artist(lib); break;
            case 4: search_by_album(lib); break;
            case 5: delete_album(lib); break;
            case 6: update_rating(lib); break;
            case 7: printf("Exiting C Music Library Management System..."); exit(0);
        }
    }
    return 0;
}