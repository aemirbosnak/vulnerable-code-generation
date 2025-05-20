//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct album {
    char title[50];
    char artist[50];
    int year;
};

void addAlbum(struct album *lib, int *size) {
    if (*size == 50) {
        printf("Library is full! Cannot add more albums.\n");
        return;
    }

    printf("Enter album title: ");
    scanf("%s", lib[*size].title);

    printf("Enter artist name: ");
    scanf("%s", lib[*size].artist);

    printf("Enter year of release: ");
    scanf("%d", &lib[*size].year);
    
    (*size)++;
    printf("Album added!\n");
}

void displayLibrary(struct album *lib, int size) {
    if (size == 0) {
        printf("Library is empty!\n");
        return;
    }

    printf("Title\t\tArtist\t\tYear\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t\t%s\t\t%d\n", lib[i].title, lib[i].artist, lib[i].year);
    }
}

void searchAlbum(struct album *lib, int size, char *title) {
    for (int i = 0; i < size; i++) {
        if (strcmp(lib[i].title, title) == 0) {
            printf("Album found!\n");
            printf("Title: %s\n", lib[i].title);
            printf("Artist: %s\n", lib[i].artist);
            printf("Year: %d\n", lib[i].year);
            return;
        }
    }

    printf("Album not found!\n");
}

void deleteAlbum(struct album *lib, int *size, char *title) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(lib[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < *size-1; j++) {
                strcpy(lib[j].title, lib[j+1].title);
                strcpy(lib[j].artist, lib[j+1].artist);
                lib[j].year = lib[j+1].year;
            }
            (*size)--;
            printf("Album deleted!\n");
            break;
        }
    }

    if (!found) {
        printf("Album not found!\n");
    }
}

int main() {
    struct album library[50];
    int size = 0;
    int choice;
    char title[50];

    while (1) {
        printf("\n---------------C MUSIC LIBRARY MANAGEMENT SYSTEM---------------\n");
        printf("1. Add Album\n");
        printf("2. Display Library\n");
        printf("3. Search Album\n");
        printf("4. Delete Album\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum(library, &size);
                break;
            case 2:
                displayLibrary(library, size);
                break;
            case 3:
                printf("Enter album title to search: ");
                scanf("%s", title);
                searchAlbum(library, size, title);
                break;
            case 4:
                printf("Enter album title to delete: ");
                scanf("%s", title);
                deleteAlbum(library, &size, title);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}