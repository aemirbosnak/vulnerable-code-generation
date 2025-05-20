//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song {
    char title[50];
    char artist[50];
    char genre[20];
    int duration;
};

int main() {
    struct song all_songs[100];
    int num_songs = 0;
    int option;
    
    do {
        // Display menu
        printf("\n=============================\n");
        printf(" C Music Library Management System\n");
        printf("==============================\n");
        printf("1. Add a Song\n");
        printf("2. View All Songs\n");
        printf("3. Search Songs\n");
        printf("4. Remove a Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            
            case 1: {
                // Add a Song
                printf("\nEnter Song Title: ");
                scanf("%s", all_songs[num_songs].title);
                
                printf("Enter Artist Name: ");
                scanf("%s", all_songs[num_songs].artist);
                
                printf("Enter Genre: ");
                scanf("%s", all_songs[num_songs].genre);
                
                printf("Enter Song Duration (in seconds): ");
                scanf("%d", &all_songs[num_songs].duration);
                
                printf("\nSong Added Successfully!\n");
                num_songs++;
                break;
            }
            
            case 2: {
                // View All Songs
                printf("\n Song Title \t\t Artist Name \t\t Genre \t\t Duration \n");
                printf("=========================================================================\n");
                for(int i=0; i<num_songs; i++) {
                    printf(" %s \t\t %s \t\t %s \t\t %d\n", all_songs[i].title, all_songs[i].artist, all_songs[i].genre, all_songs[i].duration);
                }
                break;
            }
            
            case 3: {
                // Search Songs
                char search_artist[50];
                printf("\nEnter Artist name to Search: ");
                scanf("%s", search_artist);
                
                printf("\n Song Title \t\t Artist Name \t\t Genre \t\t Duration \n");
                printf("=========================================================================\n");
                for(int i=0; i<num_songs; i++) {
                    if(strcmp(all_songs[i].artist, search_artist) == 0) {
                        printf(" %s \t\t %s \t\t %s \t\t %d\n", all_songs[i].title, all_songs[i].artist, all_songs[i].genre, all_songs[i].duration);
                    }
                }
                break;
            }
            
            case 4: {
                // Remove a Song
                char remove_title[50];
                int found = 0;
                printf("\nEnter Song Title to Remove: ");
                scanf("%s", remove_title);
                
                for(int i=0; i<num_songs; i++) {
                    if(strcmp(all_songs[i].title, remove_title) == 0) {
                        found = 1;
                        for(int j=i; j<num_songs-1; j++) {
                            all_songs[j] = all_songs[j+1];
                        }
                        num_songs--;
                        printf("\nSong Removed Successfully!\n");
                        break;
                    }
                }
                if(found == 0) {
                    printf("\nSong Not Found!\n");
                }
                break;
            }
            
            case 5: {
                // Exit
                printf("\nThank You For Using Our Music Library System!\n");
                exit(0);
            }
            
            default: {
                printf("\nInvalid Option Selected, Please Try Again!\n");
                break;
            }
        }
    } while(option != 5);
    
    return 0;
}