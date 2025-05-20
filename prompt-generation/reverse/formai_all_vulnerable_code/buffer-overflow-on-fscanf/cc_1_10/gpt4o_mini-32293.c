//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

// Structure to store music details
typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // in seconds
} Music;

// Function declarations
void addMusic(Music* collection, int* count);
void listMusics(Music* collection, int count);
void searchMusic(Music* collection, int count);
void deleteMusic(Music* collection, int* count);
void saveToFile(Music* collection, int count);
void loadFromFile(Music* collection, int* count);
void displayMenu();

int main() {
    Music collection[MAX_MUSICS];
    int count = 0;
    int choice;

    loadFromFile(collection, &count);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character left in the buffer

        switch (choice) {
            case 1:
                addMusic(collection, &count);
                break;
            case 2:
                listMusics(collection, count);
                break;
            case 3:
                searchMusic(collection, count);
                break;
            case 4:
                deleteMusic(collection, &count);
                break;
            case 5:
                saveToFile(collection, count);
                printf("Music collection saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. List Musics\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save to File\n");
    printf("6. Exit\n");
}

void addMusic(Music* collection, int* count) {
    if (*count >= MAX_MUSICS) {
        printf("Music collection is full. Cannot add more music.\n");
        return;
    }
    
    printf("Enter music title: ");
    fgets(collection[*count].title, TITLE_LENGTH, stdin);
    collection[*count].title[strcspn(collection[*count].title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(collection[*count].artist, ARTIST_LENGTH, stdin);
    collection[*count].artist[strcspn(collection[*count].artist, "\n")] = 0; // Remove newline

    printf("Enter duration (in seconds): ");
    scanf("%d", &collection[*count].duration);
    getchar(); // To consume newline character left in the buffer

    (*count)++;
    printf("Music added successfully!\n");
}

void listMusics(Music* collection, int count) {
    if (count == 0) {
        printf("No music in the collection.\n");
        return;
    }
    
    printf("\nMusic Collection:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Duration: %d seconds\n", 
            i + 1, 
            collection[i].title, 
            collection[i].artist, 
            collection[i].duration);
    }
}

void searchMusic(Music* collection, int count) {
    char title[TITLE_LENGTH];
    printf("Enter music title to search: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(collection[i].title, title) == 0) {
            printf("Found: Title: %s, Artist: %s, Duration: %d seconds\n", 
                collection[i].title, 
                collection[i].artist, 
                collection[i].duration);
            return;
        }
    }
    printf("Music not found in the collection.\n");
}

void deleteMusic(Music* collection, int* count) {
    char title[TITLE_LENGTH];
    printf("Enter music title to delete: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(collection[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                collection[j] = collection[j + 1];
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            return;
        }
    }
    printf("Music not found in the collection.\n");
}

void saveToFile(Music* collection, int count) {
    FILE *file = fopen("music_collection.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%d\n", collection[i].title, collection[i].artist, collection[i].duration);
    }
    
    fclose(file);
}

void loadFromFile(Music* collection, int* count) {
    FILE *file = fopen("music_collection.txt", "r");
    if (file == NULL) {
        printf("No previous collection found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%[^\t]\t%[^\t]\t%d\n", 
                  collection[*count].title,
                  collection[*count].artist,
                  &collection[*count].duration) != EOF) {
        (*count)++;
    }

    fclose(file);
}