//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct EBook {
    int book_id;
    char book_title[50];
    char author_name[50];
    char publisher[50];
    float book_price;
    struct EBook *next;
};

void display_menu() {
    printf("\n------EBook Reader Menu------\n");
    printf("\n1. Add a new book");
    printf("\n2. Display all books");
    printf("\n3. Remove a book");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

void add_book(struct EBook **ebook_head) {
    struct EBook *new_book = (struct EBook*)malloc(sizeof(struct EBook));
    printf("\nEnter book ID: ");
    scanf("%d", &new_book->book_id);
    printf("\nEnter book title: ");
    scanf("%s", new_book->book_title);
    printf("\nEnter author name: ");
    scanf("%s", new_book->author_name);
    printf("\nEnter publisher: ");
    scanf("%s", new_book->publisher);
    printf("\nEnter book price: ");
    scanf("%f", &new_book->book_price);
    new_book->next = *ebook_head;
    *ebook_head = new_book;
    printf("\nBook added successfully!");
}

void display_books(struct EBook *ebook_head) {
    if(ebook_head == NULL) {
        printf("\nNo books found!");
        return;
    }
    printf("\n------All Books------\n");
    printf("\nBook ID\tTitle\tAuthor\tPublisher\tPrice\n");
    while(ebook_head != NULL) {
        printf("%d\t%s\t%s\t%s\t%.2f\n", ebook_head->book_id, ebook_head->book_title, ebook_head->author_name,
            ebook_head->publisher, ebook_head->book_price);
        ebook_head = ebook_head->next;
    }
}

void remove_book(struct EBook **ebook_head) {
    if(*ebook_head == NULL) {
        printf("\nNo books found!");
        return;
    }
    int book_id;
    printf("\nEnter book ID to remove: ");
    scanf("%d", &book_id);
    struct EBook *temp = *ebook_head, *prev;
    if(temp != NULL && temp->book_id == book_id) {
        *ebook_head = temp->next;
        free(temp);
        printf("\nBook removed successfully!");
        return;
    }
    while(temp != NULL && temp->book_id != book_id) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("\nBook with ID %d not found!", book_id);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nBook removed successfully!");
}

int main() {
    struct EBook *ebook_head = NULL;
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_book(&ebook_head);
                break;
            case 2:
                display_books(ebook_head);
                break;
            case 3:
                remove_book(&ebook_head);
                break;
            case 4:
                printf("\nExiting EBook Reader!");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.");
        }
    } while(choice != 4); // Using recursion instead of loops for user input
    return 0;
}