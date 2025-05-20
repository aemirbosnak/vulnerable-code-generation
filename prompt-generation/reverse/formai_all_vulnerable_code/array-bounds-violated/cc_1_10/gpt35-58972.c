//FormAI DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct track {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int durationInSeconds;
    struct track *next;
};

struct library {
    int size;
    struct track *head;
};

void printTrack(struct track *t) {
    printf("\nTitle: %s\nArtist: %s\nAlbum: %s\nYear: %d\nDuration (seconds): %d\n", t->title, t->artist, t->album, t->year, t->durationInSeconds);
}

void printLibrary(struct library *lib) {
    struct track *current = lib->head;
    while (current != NULL) {
        printTrack(current);
        current = current->next;
    }
}

void addTrack(struct library *lib) {
    char title[100], artist[100], album[100], yearAsString[5], durationAsString[10];
    int year, duration;

    printf("\nEnter title:");
    fgets(title, sizeof(title), stdin);
    title[strlen(title) - 1] = '\0';

    printf("Enter artist:");
    fgets(artist, sizeof(artist), stdin);
    artist[strlen(artist) - 1] = '\0';

    printf("Enter album:");
    fgets(album, sizeof(album), stdin);
    album[strlen(album) - 1] = '\0';

    printf("Enter year:");
    fgets(yearAsString, sizeof(yearAsString), stdin);
    year = atoi(yearAsString);

    printf("Enter duration (seconds):");
    fgets(durationAsString, sizeof(durationAsString), stdin);
    duration = atoi(durationAsString);

    struct track *newTrack = malloc(sizeof(struct track));
    strcpy(newTrack->title, title);
    strcpy(newTrack->artist, artist);
    strcpy(newTrack->album, album);
    newTrack->year = year;
    newTrack->durationInSeconds = duration;
    newTrack->next = NULL;

    if (lib->head == NULL) {
        lib->head = newTrack;
    } else {
        struct track *current = lib->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTrack;
    }

    lib->size++;
    printf("\nTrack added successfully!\n");
}

void editTrack(struct library *lib) {
    char title[100];
    int year, duration;

    printf("\nEnter title of track to edit:");
    fgets(title, sizeof(title), stdin);
    title[strlen(title) - 1] = '\0';

    struct track *current = lib->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("\nFound track:\n");
            printTrack(current);

            printf("\nEnter new year:");
            scanf("%d", &year);
            current->year = year;
            getchar();

            printf("Enter new duration (seconds):");
            scanf("%d", &duration);
            current->durationInSeconds = duration;
            getchar();

            printf("\nTrack edited successfully!\n");
            return;
        }
        current = current->next;
    }

    printf("\nTrack not found.\n");
}

void removeTrack(struct library *lib) {
    char title[100];

    printf("\nEnter title of track to remove:");
    fgets(title, sizeof(title), stdin);
    title[strlen(title) - 1] = '\0';

    if (lib->head == NULL) {
        printf("\nLibrary is empty.\n");
        return;
    } else if (strcmp(lib->head->title, title) == 0) {
        struct track *temp = lib->head;
        lib->head = lib->head->next;
        free(temp);
        lib->size--;
        printf("\nTrack removed successfully!\n");
        return;
    }

    struct track *current = lib->head->next;
    struct track *previous = lib->head;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            previous->next = current->next;
            free(current);
            lib->size--;
            printf("\nTrack removed successfully!\n");
            return;
        }
        previous = previous->next;
        current = current->next;
    }

    printf("\nTrack not found.\n");
}

void searchTracks(struct library *lib) {
    char criteria[100], value[100], valueLC[100];
    int matchesFound = 0;

    printf("\nWhat criteria to search on? (title, artist, album, year, duration):");
    fgets(criteria, sizeof(criteria), stdin);
    criteria[strlen(criteria) - 1] = '\0';

    printf("\nEnter value to search for:");
    fgets(value, sizeof(value), stdin);
    value[strlen(value) - 1] = '\0';

    for (int i = 0; i < strlen(criteria); i++) {
        criteria[i] = tolower(criteria[i]);
    }

    for (int i = 0; i < strlen(value); i++) {
        valueLC[i] = tolower(value[i]);
    }

    struct track *current = lib->head;
    while (current != NULL) {
        if (strcmp(criteria, "title") == 0 && strcmp(valueLC, current->title) == 0) {
            printTrack(current);
            matchesFound++;
        } else if (strcmp(criteria, "artist") == 0 && strcmp(valueLC, current->artist) == 0) {
            printTrack(current);
            matchesFound++;
        } else if (strcmp(criteria, "album") == 0 && strcmp(valueLC, current->album) == 0) {
            printTrack(current);
            matchesFound++;
        } else if (strcmp(criteria, "year") == 0 && atoi(value) == current->year) {
            printTrack(current);
            matchesFound++;
        } else if (strcmp(criteria, "duration") == 0 && atoi(value) == current->durationInSeconds) {
            printTrack(current);
            matchesFound++;
        }
        current = current->next;
    }

    printf("\n%d matches found.\n", matchesFound);
}

