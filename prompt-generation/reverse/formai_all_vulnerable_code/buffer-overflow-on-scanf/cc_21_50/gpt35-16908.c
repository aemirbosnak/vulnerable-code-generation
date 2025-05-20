//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    float price;
} Book;

int main() {
    Book books[MAX_RECORDS];
    int num_records = 0;
    
    while (true) {
        printf("\n----------\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Update book\n");
        printf("4. Remove book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("\n--- Add book ---\n");
                if (num_records >= MAX_RECORDS) {
                    printf("Error: Database is full.\n");
                    break;
                }
                
                Book new_book = {
                    .id = num_records + 1
                };
                
                printf("Enter title: ");
                scanf("%s", &new_book.title);
                
                printf("Enter author: ");
                scanf("%s", &new_book.author);
                
                printf("Enter price: ");
                scanf("%f", &new_book.price);
                
                books[num_records] = new_book;
                num_records++;
                printf("Book added.\n");
                break;
            }
            
            case 2: {
                printf("\n--- Display books ---\n");
                if (num_records == 0) {
                    printf("No books in database.\n");
                    break;
                }
                
                for (int i = 0; i < num_records; i++) {
                    Book book = books[i];
                    printf("%d. %s by %s, $%.2f\n", book.id, book.title, book.author, book.price);
                }
                break;
            }
            
            case 3: {
                printf("\n--- Update book ---\n");
                if (num_records == 0) {
                    printf("No books in database.\n");
                    break;
                }
                
                printf("Enter book ID to update: ");
                int id;
                scanf("%d", &id);
                
                bool found = false;
                for (int i = 0; i < num_records; i++) {
                    if (books[i].id == id) {
                        found = true;
                        printf("Enter new title (or '-' to keep the same): ");
                        char title[100];
                        scanf("%s", &title);
                        if (strcmp(title, "-") != 0) {
                            strcpy(books[i].title, title);
                        }
                        
                        printf("Enter new author (or '-' to keep the same): ");
                        char author[100];
                        scanf("%s", &author);
                        if (strcmp(author, "-") != 0) {
                            strcpy(books[i].author, author);
                        }
                        
                        printf("Enter new price (or -1 to keep the same): ");
                        float price;
                        scanf("%f", &price);
                        if (price != -1) {
                            books[i].price = price;
                        }
                        
                        printf("Book updated.\n");
                        break;
                    }
                }
                
                if (!found) {
                    printf("Book not found.\n");
                }
                break;
            }
            
            case 4: {
                printf("\n--- Remove book ---\n");
                if (num_records == 0) {
                    printf("No books in database.\n");
                    break;
                }
                
                printf("Enter book ID to remove: ");
                int id;
                scanf("%d", &id);
                
                bool found = false;
                for (int i = 0; i < num_records; i++) {
                    if (books[i].id == id) {
                        found = true;
                        printf("Are you sure you want to remove %s by %s? (y/n)", books[i].title, books[i].author);
                        char confirm;
                        scanf(" %c", &confirm);
                        if (confirm == 'y') {
                            for (int j = i+1; j < num_records; j++) {
                                books[j-1] = books[j];
                            }
                            num_records--;
                            printf("Book removed.\n");
                        } else {
                            printf("Removal cancelled.\n");
                        }
                        break;
                    }
                }
                
                if (!found) {
                    printf("Book not found.\n");
                }
                break;
            }
            
            case 5: {
                printf("\n--- Exiting ---\n");
                return 0;
            }
            
            default: {
                printf("Error: Invalid choice.\n");
                break;
            }
        }
    }
}