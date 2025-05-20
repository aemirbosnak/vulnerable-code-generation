//FormAI DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
};

void add_song(struct song library[], int *count);
void edit_song(struct song library[], int count);
void delete_song(struct song library[], int *count);
void view_all_songs(struct song library[], int count);
void search_song(struct song library[], int count);
void sort_library(struct song library[], int count);
void save_library(struct song library[], int count);
void load_library(struct song library[], int *count);

int main() {
    struct song library[100];
    int count = 0;
    int choice;
    
    while (1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add a song\n");
        printf("2. Edit a song\n");
        printf("3. Delete a song\n");
        printf("4. View all songs\n");
        printf("5. Search for a song\n");
        printf("6. Sort the library\n");
        printf("7. Save the library to file\n");
        printf("8. Load the library from file\n");
        printf("9. Quit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_song(library, &count);
                break;
            case 2:
                edit_song(library, count);
                break;
            case 3:
                delete_song(library, &count);
                break;
            case 4:
                view_all_songs(library, count);
                break;
            case 5:
                search_song(library, count);
                break;
            case 6:
                sort_library(library, count);
                break;
            case 7:
                save_library(library, count);
                break;
            case 8:
                load_library(library, &count);
                break;
            case 9:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void add_song(struct song library[], int *count) {
    printf("Please enter the song title: ");
    scanf(" %[^\n]s", library[*count].title);
    printf("Please enter the artist name: ");
    scanf(" %[^\n]s", library[*count].artist);
    printf("Please enter the album title: ");
    scanf(" %[^\n]s", library[*count].album);
    printf("Please enter the year of release: ");
    scanf("%d", &library[*count].year);
    printf("Please enter the song duration in seconds: ");
    scanf("%d", &library[*count].duration);
    (*count)++;
    printf("Song added successfully!\n");
}

void edit_song(struct song library[], int count) {
    int index;
    printf("Please enter the index of the song you want to edit: ");
    scanf("%d", &index);
    if (index < 1 || index > count) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    printf("The song at index %d is:\n", index);
    printf("Title: %s\n", library[index - 1].title);
    printf("Artist: %s\n", library[index - 1].artist);
    printf("Album: %s\n", library[index - 1].album);
    printf("Year: %d\n", library[index - 1].year);
    printf("Duration: %d seconds\n", library[index - 1].duration);
    printf("Please enter the new song title: ");
    scanf(" %[^\n]s", library[index - 1].title);
    printf("Please enter the new artist name: ");
    scanf(" %[^\n]s", library[index - 1].artist);
    printf("Please enter the new album title: ");
    scanf(" %[^\n]s", library[index - 1].album);
    printf("Please enter the new year of release: ");
    scanf("%d", &library[index - 1].year);
    printf("Please enter the new song duration in seconds: ");
    scanf("%d", &library[index - 1].duration);
    printf("Song edited successfully!\n");
}

void delete_song(struct song library[], int *count) {
    int index;
    printf("Please enter the index of the song you want to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        strcpy(library[i].title, library[i + 1].title);
        strcpy(library[i].artist, library[i + 1].artist);
        strcpy(library[i].album, library[i + 1].album);
        library[i].year = library[i + 1].year;
        library[i].duration = library[i + 1].duration;
    }
    (*count)--;
    printf("Song deleted successfully!\n");
}

void view_all_songs(struct song library[], int count) {
    if (count == 0) {
        printf("The library is empty.\n");
        return;
    }
    printf("The library contains %d songs:\n", count);
    for (int i = 0; i < count; i++) {
        printf("------- Song %d -------\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("Duration: %d seconds\n", library[i].duration);
    }
}

void search_song(struct song library[], int count) {
    if (count == 0) {
        printf("The library is empty.\n");
        return;
    }
    char query[50];
    printf("Please enter a search query: ");
    scanf(" %[^\n]s", query);
    printf("The following songs match your search query:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            printf("------- Song %d -------\n", i + 1);
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
        }
    }
}

void sort_library(struct song library[], int count) {
    if (count == 0) {
        printf("The library is empty.\n");
        return;
    }
    int choice;
    printf("Please select a sorting method:\n");
    printf("1. By title\n");
    printf("2. By artist\n");
    printf("3. By album\n");
    printf("4. By year\n");
    printf("5. By duration\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (strcmp(library[i].title, library[j].title) > 0) {
                        struct song temp = library[i];
                        library[i] = library[j];
                        library[j] = temp;
                    }
                }
            }
            printf("Library sorted by title.\n");
            break;
        case 2:
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (strcmp(library[i].artist, library[j].artist) > 0) {
                        struct song temp = library[i];
                        library[i] = library[j];
                        library[j] = temp;
                    }
                }
            }
            printf("Library sorted by artist.\n");
            break;
        case 3:
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (strcmp(library[i].album, library[j].album) > 0) {
                        struct song temp = library[i];
                        library[i] = library[j];
                        library[j] = temp;
                    }
                }
            }
            printf("Library sorted by album.\n");
            break;
        case 4:
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (library[i].year > library[j].year) {
                        struct song temp = library[i];
                        library[i] = library[j];
                        library[j] = temp;
                    }
                }
            }
            printf("Library sorted by year.\n");
            break;
        case 5:
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (library[i].duration > library[j].duration) {
                        struct song temp = library[i];
                        library[i] = library[j];
                        library[j] = temp;
                    }
                }
            }
            printf("Library sorted by duration.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void save_library(struct song library[], int count) {
    FILE *fp;
    fp = fopen("music_library.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s;%s;%s;%d;%d\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }
    fclose(fp);
    printf("Library saved successfully!\n");
}

void load_library(struct song library[], int *count) {
    FILE *fp;
    fp = fopen("music_library.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^;];%[^;];%[^;];%d;%d", library[*count].title, library[*count].artist, library[*count].album, &library[*count].year, &library[*count].duration);
        (*count)++;
    }
    fclose(fp);
    printf("Library loaded successfully!\n");
}