void exportLibrary(struct library *lib) {
    FILE *file;
    char filepath[100];

    printf("\nEnter file path to export library to:");
    fgets(filepath, sizeof(filepath), stdin);
    filepath[strlen(filepath) - 1] = '\0';

    file = fopen(filepath, "w");
    if (file == NULL) {
        printf("\nFailed to export library to file.\n");
        return;
    }

    fprintf(file, "%d\n", lib->size);

    struct track *current = lib->head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->title);
        fprintf(file, "%s\n", current->artist);
        fprintf(file, "%s\n", current->album);
        fprintf(file, "%d\n", current->year);
        fprintf(file, "%d\n", current->durationInSeconds);
        current = current->next;
    }

    fclose(file);
    printf("\nLibrary exported successfully!\n");
}

void importLibrary(struct library *lib) {
    FILE *file;
    char filepath[100];

    printf("\nEnter file path to import library from:");
    fgets(filepath, sizeof(filepath), stdin);
    filepath[strlen(filepath) - 1] = '\0';

    file = fopen(filepath, "r");
    if (file == NULL) {
        printf("\nFailed to import library from file.\n");
        return;
    }

    char sizeAsString[10];
    fgets(sizeAsString, sizeof(sizeAsString), file);
    int size = atoi(sizeAsString);

    for (int i = 0; i < size; i++) {
        char title[100], artist[100], album[100], yearAsString[10], durationAsString[10];

        fgets(title, sizeof(title), file);
        title[strlen(title) - 1] = '\0';

        fgets(artist, sizeof(artist), file);
        artist[strlen(artist) - 1] = '\0';

        fgets(album, sizeof(album), file);
        album[strlen(album) - 1] = '\0';

        fgets(yearAsString, sizeof(yearAsString), file);
        int year = atoi(yearAsString);

        fgets(durationAsString, sizeof(durationAsString), file);
        int duration = atoi(durationAsString);

        struct track *newTrack = malloc(sizeof(struct track));
        strcpy(newTrack->title, title);
        strcpy(newTrack->artist, artist);
        strcpy(newTrack->album, album);
        newTrack->year = year;
        newTrack->durationInSeconds = duration;

        if (lib->head == NULL) {
            lib->head = newTrack;
        } else {
            struct track *current = lib->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newTrack;
        }

        lib->size++;
    }

    fclose(file);
    printf("\nLibrary imported successfully!\n");
}

int main() {
    struct library lib;
    lib.size = 0;
    lib.head = NULL;

    while (1) {
        char input[100];

        printf("\n***** C Music Library Management System *****\n");
        printf("1. Add track\n");
        printf("2. Edit track\n");
        printf("3. Remove track\n");
        printf("4. Search tracks\n");
        printf("5. Print library\n");
        printf("6. Export library\n");
        printf("7. Import library\n");
        printf("8. Quit\n");

        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "1") == 0) {
            addTrack(&lib);
        } else if (strcmp(input, "2") == 0) {
            editTrack(&lib);
        } else if (strcmp(input, "3") == 0) {
            removeTrack(&lib);
        } else if (strcmp(input, "4") == 0) {
            searchTracks(&lib);
        } else if (strcmp(input, "5") == 0) {
            printLibrary(&lib);
        } else if (strcmp(input, "6") == 0) {
            exportLibrary(&lib);
        } else if (strcmp(input, "7") == 0) {
            importLibrary(&lib);
        } else if (strcmp(input, "8") == 0) {
            break;
        } else {
            printf("\nInvalid input.\n");
        }
    }

    printf("\nGoodbye!\n");
    return 0;
}