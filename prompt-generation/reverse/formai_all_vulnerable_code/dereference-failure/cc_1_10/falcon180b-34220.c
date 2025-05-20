//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_BOOK_SIZE 10000

typedef struct {
    char* title;
    char* author;
    char* content;
    int content_size;
} Book;

Book* create_book(char* title, char* author, char* content) {
    Book* book = (Book*)malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->content = strdup(content);
    book->content_size = strlen(content);
    return book;
}

void destroy_book(Book* book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

int main() {
    Book* book = create_book("The Great Gatsby", "F. Scott Fitzgerald", "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. 'Whenever you feel like criticizing anyone,' he told me, 'just remember that all the people in this world haven't had the advantages that you've had.' He didn't say any more, but we've always been unusually communicative in a reserved way, and I understood that he meant a great deal more than that. In consequence, I'm inclined to reserve all judgments, a habit that has opened up many curious natures to me and also made me the victim of not a few veteran bores. The abnormal mind is quick to detect and attach itself to that which is irresistibly attractive to it — because a straight line is the shortest distance from where it is to where it wants to go anyway. And now here is my secret, a very simple secret: It is only with the heart that one can see rightly; what is essential is invisible to the eye. ");

    char search_word[MAX_WORD_LENGTH];
    printf("Enter a word to search: ");
    scanf("%s", search_word);

    int total_occurrences = 0;
    int current_occurrence = 0;
    char* content_copy = strdup(book->content);
    char* token = strtok(content_copy, " ");
    while (token!= NULL) {
        if (strcmp(token, search_word) == 0) {
            total_occurrences++;
            current_occurrence++;
        }
        token = strtok(NULL, " ");
    }

    if (total_occurrences == 0) {
        printf("The word '%s' was not found in the book.\n", search_word);
    } else {
        printf("The word '%s' was found %d time(s) in the book.\n", search_word, total_occurrences);
        printf("The first occurrence is at position %d.\n", current_occurrence);
    }

    destroy_book(book);

    return 0;
}