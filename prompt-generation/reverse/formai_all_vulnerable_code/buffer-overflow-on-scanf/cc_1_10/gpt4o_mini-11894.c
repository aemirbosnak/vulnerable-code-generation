//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} BookDatabase;

void initializeDatabase(BookDatabase *db) {
    db->count = 0;
    printf("🌟 Welcome to the Book Database! It's wonderful to see you here! 🌟\n");
}

void addBook(BookDatabase *db) {
    if (db->count >= MAX_BOOKS) {
        printf("💔 Our library is full! Can't add more books right now.\n");
        return;
    }
    
    Book newBook;
    
    printf("Enter the book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // Remove newline

    printf("Enter the author's name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // Remove newline
    
    db->books[db->count++] = newBook;
    printf("📚 Thank you for adding the book '%s' by %s to our library! 📚\n", newBook.title, newBook.author);
}

void viewBooks(BookDatabase *db) {
    if (db->count == 0) {
        printf("📖 Our library is empty! Let's add some books, shall we? 📖\n");
        return;
    }
    
    printf("\n🌈 Here are the books in our library:\n");
    for (int i = 0; i < db->count; i++) {
        printf("  %d. '%s' by %s\n", i + 1, db->books[i].title, db->books[i].author);
    }
    printf("🌈 Thank you for cherishing these wonderful titles! 🌈\n");
}

void searchBook(BookDatabase *db) {
    char searchTerm[MAX_TITLE_LENGTH];
    printf("Enter the title or author to search: ");
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    printf("\n🔍 Searching for books matching '%s':\n", searchTerm);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->books[i].title, searchTerm) != NULL || strstr(db->books[i].author, searchTerm) != NULL) {
            printf("  Found: '%s' by %s\n", db->books[i].title, db->books[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("⚠️ No matches found. Let's keep exploring! ⚠️\n");
    }
}

void deleteBook(BookDatabase *db) {
    if (db->count == 0) {
        printf("⚠️ The library is empty! No books to delete. ⚠️\n");
        return;
    }

    viewBooks(db);
    int index;
    printf("Please enter the number of the book you wish to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > db->count) {
        printf("❌ Invalid selection. No book deleted. ❌\n");
        return;
    }

    index--; // Convert to 0-based index
    printf("🗑️ Removing '%s' by %s from the library. Farewell! 🗑️\n", db->books[index].title, db->books[index].author);

    for (int i = index; i < db->count - 1; i++) {
        db->books[i] = db->books[i + 1];
    }
    db->count--;
}

void displayMenu() {
    printf("\n📚 Book Database Menu 📚\n");
    printf("1. Add a book\n");
    printf("2. View all books\n");
    printf("3. Search for a book\n");
    printf("4. Delete a book\n");
    printf("5. Exit\n");
}

int main() {
    BookDatabase db;
    initializeDatabase(&db);

    int choice;
    do {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                viewBooks(&db);
                break;
            case 3:
                searchBook(&db);
                break;
            case 4:
                deleteBook(&db);
                break;
            case 5:
                printf("🌼 Thank you for using the Book Database! Have a wonderful day! 🌼\n");
                break;
            default:
                printf("❓ Invalid choice, please try again. ❓\n");
        }
    } while (choice != 5);
    
    return 0;
}