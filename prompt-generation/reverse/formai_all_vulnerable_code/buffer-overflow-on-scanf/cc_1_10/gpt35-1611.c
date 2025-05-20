//FormAI DATASET v1.0 Category: Music Library Management System ; Style: calm
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct nodes {
    char title[50];
    char artist[50];
};

void printMenu();
int searchSong(struct nodes *list, char *searchTitle, int total);
void deleteSong(struct nodes *list, char *searchTitle, int *total);
void displayList(struct nodes *list, int total);

int main()
{
    struct nodes myMusicList[100]; 
    int choice, totalSongs=0;
    char searchTitle[50], deleteTitle[50];

    printf("Welcome to the Music Library Management System :)\n\n");

    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1: ; //Adding a song
                printf("\nEnter the title of the song: ");
                fgets(myMusicList[totalSongs].title,sizeof(myMusicList[totalSongs].title),stdin);

                printf("Enter the name of the artist: ");
                fgets(myMusicList[totalSongs].artist,sizeof(myMusicList[totalSongs].artist),stdin);

                printf("\n'%s' by %s has been added to the music library!\n\n", myMusicList[totalSongs].title, myMusicList[totalSongs].artist);
                totalSongs++;
                break;

            case 2: ; //Searching for a song
                printf("\nEnter the title of the song: ");
                fgets(searchTitle,sizeof(searchTitle),stdin);
                int result=searchSong(myMusicList, searchTitle, totalSongs);

                if(result==-1) {
                    printf("\nSorry, '%s' was not found in the music library.\n\n", searchTitle);
                } else {
                    printf("\n'%s' by %s was found in the music library.\n\n", myMusicList[result].title, myMusicList[result].artist);
                }
                break;

            case 3: ; //Deleting a song
                printf("\nEnter the title of the song you want to delete: ");
                fgets(deleteTitle,sizeof(deleteTitle),stdin);
                deleteSong(myMusicList, deleteTitle, &totalSongs);
                break;

            case 4: ; //Displaying the song list
                displayList(myMusicList, totalSongs);
                break;

            case 5: ; //Exiting the program
                printf("\nThank you for using the Music Library Management System :)\n\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }
    } while(1);

    return 0;
}

void printMenu() {
    printf("1. Add a song\n");
    printf("2. Search for a song\n");
    printf("3. Delete a song\n");
    printf("4. Display the music list\n");
    printf("5. Exit the program\n");
    printf("\nEnter your choice: ");
}

int searchSong(struct nodes *list, char *searchTitle, int total) {
    for(int i=0; i<total; i++) {
        if(strncmp(list[i].title,searchTitle,strlen(searchTitle)-1)==0) {
            return i;
        }
    }
    return -1;
}

void deleteSong(struct nodes *list, char *searchTitle, int *total) {
    int index=searchSong(list,searchTitle,*total);

    if(index==-1) {
        printf("\nSorry, '%s' was not found in the music library.\n\n", searchTitle);
    } else {
        printf("\n'%s' by %s has been deleted from the music library.\n\n", list[index].title, list[index].artist);
        for(int i=index; i<*total; i++) {
            list[i]=list[i+1];
        }
        (*total)--;
    }
}

void displayList(struct nodes *list, int total) {
    printf("\n---Music Library---\n\n");
    for(int i=0; i<total; i++) {
        printf("%d. '%s' by %s\n", i+1, list[i].title, list[i].artist);
    }
    printf("\n");
}