//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[50];
    char author[50];
    int year;
} Book;

int main() {
    Book books[10];
    int n = 0;
    int choice;

    while (1) {
        printf("\n****Library Management System****\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Books\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Book Title: ");
                scanf(" %[^\n]s", books[n].title);
                printf("Enter Author Name: ");
                scanf(" %[^\n]s", books[n].author);
                printf("Enter Year of Publication: ");
                scanf("%d", &books[n].year);
                books[n].id = n + 1;
                printf("\nBook Added Successfully!\n");
                n++;
                break;

            case 2:
                if (n == 0) {
                    printf("\nNo Books to Display!\n");
                } else {
                    printf("\nBooks in the Library:\n");
                    printf("ID\tTitle\t\t\tAuthor\t\tYear\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d\t%-20s\t%-20s\t%d\n", books[i].id, books[i].title, books[i].author, books[i].year);
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nNo Books to Search!\n");
                } else {
                    char search_title[50];
                    printf("\nEnter Book Title to Search: ");
                    scanf(" %[^\n]s", search_title);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (strcmp(search_title, books[i].title) == 0) {
                            printf("\nBook Found:\n");
                            printf("ID\tTitle\t\t\tAuthor\t\tYear\n");
                            printf("%d\t%-20s\t%-20s\t%d\n", books[i].id, books[i].title, books[i].author, books[i].year);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("\nBook Not Found!\n");
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    printf("\nNo Books to Delete!\n");
                } else {
                    int delete_id;
                    printf("\nEnter Book ID to Delete: ");
                    scanf("%d", &delete_id);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (delete_id == books[i].id) {
                            for (int j = i; j < n - 1; j++) {
                                books[j] = books[j + 1];
                            }
                            n--;
                            printf("\nBook Deleted Successfully!\n");
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("\nBook Not Found!\n");
                    }
                }
                break;

            case 5:
                printf("\nThank You for using the Library Management System!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }

    return 0;
}