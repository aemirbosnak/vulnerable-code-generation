//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Music;

Music library[MAX_MUSICS];
int music_count = 0;

void add_music() {
    if (music_count >= MAX_MUSICS) {
        printf("Library is full! Can't add more music.\n");
        return;
    }
    
    Music new_music;
    printf("Enter music title: ");
    getchar(); // To consume newline from previous input
    fgets(new_music.title, MAX_TITLE_LEN, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(new_music.artist, MAX_ARTIST_LEN, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &new_music.year);

    library[music_count++] = new_music;
    printf("Music added successfully!\n");
}

void display_music() {
    if (music_count == 0) {
        printf("No music found in the library.\n");
    } else {
        printf("Music Library:\n");
        for (int i = 0; i < music_count; i++) {
            printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].artist, library[i].year);
        }
    }
}

void delete_music() {
    int index;
    printf("Enter the index of the music to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > music_count) {
        printf("Invalid index. No music deleted.\n");
        return;
    }

    for (int i = index - 1; i < music_count - 1; i++) {
        library[i] = library[i + 1];
    }
    music_count--;
    printf("Music deleted successfully!\n");
}

void search_music() {
    char search[MAX_TITLE_LEN];
    printf("Enter the title or artist to search: ");
    getchar(); // To consume newline
    fgets(search, MAX_TITLE_LEN, stdin);
    search[strcspn(search, "\n")] = 0; // Remove newline

    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strstr(library[i].title, search) != NULL || strstr(library[i].artist, search) != NULL) {
            printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].artist, library[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching music found.\n");
    }
}

void save_library() {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < music_count; i++) {
        fprintf(file, "%s;%s;%d\n", library[i].title, library[i].artist, library[i].year);
    }
    fclose(file);
    printf("Library saved successfully!\n");
}

void load_library() {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("No saved library found, starting with an empty library.\n");
        return;
    }

    while (fscanf(file, " %99[^;]; %99[^;]; %d\n", library[music_count].title, library[music_count].artist, &library[music_count].year) == 3) {
        music_count++;
        if (music_count >= MAX_MUSICS) break;
    }
    fclose(file);
    printf("Library loaded successfully! %d music items found.\n", music_count);
}

int main() {
    int choice;

    load_library();

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Delete Music\n");
        printf("4. Search Music\n");
        printf("5. Save Library\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                display_music();
                break;
            case 3:
                delete_music();
                break;
            case 4:
                search_music();
                break;
            case 5:
                save_library();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}