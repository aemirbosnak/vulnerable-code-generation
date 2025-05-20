//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration; // in seconds
};

int main() {
    int choice, count = 0, i;
    struct song music[50];
    char search_title[50];
    int search_year;

    printf("*** MUSIC LIBRARY MANAGEMENT SYSTEM ***\n");

    do {
        printf("\n1. Add a song\n2. Display all songs\n3. Search for a song\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= 50) {
                    printf("Error: Music library is full.\n");
                    break;
                }
                printf("Enter song title: ");
                scanf(" %[^\n]s", music[count].title);
                printf("Enter artist name: ");
                scanf(" %[^\n]s", music[count].artist);
                printf("Enter album name: ");
                scanf(" %[^\n]s", music[count].album);
                printf("Enter release year (yyyy): ");
                scanf("%d", &music[count].year);
                printf("Enter song duration (in seconds): ");
                scanf("%d", &music[count].duration);
                count++;
                printf("Song added successfully!\n");
                break;
            case 2:
                if(count == 0) {
                    printf("Music library is empty.\n");
                    break;
                }
                printf("Title                      Artist                     Album                      Year   Duration (s)\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                for(i=0; i<count; i++) {
                    printf("%-25s %-25s %-25s %-5d %d\n", music[i].title, music[i].artist, music[i].album, music[i].year, music[i].duration);
                }
                break;
            case 3:
                if(count == 0) {
                    printf("Music library is empty.\n");
                    break;
                }
                printf("Enter song title: ");
                scanf(" %[^\n]s", search_title);
                printf("Enter release year (yyyy): ");
                scanf("%d", &search_year);
                printf("\nSearch results:\n");
                printf("Title                      Artist                     Album                      Year   Duration (s)\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                for(i=0; i<count; i++) {
                    if(strcmp(search_title, music[i].title) == 0 && search_year == music[i].year) {
                        printf("%-25s %-25s %-25s %-5d %d\n", music[i].title, music[i].artist, music[i].album, music[i].year, music[i].duration);
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try Again!\n");
        }
    } while(choice != 4);

    return 0;
}