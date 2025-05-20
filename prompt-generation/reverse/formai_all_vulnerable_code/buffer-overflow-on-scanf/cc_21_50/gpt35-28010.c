//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Romeo and Juliet C Music Library Management System

struct song{
    char name[50];
    char artist[50];
    char album[50];
};

int main(){
    printf("Welcome to the C Music Library Management System, fair user!\n");
    printf("What would you like to do with your music library today?\n\n");
    
    int choice;
    struct song songs[100];
    int count = 0;
    
    do{
        printf("\n");
        printf("1. Add a song\n");
        printf("2. View all songs\n");
        printf("3. Search for a song\n");
        printf("4. Edit a song\n");
        printf("5. Delete a song\n");
        printf("6. Exit the program\n");
        printf("\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice){
            case 1:
                printf("Ah, then let us add a new song to our collection!\n");
                printf("Please enter the name of the song: ");
                scanf("%s", &songs[count].name);
                printf("Please enter the artist's name: ");
                scanf("%s", &songs[count].artist);
                printf("Please enter the album name: ");
                scanf("%s", &songs[count].album);
                printf("Song added successfully!\n");
                count++;
                break;
                
            case 2:
                printf("Very well, here are all the songs currently in your library:\n");
                for(int i=0; i<count; i++){
                    printf("%s by %s (%s)\n", songs[i].name, songs[i].artist, songs[i].album);
                }
                break;
                
            case 3:
                printf("Let us search for a song then, good sir/madam.\n");
                printf("Please enter the name of the song you are looking for: ");
                char searchName[50];
                scanf("%s", &searchName);
                int found = 0;
                for(int i=0; i<count; i++){
                    if(strcmp(songs[i].name, searchName) == 0){
                        found++;
                        printf("%s by %s (%s)\n", songs[i].name, songs[i].artist, songs[i].album);
                    }
                }
                if(found == 0){
                    printf("I'm sorry, I cannot find that song.\n");
                }
                break;
                
            case 4:
                printf("You wish to edit a song? As you wish!\n");
                printf("Please enter the name of the song you want to edit: ");
                char editName[50];
                scanf("%s", &editName);
                int edited = 0;
                for(int i=0; i<count; i++){
                    if(strcmp(songs[i].name, editName) == 0){
                        edited++;
                        printf("What would you like to edit?\n");
                        printf("1. Name\n");
                        printf("2. Artist\n");
                        printf("3. Album\n");
                        int editChoice;
                        scanf("%d", &editChoice);
                        switch(editChoice){
                            case 1:
                                printf("Please enter the new name: ");
                                scanf("%s", &songs[i].name);
                                printf("Song name edited successfully!\n");
                                break;
                            case 2:
                                printf("Please enter the new artist's name: ");
                                scanf("%s", &songs[i].artist);
                                printf("Artist name edited successfully!\n");
                                break;
                            case 3:
                                printf("Please enter the new album name: ");
                                scanf("%s", &songs[i].album);
                                printf("Album name edited successfully!\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }
                    }
                }
                if(edited == 0){
                    printf("I'm sorry, I cannot find that song.\n");
                }
                break;
                
            case 5:
                printf("You wish to delete a song from your library? How tragic!\n");
                printf("Please enter the name of the song you want to delete: ");
                char deleteName[50];
                scanf("%s", &deleteName);
                int deleted = 0;
                for(int i=0; i<count; i++){
                    if(strcmp(songs[i].name, deleteName) == 0){
                        deleted++;
                        for(int j=i; j<count-1; j++){
                            strcpy(songs[j].name, songs[j+1].name);
                            strcpy(songs[j].artist, songs[j+1].artist);
                            strcpy(songs[j].album, songs[j+1].album);
                        }
                        count--;
                        printf("Song deleted successfully!\n");
                    }
                }
                if(deleted == 0){
                    printf("I'm sorry, I cannot find that song.\n");
                }
                break;
                
            case 6:
                printf("Farewell, good sir/madam! May your music library be always full!\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
    }while(choice != 6);
    
    return 0;
}