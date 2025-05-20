//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define EBOOK_WIDTH 80
#define EBOOK_HEIGHT 200

typedef struct {
    char *title;
    char *author;
    char *content;
    int pages;
} ebook_t;

ebook_t ebooks[5];

void init_ebooks(void) {
    ebooks[0].title = "The Great Gatsby";
    ebooks[0].author = "F. Scott Fitzgerald";
    ebooks[0].content = "In the town of West Egg, Long Island, a mysterious man named Gatsby throws extravagant parties to win back his lost love, Daisy Buchanan.";
    ebooks[0].pages = 200;

    ebooks[1].title = "To Kill a Mockingbird";
    ebooks[1].author = "Harper Lee";
    ebooks[1].content = "In the Deep South during the 1930s, a young girl named Scout Finch learns about prejudice, injustice, and the loss of innocence as her father, Atticus, defends a black man accused of rape.";
    ebooks[1].pages = 300;

    ebooks[2].title = "Pride and Prejudice";
    ebooks[2].author = "Jane Austen";
    ebooks[2].content = "In 19th century England, Elizabeth Bennet, a strong-willed and independent young woman, meets the wealthy Mr. Darcy, and despite their initial dislike for each other, they must navigate societal pressures and their own pride to find love.";
    ebooks[2].pages = 400;

    ebooks[3].title = "The Catcher in the Rye";
    ebooks[3].author = "J.D. Salinger";
    ebooks[3].content = "In post-war New York City, a disillusioned teenager named Holden Caulfield struggles to find his place in the world, grappling with the challenges of adolescence and the hypocrisy of adult society.";
    ebooks[3].pages = 250;

    ebooks[4].title = "1984";
    ebooks[4].author = "George Orwell";
    ebooks[4].content = "In a dystopian future, the totalitarian government of Oceania exercises total control over its citizens, and the protagonist, Winston Smith, must navigate the treacherous world of doublethink and newspeak to uncover the truth and find love.";
    ebooks[4].pages = 400;
}

void display_ebook(int index) {
    printf("--- %s by %s ---\n", ebooks[index].title, ebooks[index].author);
    printf("Page %d of %d\n\n", ebooks[index].pages, ebooks[index].content);
}

int main(void) {
    init_ebooks();

    while (1) {
        printf("Select an ebook by number (1-4): ");
        scanf("%d", &index);

        display_ebook(index);

        printf("Press Enter to continue...");
        getchar();
    }

    return 0;
}