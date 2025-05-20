//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char artist[50];
    char title[50];
    int year;
};

void addalbum(struct Album album[], int *count)
{
    printf("Enter artist name: ");
    scanf("%s", album[*count].artist);
    printf("Enter album title: ");
    scanf("%s", album[*count].title);
    printf("Enter year released: ");
    scanf("%d", &album[*count].year);
    *count += 1;
}

void displayalbums(struct Album album[], int count)
{
    printf("Albums in library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s (%d)\n", i+1, album[i].artist, album[i].title, album[i].year);
    }
}

void searchalbum(struct Album album[], int count)
{
    char search_artist[50];
    printf("Enter artist name to search for: ");
    scanf("%s", search_artist);
    for (int i = 0; i < count; i++) {
        if (strcmp(album[i].artist, search_artist) == 0) {
            printf("%s - %s (%d)\n", album[i].artist, album[i].title, album[i].year);
        }
    }
}

void deletealbum(struct Album album[], int *count)
{
    int choice;
    displayalbums(album, *count);
    printf("Enter album number to delete: ");
    scanf("%d", &choice);
    for (int i = choice-1; i < *count-1; i++) {
        album[i] = album[i+1];
    }
    *count -= 1;
    printf("Album deleted.\n");
}

int main()
{
    struct Album album[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add album\n");
        printf("2. Display all albums\n");
        printf("3. Search albums by artist\n");
        printf("4. Delete album\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addalbum(album, &count);
                break;
            case 2:
                if (count == 0) {
                    printf("No albums in library.\n");
                } else {
                    displayalbums(album, count);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("No albums in library.\n");
                } else {
                    searchalbum(album, count);
                }
                break;
            case 4:
                if (count == 0) {
                    printf("No albums in library.\n");
                } else {
                    deletealbum(album, &count);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}