//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Structure to store music information
struct Music {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    float duration;
};

// Function prototypes
void addMusic(struct Music[], int*);
void displayMusic(struct Music[], int);
void searchMusic(struct Music[], int);
void deleteMusic(struct Music[], int*);

int main() {
    struct Music music[100]; // Array to store Music
    int count = 0; // Variable to keep count of Music
    int choice = 0;
    
    printf("Welcome to the C Music Library Management System!\n\n");
    
    do {
        // Display options to the user
        printf("Please select an option:\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMusic(music, &count);
                break;
            case 2:
                displayMusic(music, count);
                break;
            case 3:
                searchMusic(music, count);
                break;
            case 4:
                deleteMusic(music, &count);
                break;
            case 5:
                printf("Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
        
    } while(choice != 5);
    
    return 0;
}

// Function to add Music to the library
void addMusic(struct Music music[], int *count) {
    printf("\nAdd Music\n");
    printf("------------\n");
    printf("Enter the title: ");
    getchar(); // To clear the input buffer
    fgets(music[*count].title, 50, stdin);
    music[*count].title[strcspn(music[*count].title, "\n")] = '\0'; // To remove newline character
    printf("Enter the artist: ");
    fgets(music[*count].artist, 50, stdin);
    music[*count].artist[strcspn(music[*count].artist, "\n")] = '\0'; // To remove newline character
    printf("Enter the genre: ");
    fgets(music[*count].genre, 20, stdin);
    music[*count].genre[strcspn(music[*count].genre, "\n")] = '\0'; // To remove newline character
    printf("Enter the year: ");
    scanf("%d", &music[*count].year);
    printf("Enter the duration: ");
    scanf("%f", &music[*count].duration);
    
    printf("Music added successfully!\n\n");
    
    (*count)++;
}

// Function to display all Music in the library
void displayMusic(struct Music music[], int count) {
    printf("\nDisplay Music\n");
    printf("--------------\n");
    if(count == 0) {
        printf("There are no Music in the library.\n");
    }
    else {
        for(int i=0; i<count; i++) {
            printf("Title: %s\n", music[i].title);
            printf("Artist: %s\n", music[i].artist);
            printf("Genre: %s\n", music[i].genre);
            printf("Year: %d\n", music[i].year);
            printf("Duration: %.2f\n", music[i].duration);
            printf("--------------\n");
        }
    }
}

// Function to search for a specific Music in the library
void searchMusic(struct Music music[], int count) {
    printf("\nSearch Music\n");
    printf("--------------\n");
    if(count == 0) {
        printf("There are no Music in the library.\n");
    }
    else {
        char keyword[50];
        printf("Enter a keyword to search for: ");
        getchar(); // To clear the input buffer
        fgets(keyword, 50, stdin);
        keyword[strcspn(keyword, "\n")] = '\0'; // To remove newline character
        int found = 0;
        for(int i=0; i<count; i++) {
            if(strstr(music[i].title, keyword) != NULL || strstr(music[i].artist, keyword) != NULL) {
                printf("Title: %s\n", music[i].title);
                printf("Artist: %s\n", music[i].artist);
                printf("Genre: %s\n", music[i].genre);
                printf("Year: %d\n", music[i].year);
                printf("Duration: %.2f\n", music[i].duration);
                printf("--------------\n");
                found = 1;
            }
        }
        if(found == 0) {
            printf("No Music found with that keyword.\n");
        }
    }
}

// Function to delete a Music from the library
void deleteMusic(struct Music music[], int *count) {
    printf("\nDelete Music\n");
    printf("--------------\n");
    if(*count == 0) {
        printf("There are no Music in the library.\n");
    }
    else {
        char title[50];
        printf("Enter the title of the Music to delete: ");
        getchar(); // To clear the input buffer
        fgets(title, 50, stdin);
        title[strcspn(title, "\n")] = '\0'; // To remove newline character
        int found = 0;
        for(int i=0; i<*count; i++) {
            if(strcmp(music[i].title, title) == 0) {
                for(int j=i; j<(*count)-1; j++) {
                    music[j] = music[j+1];
                }
                (*count)--;
                found = 1;
                printf("Music deleted successfully!\n");
                break;
            }
        }
        if(found == 0) {
            printf("No Music found with that title.\n");
        }
    }
}