//FormAI DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CD {
    int cd_id;
    char cd_name[50];
    char artist[50];
    int num_of_songs;
};

int main() {
    int num_of_cds, i, j;
    printf("How many CDs in your music library? ");
    scanf("%d", &num_of_cds);

    struct CD music_library[num_of_cds];

    printf("\nEnter details for each CD:\n");
    for(i=0; i<num_of_cds; i++) {
        printf("\nCD %d:\n", i+1);
        printf("Enter CD ID: ");
        scanf("%d", &music_library[i].cd_id);
        printf("Enter CD Name: ");
        scanf("%s", music_library[i].cd_name);
        printf("Enter Artist Name: ");
        scanf("%s", music_library[i].artist);
        printf("Enter Number of Songs: ");
        scanf("%d", &music_library[i].num_of_songs);
    }

    printf("\nYour Music Library:\n");
    for(i=0; i<num_of_cds; i++) {
        printf("\nCD %d:\n", i+1);
        printf("CD ID: %d\n", music_library[i].cd_id);
        printf("CD Name: %s\n", music_library[i].cd_name);
        printf("Artist Name: %s\n", music_library[i].artist);
        printf("Number of Songs: %d\n", music_library[i].num_of_songs);
    }

    printf("\nSorting your music library by CD Name...\n");

    for(i=0; i<num_of_cds-1; i++) {
        for(j=i+1; j<num_of_cds; j++) {
            if(strcmp(music_library[i].cd_name, music_library[j].cd_name) > 0) {
                struct CD temp = music_library[i];
                music_library[i] = music_library[j];
                music_library[j] = temp;
            }
        }
    }

    printf("\nYour Music Library sorted by CD Name:\n");
    for(i=0; i<num_of_cds; i++) {
        printf("\nCD %d:\n", i+1);
        printf("CD ID: %d\n", music_library[i].cd_id);
        printf("CD Name: %s\n", music_library[i].cd_name);
        printf("Artist Name: %s\n", music_library[i].artist);
        printf("Number of Songs: %d\n", music_library[i].num_of_songs);
    }

    return 0;
}