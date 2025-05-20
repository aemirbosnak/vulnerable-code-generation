//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// define the struct for each Ebook
typedef struct ebook {
    char title[50];
    char author[50];
    int year;
    int pages;
    char* content;
} Ebook;

// function to read contents of an Ebook
void readEbook(char* ebook_content) {
    printf("%s\n", ebook_content);
}

// function to display Ebook info and read
void displayEbook(Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Year: %d\n", ebook.year);
    printf("Pages: %d\n", ebook.pages);
    printf("Do you want to read this Ebook? (y/n): ");
    char answer = getchar();
    if (answer == 'y') {
        readEbook(ebook.content);
    }
}

int main() {
    Ebook ebook1 = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 180, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod nibh at mi tempor, a eleifend tortor lobortis. Curabitur non dui a odio efficitur egestas. Phasellus bibendum, odio ut hendrerit rhoncus, nulla ex placerat ipsum, eu dapibus quam lectus id mauris. Vestibulum scelerisque vel eros eget malesuada. Nam a arcu enim. Curabitur pulvinar eros id mi mattis pellentesque. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Curabitur magna nunc, vestibulum vitae magna at, tristique dapibus elit. Sed vel auctor arcu. Aenean consectetur porta lorem, a malesuada lectus ultricies at. Sed imperdiet felis sodales mauris commodo, vitae pretium sem malesuada. Vestibulum quis viverra quam, sed faucibus ligula. Vestibulum finibus porta ante at fermentum."};
    Ebook ebook2 = {"1984", "George Orwell", 1949, 328, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod nibh at mi tempor, a eleifend tortor lobortis. Curabitur non dui a odio efficitur egestas. Phasellus bibendum, odio ut hendrerit rhoncus, nulla ex placerat ipsum, eu dapibus quam lectus id mauris. Vestibulum scelerisque vel eros eget malesuada. Nam a arcu enim. Curabitur pulvinar eros id mi mattis pellentesque. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Curabitur magna nunc, vestibulum vitae magna at, tristique dapibus elit. Sed vel auctor arcu. Aenean consectetur porta lorem, a malesuada lectus ultricies at. Sed imperdiet felis sodales mauris commodo, vitae pretium sem malesuada. Vestibulum quis viverra quam, sed faucibus ligula. Vestibulum finibus porta ante at fermentum."};
    Ebook ebook3 = {"The Catcher in the Rye", "J.D. Salinger", 1951, 224, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod nibh at mi tempor, a eleifend tortor lobortis. Curabitur non dui a odio efficitur egestas. Phasellus bibendum, odio ut hendrerit rhoncus, nulla ex placerat ipsum, eu dapibus quam lectus id mauris. Vestibulum scelerisque vel eros eget malesuada. Nam a arcu enim. Curabitur pulvinar eros id mi mattis pellentesque. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Curabitur magna nunc, vestibulum vitae magna at, tristique dapibus elit. Sed vel auctor arcu. Aenean consectetur porta lorem, a malesuada lectus ultricies at. Sed imperdiet felis sodales mauris commodo, vitae pretium sem malesuada. Vestibulum quis viverra quam, sed faucibus ligula. Vestibulum finibus porta ante at fermentum."};
    Ebook ebook_library[3] = {ebook1, ebook2, ebook3}; // array of ebooks
    printf("Welcome to the Ebook reader.\n");
    while (1) { // infinite loop until user exits
        printf("Choose an Ebook to read:\n");
        for (int i = 0; i < 3; i++) { // display list of ebooks
            printf("%d. %s by %s\n", i+1, ebook_library[i].title, ebook_library[i].author);
        }
        printf("4. Exit\n");
        printf("> ");
        int choice;
        scanf("%d", &choice);
        if (choice == 4) { // break out of infinite loop and exit program
            break;
        }
        if (choice < 1 || choice > 3) { // input validation
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        displayEbook(ebook_library[choice-1]); // display Ebook info and allow user to read
        while (getchar() != '\n');
        printf("\n");
    }
    return 0;
}