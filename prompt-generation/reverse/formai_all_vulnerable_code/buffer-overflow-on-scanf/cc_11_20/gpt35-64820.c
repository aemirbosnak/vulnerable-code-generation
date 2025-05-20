//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    int s_id;
    char s_title[50];
    char s_artist[50];
    char s_album[50];
    char s_genre[50];
};

int main() {
    FILE *fp;
    struct song s;
    int choice, id, n, i, flag;
    char ch;

    while(1) {
        printf("\n\n****** Music Library Management System ******\n");
        printf("\n1. Enter New Song\n");
        printf("2. View All Songs\n");
        printf("3. Search a Song\n");
        printf("4. Delete a Song\n");
        printf("5. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fp = fopen("songs.txt", "a");
                printf("\nEnter Song ID: ");
                scanf("%d", &s.s_id);

                fflush(stdin);
                printf("\nEnter Song Title: ");
                fgets(s.s_title, 50, stdin);

                printf("Enter Song Artist: ");
                fgets(s.s_artist, 50, stdin);

                printf("Enter Song Album: ");
                fgets(s.s_album, 50, stdin);

                printf("Enter Song Genre: ");
                fgets(s.s_genre, 50, stdin);

                fwrite(&s, sizeof(s), 1, fp);
                fclose(fp);

                printf("\nSong added successfully!");
                break;

            case 2:
                fp = fopen("songs.txt", "r");
                fseek(fp, 0, SEEK_END);
                n = ftell(fp)/sizeof(s);
                rewind(fp);

                printf("\nList of Songs:\n\n");

                for(i=0; i<n; i++) {
                    fread(&s, sizeof(s), 1, fp);
                    printf("Song ID: %d\n", s.s_id);
                    printf("Song Title: %s", s.s_title);
                    printf("Song Artist: %s", s.s_artist);
                    printf("Song Album: %s", s.s_album);
                    printf("Song Genre: %s", s.s_genre);
                    printf("\n------------------------------------\n");
                }
                fclose(fp);

                break;

            case 3:
                fp = fopen("songs.txt", "r");
                printf("\nEnter Song ID to search: ");
                scanf("%d", &id);

                fseek(fp, 0, SEEK_END);
                n = ftell(fp)/sizeof(s);
                rewind(fp);

                flag = 0;

                for(i=0; i<n; i++) {
                    fread(&s, sizeof(s), 1, fp);
                    if(s.s_id == id) {
                        flag = 1;
                        printf("Song ID: %d\n", s.s_id);
                        printf("Song Title: %s", s.s_title);
                        printf("Song Artist: %s", s.s_artist);
                        printf("Song Album: %s", s.s_album);
                        printf("Song Genre: %s", s.s_genre);
                        printf("\n------------------------------------\n");
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nSong with ID %d not found!", id);
                }

                fclose(fp);
                break;

            case 4:
                fp = fopen("songs.txt", "r+");
                FILE *temp = fopen("temp.txt", "w");
                printf("\nEnter Song ID to delete: ");
                scanf("%d", &id);

                fseek(fp, 0, SEEK_END);
                n = ftell(fp)/sizeof(s);
                rewind(fp);

                flag = 0;

                for(i=0; i<n; i++) {
                    fread(&s, sizeof(s), 1, fp);
                    if(s.s_id == id) {
                        flag = 1;
                        printf("Song with ID %d will be deleted!", id);
                    } else {
                        fwrite(&s, sizeof(s), 1, temp);
                    }
                }
                if(flag == 0) {
                    printf("\nSong with ID %d not found!", id);
                }
                fclose(fp);
                fclose(temp);

                fp = fopen("songs.txt", "w");
                temp = fopen("temp.txt", "r");

                while(fread(&s, sizeof(s), 1, temp)) {
                    fwrite(&s, sizeof(s), 1, fp);
                }

                fclose(fp);
                fclose(temp);

                break;

            case 5:
                printf("\nThank you for using Music Library Management System!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please enter again.");
        }
    }

    return 0;
}