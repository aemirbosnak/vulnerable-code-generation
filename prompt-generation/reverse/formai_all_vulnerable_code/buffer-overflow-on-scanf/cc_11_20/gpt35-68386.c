//FormAI DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

int main() {
    int choice;
    struct song library[50];
    int count = 0;
    do {
        printf("\nC Music Library Management System\n");
        printf("1. Add song\n");
        printf("2. Remove song\n");
        printf("3. Display library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (count == 50) {
                    printf("Library is full!\n");
                } else {
                    printf("Enter song information:\n");
                    printf("Title: ");
                    scanf("%s", library[count].title);
                    printf("Artist: ");
                    scanf("%s", library[count].artist);
                    printf("Album: ");
                    scanf("%s", library[count].album);
                    printf("Year: ");
                    scanf("%d", &library[count].year);
                    count++;
                }
                break;
            case 2:
                if (count == 0) {
                    printf("Library is empty!\n");
                } else {
                    char title[50];
                    printf("Enter title of song to remove: ");
                    scanf("%s", title);
                    int i;
                    for (i = 0; i < count; i++) {
                        if (strcmp(library[i].title, title) == 0) {
                            int j;
                            for (j = i; j < count - 1; j++) {
                                strcpy(library[j].title, library[j+1].title);
                                strcpy(library[j].artist, library[j+1].artist);
                                strcpy(library[j].album, library[j+1].album);
                                library[j].year = library[j+1].year;
                            }
                            count--;
                            printf("%s by %s has been removed from the library.\n", title, library[i].artist);
                            break;
                        }
                    }
                    if (i == count) {
                        printf("Song not found!\n");
                    }
                }
                break;
            case 3:
                if (count == 0) {
                    printf("Library is empty!\n");
                } else {
                    printf("Library:\n");
                    int i;
                    for (i = 0; i < count; i++) {
                        printf("%s by %s from %s (%d)\n", library[i].title, library[i].artist, library[i].album, library[i].year);
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}