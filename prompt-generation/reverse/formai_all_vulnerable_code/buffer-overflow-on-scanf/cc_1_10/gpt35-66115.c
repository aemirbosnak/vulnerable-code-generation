//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main() {
    int choice, n = 0, i, flag;
    char title[MAX], artist[MAX], album[MAX];
    while(1) {
        printf("\n********** C MUSIC LIBRARY MANAGEMENT SYSTEM **********\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter song title: ");
                fflush(stdin);
                fgets(title, MAX, stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter artist name: ");
                fflush(stdin);
                fgets(artist, MAX, stdin);
                artist[strcspn(artist, "\n")] = 0;
                printf("Enter album name: ");
                fflush(stdin);
                fgets(album, MAX, stdin);
                album[strcspn(album, "\n")] = 0;
                FILE *fp;
                fp = fopen("music.txt", "a");
                fprintf(fp, "%s\t%s\t%s\n", title, artist, album);
                fclose(fp);
                printf("\nSong has been added successfully!\n");
                n++;
                break;
            case 2:
                fp = fopen("music.txt", "r");
                printf("\nTitle\t\tArtist\t\tAlbum\n");
                while (fscanf(fp, "%s%s%s", title, artist, album) != EOF) {
                    printf("%s\t\t%s\t\t%s\n", title, artist, album);
                }
                fclose(fp);
                break;
            case 3:
                printf("\nEnter song title to search: ");
                fflush(stdin);
                fgets(title, MAX, stdin);
                title[strcspn(title, "\n")] = 0;
                flag = 0;
                fp = fopen("music.txt", "r");
                while (fscanf(fp, "%s%s%s", title, artist, album) != EOF) {
                    if (strcmp(title, title) == 0) {
                        printf("\nTitle\t\tArtist\t\tAlbum\n");
                        printf("%s\t\t%s\t\t%s\n", title, artist, album);
                        flag = 1;
                        break;
                    }
                }
                fclose(fp);
                if (flag == 0) {
                    printf("\nSong not found!\n");
                }
                break;
            case 4:
                printf("Exiting now...Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid input! Please try again.\n");
                break;
        }
    }
    return 0;
}