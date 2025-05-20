//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include<stdio.h> 
#include<stdlib.h>
#include<time.h> 

// Structure to hold information of a Song 
struct song {  
    int id;
    char name[50];  
    char artist[50];  
    char album[50];  
    int year; 
    float duration;  
}; 

// Function to add new Song 
void addSong(struct song lib[], int size) {
    printf("\nGreat! Let's add a new song to our C Music Library Management System:\n\n");
    
    srand(time(NULL));
    lib[size].id = rand() % 10000 + 1;
    
    printf("Enter Song name: ");
    scanf("%s", lib[size].name);
    
    printf("Enter Artist name: ");
    scanf("%s", lib[size].artist);
    
    printf("Enter Album name: ");
    scanf("%s", lib[size].album);
    
    printf("Enter Year of release: ");
    scanf("%d", &lib[size].year);
    
    printf("Enter Duration in minutes: ");
    scanf("%f", &lib[size].duration);
    
    printf("\nNew Song added successfully with ID: %d\n", lib[size].id);
}

// Function to edit existing Song 
void editSong(struct song lib[], int size) {
    int id;
    printf("\nEnter Song ID to edit details: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (lib[i].id == id) {
            printf("\nCurrent Song Details:");
            printf("\nID: %d", lib[i].id);
            printf("\nSong name: %s", lib[i].name);
            printf("\nArtist name: %s", lib[i].artist);
            printf("\nAlbum name: %s", lib[i].album);
            printf("\nYear of release: %d", lib[i].year);
            printf("\nDuration in minutes: %.2f", lib[i].duration);
            
            printf("\nEnter new Song name (press ENTER to skip): ");
            scanf("%s", lib[i].name);
            
            printf("Enter new Artist name (press ENTER to skip): ");
            scanf("%s", lib[i].artist);
            
            printf("Enter new Album name (press ENTER to skip): ");
            scanf("%s", lib[i].album);
            
            printf("Enter new Year of release (press 0 to skip): ");
            scanf("%d", &lib[i].year);
            
            printf("Enter new Duration in minutes (press 0 to skip): ");
            scanf("%f", &lib[i].duration);
            
            printf("\nSong Details updated successfully for ID: %d\n", id);
            found = 1; 
            break;
        }
    }
    if (!found) {
        printf("\nNo Song found with ID: %d\n", id);
    }
}

// Function to display all Songs 
void displaySongs(struct song lib[], int size) {
    if (size == 0) {
        printf("\nNo Songs in the C Music Library Management System!\n");
        return;
    }
    printf("\nAll Songs in the C Music Library Management System:\n\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", lib[i].id);
        printf("Song name: %s\n", lib[i].name);
        printf("Artist name: %s\n", lib[i].artist);
        printf("Album name: %s\n", lib[i].album);
        printf("Year of release: %d\n", lib[i].year);
        printf("Duration in minutes: %.2f\n", lib[i].duration);
        printf("\n");
    }
}

// Function to delete existing Song 
void deleteSong(struct song lib[], int size) {
    int id;
    printf("\nEnter Song ID to delete: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (lib[i].id == id) {
            found = 1;
            printf("\nDeleting Song with ID: %d\n", lib[i].id);
            for (int j = i; j < size; j++) {
                lib[j] = lib[j+1];
            }
            printf("\nSong deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nNo Song found with ID: %d\n", id);
    }
}

int main() {
    int option, size = 0;
    struct song library[50];
    
    printf("Welcome to the C Music Library Management System!\n\n");
    
    do {
        printf("\nSelect an option below:");
        printf("\n1. Add new Song");
        printf("\n2. Edit existing Song");
        printf("\n3. Display all Songs");
        printf("\n4. Delete existing Song");
        printf("\n5. Exit Program\n");
        
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addSong(library, size);
                size++;
                break;
            case 2:
                editSong(library, size);
                break;
            case 3:
                displaySongs(library, size);
                break;
            case 4:
                deleteSong(library, size);
                size--;
                break;
            case 5:
                printf("\nGoodbye! Hope you enjoyed using C Music Library Management System :)\n");
                break;
            default:
                printf("\nInvalid option! Please select a valid option.\n");
                break;
        }
    } while (option != 5);
    
    return 0;
}