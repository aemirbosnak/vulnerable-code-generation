//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: scientific
/*
 * C Music Library Management System Example Program
 *
 * This program allows users to add, remove, and manage music files in a
 * library. It also provides a simple interface for searching and
 * retrieving music files based on their attributes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a music file
typedef struct {
    char* name;
    char* artist;
    char* genre;
    int duration;
} MusicFile;

// Function to add a new music file to the library
void add_file(MusicFile** files, int* num_files) {
    // Prompt user for file information
    char name[256];
    char artist[256];
    char genre[256];
    int duration;
    printf("Enter file name: ");
    fgets(name, 256, stdin);
    printf("Enter artist name: ");
    fgets(artist, 256, stdin);
    printf("Enter genre: ");
    fgets(genre, 256, stdin);
    printf("Enter duration (in seconds): ");
    scanf("%d", &duration);

    // Create a new MusicFile struct and add it to the library
    MusicFile* new_file = malloc(sizeof(MusicFile));
    new_file->name = strdup(name);
    new_file->artist = strdup(artist);
    new_file->genre = strdup(genre);
    new_file->duration = duration;
    files[*num_files] = new_file;
    (*num_files)++;
}

// Function to remove a music file from the library
void remove_file(MusicFile** files, int* num_files, char* name) {
    // Find the file to remove
    for (int i = 0; i < *num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            // Remove the file from the library
            free(files[i]->name);
            free(files[i]->artist);
            free(files[i]->genre);
            free(files[i]);

            // Shift all files after the removed file to the left
            for (int j = i; j < *num_files - 1; j++) {
                files[j] = files[j + 1];
            }

            // Decrement the number of files
            (*num_files)--;
            break;
        }
    }
}

// Function to search for a music file by name
MusicFile* search_file_by_name(MusicFile* files, int num_files, char* name) {
    // Linear search for the file
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return &files[i];
        }
    }

    // File not found
    return NULL;
}

// Function to search for music files by genre
MusicFile** search_files_by_genre(MusicFile* files, int num_files, char* genre) {
    // Linear search for files with the given genre
    MusicFile** matches = malloc(sizeof(MusicFile*) * num_files);
    int num_matches = 0;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].genre, genre) == 0) {
            matches[num_matches] = &files[i];
            num_matches++;
        }
    }

    // Return the matches
    return matches;
}

// Function to print the details of a music file
void print_file(MusicFile* file) {
    printf("File: %s\n", file->name);
    printf("Artist: %s\n", file->artist);
    printf("Genre: %s\n", file->genre);
    printf("Duration: %d\n", file->duration);
}

int main() {
    // Create an array of MusicFile pointers
    int num_files = 0;
    MusicFile** files = malloc(sizeof(MusicFile*) * 100);

    // Add some files to the library
    add_file(&files, &num_files);
    add_file(&files, &num_files);
    add_file(&files, &num_files);

    // Remove a file from the library
    remove_file(&files, &num_files, "song1.mp3");

    // Search for a file by name
    MusicFile* file = search_file_by_name(files, num_files, "song2.mp3");
    if (file != NULL) {
        print_file(file);
    } else {
        printf("File not found.\n");
    }

    // Search for files by genre
    MusicFile** matches = search_files_by_genre(files, num_files, "pop");
    printf("Files in pop genre: %d\n", num_files);
    for (int i = 0; i < num_files; i++) {
        print_file(matches[i]);
    }

    // Free the memory
    for (int i = 0; i < num_files; i++) {
        free(files[i]->name);
        free(files[i]->artist);
        free(files[i]->genre);
        free(files[i]);
    }
    free(files);

    return 0;
}