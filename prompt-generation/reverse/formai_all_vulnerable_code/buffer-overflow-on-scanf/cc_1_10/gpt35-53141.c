//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Structure to store music details
struct Music {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
    int length; // in seconds
    float rating;
};

// Function to display menu
int menu() {
    int choice;
    printf("1. Add Music\n");
    printf("2. Delete Music\n");
    printf("3. Search Music\n");
    printf("4. Display Music\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add music
void addMusic(struct Music *ptr, int *size) {
    printf("Enter music details:\n");
    printf("Title: ");
    fflush(stdin);
    fgets((ptr + *size)->title, 50, stdin);
    strtok((ptr + *size)->title, "\n"); // Removing newline character
    printf("Artist: ");
    fflush(stdin);
    fgets((ptr + *size)->artist, 50, stdin);
    strtok((ptr + *size)->artist, "\n");
    printf("Album: ");
    fflush(stdin);
    fgets((ptr + *size)->album, 50, stdin);
    strtok((ptr + *size)->album, "\n");
    printf("Year: ");
    scanf("%d", &(ptr + *size)->year);
    printf("Genre: ");
    fflush(stdin);
    fgets((ptr + *size)->genre, 20, stdin);
    strtok((ptr + *size)->genre, "\n");
    printf("Length (in seconds): ");
    scanf("%d", &(ptr + *size)->length);
    printf("Rating (out of 10): ");
    scanf("%f", &(ptr + *size)->rating);
    (*size)++; // Incrementing size of array
    printf("\nMusic added successfully!\n");
}

// Function to delete music
void deleteMusic(struct Music *ptr, int *size) {
    char title[50];
    printf("Enter title of music to be deleted: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    strtok(title, "\n");
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp((ptr + i)->title, title) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nMusic not found!\n");
    } else {
        for (int i = index; i < *size - 1; i++) {
            *(ptr + i) = *(ptr + i + 1);
        }
        (*size)--; // Decrementing size of array
        printf("\nMusic deleted successfully!\n");
    }
}

// Function to search music
void searchMusic(struct Music *ptr, int *size) {
    char title[50];
    printf("Enter title of music to be searched: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    strtok(title, "\n");
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp((ptr + i)->title, title) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nMusic not found!\n");
    } else {
        printf("\nMusic Found:\n");
        printf("Title: %s\n", (ptr + index)->title);
        printf("Artist: %s\n", (ptr + index)->artist);
        printf("Album: %s\n", (ptr + index)->album);
        printf("Year: %d\n", (ptr + index)->year);
        printf("Genre: %s\n", (ptr + index)->genre);
        printf("Length: %d seconds\n", (ptr + index)->length);
        printf("Rating: %.1f\n", (ptr + index)->rating);
    }
}

// Function to display music
void displayMusic(struct Music *ptr, int *size) {
    if (*size == 0) {
        printf("\nMusic Library is empty!\n");
    } else {
        printf("\nMusic Library:\n");
        for (int i = 0; i < *size; i++) {
            printf("%d. %s by %s\n", i + 1, (ptr + i)->title, (ptr + i)->artist);
        }
    }
}

int main() {
    printf("**** Welcome to Cryptic Music Library ****\n");
    int size = 0; // Initial size of array
    struct Music *ptr = (struct Music *) malloc(50 * sizeof(struct Music)); // Allocating memory dynamically
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                addMusic(ptr, &size);
                break;
            case 2:
                deleteMusic(ptr, &size);
                break;
            case 3:
                searchMusic(ptr, &size);
                break;
            case 4:
                displayMusic(ptr, &size);
                break;
            case 5:
                printf("\nThank you for using Cryptic Music Library!\n");
                break;
            default:
                printf("\nInvalid Choice, please try again!\n");
        }
    } while (choice != 5);
    free(ptr); // Freeing dynamically allocated memory
    return 0;
}