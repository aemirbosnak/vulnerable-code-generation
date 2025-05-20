//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 256
#define MAX_CONTENT_LEN 2048

typedef struct {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book(char *title, char *content) {
    if (book_count < MAX_BOOKS) {
        strncpy(library[book_count].title, title, MAX_TITLE_LEN);
        strncpy(library[book_count].content, content, MAX_CONTENT_LEN);
        book_count++;
        printf("The echoes of forgotten dreams whisper: '%s' has been bound to the shelf.\n", title);
    } else {
        printf("The library of shadows is full, no more tomes can be embraced.\n");
    }
}

void read_book(int index) {
    if (index < 0 || index >= book_count) {
        printf("The pages of the cosmos swirl, you have chosen a book that does not exist.\n");
        return;
    }

    printf("\n&%s&\n", library[index].title);
    printf("In the realm of imagination:\n");
    printf("%s\n", library[index].content);
    printf("The narrative fades, yet lingers like ethereal smoke in the air...\n");
}

void display_menu() {
    printf("\n--- A Library of Shadows ---\n");
    printf("1. Add a Book\n");
    printf("2. Read a Book\n");
    printf("3. List Books\n");
    printf("4. Exit into the Abyss\n");
    printf("---------------------------\n");
    printf("Choose your destiny: ");
}

void list_books() {
    if (book_count == 0) {
        printf("The shelves are bare, the silence screams for stories untold.\n");
        return;
    }

    printf("\n--- Books in the Library ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int choice;
    char title[MAX_TITLE_LEN], content[MAX_CONTENT_LEN];

    printf("Welcome, brave voyager, to the surreal library where pages breathe and ink flows like liquid stars.\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
        case 1:
            printf("What is the title of your creation? ");
            fgets(title, MAX_TITLE_LEN, stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline

            printf("What story flows from the quill of your imagination?\n");
            fgets(content, MAX_CONTENT_LEN, stdin);
            content[strcspn(content, "\n")] = 0; // Remove newline

            add_book(title, content);
            break;
        case 2:
            list_books();
            printf("Which book shall we unravel together? (Enter the number): ");
            int read_choice;
            scanf("%d", &read_choice);
            clear_input_buffer();
            read_book(read_choice - 1);
            break;
        case 3:
            list_books();
            break;
        case 4:
            printf("You have chosen to dissolve into the void. May your dreams be forever entwined with the stars.\n");
            exit(0);
        default:
            printf("The clock ticks erratically, your choice dances upon the edge of madness.\n");
        }
    }

    return 0;
}