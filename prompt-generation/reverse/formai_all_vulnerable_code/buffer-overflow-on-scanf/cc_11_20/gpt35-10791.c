//FormAI DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int page_count;
    float rating;
} Book;

typedef struct {
    int id;
    char name[50];
    int num_books;
    Book *books;
} User;

int main() {
    User users[10];
    int num_users = 0;
    int user_choice;

    do {
        printf("Welcome to the Library Database System!\n");
        printf("----------------------------------------\n");
        printf("1. Add a new user\n");
        printf("2. Add books to a user's collection\n");
        printf("3. Display all users\n");
        printf("4. Search for a user by name\n");
        printf("5. Quit\n");
        printf("Please make a selection: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1: {
                User new_user;

                printf("Enter user name: ");
                scanf("%s", new_user.name);

                printf("Enter number of books in collection: ");
                scanf("%d", &new_user.num_books);

                new_user.books = malloc(sizeof(Book) * new_user.num_books);

                for (int i = 0; i < new_user.num_books; i++) {
                    printf("Enter book title: ");
                    scanf("%s", new_user.books[i].title);

                    printf("Enter book author: ");
                    scanf("%s", new_user.books[i].author);

                    printf("Enter book page count: ");
                    scanf("%d", &new_user.books[i].page_count);

                    printf("Enter book rating: ");
                    scanf("%f", &new_user.books[i].rating);
                }

                new_user.id = num_users;
                users[num_users] = new_user;
                num_users++;

                printf("New user added!\n");

                break;
            }

            case 2: {
                char user_name[50];
                int user_index = -1;

                printf("Enter user name: ");
                scanf("%s", user_name);

                for (int i = 0; i < num_users; i++) {
                    if (strcmp(user_name, users[i].name) == 0) {
                        user_index = i;
                        break;
                    }
                }

                if (user_index == -1) {
                    printf("User not found.\n");
                    break;
                }

                int num_new_books;
                printf("Enter number of new books: ");
                scanf("%d", &num_new_books);

                users[user_index].num_books += num_new_books;
                users[user_index].books = realloc(users[user_index].books, sizeof(Book) * users[user_index].num_books);

                for (int i = users[user_index].num_books - num_new_books; i < users[user_index].num_books; i++) {
                    printf("Enter book title: ");
                    scanf("%s", users[user_index].books[i].title);

                    printf("Enter book author: ");
                    scanf("%s", users[user_index].books[i].author);

                    printf("Enter book page count: ");
                    scanf("%d", &users[user_index].books[i].page_count);

                    printf("Enter book rating: ");
                    scanf("%f", &users[user_index].books[i].rating);
                }

                printf("%d books added to %s's collection.\n", num_new_books, user_name);

                break;
            }

            case 3: {
                printf("All users:\n");
                printf("----------\n");

                for (int i = 0; i < num_users; i++) {
                    printf("ID: %d\n", users[i].id);
                    printf("Name: %s\n", users[i].name);
                    printf("Number of books in collection: %d\n", users[i].num_books);
                    printf("Book list:\n");

                    for (int j = 0; j < users[i].num_books; j++) {
                        printf("Title: %s\n", users[i].books[j].title);
                        printf("Author: %s\n", users[i].books[j].author);
                        printf("Page count: %d\n", users[i].books[j].page_count);
                        printf("Rating: %f\n", users[i].books[j].rating);
                    }
                }

                break;
            }

            case 4: {
                char user_name[50];
                int user_index = -1;

                printf("Enter user name: ");
                scanf("%s", user_name);

                for (int i = 0; i < num_users; i++) {
                    if (strcmp(user_name, users[i].name) == 0) {
                        user_index = i;
                        break;
                    }
                }

                if (user_index == -1) {
                    printf("User not found.\n");
                    break;
                }

                printf("User found!\n");
                printf("ID: %d\n", users[user_index].id);
                printf("Name: %s\n", users[user_index].name);
                printf("Number of books in collection: %d\n", users[user_index].num_books);
                printf("Book list:\n");

                for (int j = 0; j < users[user_index].num_books; j++) {
                    printf("Title: %s\n", users[user_index].books[j].title);
                    printf("Author: %s\n", users[user_index].books[j].author);
                    printf("Page count: %d\n", users[user_index].books[j].page_count);
                    printf("Rating: %f\n", users[user_index].books[j].rating);
                }

                break;
            }

            case 5: {
                printf("Exiting program...\n");
                break;
            }

            default: {
                printf("Invalid option selected. Please try again.\n");
                break;
            }
        }

    } while (user_choice != 5);

    return 0;
}