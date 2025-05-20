//FormAI DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBRARIES 100
#define MAX_LIBRARY_NAME_LENGTH 50
#define MAX_ALBUMS 100
#define MAX_ALBUM_NAME_LENGTH 50

// Define structs for storing data
typedef struct {
    char name[MAX_LIBRARY_NAME_LENGTH];
    int num_albums;
    char *albums[MAX_ALBUMS];
} Library;

// Global variables
Library libraries[MAX_LIBRARIES];
int num_libraries = 0;

// Function prototypes
void add_library();
void add_album();
void list_libraries();
void list_albums();

int main() {
    int option;

    do {
        printf("Select an option:\n");
        printf("1. Add library\n");
        printf("2. Add album\n");
        printf("3. List libraries\n");
        printf("4. List albums\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_library();
                break;
            case 2:
                add_album();
                break;
            case 3:
                list_libraries();
                break;
            case 4:
                list_albums();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

void add_library() {
    char name[MAX_LIBRARY_NAME_LENGTH];
    printf("Enter library name: ");
    scanf("%s", name);

    // Check if a library with this name already exists
    for (int i = 0; i < num_libraries; i++) {
        if (strcmp(libraries[i].name, name) == 0) {
            printf("A library with this name already exists.\n");
            return;
        }
    }

    // Initialize new library struct
    Library new_library;
    strncpy(new_library.name, name, MAX_LIBRARY_NAME_LENGTH);
    new_library.num_albums = 0;

    // Add new library to global array
    libraries[num_libraries] = new_library;
    num_libraries++;

    printf("Library %s added successfully.\n", name);
}

void add_album() {
    char name[MAX_ALBUM_NAME_LENGTH];
    printf("Enter album name: ");
    scanf("%s", name);

    // Find library to add album to
    char library_name[MAX_LIBRARY_NAME_LENGTH];
    printf("Enter library name: ");
    scanf("%s", library_name);

    int library_index = -1;
    for (int i = 0; i < num_libraries; i++) {
        if (strcmp(libraries[i].name, library_name) == 0) {
            library_index = i;
            break;
        }
    }

    // If library not found, return error message
    if (library_index == -1) {
        printf("Library %s not found.\n", library_name);
        return;
    }

    // Check if album already exists in this library
    for (int i = 0; i < libraries[library_index].num_albums; i++) {
        if (strcmp(libraries[library_index].albums[i], name) == 0) {
            printf("Album %s already exists in library %s.\n", name, library_name);
            return;
        }
    }

    // Add new album to library
    if (libraries[library_index].num_albums >= MAX_ALBUMS) {
        printf("Library %s is at max album capacity.\n", library_name);
        return;
    }

    char *new_album = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    strncpy(new_album, name, strlen(name) + 1);
    libraries[library_index].albums[libraries[library_index].num_albums] = new_album;
    libraries[library_index].num_albums++;

    printf("Album %s added to library %s successfully.\n", name, library_name);
}

void list_libraries() {
    if (num_libraries == 0) {
        printf("No libraries have been added yet.\n");
        return;
    }

    printf("List of libraries:\n");
    for (int i = 0; i < num_libraries; i++) {
        printf("- %s (%d album%s)\n", libraries[i].name, libraries[i].num_albums, libraries[i].num_albums == 1 ? "" : "s");
    }
}

void list_albums() {
    if (num_libraries == 0) {
        printf("No libraries have been added yet.\n");
        return;
    }

    char library_name[MAX_LIBRARY_NAME_LENGTH];
    printf("Enter library name: ");
    scanf("%s", library_name);

    int library_index = -1;
    for (int i = 0; i < num_libraries; i++) {
        if (strcmp(libraries[i].name, library_name) == 0) {
            library_index = i;
            break;
        }
    }

    if (library_index == -1) {
        printf("Library %s not found.\n", library_name);
        return;
    }

    printf("List of albums in library %s:\n", library_name);
    for (int i = 0; i < libraries[library_index].num_albums; i++) {
        printf("- %s\n", libraries[library_index].albums[i]);
    }
}